/*
 * Copyright (c) 2008-2009 Apple Inc. All rights reserved.
 *
 * @APPLE_APACHE_LICENSE_HEADER_START@
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * @APPLE_APACHE_LICENSE_HEADER_END@
 */

/*
 * fd_stress.c
 *
 * Stress test for dispatch read and write sources.
 */

#include "config/config.h"

#include <dispatch/dispatch.h>

#include <assert.h>
#include <CommonCrypto/CommonDigest.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <unistd.h>

static inline size_t max(size_t a, size_t b) {
	return (a > b) ? a : b;
}

static inline size_t min(size_t a, size_t b) {
	return (a < b) ? a : b;
}

int debug = 0;

#define DEBUG(...) do { \
		if (debug) fprintf(stderr, __VA_ARGS__); \
	} while(0);

#define assert_errno(str, expr) do { \
	if (!(expr)) { \
		fprintf(stderr, "%s: %s\n", (str), strerror(errno)); \
		exit(1); \
	} } while(0);

#define assert_gai_errno(str, expr) do { \
	if (!(expr)) { \
		fprintf(stderr, "%s: %s\n", (str), gai_strerror(errno)); \
		exit(1); \
	} } while(0);


/* sock_context
 *
 * Context structure used by the reader and writer queues.
 *
 * Writers begin by generating a random length and writing it to the descriptor.
 * The write buffer is filled with a random byte value and written until empty
 * or until the total length is reached. The write buffer is refilled with more
 * random data when empty. Each write updates an MD5 digest which is written to
 * the descriptor once the total length is reached.
 *
 * Readers begin by reading the total length of data. The read buffer is filled
 * and an MD5 digest is computed on the bytes as they are received. Once the
 * total length of data has be read, an MD5 digest is read from the descriptor
 * and compared with the computed value.
 */ 
struct sock_context {
	enum {
		LENGTH,
		DATA,
		CKSUM,
		DONE,
	} state;
	char label[64];
	uint32_t len;
	off_t offset;
	char buf[8192];
	size_t buflen;
	CC_MD5_CTX md5ctx;
	char md5[CC_MD5_DIGEST_LENGTH];
};

dispatch_source_t
create_writer(int wfd, dispatch_block_t completion)
{
	dispatch_source_t ds;
	struct sock_context *ctx = calloc(1, sizeof(struct sock_context));
	assert(ctx);

	snprintf(ctx->label, sizeof(ctx->label), "writer.fd.%d", wfd);
	dispatch_queue_t queue = dispatch_queue_create(ctx->label, 0);
	
	ds = dispatch_source_create(DISPATCH_SOURCE_TYPE_WRITE, wfd, 0, queue);
	assert(ds);
	dispatch_release(queue);
	
	uint32_t len;
	do {
		len = (arc4random() & 0x7FFF);
	} while (len == 0);
	ctx->state = LENGTH;
	CC_MD5_Init(&ctx->md5ctx);
	ctx->len = len;
	ctx->buflen = sizeof(len);
	len = htonl(len);
	memcpy(ctx->buf, &len, ctx->buflen);
	DEBUG("%s: LENGTH %d\n", ctx->label, ctx->len);
	
	dispatch_source_set_event_handler(ds, ^{
		DEBUG("%s: available %ld\n", ctx->label, dispatch_source_get_data(ds));
		ssize_t res;
		size_t wrsz = min(ctx->len, ctx->buflen);
		res = write(wfd, &ctx->buf[ctx->offset], wrsz);
		DEBUG("%s: write(%d, %p, %ld): %ld\n", ctx->label, wfd, &ctx->buf[ctx->offset], wrsz, res);
		if (res > 0) {
			if (ctx->state == DATA) {
				CC_MD5_Update(&ctx->md5ctx, &ctx->buf[ctx->offset], res);
				ctx->len -= res;
			}
			ctx->offset += res;
			ctx->buflen -= res;
			assert(ctx->offset >= 0);
			assert(ctx->len >= 0);
			assert(ctx->buflen >= 0);
			if (ctx->buflen == 0 || ctx->len == 0) {
				if (ctx->state == LENGTH) {
					// finished writing length, move on to data.
					ctx->state = DATA;
					ctx->buflen = sizeof(ctx->buf);
					char pattern = arc4random() & 0xFF;
					memset(ctx->buf, pattern, ctx->buflen);
				} else if (ctx->state == DATA && ctx->len == 0) {
					// finished writing data, move on to cksum.
					ctx->state = CKSUM;
					ctx->len = sizeof(ctx->md5);
					ctx->buflen = sizeof(ctx->md5);
					CC_MD5_Final(ctx->md5, &ctx->md5ctx);
					memcpy(ctx->buf, ctx->md5, ctx->buflen);
				} else if (ctx->state == DATA) {
					ctx->buflen = sizeof(ctx->buf);
					char pattern = arc4random() & 0xFF;
					memset(ctx->buf, pattern, ctx->buflen);
				} else if (ctx->state == CKSUM) {
					ctx->state = DONE;
					dispatch_source_cancel(ds);
				} else {
					assert(0);
				}
				ctx->offset = 0;
			}
		} else if (res == 0) {
			assert(ctx->state == DONE);
			assert(0);
		} else if (res == -1 && errno == EAGAIN) {
			DEBUG("%s: EAGAIN\n", ctx->label);
		} else {
			assert_errno("write", res >= 0);
		}
	});
	dispatch_source_set_cancel_handler(ds, ^{
		DEBUG("%s: close(%d)\n", ctx->label, wfd);
		int res = close(wfd);
		assert_errno("close", res == 0);
		completion();
		dispatch_release(ds);
		free(ctx);
	});
	dispatch_resume(ds);
	return ds;
}

