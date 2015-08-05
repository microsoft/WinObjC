/*
  A hacky replacement for backtrace_symbols in glibc

  backtrace_symbols in glibc looks up symbols using dladdr which is limited in
  the symbols that it sees. libbacktracesymbols opens the executable and shared
  libraries using libbfd and will look up backtrace information using the symbol
  table and the dwarf line information.

  It may make more sense for this program to use libelf instead of libbfd.
  However, I have not investigated that yet.

  Derived from addr2line.c from GNU Binutils by Jeff Muizelaar

  Copyright 2007 Jeff Muizelaar
*/

/* addr2line.c -- convert addresses to line number and function name
   Copyright 1997, 1998, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.
   Contributed by Ulrich Lauther <Ulrich.Lauther@mchp.siemens.de>

   This file was part of GNU Binutils.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, 51 Franklin Street, Suite 500, Boston, MA 02110-1335, USA.  */

#define fatal(a, b) exit(1)
#define bfd_fatal(a) exit(1)
#define bfd_nonfatal(a) exit(1)
#define list_matching_formats(a) exit(1)

/* 2 characters for each byte, plus 1 each for 0, x, and NULL */
#define PTRSTR_LEN (sizeof(void *) * 2 + 3)
#define true 1
#define false 0

#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>
#include <bfd.h>
#include <libiberty.h>
#include <dlfcn.h>
#include <link.h>
#if 0

void (*dbfd_init)(void);
bfd_vma (*dbfd_scan_vma)(const char *string, const char **end, int base);
bfd* (*dbfd_openr)(const char *filename, const char *target);
bfd_boolean (*dbfd_check_format)(bfd *abfd, bfd_format format);
bfd_boolean (*dbfd_check_format_matches)(bfd *abfd, bfd_format format, char ***matching);
bfd_boolean (*dbfd_close)(bfd *abfd);
bfd_boolean (*dbfd_map_over_sections)(bfd *abfd, void (*func)(bfd *abfd, asection *sect, void *obj),
		void *obj);
#define bfd_init dbfd_init

static void load_funcs(void)
{
	void * handle = dlopen("libbfd.so", RTLD_NOW);
	dbfd_init = dlsym(handle, "bfd_init");
	dbfd_scan_vma = dlsym(handle, "bfd_scan_vma");
	dbfd_openr = dlsym(handle, "bfd_openr");
	dbfd_check_format = dlsym(handle, "bfd_check_format");
	dbfd_check_format_matches = dlsym(handle, "bfd_check_format_matches");
	dbfd_close = dlsym(handle, "bfd_close");
	dbfd_map_over_sections = dlsym(handle, "bfd_map_over_sections");
}

#endif


static asymbol **syms;		/* Symbol table.  */

/* 150 isn't special; it's just an arbitrary non-ASCII char value.  */
#define OPTION_DEMANGLER	(150)

static void slurp_symtab(bfd * abfd);
static void find_address_in_section(bfd *abfd, asection *section, void *data);

/* Read in the symbol table.  */

static void slurp_symtab(bfd * abfd)
{
	long symcount;
	unsigned int size;

	if ((bfd_get_file_flags(abfd) & HAS_SYMS) == 0)
		return;

	symcount = bfd_read_minisymbols(abfd, false, (PTR) & syms, &size);
	if (symcount == 0)
		symcount = bfd_read_minisymbols(abfd, true /* dynamic */ ,
						(PTR) & syms, &size);

	if (symcount < 0)
		bfd_fatal(bfd_get_filename(abfd));
}

/* These global variables are used to pass information between
   translate_addresses and find_address_in_section.  */

static bfd_vma pc;
static const char *filename;
static const char *functionname;
static unsigned int line;
static int found;

/* Look for an address in a section.  This is called via
   bfd_map_over_sections.  */

static void find_address_in_section(bfd *abfd, asection *section, void *data __attribute__ ((__unused__)) )
{
	bfd_vma vma;
	bfd_size_type size;

	if (found)
		return;

	if ((bfd_get_section_flags(abfd, section) & SEC_ALLOC) == 0)
		return;

	vma = bfd_get_section_vma(abfd, section);
	if (pc < vma)
		return;

	size = bfd_section_size(abfd, section);
	if (pc >= vma + size)
		return;

	found = bfd_find_nearest_line(abfd, section, syms, pc - vma,
				      &filename, &functionname, &line);
}

/* Read hexadecimal addresses from stdin, translate into
   file_name:line_number and optionally function name.  */
#if 0
static void translate_addresses(bfd * abfd, char (*addr)[PTRSTR_LEN], int naddr)
{
	while (naddr) {
		pc = bfd_scan_vma(addr[naddr-1], NULL, 16);

		found = false;
		bfd_map_over_sections(abfd, find_address_in_section,
		(PTR) NULL);

		if (!found) {
			printf("[%s] \?\?() \?\?:0\n",addr[naddr-1]);
		} else {
			const char *name;

			name = functionname;
			if (name == NULL || *name == '\0')
				name = "??";
			if (filename != NULL) {
				char *h;

				h = strrchr(filename, '/');
				if (h != NULL)
					filename = h + 1;
			}

			printf("\t%s:%u\t", filename ? filename : "??",
			       line);

			printf("%s()\n", name);

		}

		/* fflush() is essential for using this command as a server
		   child process that reads addresses from a pipe and responds
		   with line number information, processing one address at a
		   time.  */
		fflush(stdout);
		naddr--;
	}
}
#endif

