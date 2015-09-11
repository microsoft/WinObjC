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

#include "internal.h"
#include "kevent_internal.h"
#if HAVE_MACH
#include "protocol.h"
#include "protocolServer.h"
#endif

#define DISPATCH_EVFILT_TIMER	(-EVFILT_SYSCOUNT - 1)
#define DISPATCH_EVFILT_CUSTOM_ADD	(-EVFILT_SYSCOUNT - 2)
#define DISPATCH_EVFILT_CUSTOM_OR	(-EVFILT_SYSCOUNT - 3)
#define DISPATCH_EVFILT_SYSCOUNT	(EVFILT_SYSCOUNT + 3)

static struct dispatch_kevent_s _dispatch_kevent_timer[] = {
	{
		/* .dk_list    = */	{ NULL, NULL },
		/* .dk_sources = */	TAILQ_HEAD_INITIALIZER(_dispatch_kevent_timer[0].dk_sources),
		/* .kevent     = */ {
			/* .ident  = */ 	DISPATCH_TIMER_INDEX_WALL,
			/* .filter = */ 	DISPATCH_EVFILT_TIMER,
			/* .flags  = */ 	0,
			/* .fflags = */ 	0,
			/* .data   = */ 	0,
			/* .udata  = */ 	&_dispatch_kevent_timer[0]
		                    }
	},
	{
		/* .dk_list    = */	{ NULL, NULL },
		/* .dk_sources = */	TAILQ_HEAD_INITIALIZER(_dispatch_kevent_timer[1].dk_sources),
		/* .kevent     = */ {
			/* .ident  = */ 	DISPATCH_TIMER_INDEX_MACH,
			/* .filter = */ 	DISPATCH_EVFILT_TIMER,
			/* .flags  = */ 	0,
			/* .fflags = */ 	0,
			/* .data   = */ 	0,
			/* .udata  = */ 	&_dispatch_kevent_timer[1]
		                    }
	}
};
#define DISPATCH_TIMER_COUNT (sizeof _dispatch_kevent_timer / sizeof _dispatch_kevent_timer[0])

static struct dispatch_kevent_s _dispatch_kevent_data_or = {
	/* .dk_list    = */	{ NULL, NULL },
	/* .dk_sources = */	TAILQ_HEAD_INITIALIZER(_dispatch_kevent_data_or.dk_sources),
	/* .kevent     = */ {
		/* .ident  = */ 	0,
		/* .filter = */ 	DISPATCH_EVFILT_CUSTOM_OR,
		/* .flags  = */ 	EV_CLEAR,
		/* .fflags = */ 	0,
		/* .data   = */ 	0,
		/* .udata  = */ 	&_dispatch_kevent_data_or
	                    }
};
static struct dispatch_kevent_s _dispatch_kevent_data_add = {
	/* .dk_list    = */	{ NULL, NULL },
	/* .dk_sources = */	TAILQ_HEAD_INITIALIZER(_dispatch_kevent_data_add.dk_sources),
	/* .kevent     = */ {
		/* .ident  = */ 	0,
		/* .filter = */ 	DISPATCH_EVFILT_CUSTOM_ADD,
		/* .flags  = */ 	EV_CLEAR,
		/* .fflags = */ 	0,
		/* .data   = */ 	0,
		/* .udata  = */ 	&_dispatch_kevent_data_add
	                    }
};

static void _dispatch_source_merge_kevent(dispatch_source_t ds, const struct kevent *ke);
static void _dispatch_kevent_resume(dispatch_kevent_t dk, uint32_t new_flags, uint32_t del_flags);
#if HAVE_MACH
static void _dispatch_kevent_machport_resume(dispatch_kevent_t dk, uint32_t new_flags, uint32_t del_flags);
static void _dispatch_kevent_machport_enable(dispatch_kevent_t dk);
static void _dispatch_kevent_machport_disable(dispatch_kevent_t dk);

static void _dispatch_drain_mach_messages(struct kevent *ke);
static void
#endif
#if HAVE_MACH
_dispatch_mach_notify_source_init(void *context DISPATCH_UNUSED);
#endif

static const char *
_evfiltstr(short filt)
{
	switch (filt) {
#define _evfilt2(f) case (f): return #f
	_evfilt2(EVFILT_READ);
	_evfilt2(EVFILT_WRITE);
	_evfilt2(EVFILT_AIO);
	_evfilt2(EVFILT_VNODE);
	_evfilt2(EVFILT_PROC);
	_evfilt2(EVFILT_SIGNAL);
	_evfilt2(EVFILT_TIMER);
#if HAVE_MACH
	_evfilt2(EVFILT_MACHPORT);
#endif
	_evfilt2(EVFILT_FS);
	_evfilt2(EVFILT_USER);
#if HAVE_DECL_EVFILT_SESSION
	_evfilt2(EVFILT_SESSION);
#endif
#if HAVE_DECL_EVFILT_LIO
	_evfilt2(EVFILT_LIO);
#endif
	_evfilt2(EVFILT_OIO);
	_evfilt2(DISPATCH_EVFILT_TIMER);
	_evfilt2(DISPATCH_EVFILT_CUSTOM_ADD);
	_evfilt2(DISPATCH_EVFILT_CUSTOM_OR);
	default:
		return "EVFILT_missing";
	}
}

#define DSL_HASH_SIZE 256u	// must be a power of two
#define DSL_HASH(x)	((x) & (DSL_HASH_SIZE - 1))

static TAILQ_HEAD(, dispatch_kevent_s) _dispatch_sources[DSL_HASH_SIZE];

static DISPATCH_INLINE uintptr_t
_dispatch_kevent_hash(uintptr_t ident, short filter)
{
	uintptr_t value;
#if HAVE_MACH
	value = (filter == EVFILT_MACHPORT ? MACH_PORT_INDEX(ident) : ident);
#else
	value = ident;
#endif
	return DSL_HASH(value);
}

static dispatch_kevent_t
_dispatch_kevent_find(uintptr_t ident, short filter)
{
	uintptr_t hash = _dispatch_kevent_hash(ident, filter);
	dispatch_kevent_t dki;

	TAILQ_FOREACH(dki, &_dispatch_sources[hash], dk_list) {
		if (dki->dk_kevent.ident == ident && dki->dk_kevent.filter == filter) {
			break;
		}
	}
	return dki;
}

static void
_dispatch_kevent_insert(dispatch_kevent_t dk)
{
	uintptr_t hash = _dispatch_kevent_hash(dk->dk_kevent.ident,
					       dk->dk_kevent.filter);

	TAILQ_INSERT_TAIL(&_dispatch_sources[hash], dk, dk_list);
}