dispatch_source_t
create_reader(int rfd, dispatch_block_t completion)
{
	dispatch_source_t ds;
	struct sock_context *ctx = calloc(1, sizeof(struct sock_context));
	assert(ctx);
	
	snprintf(ctx->label, sizeof(ctx->label), "reader.fd.%d", rfd);
	dispatch_queue_t queue = dispatch_queue_create(ctx->label, 0);
	
	ds = dispatch_source_create(DISPATCH_SOURCE_TYPE_READ, rfd, 0, queue);
	assert(ds);
	dispatch_release(queue);
	
	ctx->state = LENGTH;
	ctx->len = sizeof(ctx->len);
	ctx->buflen = sizeof(ctx->len);
	CC_MD5_Init(&ctx->md5ctx);
	
	dispatch_source_set_event_handler(ds, ^{
		DEBUG("%s: available %ld\n", ctx->label, dispatch_source_get_data(ds));
		ssize_t res;
		size_t rdsz = min(ctx->len, ctx->buflen);
		res = read(rfd, &ctx->buf[ctx->offset], rdsz);
		DEBUG("%s: read(%d,%p,%ld): %ld\n", ctx->label, rfd, &ctx->buf[ctx->offset], rdsz, res);

		// log unexpected data lengths...
		long expected = dispatch_source_get_data(ds);
		long actual = res;
		if (actual >= 0 && (actual != expected && actual != rdsz)) {
			fprintf(stderr, "%s: expected %ld, actual %ld (rdsz = %ld)\n", ctx->label, expected, actual, rdsz);
		}

		if (res > 0) {
			if (ctx->state == DATA) {
				CC_MD5_Update(&ctx->md5ctx, &ctx->buf[ctx->offset], res);
				ctx->len -= res;
			}
			ctx->offset += res;
			ctx->buflen -= res;
			if (ctx->buflen == 0 || ctx->len == 0) {
				if (ctx->state == LENGTH) {
					// buffer is full, interpret as uint32_t
					memcpy(&ctx->len, ctx->buf, sizeof(ctx->len));
					ctx->len = ntohl(ctx->len);
					ctx->buflen = sizeof(ctx->buf);
					ctx->state = DATA;
				} else if (ctx->state == DATA && ctx->len == 0) {
					CC_MD5_Final(ctx->md5, &ctx->md5ctx);
					ctx->state = CKSUM;
					ctx->len = CC_MD5_DIGEST_LENGTH;
					ctx->buflen = ctx->len;
				} else if (ctx->state == DATA) {
					ctx->buflen = sizeof(ctx->buf);
				} else if (ctx->state == CKSUM) {
					ctx->state = DONE;
					res = memcmp(ctx->buf, ctx->md5, sizeof(ctx->md5));
					if (res != 0) {
						DEBUG("%s: MD5 FAILURE\n", ctx->label);
					}
					assert(res == 0);
				}
				ctx->offset = 0;
			}
		} else if (res == 0) {
			assert(ctx->state == DONE);
			DEBUG("%s: EOF\n", ctx->label);
			dispatch_source_cancel(ds);
		} else {
			assert_errno("read", res >= 0);
		}
	});
	dispatch_source_set_cancel_handler(ds, ^{
		DEBUG("%s: close(%d)\n", ctx->label, rfd);
		int res = close(rfd);
		assert_errno("close", res == 0);
		completion();
		dispatch_release(ds);
		free(ctx);
	});
	dispatch_resume(ds);
	return ds;
}

void
set_nonblock(int fd)
{
	int res, flags;
	flags = fcntl(fd, F_GETFL);

	flags |= O_NONBLOCK;
	res = fcntl(fd, F_SETFL, flags);
	assert_errno("fcntl(F_SETFL,O_NONBLOCK)", res == 0);
}

void
create_fifo(int *rfd, int *wfd)
{
	int res;
	char *name;
	
	char path[MAXPATHLEN];
	strlcpy(path, "/tmp/fd_stress.fifo.XXXXXX", sizeof(path));
	name = mktemp(path);
	
	res = unlink(name);

	res = mkfifo(name, 0700);
	assert_errno(name, res == 0);
	
	*rfd = open(name, O_RDONLY | O_NONBLOCK);
	assert_errno(name, *rfd >= 0);
	
	*wfd = open(name, O_WRONLY | O_NONBLOCK);
	assert_errno(name, *wfd >= 0);
}

