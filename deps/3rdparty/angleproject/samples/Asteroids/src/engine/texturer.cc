#include "texturer.h"

#include "SDL_image.h"
#include "logger.h"

#include <stdio.h>
#include <string.h>

Texture::~Texture() {
	logger(3, "Freeing texture %s", resourceLocation->getString());
	glDeleteTextures(1, handle);
}

Texturer::Texturer(const char* _resourceDir, bool _noLinear, bool _noMipMaps)
	:	TexManager(true),
		resourceDir(_resourceDir),
		noLinear(_noLinear),
		noMipMaps (_noMipMaps)
{ }

Texture* Texturer::createResource() {
	return new Texture;
}

GLuint* Texturer::loadResource(SimpleTrl* resourceLocation) {
	char* fileName = new char[strlen(resourceDir) + strlen(resourceLocation->resourceString) + 2];
	sprintf(fileName, "%s/%s", resourceDir, resourceLocation->resourceString);
	logger(2, "Loading %s", fileName);
	SDL_Surface* surface = IMG_Load(fileName);
	delete [] fileName;
	if(surface == NULL) return NULL;

	GLuint* glIdent = new GLuint;
	GLenum textureFormat;
	GLint colors = surface->format->BytesPerPixel;

	// Get the number of channels in the SDL surface 
	if (colors == 4) {  // contains an alpha channel
		if (surface->format->Rmask == 0x000000ff)
			textureFormat = GL_RGBA;
		else
			textureFormat = GL_BGRA;
	} else if (colors == 3) {  // no alpha channel
		if (surface->format->Rmask == 0x000000ff)
			textureFormat = GL_RGB;
		else
			textureFormat = GL_BGR;
	} else {
		logger(2, "warning: the image is not truecolor... this will probably break");
		// TODO: this error should not go unhandled
	}

	// Generate OpenGL texture handle
	glGenTextures( 1, glIdent );
 
	// Bind the texture object
	glBindTexture( GL_TEXTURE_2D, *glIdent );
 
	// Set the texture's stretching properties
	if(noLinear && noMipMaps) {
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	} else if(noLinear) {
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	} else if(noMipMaps) {
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	} else {
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	}

	// Edit the texture object's image data using the information SDL_Surface gives u
	if(noMipMaps)
		glTexImage2D( GL_TEXTURE_2D, 0, colors, surface->w, surface->h, 0, textureFormat, GL_UNSIGNED_BYTE, surface->pixels );
	else
		gluBuild2DMipmaps( GL_TEXTURE_2D, 3, surface->w, surface->h, textureFormat, GL_UNSIGNED_BYTE, surface->pixels );

	return glIdent;
}

