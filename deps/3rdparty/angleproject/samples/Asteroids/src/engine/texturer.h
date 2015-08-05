#ifndef _TEXTURER_H_
#define _TEXTURER_H_ 

#include "manager.h"

#include "SDL_opengl.h"

class Texturer;

/**
 * Interface for object using textures
 */
class Texturable {
	protected:
		Texturer* texturer;
	public:
		Texturable(Texturer* tex) { texturer = tex; }
};

/**
 * Texture resource for manager
 */
class Texture : public TheResource<GLuint, Texturable, SimpleTrl> {
	public:
		virtual ~Texture();
};

/**
 * Implements manager with loading texture from file to OpenGL memory
 */
template class Manager<GLuint, Texturable, SimpleTrl>;
typedef Manager<GLuint, Texturable, SimpleTrl> TexManager;

class Texturer : public TexManager {
	public:
		typedef TexManager::ResourceList TextureList;
		typedef TextureList::iterator TextureIterator;
	protected:
		const char* resourceDir;
		Texture* createResource();
		GLuint* loadResource(SimpleTrl* resourceLocation);
		bool noLinear, noMipMaps;
	public:
		Texturer(const char* _resourceDir, bool noLinear, bool noMipMaps);
		~Texturer() { };
};

#endif // _TEXTURER_H_
