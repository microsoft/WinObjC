//
// Modified from Simple_Texture2D, found in:
//
// Book:      OpenGL(R) ES 2.0 Programming Guide
// Authors:   Aaftab Munshi, Dan Ginsburg, Dave Shreiner
// ISBN-10:   0321502795
// ISBN-13:   9780321502797
// Publisher: Addison-Wesley Professional
// URLs:      http://safari.informit.com/9780321563835
//            http://www.opengles-book.com
//

// MultipleRenderTargets.c
//
//    This is a simple example that shows how to use multiple render
//    targets in GLES 2.0 using EXT_draw_buffers. The example
//    draws to three render targets and displays
//    them together in a final pass.
//
#include <stdlib.h>
#include "esUtil.h"

PFNGLDRAWBUFFERSEXTPROC glDrawBuffersEXT;

typedef struct
{
   // Handle to a program object
   GLuint programObjectMRT;
   GLuint programObject;

   // Attribute locations
   GLint  positionLoc;
   GLint  texCoordLoc;

   // Sampler location
   GLint samplerLoc;

   // Texture handle
   GLuint textureId;

   // Framebuffer object handle
   GLuint framebuffer;

   // Framebuffer color attachments
   GLuint framebufferTextures[4];

} UserData;

///
// Create a simple 2x2 texture image with four different colors
//
GLuint CreateSimpleTexture2D( )
{
   // Texture object handle
   GLuint textureId;
   
   // 2x2 Image, 3 bytes per pixel (R, G, B)
   GLubyte pixels[4 * 3] =
   {  
      255,   0,   0, // Red
        0, 255,   0, // Green
        0,   0, 255, // Blue
      255, 255,   0  // Yellow
   };

   // Use tightly packed data
   glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );

   // Generate a texture object
   glGenTextures ( 1, &textureId );

   // Bind the texture object
   glBindTexture ( GL_TEXTURE_2D, textureId );

   // Load the texture
   glTexImage2D ( GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels );

   // Set the filtering mode
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

   return textureId;

}


///
// Initialize the shader and program object
//
int Init ( ESContext *esContext )
{
   UserData *userData = (UserData*)esContext->userData;
   GLbyte vShaderStr[] =  
      "attribute vec4 a_position;   \n"
      "attribute vec2 a_texCoord;   \n"
      "varying vec2 v_texCoord;     \n"
      "void main()                  \n"
      "{                            \n"
      "   gl_Position = a_position; \n"
      "   v_texCoord = a_texCoord;  \n"
      "}                            \n";
   
   GLbyte fMultiShaderStr[] =  
      "#extension GL_EXT_draw_buffers : enable             \n"
      "precision mediump float;                            \n"
      "varying vec2 v_texCoord;                            \n"
      "uniform sampler2D s_texture;                        \n"
      "void main()                                         \n"
      "{                                                   \n"
      "  vec4 color = texture2D( s_texture, v_texCoord );  \n"
      "  gl_FragData[0] = color;                           \n"
      "  gl_FragData[1] = vec4(1.0, 1.0, 1.0, 1.0) - color.brga;\n"
      "  gl_FragData[2] = vec4(0.2, 1.0, 0.5, 1.0) * color.gbra;\n"
      "  gl_FragData[3] = color.rrra;                      \n"
      "}                                                   \n";

   GLbyte fShaderStr[] =  
      "precision mediump float;                            \n"
      "varying vec2 v_texCoord;                            \n"
      "uniform sampler2D s_texture;                        \n"
      "void main()                                         \n"
      "{                                                   \n"
      "  vec4 color = texture2D( s_texture, v_texCoord );  \n"
      "  gl_FragColor = color;                             \n"
      "}                                                   \n";

   int i;

   // Check EXT_draw_buffers is supported
   if (strstr(glGetString(GL_EXTENSIONS), "GL_EXT_draw_buffers") == 0)
   {
       return FALSE;
   }

   // Retrieve the address of glDrawBuffersEXT from EGL
   glDrawBuffersEXT = (PFNGLDRAWBUFFERSEXTPROC)eglGetProcAddress("glDrawBuffersEXT");

   // Load the shaders and get a linked program object
   userData->programObject = esLoadProgram ( (const char*)vShaderStr, (const char*)fShaderStr );

   userData->programObjectMRT = esLoadProgram ( (const char*)vShaderStr, (const char*)fMultiShaderStr );

   // Get the attribute locations
   userData->positionLoc = glGetAttribLocation ( userData->programObject, "a_position" );
   userData->texCoordLoc = glGetAttribLocation ( userData->programObject, "a_texCoord" );
   
   // Get the sampler location
   userData->samplerLoc = glGetUniformLocation ( userData->programObject, "s_texture" );

   // Load the texture
   userData->textureId = CreateSimpleTexture2D ();

   glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );

   // Initialize the user framebuffer
   glGenFramebuffers(1, &userData->framebuffer);
   glGenTextures(4, userData->framebufferTextures);

   glBindFramebuffer(GL_FRAMEBUFFER, userData->framebuffer);

   for (i = 0; i < 4; i++)
   {
       // Create textures for the four color attachments
       glBindTexture(GL_TEXTURE_2D, userData->framebufferTextures[i]);
       glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, esContext->width, esContext->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
       glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0_EXT + i, GL_TEXTURE_2D, userData->framebufferTextures[i], 0); 
   }

   glBindTexture(GL_TEXTURE_2D, 0);
   
   return TRUE;
}

