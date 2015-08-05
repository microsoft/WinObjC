#ifndef _PLAYGROUND_H_
#define _PLAYGROUND_H_

#include "../engine/objector.h"
#include "block.h"

#include <SDL_mixer.h>
#include <SDL_ttf.h>

class Tegris;

class PlayGroundModel : public ObjModel, public Sounding, public Shadering {
		GLuint *wallTexture, *wallBump, *wallNormal;
		GLuint *floorTexture, *floorBump, *floorNormal;
		Mesh* mesh;
		GLint uniformTime;
		int displayList;
		//static const char className[];
	protected:
		Mix_Chunk* crashSound;

		GLuint normalShaderProgram;
			GLuint *normalVertShader;
			GLuint *normalFragShader;

		GLuint psychoShaderProgram;
			GLuint *psychoVertShader;
			GLuint *psychoFragShader;

		GLuint currentShaderProgram;

		GLuint colorTex;
		GLuint normalTex;
		GLuint heightTex;
		GLuint invRadius;

		int width, height, depth;
	public:
		PlayGroundModel(Teges* _engine, int widht, int height, int depth, const char* wall_texture, const char* wall_bump, const char* wall_normal, const char* floor_texture, const char* floor_bump, const char* floor_normal);
		~PlayGroundModel();
		void render();
		int getDepth() { return depth; }
		//virtual const char* getClass() { return className; }
};

class PlayGround : public PlayGroundModel {
		BlockList blocks;
		Block**** matrix;
		Tegris *game;
		bool firstBlood;
	public:
		PlayGround(Tegris* _game, int width, int height, int depth, const char* wall_texture, const char* wall_bump, const char* wall_normal, const char* floor_texture, const char* floor_bump, const char* floor_normal);
		~PlayGround();
		void logic();
		bool collision(Block* block); // returns true if 'block' colide with something in playground matrix
		bool addBlock(Block* newBlock, bool internal = false); // add block to matrix
		void update(Block* block); // update matrix deleting this block and adding with up to date block matrix
		void checkFloors(); // check for full floors - TODO: return value instead of informing game
		void eraseFloors(); // erase all full floors
		Tegris* getGame() { return game; }
};

#endif
