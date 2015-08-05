#include "osd.h"
#include "tegris.h"

//#include <math.h>

TegrisOsd::TegrisOsd(Tegris* _game) : Writing(_game->getEngine()), TegesObject(_game->getEngine()) {
	game = _game;
	osdFont = _game->getEngine()->getScriber()->associate(this, new FontTrl("vera.ttf", 14));
}

TegrisOsd::~TegrisOsd() { }

void TegrisOsd::renderForefront() {
	if(!enabled) return;
	int color[3] = { 255, 128, 0 };
	char str[64];

	sprintf(str, "Level: %d", game->getLevel());
	write(osdFont, str, 10.0, 11, color);
	
	sprintf(str, "Score: %d", game->getScore());
	write(osdFont, str, 10.0, 12, color);

}