#if DISPATCH_DEBUG
void
dispatch_debug_kevents(struct kevent* kev, size_t count, const char* str)
{
	size_t i;
	for (i = 0; i < count; ++i) {
		_dispatch_log("kevent[%lu] = { ident = %p, filter = %s, flags = 0x%x, fflags = 0x%x, data = %p, udata = %p }: %s",
			i, (void*)kev[i].ident, _evfiltstr(kev[i].filter), kev[i].flags, kev[i].fflags, (void*)kev[i].data, (void*)kev[i].udata, str);
	}
}
#endif

static size_t
_dispatch_source_kevent_debug(dispatch_source_t ds, char* buf, size_t bufsiz)
{
	size_t offset = _dispatch_source_debug(ds, buf, bufsiz);
	offset += snprintf(&buf[offset], bufsiz - offset, "filter = %s }",
			ds->ds_dkev ? _evfiltstr(ds->ds_dkev->dk_kevent.filter) : "????");
	return offset;
}

static void
_dispatch_source_init_tail_queue_array(void *context DISPATCH_UNUSED)
{
	unsigned int i;
	for (i = 0; i < DSL_HASH_SIZE; i++) {
		TAILQ_INIT(&_dispatch_sources[i]);
	}

	TAILQ_INSERT_TAIL(&_dispatch_sources[DSL_HASH(DISPATCH_TIMER_INDEX_WALL)], &_dispatch_kevent_timer[DISPATCH_TIMER_INDEX_WALL], dk_list);
	TAILQ_INSERT_TAIL(&_dispatch_sources[DSL_HASH(DISPATCH_TIMER_INDEX_MACH)], &_dispatch_kevent_timer[DISPATCH_TIMER_INDEX_MACH], dk_list);
	TAILQ_INSERT_TAIL(&_dispatch_sources[0], &_dispatch_kevent_data_or, dk_list);
	TAILQ_INSERT_TAIL(&_dispatch_sources[0], &_dispatch_kevent_data_add, dk_list);
}

// Find existing kevents, and merge any new flags if necessary
void
_dispatch_kevent_merge(dispatch_source_t ds)
{
	static dispatch_once_t pred;
	dispatch_kevent_t dk;
	uint32_t new_flags;
	bool do_resume = false;

	if (ds->ds_is_installed) {
		return;
	}
	ds->ds_is_installed = true;

	dispatch_once_f(&pred, NULL, _dispatch_source_init_tail_queue_array);

	dk = _dispatch_kevent_find(ds->ds_dkev->dk_kevent.ident, ds->ds_dkev->dk_kevent.filter);
	
	if (dk) {
		// If an existing dispatch kevent is found, check to see if new flags
		// need to be added to the existing kevent
		new_flags = ~dk->dk_kevent.fflags & ds->ds_dkev->dk_kevent.fflags;
		dk->dk_kevent.fflags |= ds->ds_dkev->dk_kevent.fflags;
		free(ds->ds_dkev);
		ds->ds_dkev = dk;
		do_resume = new_flags != 0;
	} else {
		dk = ds->ds_dkev;
		_dispatch_kevent_insert(dk);
		new_flags = dk->dk_kevent.fflags;
		do_resume = true;
	}

	TAILQ_INSERT_TAIL(&dk->dk_sources, ds, ds_list);

	// Re-register the kevent with the kernel if new flags were added
	// by the dispatch kevent
	if (do_resume) {
		dk->dk_kevent.flags |= EV_ADD;
		_dispatch_source_kevent_resume(ds, new_flags, 0);
		ds->ds_is_armed = true;
	}
}


void
_dispatch_kevent_resume(dispatch_kevent_t dk, uint32_t new_flags, uint32_t del_flags)
{
	switch (dk->dk_kevent.filter) {
	case DISPATCH_EVFILT_TIMER:
	case DISPATCH_EVFILT_CUSTOM_ADD:
	case DISPATCH_EVFILT_CUSTOM_OR:
		// these types not registered with kevent
		return;
#if HAVE_MACH
	case EVFILT_MACHPORT:
		_dispatch_kevent_machport_resume(dk, new_flags, del_flags);
		break;
#endif
	case EVFILT_PROC:
		if (dk->dk_kevent.flags & EV_ONESHOT) {
			return;
		}
		// fall through
	default:
		_dispatch_update_kq(&dk->dk_kevent);
		if (dk->dk_kevent.flags & EV_DISPATCH) {
			dk->dk_kevent.flags &= ~EV_ADD;
		}
		break;
	}
}

void
_dispatch_source_kevent_resume(dispatch_source_t ds, uint32_t new_flags, uint32_t del_flags)
{
	_dispatch_kevent_resume(ds->ds_dkev, new_flags, del_flags);
}

#ifndef DISPATCH_NO_LEGACY
static void
_dispatch_kevent_debugger2(void *context, dispatch_source_t unused DISPATCH_UNUSED)
{
	struct sockaddr sa;
	socklen_t sa_len = sizeof(sa);
	int c, fd = (int)(long)context;
	unsigned int i;
	dispatch_kevent_t dk;
	dispatch_source_t ds;
	FILE *debug_stream;

	c = accept(fd, &sa, &sa_len);
	if (c == -1) {
		if (errno != EAGAIN) {
			(void)dispatch_assume_zero(errno);
		}
		return;
	}
#if 0
	int r = fcntl(c, F_SETFL, 0);	// disable non-blocking IO
	if (r == -1) {
		(void)dispatch_assume_zero(errno);
	}
#endif
	debug_stream = fdopen(c, "a");
	if (!dispatch_assume(debug_stream)) {
		close(c);
		return;
	}

	fprintf(debug_stream, "HTTP/1.0 200 OK\r\n");
	fprintf(debug_stream, "Content-type: text/html\r\n");
	fprintf(debug_stream, "Pragma: nocache\r\n");
	fprintf(debug_stream, "\r\n");
	fprintf(debug_stream, "<html>\n<head><title>PID %u</title></head>\n<body>\n<ul>\n", getpid());

	//fprintf(debug_stream, "<tr><td>DK</td><td>DK</td><td>DK</td><td>DK</td><td>DK</td><td>DK</td><td>DK</td></tr>\n");

	for (i = 0; i < DSL_HASH_SIZE; i++) {
		if (TAILQ_EMPTY(&_dispatch_sources[i])) {
			continue;
		}
		TAILQ_FOREACH(dk, &_dispatch_sources[i], dk_list) {
			fprintf(debug_stream, "\t<br><li>DK %p ident %lu filter %s flags 0x%hx fflags 0x%x data 0x%lx udata %p\n",
					dk, (unsigned long)dk->dk_kevent.ident, _evfiltstr(dk->dk_kevent.filter), dk->dk_kevent.flags,
					dk->dk_kevent.fflags, (unsigned long)dk->dk_kevent.data, dk->dk_kevent.udata);
			fprintf(debug_stream, "\t\t<ul>\n");
			TAILQ_FOREACH(ds, &dk->dk_sources, ds_list) {
				fprintf(debug_stream, "\t\t\t<li>DS %p refcnt 0x%x suspend 0x%x data 0x%lx mask 0x%lx flags 0x%x</li>\n",
						ds, ds->do_ref_cnt, ds->do_suspend_cnt, ds->ds_pending_data, ds->ds_pending_data_mask,
						ds->ds_atomic_flags);
				if (ds->do_suspend_cnt == DISPATCH_OBJECT_SUSPEND_LOCK) {
					dispatch_queue_t dq = ds->do_targetq;
					fprintf(debug_stream, "\t\t<br>DQ: %p refcnt 0x%x suspend 0x%x label: %s\n", dq, dq->do_ref_cnt, dq->do_suspend_cnt, dq->dq_label);
				}
			}
			fprintf(debug_stream, "\t\t</ul>\n");
			fprintf(debug_stream, "\t</li>\n");
		}
	}
	fprintf(debug_stream, "</ul>\n</body>\n</html>\n");
	fflush(debug_stream);
	fclose(debug_stream);
}