void
create_pipe(int *rfd, int *wfd)
{
	int res;
	int fildes[2];
	
	res = pipe(fildes);
	assert_errno("pipe", res == 0);
	
	*rfd = fildes[0];
	*wfd = fildes[1];

	set_nonblock(*rfd);
	set_nonblock(*wfd);
}

void
create_server_socket(int *rfd, struct sockaddr_in *sa)
{
	int res;
	int value;
	socklen_t salen = sizeof(*sa);

	memset(sa, 0, salen);
	sa->sin_len = salen;
	sa->sin_family = AF_INET;
	sa->sin_port = htons(12345);
	sa->sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	*rfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	assert_errno("socket", *rfd >= 0);
	
	value = 1;
	res = setsockopt(*rfd, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value));
	assert_errno("setsockopt(SO_REUSEADDR)", res == 0);

	value = 1;
	res = setsockopt(*rfd, SOL_SOCKET, SO_REUSEPORT, &value, sizeof(value));
	assert_errno("setsockopt(SO_REUSEPORT)", res == 0);
	
	res = bind(*rfd, (const struct sockaddr *)sa, salen);
	assert_errno("bind", res == 0);

	res = listen(*rfd, 128);
	assert_errno("listen", res == 0);
}

void
create_client_socket(int *wfd, const struct sockaddr_in *sa)
{
	int res;

	*wfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	assert_errno("socket", *wfd >= 0);
	
	set_nonblock(*wfd);

	res = connect(*wfd, (const struct sockaddr *)sa, sa->sin_len);
	assert_errno("connect", res == 0 || errno == EINPROGRESS);
}

extern int optind;

void
usage(void)
{
	fprintf(stderr, "usage: fd_stress [-d] iterations width\n");
	exit(1);
}

int
main(int argc, char* argv[])
{
	int serverfd;
	struct sockaddr_in sa;
	create_server_socket(&serverfd, &sa);

	int ch;
	
	while ((ch = getopt(argc, argv, "d")) != -1) {
		switch (ch) {
			case 'd':
				debug = 1;
				break;
			case '?':
			default:
				usage();
				break;
		}
	}
	argc -= optind;
	argv += optind;
	
	if (argc != 2) {
		usage();
	}
	
	size_t iterations = strtol(argv[0], NULL, 10);
	size_t width = strtol(argv[1], NULL, 10);
	
	if (iterations == 0 || width == 0) {
		usage();
	}

	fprintf(stdout, "pid %d\n", getpid());

	dispatch_group_t group;
	group = dispatch_group_create();
	assert(group);

#if 0
	dispatch_queue_t queue = dispatch_queue_create("server", NULL);

	dispatch_source_t ds;
	ds = dispatch_source_create(DISPATCH_SOURCE_TYPE_READ, serverfd, 0, queue);
	assert(ds);
	dispatch_source_set_event_handler(ds, ^{
		int res;
		int fd;
		struct sockaddr peer;
		socklen_t peerlen;

		fd = accept(serverfd, &peer, &peerlen);
		assert_errno("accept", fd >= 0);

		set_nonblock(fd);
		
		char host[NI_MAXHOST], serv[NI_MAXSERV];
		host[0] = 0;
		serv[0] = 0;
		res = getnameinfo(&peer, peerlen, host, sizeof(host), serv, sizeof(serv), NI_NUMERICHOST|NI_NUMERICSERV);
		DEBUG("ACCEPTED %d (%s:%s)\n", fd, host, serv);
		
		create_reader(fd, ^{ dispatch_group_leave(group); });
	});
	dispatch_resume(ds);
#endif

	size_t i;
	for (i = 1; i < iterations; ++i) {
		fprintf(stderr, "iteration %ld\n", i);

		size_t j;
		for (j = 0; j < width; ++j) {
			int rfd, wfd;
			dispatch_group_enter(group);
			create_pipe(&rfd, &wfd);
			DEBUG("PIPE %d %d\n", rfd, wfd);
			dispatch_source_t reader;
			reader = create_reader(rfd, ^{ dispatch_group_leave(group); });
			create_writer(wfd, ^{});
		}
		
#if 0
		int clientfd;
		dispatch_group_enter(group);
		create_client_socket(&clientfd, &sa);
		DEBUG("CLIENT %d\n", clientfd);
		create_writer(clientfd, ^{});

		dispatch_group_enter(group);
		create_fifo(&rfd, &wfd);
		DEBUG("FIFO %d %d\n", rfd, wfd);
		create_writer(wfd, ^{});
		create_reader(rfd, ^{ dispatch_group_leave(group); });
#endif

		dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
	}
	fprintf(stdout, "pid %d\n", getpid());
	dispatch_main();

	return 0;
}
