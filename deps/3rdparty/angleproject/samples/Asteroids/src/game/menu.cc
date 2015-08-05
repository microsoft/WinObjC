#include "menu.h"
#include "tegris.h"

#include <math.h>

void TegrisMenu::populate() {
	items.push_back(Item("Start", &Tegris::startNewGame));
	items.push_back(Item("Keys", NULL, &TegrisMenu::showKeys));
	items.push_back(Item("Exit", &Tegris::exitGame));
}

TegrisMenu::Item::Item(std::string _label, void (Tegris::*_action)(void), void (TegrisMenu::*_menuAction)(void)) {
	subMenu.clear();
	label = _label;
	gameAction = _action;
	menuAction = _menuAction;
}

TegrisMenu::TegrisMenu(Tegris* _game) : Sounding(_game->getEngine()->getDJ()), Writing(_game->getEngine()), Interactive(_game->getEngine()), TegesObject(_game->getEngine()) {
	game = _game;
	titleFont = _game->getEngine()->getScriber()->associate(this, new FontTrl("vera.ttf", 64));
	menuFont = _game->getEngine()->getScriber()->associate(this, new FontTrl("vera.ttf", 24));
	keysFont = _game->getEngine()->getScriber()->associate(this, new FontTrl("vera.ttf", 14));
	populate();
	selection = items.begin();
	enabled = true;
	keys = gameover = false;
	int j=(int)Block::I_2D + (int) (((float)Block::T_2D) * rand()/(RAND_MAX+1.0));
	block = new BlockModel(Block::Type(j), engine, 0, 0, 0, "metal.jpg", "metal_bump.jpg", "metal_normal.jpg", false);
}

TegrisMenu::~TegrisMenu() { }

void TegrisMenu::renderForefront() {
	if(!enabled) return;
	if(gameover) {
		int color[3] = { 255, 128, 0 };
		write(menuFont, "- Game Over -", -8.5, 0, color);
		write(keysFont, "Press any key", -4.5, 5, color);
	} else if(keys) {
		int color[3] = { 255, 128, 0 };
		write(titleFont, "- TEGRIS -", -16.0, -5, color);

		color[2] = 255;
		color[1] = 255;
		write(keysFont, "ESC",     -14, -2  , color);	write(keysFont, "Pause/Menu",                    -6, -2  , color);
		write(keysFont, "Alt+TAB", -14,  0  , color);	write(keysFont, "Release mouse",                 -6,  0  , color);

		write(keysFont, "Arrows",  -14,  2  , color);	write(keysFont, "Move block",                    -6,  2  , color);
		write(keysFont, "Y,H",     -14,  3.5, color);	write(keysFont, "Rotate around vertical axis",   -6,  3.5, color);
		write(keysFont, "U,J",     -14,  5  , color);	write(keysFont, "Rotate around horizontal axis", -6,  5  , color);
		write(keysFont, "I,K",     -14,  6.5, color);	write(keysFont, "Rotate around depth axis",      -6,  6.5, color);
		
		write(keysFont, "Space",   -14,  8.5, color);	write(keysFont, "Drop block",                    -6,  8.5, color);
		
		write(keysFont, "W,S,A,D", -14, 10.5, color);	write(keysFont, "Move camera FPP-style",         -6, 10.5, color);
		write(keysFont, "Q,Z",     -14, 12  , color);	write(keysFont, "Move camera up/down",           -6, 12  , color);
	} else {
		int color[3] = { 255, 128, 0 };
		write(titleFont, "- TEGRIS -", -16.0, -5, color);

		int j = 0;
		ItemList::iterator i;
		for(i = items.begin(); i != items.end(); ++i) {
			if(selection == i) {
				//write(menuFont, "->", -7.5, -2 + j*3, color);
				glPushMatrix();
					glEnable(GL_DEPTH_TEST);
					float depth = -(engine->getZNear() + engine->getZNear() * 0.2);
					glTranslatef(-0.09, 0.045-(float)j/28, depth-0.005);
					glRotatef((float)(engine->ticks()%1440)/4, -1.0, 0.0, 0.0);
					glTranslatef(0.0, -0.015, 0.005);
					glScalef(0.01, 0.01, 0.01);
					block->render();
					glDisable(GL_DEPTH_TEST);
				glPopMatrix();
			}
			write(menuFont, i->label.c_str(), -4, -2 + j*3, color);
			++j;
		};

	}
}

void TegrisMenu::performEvent(const SDL_Event& event) {
	logger(0, "menu");
	if(!enabled) return;
	switch(event.type) {
		case SDL_KEYDOWN:
			if(keys || gameover) {
				keys = false;
				gameover = false;
			} else switch(event.key.keysym.sym) {

				case SDLK_UP:
					if(selection == items.begin()) selection = items.end();
					--selection;
					break;

				case SDLK_DOWN:
					if((++selection) == items.end()) selection = items.begin();
					break;

				case SDLK_RETURN:
					if(selection->gameAction != NULL)
						(game->*selection->gameAction)();
					else if(selection->menuAction != NULL)
						(this->*selection->menuAction)();
					break;
			}
	}
};
