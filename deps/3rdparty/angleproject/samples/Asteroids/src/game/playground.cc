#include "../engine/logger.h"
#include "playground.h"
#include "tegris.h"

#include "SDL_opengl.h"

#include <math.h>
#include <set>

//const char PlayGroundModel::className[] = "PlayGroundModel";

PlayGround::PlayGround(Tegris* _game, int _w, int _h, int _d, const char* wall_texture, const char* wall_bump, const char* wall_normal, const char* floor_texture, const char* floor_bump, const char* floor_normal)
	: TegesObject(_game->getEngine()), PlayGroundModel(_game->getEngine(), _w, _h, _d, wall_texture, wall_bump, wall_normal, floor_texture, floor_bump, floor_normal),
	  game(_game)
	{
	matrix = new Block*** [_d+1];
	for(int d=0; d <= _d; ++d) {
		matrix[d] = new Block** [_h];
		for(int h=0; h<_h; ++h) {
			matrix[d][h] = new Block* [_w];
			for(int w=0; w<_w; ++w) {
				matrix[d][h][w] = NULL;
			}
		}
	}
	firstBlood = false;
	logger(1, "PlayGround ready.");
}

PlayGround::~PlayGround() {
	// Blocks to delete:
	std::set<Block*> blocks;

	for(int d=0; d <= depth; ++d) {
		for(int h=0; h<height; ++h) {
			if(engine->running)
				for(int w=0; w<width; ++w)
					if(matrix[d][h][w] != NULL) blocks.insert(matrix[d][h][w]);
			delete [] matrix[d][h];
		}
		delete [] matrix[d];
	}
	delete [] matrix;

	if(engine->running)
		for(std::set<Block*>::iterator i = blocks.begin(); i != blocks.end(); ++i) {logger(0, "Do kasacji %p/%p", *i, (*i)->getId()); delete *i;}
}

bool PlayGround::collision(Block* block) {
	//logger("5, depth of checked block: %i", block->getZ());
	for(int z=0; z < Block::MAX_SIZE; ++z) {
		for(int y=0; y < Block::MAX_SIZE; ++y) {
			for(int x=0; x < Block::MAX_SIZE; ++x) {
				if(block->matrixZYX(z,y,x) == 0) continue;
				//logger(5, "Checking [%i][%i][%i]\nBock position: %i,%i,%i\n", z, y, x, block->getZ(), block->getY(), block->getX());
				if(x + block->getX() >= width
						|| x + block->getX() < 0
						|| y + block->getY() >= height
						|| y + block->getY() < 0
						|| z + block->getZ() > depth) {
					//logger(5, "Bounds collision: %i + %i = %i <? %i; y,x = %i,%i\n",  z, block->getZ(), z + block->getZ(), depth, y,x);
					return true;
				}
				//logger(5, "Checking matrix[%i][%i][%i]\n", z + block->getZ(), y + block->getY(), x + block->getX());
				if(matrix[z + block->getZ()][y + block->getY()][x + block->getX()] != NULL
						&& matrix[z + block->getZ()][y + block->getY()][x + block->getX()] != block->getId()
					) {
					//logger(5, "Matrix collision: %p\n", matrix[z + block->getZ()][y + block->getY()][x + block->getX()]);
					return true;
				}
			}
		}
	}
	//logger(5, "No collision\n");
	return false;
}

bool PlayGround::addBlock(Block* block, bool internal) {
	//logger(4, "Adding block\n");
	if(!collision(block)) {
		if(!internal) blocks.push_back(block); // add block to list if we have been called from outside world
		for(int z=0; z < Block::MAX_SIZE; ++z) {
			for(int y=0; y < Block::MAX_SIZE; ++y) {
				for(int x=0; x < Block::MAX_SIZE; ++x) {
						if(block->matrixZYX(z,y,x) > 0) {
							//logger(5, "Setting %p at [%i][%i][%i]n\n", block->getId(), z+block->getZ(), y+block->getY(), x+block->getX());
							matrix[z+block->getZ()][y+block->getY()][x+block->getX()] = block->getId();;
						}
				}
			}
		}
		return true;
	}
	return false;
}

void PlayGround::update(Block* block) {
	// Delete space occupied by the block
	for(int d=0; d <= depth; ++d) {
		for(int h=0; h<height; ++h) {
			for(int w=0; w<width; ++w) {
				if(matrix[d][h][w] == block->getId()) matrix[d][h][w] = NULL;
			}
		}
	}
	// Update matrix with new block position
	addBlock(block, true);
}

