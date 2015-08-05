#include "teges.h"
//#include "stage.h"

void Teges::addModel(Model* model) {
	model->connections++;
	models.push_back(model);
}


void Teges::addInteractive(Interactive* interactive) {
	interactive->connections++;
	interactives.push_back(interactive);
}


void Teges::addWriting(Writing* writing) {
	writing->connections++;
	writings.push_back(writing);
}

/*void Teges::loadStage(const char* resourceDir, const char* sceneDir, const char* sceneFile) {
	stage = new Stage(this);
	if(!stage->Dive(resourceDir, sceneDir, sceneFile)) {
		delete stage;
		stage = NULL;
	} else {
		stage->InitRender();
	}
}*/

void Teges::globalAmbient(float r, float g, float b, float a) {
	GLfloat color[] = {r,g,b,a};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, color);

}


void Teges::setLight(int lightNumber,
	float x, float y, float z, float w,
	float ambR, float ambG, float ambB, float ambA,
	float difR, float difG, float difB, float difA,
	float speR, float speG, float speB, float speA,
	float dirX, float dirY, float dirZ, float dirW
) {
	lightPositions[lightNumber][0] = x;
	lightPositions[lightNumber][1] = y;
	lightPositions[lightNumber][2] = z;
	lightPositions[lightNumber][3] = w;

	float amb[] = { ambR, ambG, ambB, ambA };
	float dif[] = { difR, difG, difB, difA };
	float spe[] = { speR, speG, speB, speA };
	float dir[] = { dirX, dirY, dirZ, dirW };

	GLuint light = GL_LIGHT0 + lightNumber;

	glLightfv(light, GL_AMBIENT, amb);
	glLightfv(light, GL_DIFFUSE, dif);
	glLightfv(light, GL_SPECULAR, spe);
	//glLightfv(light, GL_SPOT_DIRECTION, dir);
	//glLightfv(light, GL_SPOT_DIRECTION, dir);
	//glLightf(light, GL_SPOT_CUTOFF, 180.0f);
	//glLightf(light, GL_SPOT_EXPONENT, 1.00f);

	if(!shadower->isEnabled()) {
		glLightf(light, GL_QUADRATIC_ATTENUATION,  0.5f);
		glLightf(light, GL_LINEAR_ATTENUATION,  0.9f);
	}
}