///
// Draw a triangle using the shader pair created in Init()
//
void Draw ( ESContext *esContext )
{
   UserData *userData = (UserData*)esContext->userData;
   GLfloat vVertices[] = { -0.8f,  0.8f, 0.0f,  // Position 0
                            0.0f,  0.0f,        // TexCoord 0 
                           -0.8f, -0.8f, 0.0f,  // Position 1
                            0.0f,  1.0f,        // TexCoord 1
                            0.8f, -0.8f, 0.0f,  // Position 2
                            1.0f,  1.0f,        // TexCoord 2
                            0.8f,  0.8f, 0.0f,  // Position 3
                            1.0f,  0.0f         // TexCoord 3
                         };
   GLushort indices[] = { 0, 1, 2, 0, 2, 3 };

   GLenum drawBuffers[] = { GL_COLOR_ATTACHMENT0_EXT, GL_COLOR_ATTACHMENT1_EXT, GL_COLOR_ATTACHMENT2_EXT, GL_COLOR_ATTACHMENT3_EXT };

   // Enable drawing to the four color attachments of the user framebuffer
   glBindFramebuffer(GL_FRAMEBUFFER, userData->framebuffer);
   glDrawBuffersEXT(4, drawBuffers);

   // Set the viewport
   glViewport ( 0, 0, esContext->width, esContext->height );
   
   // Clear the color buffer
   glClear ( GL_COLOR_BUFFER_BIT );

   // Use the program object
   glUseProgram ( userData->programObjectMRT );

   // Load the vertex position
   glVertexAttribPointer ( userData->positionLoc, 3, GL_FLOAT, 
                           GL_FALSE, 5 * sizeof(GLfloat), vVertices );
   // Load the texture coordinate
   glVertexAttribPointer ( userData->texCoordLoc, 2, GL_FLOAT,
                           GL_FALSE, 5 * sizeof(GLfloat), &vVertices[3] );

   glEnableVertexAttribArray ( userData->positionLoc );
   glEnableVertexAttribArray ( userData->texCoordLoc );

   // Bind the texture
   glActiveTexture ( GL_TEXTURE0 );
   glBindTexture ( GL_TEXTURE_2D, userData->textureId );

   // Set the sampler texture unit to 0
   glUniform1i ( userData->samplerLoc, 0 );

   // Draw the textured quad to the four render targets
   glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices );

   // Enable the default framebuffer and single textured drawing
   glBindFramebuffer(GL_FRAMEBUFFER, 0);
   glUseProgram ( userData->programObject );

   // Draw the four textured quads to a separate region in the viewport
   glBindTexture( GL_TEXTURE_2D, userData->framebufferTextures[0]);
   glViewport ( 0, 0, esContext->width/2, esContext->height/2 );
   glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices );

   glBindTexture( GL_TEXTURE_2D, userData->framebufferTextures[1]);
   glViewport ( esContext->width/2, 0, esContext->width/2, esContext->height/2 );
   glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices );

   glBindTexture( GL_TEXTURE_2D, userData->framebufferTextures[2]);
   glViewport ( 0, esContext->height/2, esContext->width/2, esContext->height/2 );
   glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices );

   glBindTexture( GL_TEXTURE_2D, userData->framebufferTextures[3]);
   glViewport ( esContext->width/2, esContext->height/2, esContext->width/2, esContext->height/2 );
   glDrawElements ( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices );

   eglSwapBuffers ( esContext->eglDisplay, esContext->eglSurface );
}

///
// Cleanup
//
void ShutDown ( ESContext *esContext )
{
   UserData *userData = (UserData*)esContext->userData;

   glDeleteTextures(4, userData->framebufferTextures);

   glDeleteFramebuffers(1, &userData->framebuffer);

   // Delete texture object
   glDeleteTextures ( 1, &userData->textureId );

   // Delete program object
   glDeleteProgram ( userData->programObject );

   eglDestroyContext(esContext->eglDisplay, esContext->eglContext);
   eglDestroySurface(esContext->eglDisplay, esContext->eglSurface);
   eglTerminate(esContext->eglDisplay);
}


int main ( int argc, char *argv[] )
{
   ESContext esContext;
   UserData  userData;

   esInitContext ( &esContext );
   esContext.userData = &userData;

   esCreateWindow ( &esContext, TEXT("Multiple Render Targets"), 320, 240, ES_WINDOW_RGB );
   
   if ( !Init ( &esContext ) )
      return 0;

   esRegisterDrawFunc ( &esContext, Draw );
   
   esMainLoop ( &esContext );

   ShutDown ( &esContext );
}
