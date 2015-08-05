#include "model.h"
#include "teges.h"

Model::Model(Teges* _engine) : TegesObject(_engine), Texturable(_engine->getTexturer()) { }

