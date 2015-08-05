#include "../engine/logger.h"
#include "playground.h"
#include "tegris.h"
#include "SDL_opengl.h"

#include <math.h>
#define logc(c,x) (log(x)/log(c))

const char BlockModel::className[] = "BlockModel"; // debug, should be cleared in release
const char CurrentBlock::className[] = "CurrentBlock"; // debug, should be cleared in release

Block::Block(Type _type) {
	type = _type;
	lives = true;
	for(int x=0; x < Block::MAX_SIZE; ++x)
		for(int y=0; y < Block::MAX_SIZE; ++y)
			for(int z=0; z < Block::MAX_SIZE; ++z)
				blockMatrix[z][y][x] = 0;

	switch(_type) {
		case Block::DOT:
			blockMatrix[0][0][0] = 1;
			centerPosition[0] = 0;
			centerPosition[1] = 0;
			centerPosition[2] = 0;
			break;
		case Block::I_2D:
			blockMatrix[1][1][0] = 1;
			blockMatrix[1][1][1] = 1;
			blockMatrix[1][1][2] = 1;
			centerPosition[0] = 1;
			centerPosition[1] = 1;
			centerPosition[2] = 1;
			break;
		case Block::L_2D:
			blockMatrix[1][1][0] = 1;
			blockMatrix[1][0][0] = 1;
			blockMatrix[1][0][1] = 1;
			blockMatrix[1][0][2] = 1;
			centerPosition[0] = 1;
			centerPosition[1] = 0.5;
			centerPosition[2] = 1;
			break;
		case Block::S_2D:
			blockMatrix[1][1][0] = 1;
			blockMatrix[1][1][1] = 1;
			blockMatrix[1][2][1] = 1;
			blockMatrix[1][2][2] = 1;
			centerPosition[0] = 1;
			centerPosition[1] = 1.5;
			centerPosition[2] = 1;
			break;
		case Block::O_2D:
			blockMatrix[1][0][0] = 1;
			blockMatrix[1][0][1] = 1;
			blockMatrix[1][1][1] = 1;
			blockMatrix[1][1][0] = 1;
			centerPosition[0] = 1;
			centerPosition[1] = 0.5;
			centerPosition[2] = 0.5;
			break;
		case Block::T_2D:
			blockMatrix[1][1][0] = 1;
			blockMatrix[1][1][1] = 1;
			blockMatrix[1][2][1] = 1;
			blockMatrix[1][1][2] = 1;
			centerPosition[0] = 1.0;
			centerPosition[1] = 1.5;
			centerPosition[2] = 1.0;
			break;
		case Block::I_BIG:
			blockMatrix[1][1][0] = 1;
			blockMatrix[1][1][1] = 1;
			blockMatrix[1][1][2] = 1;
			blockMatrix[1][1][3] = 1;
			centerPosition[0] = 1;
			centerPosition[1] = 1;
			centerPosition[2] = 1.5;
			break;
		case Block::L_BIG:
			blockMatrix[1][1][0] = 1;
			blockMatrix[1][0][0] = 1;
			blockMatrix[1][0][1] = 1;
			blockMatrix[1][0][2] = 1;
			blockMatrix[1][0][3] = 1;
			centerPosition[0] = 1;
			centerPosition[1] = 0.5;
			centerPosition[2] = 1.5;
			break;
		case Block::S_BIG:
			blockMatrix[1][0][0] = 1;
			blockMatrix[1][0][1] = 1;
			blockMatrix[1][1][1] = 1;
			blockMatrix[1][2][1] = 1;
			blockMatrix[1][2][2] = 1;
			centerPosition[0] = 1;
			centerPosition[1] = 1;
			centerPosition[2] = 1;
			break;
		case Block::O_BIG:
			blockMatrix[1][0][0] = 1;
			blockMatrix[1][0][1] = 1;
			blockMatrix[1][0][2] = 1;
			blockMatrix[1][1][0] = 1;
			blockMatrix[1][1][1] = 1;
			blockMatrix[1][1][2] = 1;
			blockMatrix[1][2][0] = 1;
			blockMatrix[1][2][1] = 1;
			blockMatrix[1][2][2] = 1;
			centerPosition[0] = 1;
			centerPosition[1] = 1;
			centerPosition[2] = 1;
			break;
		case Block::T_BIG:
			blockMatrix[1][0][0] = 1;
			blockMatrix[1][0][1] = 1;
			blockMatrix[1][1][1] = 1;
			blockMatrix[1][2][1] = 1;
			blockMatrix[1][0][2] = 1;
			centerPosition[0] = 1;
			centerPosition[1] = 1;
			centerPosition[2] = 1;
			break;
		case Block::S_3D:
			blockMatrix[0][0][0] = 1;
			blockMatrix[0][0][1] = 1;
			blockMatrix[0][1][1] = 1;
			blockMatrix[1][1][1] = 1;
			blockMatrix[1][1][2] = 1;
			centerPosition[0] = 0.5;
			centerPosition[1] = 0.5;
			centerPosition[2] = 1;
			break;
		default:
			centerPosition[0] = -0.5;
			centerPosition[1] = -0.5;
			centerPosition[2] = -0.5;
			logger(1, "Undefined block type!");
	}

	weight = 0;
	for(int x=0; x < Block::MAX_SIZE; ++x)
		for(int y=0; y < Block::MAX_SIZE; ++y)
			for(int z=0; z < Block::MAX_SIZE; ++z)
				weight += blockMatrix[z][y][x];
}

