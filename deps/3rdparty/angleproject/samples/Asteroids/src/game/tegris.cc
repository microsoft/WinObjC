#include "tegris.h"

#include "playground.h"

#include <math.h>
#define logc(c,x) (log(x)/log(c))

using namespace std;

Tegris::Tegris() : Teges::Game() {
	state = INIT;
	lastFall = lastFullFloors = floorDelay = 0;
	nextBlock = false;
	playGround = NULL;
	currentBlock = NULL;
	menu = NULL;
	osd = NULL;
	level = 1;
}

void Tegris::logic() {
	switch(state) {
		case INIT:

			//engine->globalAmbient(1.0, 1.0, 1.0, 1.0);
			engine->globalAmbient(0.4, 0.4, 0.4, 1.0);

			engine->setLight(0,
				3.5, 2.5, 0.0, 1.0, // position
				0.6, 0.6, 0.6, 1.0, // ambient
				2.0, 2.0, 2.0, 1.0, // diffuse
				0.0, 0.0, 0.0, 0.0, // specular
				1.0, 1.0, 1.0, 0.0  // direction
			);

			logger(2, "DJ : %p", getEngine()->getDJ());
			logger(2, "Tex: %p", getEngine()->getTexturer());
			logger(2, "Scr: %p", getEngine()->getScriber());
			playGround = NULL;
			currentBlock = NULL;
			osd = new TegrisOsd(this);
			osd->enabled = false;
			state = SPLASH;
			break;
		case SPLASH:
			getEngine()->getDJ()->setMusic("salad_menu.ogg");
			state = MENU;
			break;
		case MENU:
			if(menu == NULL) {
				menu = new TegrisMenu(this);
				engine->addWriting(menu);
				engine->addInteractive(menu);
			}
			break;
		case GAME_START:
			logger(4, "new PlayGround\n");
			if(playGround != NULL) delete playGround;
			engine->view.set(3.5, 2.5, 4, 0, 0);
			engine->view.mode = Teges::View::FPP;
			engine->renderModels = true;
			playGround = new PlayGround(this, 7, 5, 15, "brick.jpg", "brick_bump.jpg", "brick_normal.jpg", "rustedpanels.jpg", "rustedpanels_bump.jpg", "rustedpanels_normal.jpg");
			//playGround = new PlayGround(this, 7, 5, 15, "bricks7.jpg", "stone_floor.jpg");
			engine->addModel(playGround);

			{
				int j=(int)Block::DOT + (int) (((float)Block::S_3D-1) * rand()/(RAND_MAX+1.0));
				if(currentBlock != NULL) delete currentBlock;
				BlockModel* currentBlockModel;
				//if((int) (2 * rand()/(RAND_MAX+1.0))) {
					currentBlockModel = new BlockModel(Block::Type(j), engine, 1.0, 1.0, 0, "metal.jpg", "metal_bump.jpg", "metal_normal.jpg", 1);
				//} else {
				//	currentBlockModel = new BlockModel(Block::Type(j), engine, 1.0, 1.0, 0, "stone_floor.jpg", 1);
				//}
				playGround->addBlock(currentBlockModel);
				engine->addModel(currentBlockModel);
				currentBlock = new CurrentBlock(currentBlockModel, playGround, engine); //with inverted normal
			}

			logger(4, "CurrentBlock ptr: %p (%p), as Interactive: %p\n", currentBlock, currentBlock->getId(), (Interactive*) currentBlock);
			engine->addInteractive(currentBlock);

			engine->inputEnabled = true;
			engine->getDJ()->setMusic("test.ogg");
			menu->enabled = false;
			level = 1;
			score = 0;
			osd->enabled = true;
			engine->addWriting(osd);
			state = GAME_RUN;
			break;
		case GAME_RUN:
			if(floorDelay == 1) {
				drawNextBlock();
			} else if((floorDelay == 0) && (engine->ticks() - currentBlock->lastFall > 2000.0*pow(0.8+level/30, level-1))) {
				if(currentBlock->fallDown()) {
					currentBlock->lastFall = engine->ticks();
					if(nextBlock) nextBlock = false;
				} else if(!nextBlock) {
					currentBlock->lastFall = engine->ticks() + 500 - 2000*pow(0.8, level-1);
					playGround->checkFloors();
					nextBlock = true;
				} else {
					drawNextBlock();
				}
			}

			currentBlock->logic();

			{
				int sumx=0, sumy=0, sumz=0, q=0;
				for(int z=0; z<Block::MAX_SIZE; ++z) {
					for(int y=0; y<Block::MAX_SIZE; ++y) {
						for(int x=0; x<Block::MAX_SIZE; ++x) {
							if(currentBlock->matrixZYX(z,y,x)) {
								sumx+=x;
								sumy+=y;
								sumz+=z;
								++q;
							}
						}
					}
				}
				if(q)
					engine->setLight(1,
						currentBlock->getX()+sumx/q+0.5, currentBlock->getY()+sumy/q+0.5, -currentBlock->getZ()-sumz/q+0.5, 1.0, // position
						0.2, 0.2, 0.2, 0.1, // ambient
						1.0, 1.0, 1.0, 0.1, // diffuse
						0.8, 0.8, 0.8, 0.1, // specular
						0.0, 0.0, 0.0, 0.0  // direction
					);
				else {
					//playGround->checkFloors();
					//nextBlock = true;
				}
			}
			if(floorDelay != 0) {
				if(floorDelay == 10) {
					floorDelay--;
					currentBlock->tilt = 30 + (30 * lastFullFloors); 
					score += 20 * lastFullFloors * lastFullFloors;
					level = score/100 + 1;
					logger(4, "eraseFloors");
					playGround->eraseFloors();
				} else floorDelay--;
			}
			break;
		case GAME_OVER:
			// TODO: some text
			menu->enabled = true;
			menu->gameover = true;
			osd->enabled = false;
			engine->renderModels = false;
			currentBlock->enabled = false;
			state = MENU;
			break;
		case QUIT:
			engine->running = false;
			break;
		case UNSTABLE:
		default:
			logger(-1, "Error: Game ran into undefined state. Are You Neo?");
			exit(1);
	}
}

