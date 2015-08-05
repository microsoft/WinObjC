//
// Modified from Simple_Texture2D found in:
// Book:      OpenGL(R) ES 2.0 Programming Guide
// Authors:   Aaftab Munshi, Dan Ginsburg, Dave Shreiner
// ISBN-10:   0321502795
// ISBN-13:   9780321502797
// Publisher: Addison-Wesley Professional
// URLs:      http://safari.informit.com/9780321563835
//            http://www.opengles-book.com
//

// Simple_Instancing.c
//
//    This is a simple example that draws two quads with a 2D
//    texture image. The purpose of this example is to demonstrate 
//    the basics of ANGLE instancing in GLESv2.
//
#include <stdlib.h>
#include "esUtil.h"

#include <GLES2/gl2ext.h>

PFNGLVERTEXATTRIBDIVISORANGLEPROC glVertexAttribDivisorANGLE;
PFNGLDRAWARRAYSINSTANCEDANGLEPROC glDrawArraysInstancedANGLE;
PFNGLDRAWELEMENTSINSTANCEDANGLEPROC glDrawElementsInstancedANGLE;

typedef struct
{
   // Handle to a program object
   GLuint programObject;

   // Attribute locations
   GLint  positionLoc;
   GLint  texCoordLoc;

   // Sampler location
   GLint samplerLoc;

   // Texture handle
   GLuint textureId;

   // Instance VBO
   GLint  instancePosLoc;

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
    // init instancing functions
    char *extensionString = (char*) glGetString(GL_EXTENSIONS);

   UserData *userData = esContext->userData;
   GLbyte vShaderStr[] =  
      "attribute vec3 a_position;   \n"
      "attribute vec2 a_texCoord;   \n"
      "attribute vec3 a_instancePos;\n"
      "varying vec2 v_texCoord;     \n"
      "void main()                  \n"
      "{                            \n"
      "   gl_Position = vec4(a_position.xyz + a_instancePos.xyz, 1.0); \n"
      "   v_texCoord = a_texCoord;  \n"
      "}                            \n";
   
   GLbyte fShaderStr[] =  
      "precision mediump float;                            \n"
      "varying vec2 v_texCoord;                            \n"
      "uniform sampler2D s_texture;                        \n"
      "void main()                                         \n"
      "{                                                   \n"
      "  gl_FragColor = texture2D( s_texture, v_texCoord );\n"
      "}                                                   \n";

    if (strstr(extensionString, "GL_ANGLE_instanced_arrays"))
    {
        glVertexAttribDivisorANGLE = (PFNGLVERTEXATTRIBDIVISORANGLEPROC)eglGetProcAddress("glVertexAttribDivisorANGLE");
        glDrawArraysInstancedANGLE = (PFNGLDRAWARRAYSINSTANCEDANGLEPROC)eglGetProcAddress("glDrawArraysInstancedANGLE");
        glDrawElementsInstancedANGLE = (PFNGLDRAWELEMENTSINSTANCEDANGLEPROC)eglGetProcAddress("glDrawElementsInstancedANGLE");
    }

   // Load the shaders and get a linked program object
   userData->programObject = esLoadProgram ( vShaderStr, fShaderStr );

   // Get the attribute locations
   userData->positionLoc = glGetAttribLocation ( userData->programObject, "a_position" );
   userData->texCoordLoc = glGetAttribLocation ( userData->programObject, "a_texCoord" );
   userData->instancePosLoc = glGetAttribLocation ( userData->programObject, "a_instancePos" );
   
   // Get the sampler location
   userData->samplerLoc = glGetUniformLocation ( userData->programObject, "s_texture" );

   // Load the texture
   userData->textureId = CreateSimpleTexture2D ();

   glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );
   return TRUE;
}

///
// Draw a triangle using the shader pair created in Init()
//
void Draw ( ESContext *esContext )
{
   UserData *userData = (UserData*) esContext->userData;
   GLfloat vVertices[] = { -0.2f,  0.2f, 0.0f,  // Position 0
                            0.0f,  0.0f,        // TexCoord 0 
                           -0.2f, -0.2f, 0.0f,  // Position 1
                            0.0f,  1.0f,        // TexCoord 1
                            0.2f, -0.2f, 0.0f,  // Position 2
                            1.0f,  1.0f,        // TexCoord 2
                            0.2f,  0.2f, 0.0f,  // Position 3
                            1.0f,  0.0f         // TexCoord 3
                         };
   GLushort indices[] = { 0, 1, 2, 0, 2, 3 };

   GLfloat instanceVerts [] = { -0.3f, -0.3f, 0.0f, 0.3f, 0.3f, 0.0f };
      
   // Set the viewport
   glViewport ( 0, 0, esContext->width, esContext->height );
   
   // Clear the color buffer
   glClear ( GL_COLOR_BUFFER_BIT );

   // Use the program object
   glUseProgram ( userData->programObject );

   // Load the vertex position
   glVertexAttribPointer ( userData->positionLoc, 3, GL_FLOAT, 
                           GL_FALSE, 5 * sizeof(GLfloat), vVertices );
   // Load the texture coordinate
   glVertexAttribPointer ( userData->texCoordLoc, 2, GL_FLOAT,
                           GL_FALSE, 5 * sizeof(GLfloat), &vVertices[3] );

   // Load the instance position
   glVertexAttribPointer ( userData->instancePosLoc, 3, GL_FLOAT, 
                           GL_FALSE, 3 * sizeof(GLfloat), instanceVerts );

   glEnableVertexAttribArray ( userData->positionLoc );
   glEnableVertexAttribArray ( userData->texCoordLoc );
   glEnableVertexAttribArray ( userData->instancePosLoc );

   // Enable instancing
   glVertexAttribDivisorANGLE( userData->instancePosLoc, 1 );

   // Bind the texture
   glActiveTexture ( GL_TEXTURE0 );
   glBindTexture ( GL_TEXTURE_2D, userData->textureId );

   // Set the sampler texture unit to 0
   glUniform1i ( userData->samplerLoc, 0 );

   glDrawElementsInstancedANGLE ( GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices, 2 );
   
   eglSwapBuffers ( esContext->eglDisplay, esContext->eglSurface );
}

///
// Cleanup
//
void ShutDown ( ESContext *esContext )
{
   UserData *userData = (UserData*) esContext->userData;

   // Delete texture object
   glDeleteTextures ( 1, &userData->textureId );

   // Delete program object
   glDeleteProgram ( userData->programObject );
}


int main ( int argc, char *argv[] )
{
   ESContext esContext;
   UserData  userData;

   esInitContext ( &esContext );
   esContext.userData = &userData;

   esCreateWindow ( &esContext, TEXT("Simple Instancing"), 320, 240, ES_WINDOW_RGB );
   
   if ( !Init ( &esContext ) )
      return 0;

   esRegisterDrawFunc ( &esContext, Draw );
   
   esMainLoop ( &esContext );

   ShutDown ( &esContext );
}