void Block::rotate(int xDir, int yDir, int zDir) {
	int oldMatrix[Block::MAX_SIZE][Block::MAX_SIZE][Block::MAX_SIZE];
	float bz = 0, by = 0, bx = 0;
	float az = 0, ay = 0, ax = 0;
	int nz = 0, ny = 0, nx = 0;
	float newCenterPosition[3], buffer;
	
	// Calculate center positions after rotating
	newCenterPosition[0] = centerPosition[0];
	newCenterPosition[1] = centerPosition[1];
	newCenterPosition[2] = centerPosition[2];
	if(xDir != 0) {
						buffer = newCenterPosition[0];
						newCenterPosition[0] = newCenterPosition[1];
						newCenterPosition[1] = buffer;
	}
	if(yDir != 0) {
						buffer = newCenterPosition[2];
						newCenterPosition[2] = newCenterPosition[0];
						newCenterPosition[0] = buffer;
	}
	if(zDir != 0) {
						buffer = newCenterPosition[2];
						newCenterPosition[2] = newCenterPosition[1];
						newCenterPosition[1] = buffer;
	}
	//logger(5, "Rotate. center: (%.1f, %.1f, %.1f) -> (%.1f, %.1f, %.1f)", centerPosition[0], centerPosition[1], centerPosition[2], newCenterPosition[0], newCenterPosition[1], newCenterPosition[2]);

	// Backup current blockMatrix and erase it
	for(int x=0; x < Block::MAX_SIZE; ++x)
		for(int y=0; y < Block::MAX_SIZE; ++y)
			for(int z=0; z < Block::MAX_SIZE; ++z) {
				oldMatrix[z][y][x] = blockMatrix[z][y][x];
				blockMatrix[z][y][x] = 0;
			}
	
	// Travers blocks in oldMatrix: move to centerPosition, rotate, move away from newCenterPosition and save to new blockMatrix
	for(int x=0; x <= centerPosition[2]*2+0.5; ++x) {
		for(int y=0; y <= centerPosition[1]*2+0.5; ++y) {
			for(int z=0; z <= centerPosition[0]*2+0.5; ++z) {
				//if(oldMatrix[z][y][x]) {
					bz = z - centerPosition[0];
					by = y - centerPosition[1];
					bx = x - centerPosition[2];
					if(xDir != 0) {
						ax=bx; ay=by; az=bz;
						bx = ax;
						by = xDir * az;
						bz = -xDir * ay;
					}
					//logger(5, "Rotate: Wzgledne: [%f][%f][%f] -> [%f][%f][%f]\n", az,ay,ax, bz,by,bx);
					if(yDir != 0) {
						ax=bx; ay=by; az=bz;
						bx = -yDir * az;
						by = ay;
						bz = yDir * ax;
					}
					if(zDir != 0) {
						ax=bx; ay=by; az=bz;
						bx = zDir * ay;
						by = -zDir * ax;
						bz = az;
					}
					nz = floor(0.5 + bz + newCenterPosition[0]);
					ny = floor(0.5 + by + newCenterPosition[1]);
					nx = floor(0.5 + bx + newCenterPosition[2]);
					//logger(5, "Rotate: Przekrecam [%i][%i][%i] -> [%i][%i][%i]\n", z,y,x, nz,ny,nx);
					blockMatrix[nz][ny][nx] = oldMatrix[z][y][x];
				//}
			}
		}
	}

	// Save new center position
	centerPosition[0] = newCenterPosition[0];
	centerPosition[1] = newCenterPosition[1];
	centerPosition[2] = newCenterPosition[2];

}