PlayGroundModel::PlayGroundModel(Teges* _engine, int _w, int _h, int _d, const char* wall_texture, const char* wall_bump, const char* wall_normal, const char* floor_texture, const char* floor_bump, const char* floor_normal)
	: TegesObject(_engine), ObjModel(_engine), Sounding(_engine->getDJ()), Shadering(_engine) {

	wallTexture = _engine->getTexturer()->associate(this, new SimpleTrl(wall_texture));
	wallBump = _engine->getTexturer()->associate(this, new SimpleTrl(wall_bump));
	wallNormal = _engine->getTexturer()->associate(this, new SimpleTrl(wall_normal));
	floorTexture = _engine->getTexturer()->associate(this, new SimpleTrl(floor_texture));
	floorBump = _engine->getTexturer()->associate(this, new SimpleTrl(floor_bump));
	floorNormal = _engine->getTexturer()->associate(this, new SimpleTrl(floor_normal));

	crashSound = _engine->getDJ()->associate(this, new SimpleTrl("fall_big.ogg"));

	mesh = _engine->getObjector()->associate(this, new SimpleTrl("playground.obj"));
	
	normalVertShader = _engine->getShadower()->associate(this, new ShaderTrl("parallax.vert", GL_VERTEX_SHADER));
	normalFragShader = _engine->getShadower()->associate(this, new ShaderTrl("parallax.frag", GL_FRAGMENT_SHADER));
	psychoVertShader = _engine->getShadower()->associate(this, new ShaderTrl("psychofrog.vert", GL_VERTEX_SHADER));
	psychoFragShader = _engine->getShadower()->associate(this, new ShaderTrl("psychofrog.frag", GL_FRAGMENT_SHADER));

	int w = width = _w;
	int h = height = _h;
	int d = depth = _d;

	displayList = glGenLists(2);

	const float s = 0.5;
	float x,y,z;
	float sx, sy, sz;
	glNewList(displayList, GL_COMPILE);
		glBegin(GL_QUADS);

			// Tyl
			glNormal3f( 0.0f,  0.0f,  1.0f);
			glMultiTexCoord3fARB(GL_TEXTURE1_ARB,  1.0f,  0.0f,  0.0f);
			glMultiTexCoord3fARB(GL_TEXTURE2_ARB,  0.0f, -1.0f,  0.0f);
			for(x = 0; x < w; ++x) {
				for(y = 0; y < h; ++y) {

					// Determine what quarter of texture we should use
					if(int(x) % 2) sx = 0;
					else sx = s;
					if(int(y) % 2) sy = 0;
					else sy = s;

					glTexCoord2f(sx+s,sy  );	glVertex3f(x  , y  , -d);
					glTexCoord2f(sx,  sy  );	glVertex3f(x+1, y  , -d);
					glTexCoord2f(sx,  sy+s);	glVertex3f(x+1, y+1, -d);
					glTexCoord2f(sx+s,sy+s);	glVertex3f(x  , y+1, -d);
				}
			}//*/

			// Lewa
			glNormal3f( 1.0,  0.0,  0.0);
			glMultiTexCoord3fARB(GL_TEXTURE1_ARB,  0.0f,  0.0f, -1.0f);
			glMultiTexCoord3fARB(GL_TEXTURE2_ARB,  0.0f, -1.0f,  0.0f);
			for(z = -d; z < 0; ++z) {
				for(y = 0; y < h; ++y) {

					// Determine what quarter of texture we should use
					if(int(z) % 2) sy = 0;
					else sy = s;
					if(int(y) % 2) sz = 0;
					else sz = s;

					glTexCoord2f(sy  ,sz  );	glVertex3f(0, y,   z);
					glTexCoord2f(sy  ,sz+s);	glVertex3f(0, y+1, z);
					glTexCoord2f(sy+s,sz+s);	glVertex3f(0, y+1, z+1);
					glTexCoord2f(sy+s,sz  );	glVertex3f(0, y,   z+1);
				}
			}//*/

			// Prawa
			glNormal3f(-1.0,  0.0,  0.0);
			glMultiTexCoord3fARB(GL_TEXTURE1_ARB,  0.0f,  0.0f, -1.0f);
			glMultiTexCoord3fARB(GL_TEXTURE2_ARB,  0.0f, -1.0f,  0.0f);
			for(z = -d; z < 0; ++z) {
				for(y = 0; y < h; ++y) {

					// Determine what quarter of texture we should use
					if(int(z) % 2) sy = 0;
					else sy = s;
					if(int(y) % 2) sz = 0;
					else sz = s;

					glTexCoord2f(sy+s,sz  );	glVertex3f( w, y,   z+1);
					glTexCoord2f(sy+s,sz+s);	glVertex3f( w, y+1, z+1);
					glTexCoord2f(sy  ,sz+s);	glVertex3f( w, y+1, z);
					glTexCoord2f(sy  ,sz  );	glVertex3f( w, y,   z);
				}
			}//*/
		glEnd();
	glEndList();

	glNewList(displayList+1, GL_COMPILE);
		glBegin(GL_QUADS);
			// Gora
			glNormal3f( 0.0, -1.0,  0.0);
			glMultiTexCoord3fARB(GL_TEXTURE1_ARB,  1.0f,  0.0f,  0.0f);
			glMultiTexCoord3fARB(GL_TEXTURE2_ARB,  0.0f,  0.0f,  1.0f);
			for(z = -d; z < 0; ++z) {
				for(x = 0; x < w; ++x) {

					// Determine what quarter of texture we should use
					if(int(z) % 2) sz = 0;
					else sz = s;
					if(int(x) % 2) sx = 0;
					else sx = s;

					glTexCoord2f(sx+s,sz  );	glVertex3f( x+1, h,  z  );
					glTexCoord2f(sx+s,sz+s);	glVertex3f( x+1, h,  z+1);
					glTexCoord2f(sx  ,sz+s);	glVertex3f( x  , h,  z+1);
					glTexCoord2f(sx  ,sz  );	glVertex3f( x  , h,  z  );
				}
			}//*/

			// Dol
			glNormal3f( 0.0, 1.0,  0.0);
			glMultiTexCoord3fARB(GL_TEXTURE1_ARB,  1.0f,  0.0f,  0.0f);
			glMultiTexCoord3fARB(GL_TEXTURE2_ARB,  0.0f,  0.0f,  1.0f);
			for(z = -d; z < 0; ++z) {
				for(x = 0; x < w; ++x) {

					// Determine what quarter of texture we should use
					if(int(z) % 2) sz = 0;
					else sz = s;
					if(int(x) % 2) sx = 0;
					else sx = s;

					glTexCoord2f(sx  ,sz  );	glVertex3f( x  , 0,  z  );
					glTexCoord2f(sx  ,sz+s);	glVertex3f( x  , 0,  z+1);
					glTexCoord2f(sx+s,sz+s);	glVertex3f( x+1, 0,  z+1);
					glTexCoord2f(sx+s,sz  );	glVertex3f( x+1, 0,  z  );
				}
			}//*/

		glEnd();
	glEndList();

	if(_engine->getShadower()->isEnabled()) {
		normalShaderProgram = glCreateProgram();
		glAttachShader(normalShaderProgram, *normalVertShader);
		glAttachShader(normalShaderProgram, *normalFragShader);
		glLinkProgram(normalShaderProgram);
		
		colorTex = glGetUniformLocation(normalShaderProgram, "colorMap");
		normalTex = glGetUniformLocation(normalShaderProgram, "normalMap");
		heightTex = glGetUniformLocation(normalShaderProgram, "heightMap");
		invRadius = glGetUniformLocation(normalShaderProgram, "invRadius");

		psychoShaderProgram = glCreateProgram();
		glAttachShader(psychoShaderProgram, *psychoVertShader);
		glAttachShader(psychoShaderProgram, *psychoFragShader);
		glLinkProgram(psychoShaderProgram);

		uniformTime = glGetUniformLocation(normalShaderProgram, "time");
		uniformTime = glGetUniformLocation(psychoShaderProgram, "time");

		currentShaderProgram = normalShaderProgram;
	}
}

