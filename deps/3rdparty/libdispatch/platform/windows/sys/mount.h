#ifndef PLATFORM_WINDOWS_SYS_MOUNT__H
#define PLATFORM_WINDOWS_SYS_MOUNT__H

#define VQ_NOTRESP      0x0001  /* server down */
#define VQ_NEEDAUTH     0x0002  /* server bad auth */
#define VQ_LOWDISK      0x0004  /* we're low on space */
#define VQ_MOUNT        0x0008  /* new filesystem arrived */
#define VQ_UNMOUNT      0x0010  /* filesystem has left */
#define VQ_DEAD         0x0020  /* filesystem is dead, needs force unmount */
#define VQ_ASSIST       0x0040  /* filesystem needs assistance from external program */
#define VQ_NOTRESPLOCK  0x0080  /* server lockd down */
#define VQ_UPDATE       0x0100  /* filesystem information has changed */
#define VQ_FLAG0200     0x0200  /* placeholder */
#define VQ_FLAG0400     0x0400  /* placeholder */
#define VQ_FLAG0800     0x0800  /* placeholder */
#define VQ_FLAG1000     0x1000  /* placeholder */
#define VQ_FLAG2000     0x2000  /* placeholder */
#define VQ_FLAG4000     0x4000  /* placeholder */
#define VQ_FLAG8000     0x8000  /* placeholder */

#endif
