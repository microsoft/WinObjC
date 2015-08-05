#include "teges.h"
//#include "stage.h"

#include <math.h>


void Teges::DoLogic() {
	
	// Set new camera position according to current moving states

	if(moveLeft) {
		view.posX -= 0.05 * cos(view.glop*view.imopi); //*cos(heading*imopi);
		view.posZ -= 0.05 * sin(view.glop*view.imopi); //*cos(heading*imopi);
	}
	if(moveRight) {
		view.posX += 0.05 * cos(view.glop*view.imopi); //*cos(heading*imopi);
		view.posZ += 0.05 * sin(view.glop*view.imopi); //*cos(heading*imopi);
	}
	if(moveUp) {
		view.posX += 0.05 * sin(view.glop*view.imopi); //*cos(heading*imopi);
		view.posZ -= 0.05 * cos(view.glop*view.imopi); //*cos(heading*imopi);
	}
	if(moveDown) {
		view.posX -= 0.05 * sin(view.glop*view.imopi); //*cos(heading*imopi);
		view.posZ += 0.05 * cos(view.glop*view.imopi); //*cos(heading*imopi);
	}
	if(flyUp) {
		view.posY += 0.05;
	}
	if(flyDown) {
		view.posY -= 0.05;
	}

	view.logic();
	game->logic();

	// Make logic for all models
	for(ModelList::const_iterator i = models.begin(); i != models.end(); ++i) {
		(*i)->logic();
	}

}


void Teges::DoRender() {

    // Clear buffer and switch to modeling
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	switch(view.mode) {
		case View::FPP:
			gluLookAt(
				view.posX, view.posY, view.posZ,
				view.posX + 10*(sin(view.glop*view.imopi)*cos(view.heading*view.imopi)),
				view.posY - 10*(sin(view.heading*view.imopi)),
				view.posZ - 10*(cos(view.glop*view.imopi)*cos(view.heading*view.imopi)),
				0.0, 1.0, 0.0
			);
			break;
		case View::SPHERE:
		case View::TPP:
			glTranslatef(0.0, 0.0, -view.radius);
			glRotatef(view.glop, 0, 1, 0);
			glRotatef(view.heading, cos(view.imopi*view.glop), 0, sin(view.imopi*view.glop));
			glTranslatef(-view.posX, -view.posY, -view.posZ+view.radius);
			break;
		case View::FOLLOW:
			gluLookAt(
				view.posX, view.posY, view.posZ,
				view.followX, view.followY, view.followZ,
				0.0, 1.0, 0.0
			);
			break;
	}

	// Set lights
	for(int light = 0; light < 8; ++light) {
		glLightfv(GL_LIGHT0 + light, GL_POSITION, lightPositions[light]);
	}

	// Render scene
	//if(stage != NULL) stage->Render();

	if(renderModels) {
		// Render all models
		for(ModelList::const_iterator i = models.begin(); i != models.end(); ++i) {
			(*i)->render();
		}
	}

	if(renderForeFronts) {
		if(shadower->isEnabled()) glUseProgram(0);
		glPushMatrix();
			glLoadIdentity();
			glDisable(GL_DEPTH_TEST);

			// Render all forefronts
			for(WritingList::const_iterator i = writings.begin(); i != writings.end(); ++i) {
				(*i)->renderForefront();
			}

			glEnable(GL_DEPTH_TEST);
		glPopMatrix();
	}

	// Execute commands (wait until everything is rendered) and put frame on display
	glFinish();

	SDL_GL_SwapBuffers();

}


void Teges::DoEvents(const SDL_Event& event) {
	switch(event.type) {

		case SDL_MOUSEMOTION:
			if(!inputEnabled) break;
				if(view.mode == View::FPP) {
					view.glop += (float)event.motion.xrel/5;
					view.heading -= (float)event.motion.yrel/20;
				} else {
					view.glop += (float)event.motion.xrel;
					view.heading -= (float)event.motion.yrel;
				}

			view.bound();
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button) {

				case SDL_BUTTON_LEFT:
					if(!inputEnabled) {
						inputEnabled = true;
						SDL_WM_GrabInput(SDL_GRAB_ON);
						SDL_ShowCursor(SDL_DISABLE);
					} else {
						// normal left button action
					}
					break;

			}

		// Keypressed
		case SDL_KEYDOWN:
			//if(event.key.keysym.sym == SDLK_ESCAPE) running = false;
			if(!inputEnabled) break;
			switch(event.key.keysym.sym) {

				case SDLK_p:
					SDL_WM_ToggleFullScreen(gameDisplay);
					break;
				case SDLK_TAB:
					//if ((SDL_GetModState() & KMOD_ALT) == KMOD_ALT) {
						inputEnabled = false;
						SDL_WM_GrabInput(SDL_GRAB_OFF);
						SDL_ShowCursor(SDL_ENABLE);
					//}
					break;

				case SDLK_q:
					flyUp = true;
					break;
				case SDLK_z:
					flyDown = true;
					break;

				case SDLK_a:
					moveLeft = true;
					break;
				case SDLK_d:
					moveRight = true;
					break;
				case SDLK_w:
					moveUp = true;
					break;
				case SDLK_s:
					moveDown = true;
					break;
				case SDLK_c:
					switch(view.mode) {
						case View::FPP: view.mode = View::SPHERE; break;
						case View::SPHERE: view.mode = View::TPP; break;
						case View::TPP: view.mode = View::FOLLOW; break;
						case View::FOLLOW: view.mode = View::FPP; break;
					}
					break;
				case SDLK_KP_MINUS:
					--view.radius;
					break;
				case SDLK_KP_PLUS:
					++view.radius;
					break;

				default:
					break;

			}
			break;

		case SDL_KEYUP:
			switch(event.key.keysym.sym) {

				case SDLK_q:
					flyUp = false;
					break;
				case SDLK_z:
					flyDown = false;
					break;
				case SDLK_a:
					moveLeft = false;
					break;
				case SDLK_d:
					moveRight = false;
					break;
				case SDLK_w:
					moveUp = false;
					break;
				case SDLK_s:
					moveDown = false;
					break;

			}
			break;

		// Wndow Closed
		case SDL_QUIT:
			running = false;
			break;

		default:
			break;
	}

	// Game events
	game->performEvent(event);

	// Loop all interactives
	//logger(0, "interactive count: %d", interactives.size());
	for(InteractiveList::iterator i = interactives.begin(); i != interactives.end(); ++i) {
		//logger(0, "performEvent for %p", *i);
		(*i)->performEvent(event);
	}
}
