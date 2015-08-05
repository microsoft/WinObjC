#ifndef _BLOCK_H_
#define _BLOCK_H_ 

#include "../engine/teges.h"

#include <vector>

class PlayGround;

/**
 * All logic for block as a configuration of cubes.
 */
class Block {
	public: 
		enum Type {
			DOT = 0,
			I_2D,  L_2D,  S_2D,  O_2D,  T_2D,
			I_BIG, L_BIG, S_BIG, O_BIG, T_BIG,
			L_3D,  S_3D,  LS_3D
		};

		enum RightRotate {
			NONE = 0,
			QUARTER = 90,
			HALF = 180,
			HALFQUARTER = 270,
			FULL = 360
		};

		static const int MAX_SIZE = 4;

	protected:
		Type type;
		float centerPosition[3]; // defines where is the center of block, 2 if part 2 is center, 2.5 if center is between 2 and 3
		int blockMatrix[MAX_SIZE][MAX_SIZE][MAX_SIZE];
		bool lives;
		int weight;

	public:
		int posX, posY, posZ; // Position is also OpenGL position as playground is normalized.
		Block(Type type);
		virtual ~Block() { }
		Type getType() { return type; }
		bool isLiving() { return lives; } // returns false is block has no more cubes.
		virtual int matrixZYX(int z, int y, int x) { return blockMatrix[z][y][x]; }
		virtual int getX() { return posX; }
		virtual int getY() { return posY; }
		virtual int getZ() { return posZ; }
		virtual Block* getId() { return this; }
		virtual void rotate(int xDir, int yDir, int zDir);
		virtual void eraseIntersection(int floorDepth); // erase all cubes situated at floorDepth'th floor
		int getWeight() { return weight; } // returns number of cubes for current block type
};

typedef std::vector<Block*> BlockList;

class BlockModel : public Model, public Block {
		GLuint *faceTexture, *faceBump, *faceNormal;

		GLuint displayList;
		void makeQuads(int invertNormal);
		float* getBlockColor(int depth);
		static const char className[]; // debug, should be cleared in release
	public:
		bool invertNormal; // set to true if block have light inside and block faces should be lightened
		BlockModel(Type _type, Teges* _engine, int x, int y, int z, const char* texture, const char* bump, const char* normal, bool _invertNormal = false);
		~BlockModel();
		void render();
		void logic();
		virtual const char* getClass() { return className; } // debug, should be cleared in release
};

class CurrentBlock : public Block, public Interactive, public Sounding {
		BlockModel* model; // block model currently controller
		PlayGround* playGround;
		Teges* engine;
		Mix_Chunk* fallSound[4];
		Mix_Chunk* rotateSound;
		static const char className[]; // debug, should be cleared in release
	public:
		float tilt; // temporary place for tilting. should be moved to engine.
		bool enabled;
		CurrentBlock(BlockModel* _model, PlayGround* playGround, Teges* engine);
		~CurrentBlock();
		void performEvent(const SDL_Event& event);
		void logic();
		void render() {}
		void setModel(BlockModel* newBlock);
		BlockModel* getModel() { return model; }
		int matrixZYX(int z, int y, int x) { return model->matrixZYX(z,y,x); }
		int getX() { return model->getX(); }
		int getY() { return model->getY(); }
		int getZ() { return model->getZ(); }
		void rotate(int xDir, int yDir, int zDir) { return model->rotate(xDir, yDir, zDir); }
		Block* getId() { return model; }
		bool fallDown(); // try step down and if it is not possible, return false;
		long lastFall; // no. ticks when last fall occured
		virtual const char* getClass() { return className; } // debug, should be cleared in release
};

#endif
