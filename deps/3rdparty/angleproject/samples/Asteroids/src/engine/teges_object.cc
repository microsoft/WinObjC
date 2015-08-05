#include "teges_object.h"
#include "teges.h"

TegesObject::~TegesObject() {
	if(connections > 0 && engine->running)
		if(connections != engine->removeFromLists(this))
		logger(-1, "%p: Unconsistency with engine connections!", this);
}