void Block::eraseIntersection(int floorDepth) {
	//logger(5, "floorDepth - posZ = %i\n", floorDepth-posZ);
	for(int y=0; y < Block::MAX_SIZE; ++y)
		for(int x=0; x < Block::MAX_SIZE; ++x) {
			//logger(5, "Erasing at %i,%i,%i\n", floorDepth-posZ,y,x);
			blockMatrix[floorDepth-posZ][y][x] = 0;

			// Check if we should take up bricks under intersection (glue them to top of the block)
			for(int z=floorDepth-posZ+1; z < Block::MAX_SIZE; ++z) {
				//logger(5, "Checking to glue: %i, %i, %i\n", z, y, x);
				if(blockMatrix[z][y][x] == 1) {
					//logger(5, "Glueing from %i to %i at %i,%i\n", z, z-1, y, x);
					blockMatrix[z-1][y][x] = 1;
					blockMatrix[z  ][y][x] = 0;
				}
			}
		}
	
}


BlockModel::BlockModel(Type type, Teges* _engine, int x, int y, int z, const char* texture, const char* bump, const char* normal, bool _invertNormal) : TegesObject(_engine), Model(_engine), Block(type) {
	faceTexture = _engine->getTexturer()->associate(this, new SimpleTrl(texture));
	faceBump    = _engine->getTexturer()->associate(this, new SimpleTrl(bump));
	faceNormal  = _engine->getTexturer()->associate(this, new SimpleTrl(normal));

	posX = x;
	posY = y;
	posZ = z;
	invertNormal = _invertNormal;

	// Compile list to display block model
	displayList = glGenLists(2);
	glNewList(displayList, GL_COMPILE);
		makeQuads(1);
	glEndList();
	glNewList(displayList+1, GL_COMPILE);
		makeQuads(-1);
	glEndList();
}

// TODO: destructor - delete faceTexture
BlockModel::~BlockModel() {
	glDeleteLists(displayList, 2);
	texturer->free(this, faceTexture);
}

void BlockModel::makeQuads(int invertNormal) {
	int s = 1; // texture scaling;
	if(engine->getShadower()->isEnabled()) invertNormal = 1;
	glBegin(GL_QUADS);
		// podstawa
		glNormal3f( 0.0, -1.0 * invertNormal,  0.0);
		glMultiTexCoord3fARB(GL_TEXTURE1_ARB, -1.0f,  0.0f,  0.0f);
		glMultiTexCoord3fARB(GL_TEXTURE2_ARB,  0.0f,  0.0f,  1.0f);
		glTexCoord2i( s,s);	glVertex3f( 1.0,   0.0,  0.0);//*/
		glTexCoord2i( s,0);	glVertex3f( 1.0,   0.0,  1.0);
		glTexCoord2i( 0,0);	glVertex3f( 0.0,   0.0,  1.0);
		glTexCoord2i( 0,s);	glVertex3f( 0.0,   0.0,  0.0);

		// gora
		glNormal3f( 0.0, 1.0 * invertNormal,  0.0);	
		glMultiTexCoord3fARB(GL_TEXTURE1_ARB, -1.0f,  0.0f,  0.0f);
		glMultiTexCoord3fARB(GL_TEXTURE2_ARB,  0.0f,  0.0f, -1.0f);
		glTexCoord2i( 0,0);	glVertex3f( 0.0,  1.0,  0.0);//*/
		glTexCoord2i( 0,s);	glVertex3f( 0.0,  1.0,  1.0);
		glTexCoord2i( s,s);	glVertex3f( 1.0,  1.0,  1.0);
		glTexCoord2i( s,0);	glVertex3f( 1.0,  1.0,  0.0);

		// prawa
		glNormal3f( 1.0 * invertNormal, 0.0,  0.0);
		glMultiTexCoord3fARB(GL_TEXTURE1_ARB,  0.0f,  0.0f,  1.0f);
		glMultiTexCoord3fARB(GL_TEXTURE2_ARB,  0.0f,  1.0f,  0.0f);
		glTexCoord2i( s,s);	glVertex3f( 1.0,  0.0,  0.0);//*/
		glTexCoord2i( s,0);	glVertex3f( 1.0,  1.0,  0.0);
		glTexCoord2i( 0,0);	glVertex3f( 1.0,  1.0,  1.0);
		glTexCoord2i( 0,s);	glVertex3f( 1.0,  0.0,  1.0);

		// lewa
		glNormal3f(-1.0 * invertNormal, 0.0,  0.0);
		glMultiTexCoord3fARB(GL_TEXTURE1_ARB,  0.0f,  0.0f, -1.0f);
		glMultiTexCoord3fARB(GL_TEXTURE2_ARB,  0.0f,  1.0f,  0.0f);
		glTexCoord2i( s,s);	glVertex3f( 0.0,  0.0,  1.0);//*/
		glTexCoord2i( s,0);	glVertex3f( 0.0,  1.0,  1.0);
		glTexCoord2i( 0,0);	glVertex3f( 0.0,  1.0,  0.0);
		glTexCoord2i( 0,s);	glVertex3f( 0.0,  0.0,  0.0);

		// przod
		glNormal3f( 0.0, 0.0,  1.0 * invertNormal);
		glMultiTexCoord3fARB(GL_TEXTURE1_ARB, -1.0f,  0.0f,  0.0f);
		glMultiTexCoord3fARB(GL_TEXTURE2_ARB,  0.0f,  1.0f,  0.0f);
		glTexCoord2i( 0,s);	glVertex3f( 0.0,  0.0,  1.0);//*/
		glTexCoord2i( s,s);	glVertex3f( 1.0,  0.0,  1.0);
		glTexCoord2i( s,0);	glVertex3f( 1.0,  1.0,  1.0);
		glTexCoord2i( 0,0);	glVertex3f( 0.0,  1.0,  1.0);

		// tyl
		glNormal3f( 0.0, 0.0, -1.0 * invertNormal);
		glMultiTexCoord3fARB(GL_TEXTURE1_ARB,  1.0f,  0.0f,  0.0f);
		glMultiTexCoord3fARB(GL_TEXTURE2_ARB,  0.0f,  1.0f,  0.0f);
		glTexCoord2i( s,0);	glVertex3f( 0.0,  1.0,  0.0);//*/
		glTexCoord2i( 0,0);	glVertex3f( 1.0,  1.0,  0.0);
		glTexCoord2i( 0,s);	glVertex3f( 1.0,  0.0,  0.0);
		glTexCoord2i( s,s);	glVertex3f( 0.0,  0.0,  0.0);

	glEnd();
}

