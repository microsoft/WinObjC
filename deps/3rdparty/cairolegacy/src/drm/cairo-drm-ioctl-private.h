#ifndef CAIRO_DRM_IOCTL_PRIVATE_H
#define CAIRO_DRM_IOCTL_PRIVATE_H

#define DRM_IOCTL_BASE			'd'
#define DRM_IO(nr)			_IO(DRM_IOCTL_BASE,nr)
#define DRM_IOR(nr,type)		_IOR(DRM_IOCTL_BASE,nr,type)
#define DRM_IOW(nr,type)		_IOW(DRM_IOCTL_BASE,nr,type)
#define DRM_IOWR(nr,type)		_IOWR(DRM_IOCTL_BASE,nr,type)

#define DRM_COMMAND_BASE                0x40

#endif /* CAIRO_DRM_IOCTL_PRIVATE_H */
