/* cairo - a vector graphics library with display and print output
 *
 * Copyright © 2010 Linaro Limited
 *
 * This library is free software; you can redistribute it and/or
 * modify it either under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * (the "LGPL") or, at your option, under the terms of the Mozilla
 * Public License Version 1.1 (the "MPL"). If you do not alter this
 * notice, a recipient may use your version of this file under either
 * the MPL or the LGPL.
 *
 * You should have received a copy of the LGPL along with this library
 * in the file COPYING-LGPL-2.1; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA 02110-1335, USA
 * You should have received a copy of the MPL along with this library
 * in the file COPYING-MPL-1.1
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.1 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY
 * OF ANY KIND, either express or implied. See the LGPL or the MPL for
 * the specific language governing rights and limitations.
 *
 * Contributor(s):
 *      Alexandros Frantzis <alexandros.frantzis@linaro.org>
 */

#ifndef CAIRO_GL_DISPATCH_PRIVATE_H
#define CAIRO_GL_DISPATCH_PRIVATE_H

#include "cairo-gl-private.h"
#include <stddef.h>

typedef struct _cairo_gl_dispatch_entry {
    const char *name_core;
    const char *name_ext;
    size_t offset;
} cairo_gl_dispatch_entry_t;

#define DISPATCH_ENTRY_ARB(name) { "gl"#name, "gl"#name"ARB", \
				   offsetof(cairo_gl_dispatch_t, name) }
#define DISPATCH_ENTRY_EXT(name) { "gl"#name, "gl"#name"EXT", \
				   offsetof(cairo_gl_dispatch_t, name) }
#define DISPATCH_ENTRY_CUSTOM(name, name2) { "gl"#name, "gl"#name2, \
			                     offsetof(cairo_gl_dispatch_t, name)}
#define DISPATCH_ENTRY_LAST { NULL, NULL, 0 }

cairo_private cairo_gl_dispatch_entry_t dispatch_buffers_entries[] = {
    DISPATCH_ENTRY_ARB (GenBuffers),
    DISPATCH_ENTRY_ARB (BindBuffer),
    DISPATCH_ENTRY_ARB (BufferData),
    DISPATCH_ENTRY_ARB (MapBuffer),
    DISPATCH_ENTRY_ARB (UnmapBuffer),
    DISPATCH_ENTRY_LAST
};

cairo_private cairo_gl_dispatch_entry_t dispatch_shaders_entries[] = {
    /* Shaders */
    DISPATCH_ENTRY_CUSTOM (CreateShader, CreateShaderObjectARB),
    DISPATCH_ENTRY_ARB    (ShaderSource),
    DISPATCH_ENTRY_ARB    (CompileShader),
    DISPATCH_ENTRY_CUSTOM (GetShaderiv, GetObjectParameterivARB),
    DISPATCH_ENTRY_CUSTOM (GetShaderInfoLog, GetInfoLogARB),
    DISPATCH_ENTRY_CUSTOM (DeleteShader, DeleteObjectARB),

    /* Programs */
    DISPATCH_ENTRY_CUSTOM (CreateProgram, CreateProgramObjectARB),
    DISPATCH_ENTRY_CUSTOM (AttachShader, AttachObjectARB),
    DISPATCH_ENTRY_CUSTOM (DeleteProgram, DeleteObjectARB),
    DISPATCH_ENTRY_ARB    (LinkProgram),
    DISPATCH_ENTRY_CUSTOM (UseProgram, UseProgramObjectARB),
    DISPATCH_ENTRY_CUSTOM (GetProgramiv, GetObjectParameterivARB),
    DISPATCH_ENTRY_CUSTOM (GetProgramInfoLog, GetInfoLogARB),

    /* Uniforms */
    DISPATCH_ENTRY_ARB (GetUniformLocation),
    DISPATCH_ENTRY_ARB (Uniform1f),
    DISPATCH_ENTRY_ARB (Uniform2f),
    DISPATCH_ENTRY_ARB (Uniform3f),
    DISPATCH_ENTRY_ARB (Uniform4f),
    DISPATCH_ENTRY_ARB (UniformMatrix3fv),
    DISPATCH_ENTRY_ARB (Uniform1i),
    DISPATCH_ENTRY_LAST
};

cairo_private cairo_gl_dispatch_entry_t dispatch_fbo_entries[] = {
    DISPATCH_ENTRY_EXT (GenFramebuffers),
    DISPATCH_ENTRY_EXT (BindFramebuffer),
    DISPATCH_ENTRY_EXT (FramebufferTexture2D),
    DISPATCH_ENTRY_EXT (CheckFramebufferStatus),
    DISPATCH_ENTRY_EXT (DeleteFramebuffers),
    DISPATCH_ENTRY_LAST
};

#endif /* CAIRO_GL_DISPATCH_PRIVATE_H */