static void
_dispatch_kevent_debugger(void *context DISPATCH_UNUSED)
{
	union {
		struct sockaddr_in sa_in;
		struct sockaddr sa;
	} sa_u = {
		.sa_in = {
			.sin_family = AF_INET,
			.sin_addr = { htonl(INADDR_LOOPBACK), },
		},
	};
	dispatch_source_t ds;
	const char *valstr;
	int val, r, fd, sock_opt = 1;
	socklen_t slen = sizeof(sa_u);

	if (issetugid()) {
		return;
	}
	valstr = getenv("LIBDISPATCH_DEBUGGER");
	if (!valstr) {
		return;
	}
	val = atoi(valstr);
	if (val == 2) {
		sa_u.sa_in.sin_addr.s_addr = 0;
	}
	fd = socket(PF_INET, SOCK_STREAM, 0);
	if (fd == -1) {
		(void)dispatch_assume_zero(errno);
		return;
	}
	r = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (void *)&sock_opt, (socklen_t) sizeof sock_opt);
	if (r == -1) {
		(void)dispatch_assume_zero(errno);
		goto out_bad;
	}
#if 0
	r = fcntl(fd, F_SETFL, O_NONBLOCK);
	if (r == -1) {
		(void)dispatch_assume_zero(errno);
		goto out_bad;
	}
#endif
	r = bind(fd, &sa_u.sa, sizeof(sa_u));
	if (r == -1) {
		(void)dispatch_assume_zero(errno);
		goto out_bad;
	}
	r = listen(fd, SOMAXCONN);
	if (r == -1) {
		(void)dispatch_assume_zero(errno);
		goto out_bad;
	}
	r = getsockname(fd, &sa_u.sa, &slen);
	if (r == -1) {
		(void)dispatch_assume_zero(errno);
		goto out_bad;
	}
	ds = dispatch_source_read_create_f(fd, NULL, &_dispatch_mgr_q, (void *)(long)fd, _dispatch_kevent_debugger2);
	if (dispatch_assume(ds)) {
		_dispatch_log("LIBDISPATCH: debug port: %hu", ntohs(sa_u.sa_in.sin_port));
		return;
	}
out_bad:
	close(fd);
}
#endif /* DISPATCH_NO_LEGACY */

void
_dispatch_source_drain_kevent(struct kevent *ke)
{
#ifndef DISPATCH_NO_LEGACY
	static dispatch_once_t pred;
#endif
	dispatch_kevent_t dk = ke->udata;
	dispatch_source_t dsi;

#ifndef DISPATCH_NO_LEGACY
	dispatch_once_f(&pred, NULL, _dispatch_kevent_debugger);
#endif

	dispatch_debug_kevents(ke, 1, __FUNCTION__);

#if HAVE_MACH
	if (ke->filter == EVFILT_MACHPORT) {
		return _dispatch_drain_mach_messages(ke);
	}
#endif
	dispatch_assert(dk);

	if (ke->flags & EV_ONESHOT) {
		dk->dk_kevent.flags |= EV_ONESHOT;
	}

	TAILQ_FOREACH(dsi, &dk->dk_sources, ds_list) {
		_dispatch_source_merge_kevent(dsi, ke);
	}
}

static void
_dispatch_kevent_dispose(dispatch_kevent_t dk)
{
	uintptr_t hash;

	switch (dk->dk_kevent.filter) {
	case DISPATCH_EVFILT_TIMER:
	case DISPATCH_EVFILT_CUSTOM_ADD:
	case DISPATCH_EVFILT_CUSTOM_OR:
		// these sources live on statically allocated lists
		return;
#if HAVE_MACH
	case EVFILT_MACHPORT:
		_dispatch_kevent_machport_resume(dk, 0, dk->dk_kevent.fflags);
		break;
#endif
	case EVFILT_PROC:
		if (dk->dk_kevent.flags & EV_ONESHOT) {
			break;	// implicitly deleted
		}
		// fall through
	default:
		if (~dk->dk_kevent.flags & EV_DELETE) {
			dk->dk_kevent.flags |= EV_DELETE;
			_dispatch_update_kq(&dk->dk_kevent);
		}
		break;
	}

	hash = _dispatch_kevent_hash(dk->dk_kevent.ident,
				     dk->dk_kevent.filter);
	TAILQ_REMOVE(&_dispatch_sources[hash], dk, dk_list);
	free(dk);
}

void
_dispatch_kevent_release(dispatch_source_t ds)
{
	dispatch_kevent_t dk = ds->ds_dkev;
	dispatch_source_t dsi;
	uint32_t del_flags, fflags = 0;

	ds->ds_dkev = NULL;

	TAILQ_REMOVE(&dk->dk_sources, ds, ds_list);

	if (TAILQ_EMPTY(&dk->dk_sources)) {
		_dispatch_kevent_dispose(dk);
	} else {
		TAILQ_FOREACH(dsi, &dk->dk_sources, ds_list) {
			fflags |= (uint32_t)dsi->ds_pending_data_mask;
		}
		del_flags = (uint32_t)ds->ds_pending_data_mask & ~fflags;
		if (del_flags) {
			dk->dk_kevent.flags |= EV_ADD;
			dk->dk_kevent.fflags = fflags;
			_dispatch_kevent_resume(dk, 0, del_flags);
		}
	}

	ds->ds_is_armed = false;
	ds->ds_needs_rearm = false;	// re-arm is pointless and bad now
	_dispatch_release(as_do(ds));	// the retain is done at creation time
}