void BlockModel::render() {
	glBindTexture(GL_TEXTURE_2D, *faceTexture);
	
	float specReflection[] = { 0.2f, 0.2f, 0.2f, 1.0f };

	// TEXTURE-UNIT #0
	glActiveTextureARB(GL_TEXTURE0_ARB);
	glBindTexture(GL_TEXTURE_2D, *faceTexture);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specReflection);
	glMateriali(GL_FRONT, GL_SHININESS, 64);

	// TEXTURE-UNIT #1
	glActiveTextureARB(GL_TEXTURE1_ARB);
	glBindTexture(GL_TEXTURE_2D, *faceNormal);

	// TEXTURE-UNIT #2
	glActiveTextureARB(GL_TEXTURE2_ARB);
	glBindTexture(GL_TEXTURE_2D, *faceBump);

	GLuint list;
	float* color;
	if(invertNormal) {
		list = displayList +1;
	} else {
		list = displayList;
	}

	glPushMatrix();
		glColor3f(0.8, 0.8, 0.8);
		for(int x=0; x < Block::MAX_SIZE; ++x) {
			for(int y=0; y < Block::MAX_SIZE; ++y) {
				for(int z=0; z < Block::MAX_SIZE; ++z) {
					if(blockMatrix[z][y][x]) {
						glPushMatrix();
							if(!invertNormal) {
								color = getBlockColor(posZ+z);
								glColor3f(color[0], color[1], color[2]);
								delete [] color;
							}
							glTranslatef(posX+x, posY+y, -posZ-z);
							glCallList(list);
						glPopMatrix();
					}
				}
			}
		}
	glPopMatrix();

	glActiveTextureARB(GL_TEXTURE0_ARB);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_EXT);
	glTexEnvf(GL_TEXTURE_ENV, GL_COMBINE_RGB_EXT, GL_MODULATE);

}

void BlockModel::logic() { 
}

float* BlockModel::getBlockColor(int depth) {
	float* v = new float[3];
	v[0] = 0.4; v[1] = 0.4; v[2] = 0.4;
	switch(depth%6) {
		case 0: 
			v[0] = 0.9;
			return v;
		case 1: 
			v[1] = 0.9;
			return v;
		case 2: 
			v[2] = 0.9;
			return v;
		case 3: 
			v[0] = 0.7; v[1] = 0.7;
			return v;
		case 4: 
			v[1] = 0.7; v[2] = 0.7;
			return v;
		case 5: 
			v[0] = 0.7; v[2] = 0.7;
			return v;
		default: 
			v[0] =  0.5; v[1] = 0.5; v[2] = 0.5;
			return v;
	}
}