PlayGroundModel::~PlayGroundModel() {
	glDeleteLists(displayList, 2);
	texturer->free(this, wallTexture);
	texturer->free(this, floorTexture);
	dj->free(this, crashSound);
}

void PlayGroundModel::render() {

	if(engine->getShadower()->isEnabled()) {
		glUseProgram(currentShaderProgram);
		glUniform1i(colorTex, 0);
		glUniform1i(normalTex, 1);
		glUniform1i(heightTex, 2);
		glUniform1f(invRadius, 0.01);
		glUniform1i(uniformTime, engine->ticks());
	}

	glBindTexture(GL_TEXTURE_2D, *wallTexture);
	float specReflectionWall[] = { 0.1f, 0.08f, 0.04f, 0.1f };
	
	// TEXTURE-UNIT #0
	glActiveTextureARB(GL_TEXTURE0_ARB);
	glBindTexture(GL_TEXTURE_2D, *wallTexture);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specReflectionWall);
	glMateriali(GL_FRONT, GL_SHININESS, 10);

	// TEXTURE-UNIT #1
	glActiveTextureARB(GL_TEXTURE1_ARB);
	glBindTexture(GL_TEXTURE_2D, *wallNormal);

	// TEXTURE-UNIT #2
	glActiveTextureARB(GL_TEXTURE2_ARB);
	glBindTexture(GL_TEXTURE_2D, *wallBump);

	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glCallList(displayList);
	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, *floorTexture);
	float specReflectionFloor[] = { 0.08f, 0.08f, 0.08f, 0.2f };
	
	// TEXTURE-UNIT #0
	glActiveTextureARB(GL_TEXTURE0_ARB);
	glBindTexture(GL_TEXTURE_2D, *floorTexture);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specReflectionFloor);
	glMateriali(GL_FRONT, GL_SHININESS, 10);

	// TEXTURE-UNIT #1
	glActiveTextureARB(GL_TEXTURE1_ARB);
	glBindTexture(GL_TEXTURE_2D, *floorNormal);

	// TEXTURE-UNIT #2
	glActiveTextureARB(GL_TEXTURE2_ARB);
	glBindTexture(GL_TEXTURE_2D, *floorBump);
	
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glCallList(displayList+1);
	glPopMatrix();
	
	//if(engine->getShadower()->isEnabled()) {
	//	glUseProgram(0);
	//}

	glPushMatrix();
		glTranslatef(-2, 2, 0);

		//int color[3] = { 128, 32, 32 };
		//write(testFont1, "Zjawa", -1, -2, color);

		//mesh->Render();
	glPopMatrix();
	
	glActiveTextureARB(GL_TEXTURE0_ARB);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_EXT);
	glTexEnvf(GL_TEXTURE_ENV, GL_COMBINE_RGB_EXT, GL_MODULATE);
}