void
_dispatch_source_merge_kevent(dispatch_source_t ds, const struct kevent *ke)
{
	struct kevent fake;

	if ((ds->ds_atomic_flags & DSF_CANCELED) || (ds->do_xref_cnt == 0)) {
		return;
	}

	// EVFILT_PROC may fail with ESRCH when the process exists but is a zombie.
	// We simulate an exit event in this case. <rdar://problem/5067725>
	if (ke->flags & EV_ERROR) {
		if (ke->filter == EVFILT_PROC && ke->data == ESRCH) {
			fake = *ke;
			fake.flags &= ~EV_ERROR;
			fake.fflags = NOTE_EXIT;
			fake.data = 0;
			ke = &fake;
		} else {
			// log the unexpected error
#if defined (__GNUC__)
			(void)
#endif
			dispatch_assume_zero(ke->data);
			return;
		}
	}

	if (ds->ds_is_level) {
		// ke->data is signed and "negative available data" makes no sense
		// zero bytes happens when EV_EOF is set
		// 10A268 does not fail this assert with EVFILT_READ and a 10 GB file
		dispatch_assert(ke->data >= 0l);
		// flipping the bits ensures that we still pass the test at source.c:142 when zero bytes pending
		ds->ds_pending_data = ~ke->data;
	} else if (ds->ds_is_adder) {
		dispatch_atomic_add((intptr_t*)&ds->ds_pending_data, ke->data);
	} else if(ds->ds_dkev->dk_kevent.filter == DISPATCH_EVFILT_CUSTOM_OR) {
		dispatch_atomic_or((intptr_t*)&ds->ds_pending_data, (uintptr_t)ke->data & ds->ds_pending_data_mask);
	} else {
		dispatch_atomic_or((intptr_t*)&ds->ds_pending_data, ke->fflags & (u_int)ds->ds_pending_data_mask);
	}

	// EV_DISPATCH and EV_ONESHOT sources are no longer armed after delivery
	if (ds->ds_needs_rearm) {
		ds->ds_is_armed = false;
	}

	_dispatch_wakeup(as_do(ds));
}

const struct dispatch_source_vtable_s _dispatch_source_kevent_vtable = {
	/*.do_type    = */	DISPATCH_SOURCE_KEVENT_TYPE,
	/*.do_kind    = */	"kevent-source",
	/*.do_debug   = */	_dispatch_source_debug,
	/*.do_invoke  = */	_dispatch_source_invoke,
	/*.do_probe   = */	_dispatch_source_probe,
	/*.do_dispose = */	_dispatch_source_dispose,
};

void
dispatch_source_merge_data(dispatch_source_t ds, uintptr_t val)
{	
	struct kevent kev = {
		/* .ident  = */	0,
		/* .filter = */	0,
		/* .flags  = */	0,
		/* .fflags = */	(u_int)val,
		/* .data   = */	val,
	};

	dispatch_assert(ds->ds_dkev->dk_kevent.filter == DISPATCH_EVFILT_CUSTOM_ADD ||
					ds->ds_dkev->dk_kevent.filter == DISPATCH_EVFILT_CUSTOM_OR);

	_dispatch_source_merge_kevent(ds, &kev);
}

static bool
dispatch_source_type_kevent_init(dispatch_source_t ds, dispatch_source_type_t type, uintptr_t handle, uintptr_t mask, dispatch_queue_t q)
{
	const struct kevent *proto_kev = type->opaque;
	dispatch_kevent_t dk = NULL;

	switch (proto_kev->filter) {
	case EVFILT_SIGNAL:
		if (handle >= NSIG) {
			return false;
		}
		break;
	case EVFILT_FS:
	case DISPATCH_EVFILT_CUSTOM_ADD:
	case DISPATCH_EVFILT_CUSTOM_OR:
	case DISPATCH_EVFILT_TIMER:
		if (handle) {
			return false;
		}
		break;
	default:
		break;
	}

	dk = calloc(1ul, sizeof(struct dispatch_kevent_s));
	if (slowpath(!dk)) {
		return false;
	}

	dk->dk_kevent = *proto_kev;
	dk->dk_kevent.ident = handle;
	dk->dk_kevent.flags |= EV_ADD|EV_ENABLE;
	dk->dk_kevent.fflags |= (uint32_t)mask;
	dk->dk_kevent.udata = dk;
	TAILQ_INIT(&dk->dk_sources);

	// Dispatch Source
	ds->ds_ident_hack = dk->dk_kevent.ident;
	ds->ds_dkev = dk;
	ds->ds_pending_data_mask = mask;
	if ((EV_DISPATCH|EV_ONESHOT) & proto_kev->flags) {
		ds->ds_is_level = true;
		ds->ds_needs_rearm = true;
	} else if (!(EV_CLEAR & proto_kev->flags)) {
		// we cheat and use EV_CLEAR to mean a "flag thingy"
		ds->ds_is_adder = true;
	}
	return true;
}

static bool
dispatch_source_type_timer_init(dispatch_source_t ds, dispatch_source_type_t type, uintptr_t handle, uintptr_t mask, dispatch_queue_t q)
{
	if (!dispatch_source_type_kevent_init(ds, type, handle, mask, q)) {
		return false;
	}
	ds->ds_needs_rearm = true;
	ds->ds_timer.flags = mask;
	return true;
}

static const struct kevent _dispatch_source_type_timer_ke = {
	/* .ident  = */	0,
	/* .filter = */	DISPATCH_EVFILT_TIMER,
};

const struct dispatch_source_type_s _dispatch_source_type_timer = {
	/* .opaque = */	(void *)&_dispatch_source_type_timer_ke,
	/* .mask   = */	DISPATCH_TIMER_TYPE_MASK | DISPATCH_TIMER_CLOCK_MASK,
	/* .init   = */	dispatch_source_type_timer_init,
};

static const struct kevent _dispatch_source_type_oio_ke = {
	/* .ident  = */	0,
	/* .filter = */	EVFILT_OIO,
	/* .flags  = */	EV_DISPATCH
};

const struct dispatch_source_type_s _dispatch_source_type_oio = {
	/* .opaque = */	(void *)&_dispatch_source_type_oio_ke,
	/* .mask   = */	0,
	/* .init   = */	dispatch_source_type_kevent_init,
};

static const struct kevent _dispatch_source_type_read_ke = {
	/* .ident  = */	0,
	/* .filter = */	EVFILT_READ,
	/* .flags  = */	EV_DISPATCH
};

const struct dispatch_source_type_s _dispatch_source_type_read = {
	/* .opaque = */	(void *)&_dispatch_source_type_read_ke,
	/* .mask   = */	0,
	/* .init   = */	dispatch_source_type_kevent_init
};

static const struct kevent _dispatch_source_type_write_ke = {
	/* .ident  = */	0,
	/* .filter = */	EVFILT_WRITE,
	/* .flags  = */	EV_DISPATCH
};

const struct dispatch_source_type_s _dispatch_source_type_write = {
	/* .opaque = */	(void *)&_dispatch_source_type_write_ke,
	/* .mask   = */	0,
	/* .init   = */	dispatch_source_type_kevent_init
};

static const struct kevent _dispatch_source_type_proc_ke = {
	/* .ident  = */	0,
	/* .filter = */	EVFILT_PROC,
	/* .flags  = */	EV_CLEAR
};