CurrentBlock::CurrentBlock(BlockModel* _model, PlayGround* _playGround, Teges* _engine) : TegesObject(_engine), Interactive(_engine), Block(_model->getType()), Sounding(_engine->getDJ()) {
	model = _model;
	playGround = _playGround;
	engine = _engine;
	fallSound[0] = _engine->getDJ()->associate(this, new SimpleTrl("fall_tiny.ogg"));
	fallSound[1] = _engine->getDJ()->associate(this, new SimpleTrl("fall_medium.ogg"));
	fallSound[2] = _engine->getDJ()->associate(this, new SimpleTrl("fall_big_i.ogg"));
	fallSound[3] = _engine->getDJ()->associate(this, new SimpleTrl("fall_big.ogg"));
	rotateSound = _engine->getDJ()->associate(this, new SimpleTrl("rotate.ogg"));
	tilt = 0.0;
	lastFall = 0;
	enabled = true;
}

CurrentBlock::~CurrentBlock() {
	for(int i=0; i<4; ++i) dj->free(this, fallSound[i]);
	dj->free(this, rotateSound);
}

void CurrentBlock::performEvent(const SDL_Event& event) {
	logger(0, "Block");
	if(!enabled) return;
	switch(event.type) {
		case  SDL_KEYDOWN:
			switch(event.key.keysym.sym) {

				case SDLK_LEFT:
					model->posX--;
					if(playGround->collision(this)) model->posX++;
					else playGround->update(this);
					break;

				case SDLK_RIGHT:
					model->posX++;
					if(playGround->collision(this)) model->posX--;
					else playGround->update(this);
					break;

				case SDLK_UP:
					model->posY++;
					if(playGround->collision(this)) model->posY--;
					else playGround->update(this);
					break;

				case SDLK_DOWN:
					model->posY--;
					if(playGround->collision(this)) model->posY++;
					else playGround->update(this);
					break;

				case SDLK_SPACE:
					if(tilt <= 0) {
						switch(model->getType()) {
							case DOT:
								play(fallSound[0]); break;
							case I_2D:
							case L_2D:
							case S_2D:
							case O_2D:
							case T_2D:
								play(fallSound[1]); break;
							case I_BIG:
							case L_BIG:
							case S_BIG:
								play(fallSound[2]); break;
							case O_BIG:
								play(fallSound[3]); break;
							default:
								play(fallSound[1]); break;
						}
						while(fallDown());
						//playGround->update(this);
						tilt = 10 + 2 * model->getWeight();
						lastFall = engine->ticks() + 500 - 2000*pow(0.8, playGround->getGame()->getLevel()-1);
					}
					break;

				case SDLK_i:
					rotate(0,0,1);
					if(playGround->collision(this)) rotate(0,0,-1);
					else play(rotateSound);
					playGround->update(this);
					break;
				case SDLK_k:
					rotate(0,0,-1);
					if(playGround->collision(this)) rotate(0,0,1);
					else play(rotateSound);
					playGround->update(this);
					break;
				case SDLK_u:
					rotate(-1,0,0);
					if(playGround->collision(this)) rotate(1,0,0);
					else play(rotateSound);
					playGround->update(this);
					break;
				case SDLK_j:
					rotate(1,0,0);
					if(playGround->collision(this)) rotate(-1,0,0);
					else play(rotateSound);
					playGround->update(this);
					break;
				case SDLK_y:
					rotate(0,-1,0);
					if(playGround->collision(this)) rotate(0,1,0);
					else play(rotateSound);
					playGround->update(this);
					break;
				case SDLK_h:
					rotate(0,1,0);
					if(playGround->collision(this)) rotate(0,-1,0);
					else play(rotateSound);
					playGround->update(this);
					break;
			}
			break;
	}
	
}

void CurrentBlock::setModel(BlockModel* newBlock) {
	model = newBlock;
}

bool CurrentBlock::fallDown() {
	model->posZ++;
	if(playGround->collision(this)) {
		model->posZ--;
		//logger(5, "Stuck at %i\n", model->getZ());
		return false;
	} else {
		//logger(5, "Falled to %i\n", model->getZ());
		playGround->update(this);
		return true;
	}
}

void CurrentBlock::logic() {
	if(!enabled) return;
	if(tilt > 0) {
		engine->view.posZ += 0.01*tilt*sin(tilt);
		tilt--;
	}
	if(tilt > 40) {
		engine->view.posX += 0.01*(tilt-40)*sin(tilt-40);
	}
	if(tilt > 60) {
		engine->view.posY += 0.01*(tilt-60)*sin(tilt-60);
	}

	engine->view.followX = model->posX + centerPosition[0];
	engine->view.followY = model->posY + centerPosition[1];
	engine->view.followZ = -model->posZ + engine->view.radius - centerPosition[2];
}
