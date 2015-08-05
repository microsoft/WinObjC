#ifndef _MODEL_H_
#define _MODEL_H_

#include "texturer.h"
#include "teges_object.h"

#include <vector>

/**
 * The model can be rendered and can have logic. It is also texturable and can be put on the engine models list.
 */
class Model : public Texturable, public virtual TegesObject {
	//static const char className[];
public:
	Model(Teges* _engine);
	virtual void render() { };
	virtual void logic() { };
	//virtual const char* getClass() { return className; }
};

typedef std::vector<Model*> ModelList;

#endif // MODEL_H