const struct dispatch_source_type_s _dispatch_source_type_proc = {
	/* .opaque = */	(void *)&_dispatch_source_type_proc_ke,
	/* .mask   = */	NOTE_EXIT|NOTE_FORK|NOTE_EXEC
#if HAVE_DECL_NOTE_SIGNAL
	               	|NOTE_SIGNAL
#endif
#if HAVE_DECL_NOTE_REAP
	               	|NOTE_REAP
#endif
	               	,
	/* .init   = */	dispatch_source_type_kevent_init
};

static const struct kevent _dispatch_source_type_signal_ke = {
	/* .ident  = */	0,
	/* .filter = */	EVFILT_SIGNAL
};

const struct dispatch_source_type_s _dispatch_source_type_signal = {
	/* .opaque = */	(void *)&_dispatch_source_type_signal_ke,
	/* .mask   = */	0,
	/* .init   = */	dispatch_source_type_kevent_init
};

static const struct kevent _dispatch_source_type_vnode_ke = {
	/* .ident  = */	0,
	/* .filter = */	EVFILT_VNODE,
	/* .flags  = */	EV_CLEAR
};

const struct dispatch_source_type_s _dispatch_source_type_vnode = {
	/* .opaque = */	(void *)&_dispatch_source_type_vnode_ke,
	/* .mask   = */	NOTE_DELETE|NOTE_WRITE|NOTE_EXTEND|NOTE_ATTRIB|NOTE_LINK|NOTE_RENAME
#if HAVE_DECL_NOTE_REVOKE
	               	|NOTE_REVOKE
#endif
#if HAVE_DECL_NOTE_NONE
	               	|NOTE_NONE
#endif
	               	,
	/* .init   = */	dispatch_source_type_kevent_init
};

static const struct kevent _dispatch_source_type_vfs_ke = {
	/* .ident  = */	0,
	/* .filter = */	EVFILT_FS,
	/* .flags  = */	EV_CLEAR
};

const struct dispatch_source_type_s _dispatch_source_type_vfs = {
	/* .opaque = */	(void *)&_dispatch_source_type_vfs_ke,
	/* .mask   = */	VQ_NOTRESP|VQ_NEEDAUTH|VQ_LOWDISK|VQ_MOUNT|VQ_UNMOUNT|VQ_DEAD|VQ_ASSIST|VQ_NOTRESPLOCK
#if HAVE_DECL_VQ_UPDATE
	               	|VQ_UPDATE
#endif
#if HAVE_DECL_VQ_VERYLOWDISK
	               	|VQ_VERYLOWDISK
#endif
	               	,
	/* .init   = */	dispatch_source_type_kevent_init
};

#if HAVE_MACH

static bool
dispatch_source_type_mach_send_init(dispatch_source_t ds, dispatch_source_type_t type, uintptr_t handle, unsigned long mask, dispatch_queue_t q)
{
	static dispatch_once_t pred;

	if (!dispatch_source_type_kevent_init(ds, type, handle, mask, q)) {
		return false;
	}
	ds->ds_is_level = false;
	dispatch_once_f(&pred, NULL, _dispatch_mach_notify_source_init);
	return true;
}

static const struct kevent _dispatch_source_type_mach_send_ke = {
	.filter = EVFILT_MACHPORT,
	.flags = EV_DISPATCH,
	.fflags = DISPATCH_MACHPORT_DEAD,
};

const struct dispatch_source_type_s _dispatch_source_type_mach_send = {
	.opaque = (void *)&_dispatch_source_type_mach_send_ke,
	.mask = DISPATCH_MACH_SEND_DEAD,
	.init = dispatch_source_type_mach_send_init,
};

static bool
dispatch_source_type_mach_recv_init(dispatch_source_t ds, dispatch_source_type_t type, uintptr_t handle, unsigned long mask, dispatch_queue_t q)
{
	if (!dispatch_source_type_kevent_init(ds, type, handle, mask, q)) {
		return false;
	}
	ds->ds_is_level = false;
	return true;
}

static const struct kevent _dispatch_source_type_mach_recv_ke = {
	.filter = EVFILT_MACHPORT,
	.flags = EV_DISPATCH,
	.fflags = DISPATCH_MACHPORT_RECV,
};

const struct dispatch_source_type_s _dispatch_source_type_mach_recv = {
	.opaque = (void *)&_dispatch_source_type_mach_recv_ke,
	.init = dispatch_source_type_mach_recv_init,
};
#endif

static const struct kevent _dispatch_source_type_data_add_ke = {
	/* .ident  = */	0,
	/* .filter = */	DISPATCH_EVFILT_CUSTOM_ADD,
};

const struct dispatch_source_type_s _dispatch_source_type_data_add = {
	/* .opaque = */	(void *)&_dispatch_source_type_data_add_ke,
	/* .mask   = */	0,
	/* .init   = */	dispatch_source_type_kevent_init,
};

static const struct kevent _dispatch_source_type_data_or_ke = {
	/* .ident  = */	0,
	/* .filter = */	DISPATCH_EVFILT_CUSTOM_OR,
	/* .flags  = */	EV_CLEAR,
	/* .fflags = */	~0U,
};

const struct dispatch_source_type_s _dispatch_source_type_data_or = {
	/* .opaque = */	(void *)&_dispatch_source_type_data_or_ke,
	/* .mask   = */	0,
	/* .init   = */	dispatch_source_type_kevent_init,
};

// Updates the ordered list of timers based on next fire date for changes to ds.
// Should only be called from the context of _dispatch_mgr_q.
void
_dispatch_timer_list_update(dispatch_source_t ds)
{
	dispatch_source_t dsi = NULL;
	int idx;
	
	dispatch_assert(_dispatch_queue_get_current() == &_dispatch_mgr_q);

	// do not reschedule timers unregistered with _dispatch_kevent_release()
	if (!ds->ds_dkev) {
		return;
	}

	// Ensure the source is on the global kevent lists before it is removed and
	// readded below.
	_dispatch_kevent_merge(ds);
	
	TAILQ_REMOVE(&ds->ds_dkev->dk_sources, ds, ds_list);

	// change the list if the clock type has changed
	if ((ds->ds_timer.flags & DISPATCH_TIMER_CLOCK_MASK) == DISPATCH_TIMER_WALL_CLOCK) {
		idx = DISPATCH_TIMER_INDEX_WALL;
	} else {
		idx = DISPATCH_TIMER_INDEX_MACH;
	}
	ds->ds_dkev = &_dispatch_kevent_timer[idx];

	if (ds->ds_timer.target) {
		TAILQ_FOREACH(dsi, &ds->ds_dkev->dk_sources, ds_list) {
			if (dsi->ds_timer.target == 0 || ds->ds_timer.target < dsi->ds_timer.target) {
				break;
			}
		}
	}
	
	if (dsi) {
		TAILQ_INSERT_BEFORE(dsi, ds, ds_list);
	} else {
		TAILQ_INSERT_TAIL(&ds->ds_dkev->dk_sources, ds, ds_list);
	}
}

