#ifndef PLATFORM_WINDOWS_SYS_EVENT__H
#define PLATFORM_WINDOWS_SYS_EVENT__H

#ifdef WINOBJC
 #include <mactypes.h>
#endif

struct kevent {
	uintptr_t ident;        /* identifier for this event */
	short     filter;       /* filter for event */
	u_short   flags;        /* action flags for kqueue */
	u_int     fflags;       /* filter flag value */
	intptr_t  data;         /* filter data value */
	void      *udata;       /* opaque user data identifier */
};

struct kevent64_s {
	uint64_t  ident;          /* identifier for this event */
	int16_t   filter;         /* filter for event */
	uint16_t  flags;          /* general flags */
	uint32_t  fflags;         /* filter-specific flags */
	int64_t   data;           /* filter-specific data */
	uint64_t  udata;          /* opaque user data identifier */
	uint64_t  ext[2];         /* filter-specific extensions */
};

#define EVFILT_READ         (-1)
#define EVFILT_WRITE        (-2)
#define EVFILT_AIO          (-3)	/* attached to aio requests */
#define EVFILT_VNODE        (-4)	/* attached to vnodes */
#define EVFILT_PROC         (-5)	/* attached to struct proc */
#define EVFILT_SIGNAL       (-6)	/* attached to struct proc */
#define EVFILT_TIMER        (-7)	/* timers */
#define EVFILT_MACHPORT     (-8)	/* Mach portsets */
#define EVFILT_FS           (-9)	/* Filesystem events */
#define EVFILT_USER         (-10)	/* User events */
#define EVFILT_SESSION      (-11)	/* Audit session events */
#define EVFILT_OIO          (-12)

#define EVFILT_SYSCOUNT     12
#define EVFILT_THREADMARKER EVFILT_SYSCOUNT /* Internal use only */

/* actions */
#define EV_ADD      0x0001	/* add event to kq (implies enable) */
#define EV_DELETE   0x0002	/* delete event from kq */
#define EV_ENABLE   0x0004	/* enable event */
#define EV_DISABLE  0x0008	/* disable event (not reported) */
#define EV_RECEIPT  0x0040	/* force EV_ERROR on success, data == 0 */
/* flags */
#define EV_ONESHOT  0x0010	/* only report one occurrence */
#define EV_CLEAR    0x0020	/* clear event state after reporting */
#define EV_DISPATCH 0x0080	/* disable event after reporting */

#define EV_SYSFLAGS 0xF000	/* reserved by system */
#define EV_FLAG0    0x1000	/* filter-specific flag */
#define EV_FLAG1    0x2000	/* filter-specific flag */

/* returned values */
#define EV_EOF      0x8000	/* EOF detected */
#define EV_ERROR    0x4000	/* error, data contains errno */

#define EV_SET(kevp, a, b, c, d, e, f) do { \
	(kevp)->ident = (a); \
	(kevp)->filter = (b); \
	(kevp)->flags = (c); \
	(kevp)->fflags = (d); \
	(kevp)->data = (e); \
	(kevp)->udata = (f); \
} while(0)

#define EV_POLL   EV_FLAG0
#define EV_OOBAND EV_FLAG1

#define NOTE_TRIGGER    0x01000000
#define EV_TRIGGER      0x0100 /*deprecated--for backwards compatibility only*/

#define NOTE_FFNOP      0x00000000	/* ignore input fflags */
#define NOTE_FFAND      0x40000000	/* and fflags */
#define NOTE_FFOR       0x80000000	/* or fflags */
#define NOTE_FFCOPY     0xc0000000	/* copy fflags */
#define NOTE_FFCTRLMASK 0xc0000000	/* mask for operations */
#define NOTE_FFLAGSMASK 0x00ffffff

#define NOTE_LOWAT      0x00000001	/* low water mark */

#define NOTE_DELETE     0x00000001	/* vnode was removed */
#define NOTE_WRITE      0x00000002	/* data contents changed */
#define NOTE_EXTEND     0x00000004	/* size increased */
#define NOTE_ATTRIB     0x00000008	/* attributes changed */
#define NOTE_LINK       0x00000010	/* link count changed */
#define NOTE_RENAME     0x00000020	/* vnode was renamed */
#define NOTE_REVOKE     0x00000040	/* vnode access was revoked */
#define NOTE_NONE       0x00000080	/* No specific vnode event: to test for EVFILT_READ activation*/

#define NOTE_EXIT       0x80000000	/* process exited */
#define NOTE_FORK       0x40000000	/* process forked */
#define NOTE_EXEC       0x20000000	/* process exec'd */
#define NOTE_REAP       0x10000000	/* process reaped */
#define NOTE_SIGNAL     0x08000000	/* shared with EVFILT_SIGNAL */
#define NOTE_PDATAMASK  0x000fffff	/* mask for pid/signal */
#define NOTE_PCTRLMASK  (~NOTE_PDATAMASK)

#define NOTE_SECONDS    0x00000001	/* data is seconds         */
#define NOTE_USECONDS   0x00000002	/* data is microseconds    */
#define NOTE_NSECONDS   0x00000004	/* data is nanoseconds     */
#define NOTE_ABSOLUTE   0x00000008	/* absolute timeout        */
                                  	/* ... implicit EV_ONESHOT */

#endif
