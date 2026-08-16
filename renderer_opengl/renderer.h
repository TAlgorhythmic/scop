#ifndef RENDERER_OPENGL_H
# define RENDERER_OPENGL_H

#include "scop_types.h"
#include <GL/glcorearb.h>

/*
** Every OpenGL 3.3 core entry point the renderer needs, loaded at runtime.
** Grouped by purpose: framebuffer state, pipeline state, shaders, programs,
** uniforms, buffers/vertex arrays, textures, drawing, and queries.
*/
#define GL_FUNCS(X) \
	/* framebuffer */ \
	X(PFNGLCLEARPROC, Clear) \
	X(PFNGLCLEARCOLORPROC, ClearColor) \
	X(PFNGLCLEARDEPTHPROC, ClearDepth) \
	X(PFNGLVIEWPORTPROC, Viewport) \
	/* pipeline state */ \
	X(PFNGLENABLEPROC, Enable) \
	X(PFNGLDISABLEPROC, Disable) \
	X(PFNGLDEPTHFUNCPROC, DepthFunc) \
	X(PFNGLDEPTHMASKPROC, DepthMask) \
	X(PFNGLBLENDFUNCPROC, BlendFunc) \
	X(PFNGLCULLFACEPROC, CullFace) \
	X(PFNGLFRONTFACEPROC, FrontFace) \
	X(PFNGLPOLYGONMODEPROC, PolygonMode) \
	X(PFNGLPIXELSTOREIPROC, PixelStorei) \
	/* shaders */ \
	X(PFNGLCREATESHADERPROC, CreateShader) \
	X(PFNGLSHADERSOURCEPROC, ShaderSource) \
	X(PFNGLCOMPILESHADERPROC, CompileShader) \
	X(PFNGLGETSHADERIVPROC, GetShaderiv) \
	X(PFNGLGETSHADERINFOLOGPROC, GetShaderInfoLog) \
	X(PFNGLDELETESHADERPROC, DeleteShader) \
	/* programs */ \
	X(PFNGLCREATEPROGRAMPROC, CreateProgram) \
	X(PFNGLATTACHSHADERPROC, AttachShader) \
	X(PFNGLDETACHSHADERPROC, DetachShader) \
	X(PFNGLLINKPROGRAMPROC, LinkProgram) \
	X(PFNGLGETPROGRAMIVPROC, GetProgramiv) \
	X(PFNGLGETPROGRAMINFOLOGPROC, GetProgramInfoLog) \
	X(PFNGLUSEPROGRAMPROC, UseProgram) \
	X(PFNGLDELETEPROGRAMPROC, DeleteProgram) \
	/* uniforms and attributes */ \
	X(PFNGLGETUNIFORMLOCATIONPROC, GetUniformLocation) \
	X(PFNGLGETATTRIBLOCATIONPROC, GetAttribLocation) \
	X(PFNGLUNIFORM1IPROC, Uniform1i) \
	X(PFNGLUNIFORM1FPROC, Uniform1f) \
	X(PFNGLUNIFORM2FVPROC, Uniform2fv) \
	X(PFNGLUNIFORM3FVPROC, Uniform3fv) \
	X(PFNGLUNIFORM4FVPROC, Uniform4fv) \
	X(PFNGLUNIFORMMATRIX3FVPROC, UniformMatrix3fv) \
	X(PFNGLUNIFORMMATRIX4FVPROC, UniformMatrix4fv) \
	/* buffers and vertex arrays */ \
	X(PFNGLGENVERTEXARRAYSPROC, GenVertexArrays) \
	X(PFNGLBINDVERTEXARRAYPROC, BindVertexArray) \
	X(PFNGLDELETEVERTEXARRAYSPROC, DeleteVertexArrays) \
	X(PFNGLGENBUFFERSPROC, GenBuffers) \
	X(PFNGLBINDBUFFERPROC, BindBuffer) \
	X(PFNGLBUFFERDATAPROC, BufferData) \
	X(PFNGLBUFFERSUBDATAPROC, BufferSubData) \
	X(PFNGLDELETEBUFFERSPROC, DeleteBuffers) \
	X(PFNGLVERTEXATTRIBPOINTERPROC, VertexAttribPointer) \
	X(PFNGLENABLEVERTEXATTRIBARRAYPROC, EnableVertexAttribArray) \
	X(PFNGLDISABLEVERTEXATTRIBARRAYPROC, DisableVertexAttribArray) \
	/* textures */ \
	X(PFNGLGENTEXTURESPROC, GenTextures) \
	X(PFNGLBINDTEXTUREPROC, BindTexture) \
	X(PFNGLACTIVETEXTUREPROC, ActiveTexture) \
	X(PFNGLTEXIMAGE2DPROC, TexImage2D) \
	X(PFNGLTEXPARAMETERIPROC, TexParameteri) \
	X(PFNGLGENERATEMIPMAPPROC, GenerateMipmap) \
	X(PFNGLDELETETEXTURESPROC, DeleteTextures) \
	/* drawing */ \
	X(PFNGLDRAWARRAYSPROC, DrawArrays) \
	X(PFNGLDRAWELEMENTSPROC, DrawElements) \
	/* queries */ \
	X(PFNGLGETERRORPROC, GetError) \
	X(PFNGLGETSTRINGPROC, GetString) \
	X(PFNGLGETINTEGERVPROC, GetIntegerv)

#define GL_DECL(type, name) extern type gl##name;

GL_FUNCS(GL_DECL)

#undef GL_DECL

bool renderer_gl_load_symbols();
ScopBackend create_gl_backend();

#endif