static char** translate_addresses_buf(bfd * abfd, bfd_vma *addr, int naddr)
{
	int naddr_orig = naddr;
	char b;
	int total  = 0;
	enum { Count, Print } state;
	char *buf = &b;
	int len = 0;
	char **ret_buf = NULL;
	/* iterate over the formating twice.
	 * the first time we count how much space we need
	 * the second time we do the actual printing */
	for (state=Count; state<=Print; state++) {
	if (state == Print) {
		ret_buf = malloc(total + sizeof(char*)*naddr);
		buf = (char*)(ret_buf + naddr);
		len = total;
	}
	while (naddr) {
		if (state == Print)
			ret_buf[naddr-1] = buf;
		pc = addr[naddr-1];

		found = false;
		bfd_map_over_sections(abfd, find_address_in_section,
		(PTR) NULL);

		if (!found) {
			total += snprintf(buf, len, "[0x%llx] \?\?() \?\?:0",(long long unsigned int) addr[naddr-1]) + 1;
		} else {
			const char *name;

			name = functionname;
			if (name == NULL || *name == '\0')
				name = "??";
			if (filename != NULL) {
				char *h;

				h = strrchr(filename, '/');
				if (h != NULL)
					filename = h + 1;
			}
			total += snprintf(buf, len, "%s:%u\t%s()", filename ? filename : "??",
			       line, name) + 1;

		}
		if (state == Print) {
			/* set buf just past the end of string */
			buf = buf + total + 1;
		}
		naddr--;
	}
	naddr = naddr_orig;
	}
	return ret_buf;
}
/* Process a file.  */

static char **process_file(const char *file_name, bfd_vma *addr, int naddr)
{
	bfd *abfd;
	char **matching;
	char **ret_buf;

	abfd = bfd_openr(file_name, NULL);

	if (abfd == NULL)
		bfd_fatal(file_name);

	if (bfd_check_format(abfd, bfd_archive))
		fatal("%s: can not get addresses from archive", file_name);

	if (!bfd_check_format_matches(abfd, bfd_object, &matching)) {
		bfd_nonfatal(bfd_get_filename(abfd));
		if (bfd_get_error() ==
		    bfd_error_file_ambiguously_recognized) {
			list_matching_formats(matching);
			free(matching);
		}
		xexit(1);
	}

	slurp_symtab(abfd);

	ret_buf = translate_addresses_buf(abfd, addr, naddr);

	if (syms != NULL) {
		free(syms);
		syms = NULL;
	}

	bfd_close(abfd);
	return ret_buf;
}

#define MAX_DEPTH 16

struct file_match {
	const char *file;
	void *address;
	void *base;
	void *hdr;
};

static int find_matching_file(struct dl_phdr_info *info,
		size_t size, void *data)
{
	struct file_match *match = data;
	/* This code is modeled from Gfind_proc_info-lsb.c:callback() from libunwind */
	long n;
	const ElfW(Phdr) *phdr;
	ElfW(Addr) load_base = info->dlpi_addr;
	phdr = info->dlpi_phdr;
	for (n = info->dlpi_phnum; --n >= 0; phdr++) {
		if (phdr->p_type == PT_LOAD) {
			ElfW(Addr) vaddr = phdr->p_vaddr + load_base;
			if (match->address >= vaddr && match->address < vaddr + phdr->p_memsz) {
				/* we found a match */
				match->file = info->dlpi_name;
				match->base = info->dlpi_addr;
			}
		}
	}
	return 0;
}

char **backtrace_symbols(void *const *buffer, int size)
{
	int stack_depth = size - 1;
	int x,y;
	/* discard calling function */
	int total = 0;

	char ***locations;
	char **final;
	char *f_strings;

	locations = malloc(sizeof(char**) * (stack_depth+1));

	bfd_init();
	for(x=stack_depth, y=0; x>=0; x--, y++){
		struct file_match match = { .address = buffer[x] };
		char **ret_buf;
		bfd_vma addr;
		dl_iterate_phdr(find_matching_file, &match);
		addr = buffer[x] - match.base;
		if (match.file && strlen(match.file))
			ret_buf = process_file(match.file, &addr, 1);
		else
			ret_buf = process_file("/proc/self/exe", &addr, 1);
		locations[x] = ret_buf;
		total += strlen(ret_buf[0]) + 1;
	}

	/* allocate the array of char* we are going to return and extra space for
	 * all of the strings */
	final = malloc(total + (stack_depth + 1) * sizeof(char*));
	/* get a pointer to the extra space */
	f_strings = (char*)(final + stack_depth + 1);

	/* fill in all of strings and pointers */
	for(x=stack_depth; x>=0; x--){
		strcpy(f_strings, locations[x][0]);
		free(locations[x]);
		final[x] = f_strings;
		f_strings += strlen(f_strings) + 1;
	}

	free(locations);

	return final;
}

void
backtrace_symbols_fd(void *const *buffer, int size, int fd)
{
        int j;
        char **strings;

        strings = backtrace_symbols(buffer, size);
        if (strings == NULL) {
		perror("backtrace_symbols");
		exit(EXIT_FAILURE);
        }

        for (j = 0; j < size; j++)
		printf("%s\n", strings[j]);

        free(strings);
}