void PlayGround::logic() {
	if(firstBlood) {
		engine->view.glop = 15*sin(0.003*(float)engine->ticks());
		engine->view.heading = 5+15*sin(0.002*(float)engine->ticks());
	}
}

void PlayGround::checkFloors() {
	bool eraseFloor;
	int numberOfErased = 0;
	for(int d=0; d <= depth; ++d) {
		eraseFloor = true;
		for(int h=0; h<height; ++h) {
			for(int w=0; w<width; ++w) {
				if(matrix[d][h][w] == NULL) eraseFloor = false;
			}
		}
		if(eraseFloor) numberOfErased++;
	}
	if(numberOfErased) {
		//if(firstBlood == false && numberOfErased == 4) {
		//	numberOfErased *= 5;
		//}
		game->fullFloorState(numberOfErased);
	}
}

void PlayGround::eraseFloors() {
	//logger(4, "Erasing full floors");
	play(crashSound);

	int count = 0;

	bool eraseFloor;
	for(int d=0; d <= depth; ++d) {
		eraseFloor = true;
		for(int h=0; h<height; ++h) {
			for(int w=0; w<width; ++w) {
				if(matrix[d][h][w] == NULL) eraseFloor = false;
			}
		}
		if(eraseFloor) {
			++count;
			// Erasing block by block
			//logger(5, "Erasing floor: %d, blockcount: %i\n", d, blocks.size());
			for(BlockList::iterator i = blocks.begin(); i != blocks.end(); ++i) {
				//logger(5, "procesing block");
				if(d - (*i)->posZ >= 0 && d - (*i)->posZ < Block::MAX_SIZE) { // Filter out blocks with too much distance from intersect floor
					//logger(5, "erasing intersection for %p", *i);
					(*i)->eraseIntersection(d); // and glue bottom if present
					(*i)->posZ++;
					update(*i);
				}
			}
			for(BlockList::iterator i = blocks.begin(); i != blocks.end(); ++i) {
				//logger(5, "procesing block2");
				if(d - (*i)->posZ >= Block::MAX_SIZE) { // Filter out blocks bellow
					//logger(5, "Fall block %p situated at %i", *i, (*i)->posZ);
					(*i)->posZ++;
					update(*i);
				}
			}
		}

	}
	//logger(5, "End of erasing floors");
	if(firstBlood == false && count >= 4) {
		firstBlood = true;
		engine->getDJ()->setMusic("frog_machine.ogg");
		//if(engine->getDJ()->isEnabled()) Mix_HookMusicFinished()
		currentShaderProgram = psychoShaderProgram;
		engine->view.mode = Teges::View::TPP;
		engine->view.glop = 10;
		engine->view.heading = 10;
	}
}