static void
_dispatch_run_timers2(unsigned int timer)
{
	dispatch_source_t ds;
	uint64_t now, missed;

	if (timer == DISPATCH_TIMER_INDEX_MACH) {
		now = _dispatch_absolute_time();
	} else {
		now = _dispatch_get_nanoseconds();
	}

	while ((ds = TAILQ_FIRST(&_dispatch_kevent_timer[timer].dk_sources))) {
		// We may find timers on the wrong list due to a pending update from
		// dispatch_source_set_timer. Force an update of the list in that case.
		if (timer != ds->ds_ident_hack) {
			_dispatch_timer_list_update(ds);
			continue;
		}
		if (!ds->ds_timer.target) {
			// no configured timers on the list
			break;
		}
		if (ds->ds_timer.target > now) {
			// Done running timers for now.
			break;
		}

		if ((ds->ds_timer.flags & DISPATCH_TIMER_TYPE_MASK) == DISPATCH_TIMER_ONESHOT) {
			dispatch_atomic_inc((intptr_t*)&ds->ds_pending_data);
			ds->ds_timer.target = 0;
		} else {
			// Calculate number of missed intervals.
			missed = (now - ds->ds_timer.target) / ds->ds_timer.interval;
			dispatch_atomic_add((intptr_t*)&ds->ds_pending_data, missed + 1);
			ds->ds_timer.target += (missed + 1) * ds->ds_timer.interval;
		}

		_dispatch_timer_list_update(ds);
		_dispatch_wakeup(as_do(ds));
	}
}

void
_dispatch_run_timers(void)
{
	unsigned int i;
	for (i = 0; i < DISPATCH_TIMER_COUNT; i++) {
		_dispatch_run_timers2(i);
	}
}

// approx 1 year (60s * 60m * 24h * 365d)
#define FOREVER_SEC 3153600l
#define FOREVER_NSEC 31536000000000000ull

struct timespec *
_dispatch_get_next_timer_fire(struct timespec *howsoon)
{
	// <rdar://problem/6459649>
	// kevent(2) does not allow large timeouts, so we use a long timeout
	// instead (approximately 1 year).
	dispatch_source_t ds = NULL;
	unsigned int timer;
	uint64_t now, delta_tmp, delta = UINT64_MAX;

	// We are looking for the first unsuspended timer which has its target
	// time set. Given timers are kept in order, if we hit an timer that's
	// unset there's no point in continuing down the list.
	for (timer = 0; timer < DISPATCH_TIMER_COUNT; timer++) {
		TAILQ_FOREACH(ds, &_dispatch_kevent_timer[timer].dk_sources, ds_list) {
			if (!ds->ds_timer.target) {
				break;
			}
			if (DISPATCH_OBJECT_SUSPENDED(ds)) {
				ds->ds_is_armed = false;
			} else {
				break;
			}
		}

		if (!ds || !ds->ds_timer.target) {
			continue;
		}
				
		if (ds->ds_timer.flags & DISPATCH_TIMER_WALL_CLOCK) {
			now = _dispatch_get_nanoseconds();
		} else {
			now = _dispatch_absolute_time();
		}
		if (ds->ds_timer.target <= now) {
			howsoon->tv_sec = 0;
			howsoon->tv_nsec = 0;
			return howsoon;
		}

		// the subtraction cannot go negative because the previous "if"
		// verified that the target is greater than now.
		delta_tmp = ds->ds_timer.target - now;
		if (!(ds->ds_timer.flags & DISPATCH_TIMER_WALL_CLOCK)) {
			delta_tmp = _dispatch_time_mach2nano(delta_tmp);
		}
		if (delta_tmp < delta) {
			delta = delta_tmp;
		}
	}
	if (slowpath(delta > FOREVER_NSEC)) {
		return NULL;
	} else {
		howsoon->tv_sec = (time_t)(delta / NSEC_PER_SEC);
		howsoon->tv_nsec = (long)(delta % NSEC_PER_SEC);
	}
	return howsoon;
}

#if HAVE_MACH
static dispatch_source_t _dispatch_mach_notify_source;
static mach_port_t _dispatch_port_set;
static mach_port_t _dispatch_event_port;

#define _DISPATCH_IS_POWER_OF_TWO(v)	(!(v & (v - 1)) && v)
#define _DISPATCH_HASH(x, y)    (_DISPATCH_IS_POWER_OF_TWO(y) ? (MACH_PORT_INDEX(x) & ((y) - 1)) : (MACH_PORT_INDEX(x) % (y)))

#define _DISPATCH_MACHPORT_HASH_SIZE 32
#define _DISPATCH_MACHPORT_HASH(x)    _DISPATCH_HASH((x), _DISPATCH_MACHPORT_HASH_SIZE)

static void _dispatch_port_set_init(void *);
static mach_port_t _dispatch_get_port_set(void);

void
_dispatch_drain_mach_messages(struct kevent *ke)
{
	dispatch_source_t dsi;
	dispatch_kevent_t dk;
	struct kevent ke2;

	if (!dispatch_assume(ke->data)) {
		return;
	}
	dk = _dispatch_kevent_find(ke->data, EVFILT_MACHPORT);
	if (!dispatch_assume(dk)) {
		return;
	}
	_dispatch_kevent_machport_disable(dk);	// emulate EV_DISPATCH

	EV_SET(&ke2, ke->data, EVFILT_MACHPORT, EV_ADD|EV_ENABLE|EV_DISPATCH, DISPATCH_MACHPORT_RECV, 0, dk);

	TAILQ_FOREACH(dsi, &dk->dk_sources, ds_list) {
		_dispatch_source_merge_kevent(dsi, &ke2);
	}
}

void
_dispatch_port_set_init(void *context DISPATCH_UNUSED)
{
	struct kevent kev = {
		.filter = EVFILT_MACHPORT,
		.flags = EV_ADD,
	};
	kern_return_t kr;

	kr = mach_port_allocate(mach_task_self(), MACH_PORT_RIGHT_PORT_SET, &_dispatch_port_set);
	DISPATCH_VERIFY_MIG(kr);
	(void)dispatch_assume_zero(kr);
	kr = mach_port_allocate(mach_task_self(), MACH_PORT_RIGHT_RECEIVE, &_dispatch_event_port);
	DISPATCH_VERIFY_MIG(kr);
	(void)dispatch_assume_zero(kr);
	kr = mach_port_move_member(mach_task_self(), _dispatch_event_port, _dispatch_port_set);
	DISPATCH_VERIFY_MIG(kr);
	(void)dispatch_assume_zero(kr);

	kev.ident = _dispatch_port_set;

	_dispatch_update_kq(&kev);
}

mach_port_t
_dispatch_get_port_set(void)
{
	static dispatch_once_t pred;

	dispatch_once_f(&pred, NULL, _dispatch_port_set_init);

	return _dispatch_port_set;
}

