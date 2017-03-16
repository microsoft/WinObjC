/* 
 * Mach Operating System
 * Copyright (c) 1992,1991,1990,1989,1988,1987 Carnegie Mellon University
 * All Rights Reserved.
 * 
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 * 
 * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"
 * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR
 * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
 * 
 * Carnegie Mellon requests users of this software to return to
 * 
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 * 
 * any improvements or extensions that they make and grant Carnegie Mellon
 * the rights to redistribute these changes.
 */
/*
 * HISTORY
 * $Log:        vm_statistics.h,v $
 * Revision 2.4  93/01/14  17:49:14  danner
 *      Standardized include symbol name.
 *      [92/06/10            pds]
 *      64bit cleanup.
 *      [92/12/01            af]
 * 
 * Revision 2.3  91/05/14  17:03:07  mrt
 *      Correcting copyright
 * 
 * Revision 2.2  91/02/05  17:37:41  mrt
 *      Changed to new Mach copyright
 *      [91/02/01  17:22:49  mrt]
 * 
 * Revision 2.1  89/08/03  16:06:55  rwd
 * Created.
 * 
 * Revision 2.4  89/02/25  18:42:35  gm0w
 *      Changes for cleanup.
 * 
 * Revision 2.3  89/02/07  00:54:39  mwyoung
 * Relocated from sys/vm_statistics.h
 * 
 * Revision 2.2  89/01/30  22:08:54  rpd
 *      Made variable declarations use "extern".
 *      [89/01/25  15:26:30  rpd]
 * 
 * 30-Sep-86  Avadis Tevanian (avie) at Carnegie-Mellon University
 *      Changed "reclaim" to "inactive."
 *
 * 22-Aug-86  Michael Young (mwyoung) at Carnegie-Mellon University
 *      Made vm_stat structure kernel-only.
 *
 * 22-May-86  Avadis Tevanian (avie) at Carnegie-Mellon University
 *      Defined vm_statistics_data_t as a real typedef so that
 *      MatchMaker can deal with it.
 *
 * 14-Feb-86  Avadis Tevanian (avie) at Carnegie-Mellon University
 *      Created.
 *
 */
/*
 *      File:   mach/vm_statistics.h
 *      Author: Avadis Tevanian, Jr., Michael Wayne Young, David Golub
 *
 *      Virtual memory statistics structure.
 *
 */

#ifndef _MACH_VM_STATISTICS_H_
#define _MACH_VM_STATISTICS_H_

#define HOST_VM_INFO_COUNT  13

struct vm_statistics {
        integer_t       pagesize;               /* page size in bytes */
        integer_t       free_count;             /* # of pages free */
        integer_t       active_count;           /* # of pages active */
        integer_t       inactive_count;         /* # of pages inactive */
        integer_t       wire_count;             /* # of pages wired down */
        integer_t       zero_fill_count;        /* # of zero fill pages */
        integer_t       reactivations;          /* # of pages reactivated */
        integer_t       pageins;                /* # of pageins */
        integer_t       pageouts;               /* # of pageouts */
        integer_t       faults;                 /* # of faults */
        integer_t       cow_faults;             /* # of copy-on-writes */
        integer_t       lookups;                /* object cache lookups */
        integer_t       hits;                   /* object cache hits */
};

typedef struct vm_statistics    *vm_statistics_t;
typedef struct vm_statistics    vm_statistics_data_t;

#ifdef  KERNEL
extern vm_statistics_data_t     vm_stat;
#endif  /* KERNEL */

/*
 *      Each machine dependent implementation is expected to
 *      keep certain statistics.  They may do this anyway they
 *      so choose, but are expected to return the statistics
 *      in the following structure.
 */

struct pmap_statistics {
        integer_t               resident_count; /* # of pages mapped (total)*/
        integer_t               wired_count;    /* # of pages wired */
};

typedef struct pmap_statistics  *pmap_statistics_t;
#endif  /* _MACH_VM_STATISTICS_H_ */
