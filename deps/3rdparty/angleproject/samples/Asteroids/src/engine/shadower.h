#ifndef _SHADOWER_H_
#define _SHADOWER_H_

#include "manager.h"
#include "teges_object.h"

#include <SDL_opengl.h>
#include <vector>

class ShaderTrl : public SimpleTrl {
	public:
		GLenum type; // vertex or fragment
		ShaderTrl(const char* _resourceString, GLenum _type);
		virtual bool equals(ShaderTrl* trl);
		virtual char* getString();
};


class Shadower;

/**
 * Interface for object that can use shaders
 */
class Shadering : public virtual TegesObject {
		//static const char className[]; // debug, should be cleaned in release
	protected:
		Shadower* shadower;
	public:
		Shadering(Teges* _engine);
		virtual void renderForefront() { };
		//virtual const char* getClass() { return className; }
};

typedef std::vector<Shadering*> ShaderingList;

/**
 * Shader resource for manager
 */
class Shader : public TheResource<GLuint, Shadering, ShaderTrl> {
	public:
		virtual ~Shader();
};


template class Manager<GLuint, Shadering, ShaderTrl>;
typedef Manager<GLuint, Shadering, ShaderTrl> ShaderManager;

/**
 * Implements manager and allows to blit text
 */
class Shadower : public ShaderManager {
	public:
		typedef ShaderManager::ResourceList ShaderList;
		typedef ShaderList::iterator ShaderIterator;
	protected:
		const char* resourceDir;
		Shader* createResource();
		GLuint* loadResource(ShaderTrl* resourceLocation);
	public:
		Shadower(const char* _resourceDir, bool _shadersEnabled = true);
		~Shadower();
};

#endif // _SHADOWER_H_
