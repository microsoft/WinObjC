#ifndef _INTERACTIVE_H_
#define _INTERACTIVE_H_ 

#include "teges_object.h"

#include "SDL.h"
#include <vector>

class Interactive : public virtual TegesObject {
		//static const char className[]; // debug, should be cleaned in release
	public:
		Interactive(Teges* _engine);
		virtual ~Interactive() { }
		virtual void performEvent(const SDL_Event& event) = 0;
		//virtual const char* getClass() { return className; }
};

typedef std::vector<Interactive*> InteractiveList;

#endif