void
_dispatch_kevent_machport_resume(dispatch_kevent_t dk, uint32_t new_flags, uint32_t del_flags)
{
	mach_port_t previous, port = (mach_port_t)dk->dk_kevent.ident;
	kern_return_t kr;

	if ((new_flags & DISPATCH_MACHPORT_RECV) || (!new_flags && !del_flags && dk->dk_kevent.fflags & DISPATCH_MACHPORT_RECV)) {
		_dispatch_kevent_machport_enable(dk);
	}
	if (new_flags & DISPATCH_MACHPORT_DEAD) {
		kr = mach_port_request_notification(mach_task_self(), port, MACH_NOTIFY_DEAD_NAME, 1,
				_dispatch_event_port, MACH_MSG_TYPE_MAKE_SEND_ONCE, &previous);
		DISPATCH_VERIFY_MIG(kr);

	
		switch(kr) {
			case KERN_INVALID_NAME:
			case KERN_INVALID_RIGHT:
				// Supress errors 
				break;
			default:
			// Else, we dont expect any errors from mach. Log any errors if we do
			if (dispatch_assume_zero(kr)) {
				// log the error
			} else if (dispatch_assume_zero(previous)) {
				// Another subsystem has beat libdispatch to requesting the Mach
				// dead-name notification on this port. We should technically cache the
				// previous port and message it when the kernel messages our port. Or
				// we can just say screw those subsystems and drop the previous port.
				// They should adopt libdispatch :-P
				kr = mach_port_deallocate(mach_task_self(), previous);
				DISPATCH_VERIFY_MIG(kr);
				(void)dispatch_assume_zero(kr);
			}
		}
	}

	if (del_flags & DISPATCH_MACHPORT_RECV) {
		_dispatch_kevent_machport_disable(dk);
	}
	if (del_flags & DISPATCH_MACHPORT_DEAD) {
		kr = mach_port_request_notification(mach_task_self(), (mach_port_t)dk->dk_kevent.ident,
				MACH_NOTIFY_DEAD_NAME, 1, MACH_PORT_NULL, MACH_MSG_TYPE_MAKE_SEND_ONCE, &previous);
		DISPATCH_VERIFY_MIG(kr);

		switch (kr) {
			case KERN_INVALID_NAME:
			case KERN_INVALID_RIGHT:
			case KERN_INVALID_ARGUMENT:
				break;
			default:
			if (dispatch_assume_zero(kr)) {
				// log the error
			} else if (previous) {
				// the kernel has not consumed the right yet
				(void)dispatch_assume_zero(_dispatch_send_consume_send_once_right(previous));
			}
		}
	}
}

void
_dispatch_kevent_machport_enable(dispatch_kevent_t dk)
{
	mach_port_t mp = (mach_port_t)dk->dk_kevent.ident;
	kern_return_t kr;

	kr = mach_port_move_member(mach_task_self(), mp, _dispatch_get_port_set());
	DISPATCH_VERIFY_MIG(kr);
	switch (kr) {
	case KERN_INVALID_NAME:
#if DISPATCH_DEBUG
		_dispatch_log("Corruption: Mach receive right 0x%x destroyed prematurely", mp);
#endif
		break;
	default:
	 	(void)dispatch_assume_zero(kr);
	}
}

void
_dispatch_kevent_machport_disable(dispatch_kevent_t dk)
{
	mach_port_t mp = (mach_port_t)dk->dk_kevent.ident;
	kern_return_t kr;

	kr = mach_port_move_member(mach_task_self(), mp, 0);
	DISPATCH_VERIFY_MIG(kr);
	switch (kr) {
	case KERN_INVALID_RIGHT:
	case KERN_INVALID_NAME:
#if DISPATCH_DEBUG
		_dispatch_log("Corruption: Mach receive right 0x%x destroyed prematurely", mp);
#endif
		break;
	case 0:
		break;
	default:
		(void)dispatch_assume_zero(kr);
		break;
	}
}

#define _DISPATCH_MIN_MSG_SZ (8ul * 1024ul - MAX_TRAILER_SIZE)
#ifndef DISPATCH_NO_LEGACY
dispatch_source_t
dispatch_source_mig_create(mach_port_t mport, size_t max_msg_size, dispatch_source_attr_t attr,
	dispatch_queue_t dq, dispatch_mig_callback_t mig_callback)
{
	if (max_msg_size < _DISPATCH_MIN_MSG_SZ) {
		max_msg_size = _DISPATCH_MIN_MSG_SZ;
	}
	return dispatch_source_machport_create(mport, DISPATCH_MACHPORT_RECV, attr, dq,
	^(dispatch_source_t ds) {
		if (!dispatch_source_get_error(ds, NULL)) {
			if (dq->dq_width != 1) {
				dispatch_retain(ds);	// this is a shim -- use the external retain
				dispatch_async(dq, ^{
					dispatch_mig_server(ds, max_msg_size, mig_callback);
					dispatch_release(ds);	// this is a shim -- use the external release
				});
			} else {
				dispatch_mig_server(ds, max_msg_size, mig_callback);
			}
		}
	});	
}
#endif /* DISPATCH_NO_LEGACY */

static void
_dispatch_mach_notify_source2(void *context)
{
	dispatch_source_t ds = context;
	const size_t maxsz = MAX(
		sizeof(union __RequestUnion___dispatch_send_libdispatch_internal_protocol_subsystem),
		sizeof(union __ReplyUnion___dispatch_libdispatch_internal_protocol_subsystem));

	dispatch_mig_server(ds, maxsz, libdispatch_internal_protocol_server);
}

static void
_dispatch_mach_notify_source_init(void *context DISPATCH_UNUSED)
{
	_dispatch_get_port_set();

	_dispatch_mach_notify_source = dispatch_source_create(DISPATCH_SOURCE_TYPE_MACH_RECV, _dispatch_event_port, 0, &_dispatch_mgr_q);
	dispatch_assert(_dispatch_mach_notify_source);
	dispatch_set_context(_dispatch_mach_notify_source, _dispatch_mach_notify_source);
	dispatch_source_set_event_handler_f(_dispatch_mach_notify_source, _dispatch_mach_notify_source2);
	dispatch_resume(_dispatch_mach_notify_source);
}

kern_return_t
_dispatch_mach_notify_port_deleted(mach_port_t notify DISPATCH_UNUSED, mach_port_name_t name)
{
	dispatch_source_t dsi;
	dispatch_kevent_t dk;
	struct kevent kev;

#if DISPATCH_DEBUG
	_dispatch_log("Corruption: Mach send/send-once/dead-name right 0x%x deleted prematurely", name);
#endif

	dk = _dispatch_kevent_find(name, EVFILT_MACHPORT);
	if (!dk) {
		goto out;
	}

	EV_SET(&kev, name, EVFILT_MACHPORT, EV_ADD|EV_ENABLE|EV_DISPATCH|EV_EOF, DISPATCH_MACHPORT_DELETED, 0, dk);

	TAILQ_FOREACH(dsi, &dk->dk_sources, ds_list) {
		_dispatch_source_merge_kevent(dsi, &kev);
		// this can never happen again
		// this must happen after the merge
		// this may be racy in the future, but we don't provide a 'setter' API for the mask yet
		dsi->ds_pending_data_mask &= ~DISPATCH_MACHPORT_DELETED;
	}

	// no more sources have this flag
	dk->dk_kevent.fflags &= ~DISPATCH_MACHPORT_DELETED;

out:
	return KERN_SUCCESS;
}

