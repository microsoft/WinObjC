#ifndef _TEGRIS_H_
#define _TEGRIS_H_ 

#include "../engine/teges.h"
#include "menu.h"
#include "osd.h"

//using namespace std;

class Tegris : public Teges::Game {
	public:
		enum State {
			UNSTABLE, INIT, SPLASH, MENU, QUIT,
			GAME_START, GAME_RUN, GAME_OVER
		};

	private:
		State state;

		TegrisMenu* menu;
		TegrisOsd* osd;
		PlayGround* playGround;
		CurrentBlock* currentBlock;
		int lastFall, lastFullFloors, floorDelay;
		int level, score;
		bool nextBlock;

	protected:
		void drawNextBlock();

	public:
		Tegris();
		void startNewGame() { state = GAME_START; }
		void exitGame() { state = QUIT; }
		void logic();
		void performEvent(const SDL_Event& event);
		void fullFloorState(int numberOfErased);
		int getLevel() { return level; }
		int getScore() { return score; }
};

#endif
