#ifndef _SCRIBER_H_
#define _SCRIBER_H_

#include "manager.h"
#include "teges_object.h"

#include "SDL_ttf.h"

#include <vector>

class FontTrl : public SimpleTrl {
	public:
		int fontsize;
		FontTrl(const char* _resourceString, int _fontsize);
		virtual bool equals(FontTrl* trl);
		virtual char* getString();
};


class Scriber;

/**
 * Interface for object that can play sound
 */
class Writing : public virtual TegesObject {
		//static const char className[]; // debug, should be cleaned in release
	protected:
		Scriber* scriber;
		SDL_Surface* surface;
		void write(TTF_Font* font, const char* text, float x, float y, int color[3], float depth = 0);
	public:
		Writing(Teges* _engine);
		virtual void renderForefront() = 0;
		//virtual const char* getClass() { return className; }
};

typedef std::vector<Writing*> WritingList;

/**
 * Sound resource for manager
 */
class Font : public TheResource<TTF_Font, Writing, FontTrl> {
	public:
		virtual ~Font();
};


template class Manager<TTF_Font, Writing, FontTrl>;
typedef Manager<TTF_Font, Writing, FontTrl> FontManager;

/**
 * Implements manager and allows to blit text
 */
class Scriber : public FontManager {
	public:
		typedef FontManager::ResourceList FontList;
		typedef FontList::iterator FontIterator;
	protected:
		SDL_Surface* surface;
		const char* resourceDir;
		Font* createResource();
		TTF_Font* loadResource(FontTrl* resourceLocation);
		//bool blendingEnabled;
	public:
		Scriber(SDL_Surface* _surface, const char* _resourceDir, bool _blendingEnabled = true);
		~Scriber();
		SDL_Surface* getSurface() { return surface; }
		void blending(bool b = true);
};

#endif // _SCRIBER_H_