kern_return_t
_dispatch_mach_notify_port_destroyed(mach_port_t notify DISPATCH_UNUSED, mach_port_t name)
{
	kern_return_t kr;
	// this function should never be called
	(void)dispatch_assume_zero(name);
	kr = mach_port_mod_refs(mach_task_self(), name, MACH_PORT_RIGHT_RECEIVE, -1);
	DISPATCH_VERIFY_MIG(kr);
	(void)dispatch_assume_zero(kr);
	return KERN_SUCCESS;
}

kern_return_t
_dispatch_mach_notify_no_senders(mach_port_t notify, mach_port_mscount_t mscnt DISPATCH_UNUSED)
{
	// this function should never be called
	(void)dispatch_assume_zero(notify);
	return KERN_SUCCESS;
}

kern_return_t
_dispatch_mach_notify_send_once(mach_port_t notify DISPATCH_UNUSED)
{
	// we only register for dead-name notifications
	// some code deallocated our send-once right without consuming it
#if DISPATCH_DEBUG
	_dispatch_log("Corruption: An app/library deleted a libdispatch dead-name notification");
#endif
	return KERN_SUCCESS;
}

kern_return_t
_dispatch_mach_notify_dead_name(mach_port_t notify DISPATCH_UNUSED, mach_port_name_t name)
{
	dispatch_source_t dsi;
	dispatch_kevent_t dk;
	struct kevent kev;
	kern_return_t kr;

	dk = _dispatch_kevent_find(name, EVFILT_MACHPORT);
	if (!dk) {
		goto out;
	}

	EV_SET(&kev, name, EVFILT_MACHPORT, EV_ADD|EV_ENABLE|EV_DISPATCH|EV_EOF, DISPATCH_MACHPORT_DEAD, 0, dk);

	TAILQ_FOREACH(dsi, &dk->dk_sources, ds_list) {
		_dispatch_source_merge_kevent(dsi, &kev);
		// this can never happen again
		// this must happen after the merge
		// this may be racy in the future, but we don't provide a 'setter' API for the mask yet
		dsi->ds_pending_data_mask &= ~DISPATCH_MACHPORT_DEAD;
	}

	// no more sources have this flag
	dk->dk_kevent.fflags &= ~DISPATCH_MACHPORT_DEAD;

out:
	// the act of receiving a dead name notification allocates a dead-name right that must be deallocated
	kr = mach_port_deallocate(mach_task_self(), name);
	DISPATCH_VERIFY_MIG(kr);
	//(void)dispatch_assume_zero(kr);

	return KERN_SUCCESS;
}

kern_return_t
_dispatch_wakeup_main_thread(mach_port_t mp DISPATCH_UNUSED)
{
	// dummy function just to pop out the main thread out of mach_msg()
	return 0;
}

kern_return_t
_dispatch_consume_send_once_right(mach_port_t mp DISPATCH_UNUSED)
{
	// dummy function to consume a send-once right
	return 0;
}

mach_msg_return_t
dispatch_mig_server(dispatch_source_t ds, size_t maxmsgsz, dispatch_mig_callback_t callback)
{
	mach_msg_options_t options = MACH_RCV_MSG | MACH_RCV_TIMEOUT
		| MACH_RCV_TRAILER_ELEMENTS(MACH_RCV_TRAILER_CTX)
		| MACH_RCV_TRAILER_TYPE(MACH_MSG_TRAILER_FORMAT_0);
	mach_msg_options_t tmp_options = options;
	mig_reply_error_t *bufTemp, *bufRequest, *bufReply;
	mach_msg_return_t kr = 0;
	unsigned int cnt = 1000;	// do not stall out serial queues
	int demux_success;

	maxmsgsz += MAX_TRAILER_SIZE;

	// XXX FIXME -- allocate these elsewhere
	bufRequest = alloca(maxmsgsz);
	bufReply = alloca(maxmsgsz);
	bufReply->Head.msgh_size = 0;	// make CLANG happy

	// XXX FIXME -- change this to not starve out the target queue
	for (;;) {
		if (DISPATCH_OBJECT_SUSPENDED(ds) || (--cnt == 0)) {
			options &= ~MACH_RCV_MSG;
			tmp_options &= ~MACH_RCV_MSG;

			if (!(tmp_options & MACH_SEND_MSG)) {
				break;
			}
		}

		kr = mach_msg(&bufReply->Head, tmp_options, bufReply->Head.msgh_size,
				(mach_msg_size_t)maxmsgsz, (mach_port_t)ds->ds_ident_hack, 0, 0);

		tmp_options = options;

		if (slowpath(kr)) {
			switch (kr) {
			case MACH_SEND_INVALID_DEST:
			case MACH_SEND_TIMED_OUT:
				if (bufReply->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX) {
					mach_msg_destroy(&bufReply->Head);
				}
				break;
			case MACH_RCV_TIMED_OUT:
			case MACH_RCV_INVALID_NAME:
				break;
			default:
				(void)dispatch_assume_zero(kr);
				break;
			}
			break;
		}

		if (!(tmp_options & MACH_RCV_MSG)) {
			break;
		}

		bufTemp = bufRequest;
		bufRequest = bufReply;
		bufReply = bufTemp;

		demux_success = callback(&bufRequest->Head, &bufReply->Head);

		if (!demux_success) {
			// destroy the request - but not the reply port
			bufRequest->Head.msgh_remote_port = 0;
			mach_msg_destroy(&bufRequest->Head);
		} else if (!(bufReply->Head.msgh_bits & MACH_MSGH_BITS_COMPLEX)) {
			// if MACH_MSGH_BITS_COMPLEX is _not_ set, then bufReply->RetCode is present
			if (slowpath(bufReply->RetCode)) {
				if (bufReply->RetCode == MIG_NO_REPLY) {
					continue;
				}

				// destroy the request - but not the reply port
				bufRequest->Head.msgh_remote_port = 0;
				mach_msg_destroy(&bufRequest->Head);
			}
		}

		if (bufReply->Head.msgh_remote_port) {
			tmp_options |= MACH_SEND_MSG;
			if (MACH_MSGH_BITS_REMOTE(bufReply->Head.msgh_bits) != MACH_MSG_TYPE_MOVE_SEND_ONCE) {
				tmp_options |= MACH_SEND_TIMEOUT;
			}
		}
	}

	return kr;
}
#endif /* HAVE_MACH */
