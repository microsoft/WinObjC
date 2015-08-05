#ifndef _MENU_H_
#define _MENU_H_

#include "../engine/teges.h"
#include "block.h"

#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <vector>
#include <string>

class Tegris;

class TegrisMenu : public Sounding, public Writing, public Interactive {
	public:
		class Item;
		typedef std::vector<Item> ItemList;
		class Item {
			public:
				ItemList subMenu;
				std::string label;
				void (Tegris::*gameAction)();
				void (TegrisMenu::*menuAction)();

				Item(std::string _label, void (Tegris::*_gameAction)(void), void (TegrisMenu::*_menuAction)(void) = NULL);
		};

	private:
		TTF_Font *titleFont;
		TTF_Font *menuFont;
		TTF_Font *keysFont;
		BlockModel* block;

	protected:
		Mix_Chunk* changeSound;
		Mix_Chunk* selectSound;

		ItemList items;
		ItemList::iterator selection;

		void populate();
		ItemList getCurrentItemSet();
		int getSelection();

		Tegris* game;

	public:
		TegrisMenu(Tegris* _game);
		~TegrisMenu();
		void performEvent(const SDL_Event& event);
		//void render() { };
		void renderForefront();
		bool enabled;
		bool keys;  // are we showing keys information
		bool gameover;
		void showKeys() { keys = true; }
};

#endif
