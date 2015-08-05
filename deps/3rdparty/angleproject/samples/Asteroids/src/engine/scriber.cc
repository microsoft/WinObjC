#include "scriber.h"
#include "teges.h"

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <SDL_opengl.h>

FontTrl::FontTrl(const char* _resourceString, int _fontsize) : SimpleTrl(_resourceString) {
	fontsize = _fontsize;
}

bool FontTrl::equals(FontTrl* trl) {
	if(fontsize == trl->fontsize && SimpleTrl::equals(trl)) return true;
	else return false;
}

char* FontTrl::getString() {
	return resourceString;
}


Font::~Font() {
	logger(3, "Freeing font %s, size %i", resourceLocation->getString(), resourceLocation->fontsize);
	TTF_CloseFont(handle);
}

Writing::Writing(Teges* _engine) : TegesObject(_engine), scriber(_engine->getScriber()) {
	surface = _engine->getScriber()->getSurface();
}

int nextpoweroftwo(int x) {
	double logbase2 = log(x) / log(2);
	return round(pow(2,ceil(logbase2)));
}

void Writing::write(TTF_Font* font, const char* text, float x, float y, int c[3], float depth) {
	x /= 100;
	y /= 100; //TODO: Not so fast dodger
	y = - y;
	
	SDL_Color color = { c[0], c[1], c[2], 0};
	SDL_Surface *initial;
	SDL_Surface *intermediary;
	SDL_Rect rect;
	GLuint texture;

	/* Use SDL_TTF to render our text */
	//if(!(text_surface=TTF_RenderUTF8_Blended(font, text, color))) {
	initial = TTF_RenderUTF8_Blended(font, text, color);
	
	/* Convert the rendered text to a known format */
	// No more need to be x,y a power of 2
	int w = nextpoweroftwo(initial->w);
	int h = nextpoweroftwo(initial->h);
	rect.x = 0;
	rect.y = h - initial->h;
	
	intermediary = SDL_CreateRGBSurface(0, w, h, 32, 
			0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

	SDL_BlitSurface(initial, 0, intermediary, &rect);
	
	/* Tell GL about our new texture */
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, w, h, 0, GL_BGRA, GL_UNSIGNED_BYTE, intermediary->pixels );
	
	/* GL_NEAREST looks horrible, if scaled... */
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	

	/* prepare to render our texture */
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glColor3f(1.0f, 1.0f, 1.0f);

	if(depth == 0) depth = -(engine->getZNear() + engine->getZNear() * 0.01);
	else depth = -depth;

	/* Draw a quad at location */
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x + (float)w/1000, y + (float)h/1000, depth);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x                , y + (float)h/1000, depth);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x                , y                         , depth);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x + (float)w/1000, y                         , depth);
	glEnd();

	glDisable(GL_BLEND);
		
	/* Bad things happen if we delete the texture before it finishes */
	glFinish();
	
	/* Clean up */
	SDL_FreeSurface(initial);
	SDL_FreeSurface(intermediary);
	glDeleteTextures(1, &texture);

}


Scriber::Scriber(SDL_Surface* _surface, const char* _resourceDir, bool _blendingEnabled)
	: resourceDir(_resourceDir), FontManager(_blendingEnabled)
{
	if(TTF_Init() == -1) {
		logger(-1, "Unable to initialize font system: %s", TTF_GetError());
		exit(1);
	}
	surface = _surface;
}

Scriber::~Scriber() {
	cleanUp();  // Delete all fonts first
	TTF_Quit();
}

Font* Scriber::createResource() {
	return new Font;
}

TTF_Font* Scriber::loadResource(FontTrl* resourceLocation) {
	char* fileName = new char[strlen(resourceDir) + strlen(resourceLocation->resourceString) + 2];
	sprintf(fileName, "%s/%s", resourceDir, resourceLocation->resourceString);
	logger(2, "Loading %s, size %i", fileName, resourceLocation->fontsize);
	TTF_Font* ret = TTF_OpenFont(fileName, resourceLocation->fontsize);
	if(ret == NULL) logger(-1, "Unable to loaf font %s: %s", fileName, TTF_GetError());
	return ret;
}

void Scriber::blending(bool b) {
	//TODO
}