void Tegris::fullFloorState(int numberOfErased) {
	lastFullFloors = numberOfErased;
	floorDelay = 30;
}

void Tegris::drawNextBlock() {
	//if(engine->ticks() - currentBlock->lastFall < 2000.0*pow(0.8+level/30, level-1)) return;
	score += currentBlock->getWeight();
	nextBlock = false;
	int j=(int)Block::DOT + (int) (((float)Block::S_3D-1) * rand()/(RAND_MAX+1.0));
	logger(4, "random: %i", j);
	BlockModel* newBlock;
	if(j % 2) {
		newBlock = new BlockModel(Block::Type(j), engine, 1.0, 1.0, 0, "metal.jpg", "metal_bump.jpg", "metal_normal.jpg", true);
	} else {
		newBlock = new BlockModel(Block::Type(j), engine, 1.0, 1.0, 0, "truss.jpg", "truss_bump.jpg", "truss_normal.jpg", true);
	}
	if(playGround->collision(newBlock)) state = GAME_OVER;
	engine->addModel(newBlock);
	playGround->addBlock(newBlock);
	currentBlock->getModel()->invertNormal = false;
	currentBlock->setModel(newBlock);
}

void Tegris::performEvent(const SDL_Event& event) {
	logger(0, "game");
	switch(event.type) {
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym) {

				case SDLK_ESCAPE:
					if(menu->enabled && playGround != NULL) {
						menu->enabled = false;
						osd->enabled = true;
						engine->renderModels = true;
						currentBlock->enabled = true;
						state = GAME_RUN;
					}
					else if(!menu->enabled) {
						menu->enabled = true;
						osd->enabled = false;
						engine->renderModels = false;
						currentBlock->enabled = false;
						state = MENU;
					}
					break;
				case SDLK_m: ++level; break;
				case SDLK_n: --level; break;
			}
	}
};
