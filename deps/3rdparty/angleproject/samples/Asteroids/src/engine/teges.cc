#include "teges.h"

#include <stdio.h>
#include <time.h>
#include <unistd.h>

//#include "stage.h"

#ifdef WIN32
#include <sys/timeb.h>
#define usleep(t) Sleep((t) / 1000)
#endif

// debug, should be cleaned in release
//const char TegesObject::className[] = "TegesObject";
//const char Model::className[] = "Model";
//const char Interactive::className[] = "Interactive";
//const char Writing::className[] = "Writing";
//const char Shadering::className[] = "Shadering";
//const char Stage::className[] = "Stage";
// /debug

Logger logger;

Teges::Teges() {
	logger.level = 5;

	running = renderModels = renderForeFronts = noSound = noLinear = noMipMaps = inputEnabled = moveLeft = moveRight = moveUp = moveDown = flyUp = flyDown = false;
	
	game = NULL;
	gameDisplay = NULL;
	texturer = NULL;
	dj = NULL;
	scriber = NULL;
	shadower = NULL;
	objector = NULL;
	//stage = NULL;
	
	fps = 10;
	maxFps = 60;
	dropFrame = 0;
	
	for(int x=0; x<8; ++x) 
		for(int y=0; y<4; ++y)
			lightPositions[x][y] = 0.0;

	srand( (unsigned)time( NULL ) );
}


int Teges::Init() {

	//****  SDL video configuration  ****//
	Uint32 flags = SDL_INIT_VIDEO;

	logger(1, "Starting SDL subsystems... flags: %i", flags);

	//if(!noSound) flags |= SDL_INIT_AUDIO;
	
	if(SDL_Init(flags) < 0) {
		logger(-1, "Can't initialize SDL: %s", SDL_GetError());
		exit(1);
	}

	// Get the video properties of running environment
	const SDL_VideoInfo* vidinfo = SDL_GetVideoInfo();
	if(!vidinfo)
	{
		logger(-1,"Can't get video information: %s", SDL_GetError());
		exit(1);
	}

	logger(2, "Current bits per pixel: %i", vidinfo->vfmt->BitsPerPixel);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,  16);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,     5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,   5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,    5);

	logger(1, "Opening video buffer...");
	flags = SDL_OPENGL;
	if(startFullScreen) flags = flags | SDL_FULLSCREEN;
	gameDisplay = SDL_SetVideoMode(resWidth, resHeight, vidinfo->vfmt->BitsPerPixel, flags);
	if(!gameDisplay) {
		logger(-1, "Can't set video mode: %s", SDL_GetError());
		exit(1);
	}


	//****  Global OpenGL parameters  ****//


	logger(2, "Setting up OpenGL parameters...");
	logger(3, "GL_Version: %s", glGetString(GL_VERSION));
	//logger(4, "GL_Extens.: %s", glGetString(GL_EXTENSIONS));
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_BLEND);

	//****  Set lights  ****//

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1); // TODO: dynamic
	glEnable(GL_LIGHTING);

	
	//****  Camera!... :] ****//

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(view.fov, (float)resWidth/resHeight, view.near, view.far);


	//****  Managers initialization  ****//

	logger(1, "Starting texturing system...");
	texturer = new Texturer("res", noLinear, noMipMaps); // res - resource directory

	if(noSound) {
		dj = new DJ("", false);
	} else {
		logger(1, "Starting sound system...");
		dj = new DJ("res"); // resources directory
	}

	logger(1, "Starting font system...");
	scriber = new Scriber(gameDisplay, "res");

	const GLubyte* gl_version = glGetString(GL_VERSION);
	if(gl_version[0] < '2') {
		logger(0, "Shaders disabled (OpenGL 2.0 required)");
		shadower = new Shadower("", false);
		glShadeModel(GL_SMOOTH);
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
		glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
	} else {
		logger(1, "Starting shader manager...");
		shadower = new Shadower("res");
	}

	logger(1, "Starting OBJ loader...");
	objector = new Objector("res");

	//****  Game initialisation  ****//

	if(game == NULL) {
		logger(-1, "ERROR: Engine without game implementation!");
	} else {
		game->logic();   // Let the game pass through the init state
	}

	// Grab input if everything is cool
	//if(startFullScreen) {
		//inputEnabled = true;
		SDL_ShowCursor(SDL_DISABLE);
		SDL_WM_GrabInput(SDL_GRAB_ON);
	//}

	logger(1, "Initialising complete.");
	return true;

}



int Teges::Execute() {

	SDL_Event event;

	long ticksStart, ticksStop, passed;

	running = renderModels = renderForeFronts = true;

	while(running) {
		ticksStart = ticks();
		while(SDL_PollEvent(&event)) {
			DoEvents(event);
		}
		DoLogic();
		if(dropFrame == 0) {
			DoRender();
			ticksStop = ticks();
			passed = ticksStop - ticksStart;
			if(passed < 0) passed = (float)1000/fps;
			//logger(4, "Loop taked %li miliseconds, %i fps needs at most %i ms\n", passed, fps, 1000/fps);
			if((float)passed > (float)1000/fps) {
				--fps;
				logger(3, "Dropping %3i frames. New FPS = %i", passed * fps / 1000, fps);
				dropFrame = passed * fps / 1000;
			} else {
				//logger(4, "Waiting %.2f ms to make next loop\n", (float)1000/fps - passed);
				// TODO: Win32 version
				if(fps < maxFps && (float)passed < (float)1000/(fps+fps/10)) {
					while(fps < maxFps && (float)passed < (float)1000/(fps+fps/10)) ++fps;
					logger(3, "Rendering hastes.    New FPS = %i", fps);
				}
				usleep(1000*((float)1000/fps - passed));
			}
		} else {
			dropFrame--;
		}
	}


    return 0;

}



void Teges::CleanUp() {
	game = NULL;

	logger(2, "Deleting interactives...");
	for(InteractiveList::iterator i = interactives.begin(); i != interactives.end(); ++i) {
		if((*i)->connections == 1) {
			//logger(3, "Deleting %p - %s", *i, (*i)->getClass());
			logger(3, "Deleting %p", *i);
			delete *i;
			*i = NULL;
		} else {
			//logger(4, "Ommiting %p - %s", *i, (*i)->getClass());
			logger(4, "Ommiting %p", *i);
			(*i)->connections--;
		}
	}

	logger(2, "Deleting writings...");
	for(WritingList::iterator w = writings.begin(); w != writings.end(); ++w) {
		if((*w)->connections == 1) {
			//logger(3, "Deleting %p - %s", *w, (*w)->getClass());
			logger(3, "Deleting %p", *w);
			delete *w;
			*w = NULL;
		} else {
			//logger(4, "Ommiting %p - %s", *i, (*i)->getClass());
			logger(4, "Ommiting %p", *w);
			(*w)->connections--;
		}
	}

	logger(2, "Deleting models...");
	for(ModelList::iterator m = models.begin(); m != models.end(); ++m) {
		if((*m)->connections == 1) {
			//logger(3, "Deleting %p - %s", *m, (*m)->getClass());
			logger(3, "Deleting %p", *m);
			delete *m;
			*m = NULL;
		} else {
			//logger(4, "Ommiting %p - %s", *m, (*m)->getClass());
			logger(4, "Ommiting %p - %s", *m);
			(*m)->connections--;
		}
	}

	logger(2, "Closing font system...");
	delete scriber;
	scriber = NULL;

	logger(2, "Closing audio...");
	delete dj;
	dj = NULL;

	logger(2, "Closing texturing system...");
	delete texturer;
	texturer = NULL;

	logger(1, "Closing video...");
	SDL_FreeSurface(gameDisplay);

	logger(1, "Closing SDL...");
	SDL_Quit();
}

int Teges::removeFromLists(TegesObject* object) {
	int removeCount = 0;
	for(InteractiveList::iterator i = interactives.begin(); i != interactives.end(); ++i) {
		if(*i == object) {
			logger(3, "Removing %p from interactives list", *i);
			interactives.erase(i);
			--object->connections;
			++removeCount;
			break;
		}
	}

	for(WritingList::iterator w = writings.begin(); w != writings.end(); ++w) {
		if(*w == object) {
			logger(3, "Removing %p from writings list", *w);
			writings.erase(w);
			--object->connections;
			++removeCount;
			break;
		}
	}

	for(ModelList::iterator m = models.begin(); m != models.end(); ++m) {
		if(*m == object) {
			logger(3, "Removing %p from writings list", *m);
			models.erase(m);
			--object->connections;
			++removeCount;
			break;
		}
	}
	return removeCount;
}

void Teges::registerGame(Game* _game) {
	if(game == NULL) {
		game = _game;
		_game->registerEngine(this);
	}
	else logger(-1, "Game already registered!");
}


//* Teges::Game *//

Teges::Game::Game() {
	engine = NULL;
}


void Teges::Game::registerEngine(Teges* _engine) {
	if(engine == NULL) engine = _engine;
	else logger(-1, "Engine already registered!");
}


void Teges::View::set(float x, float y, float z, float _glop, float _heading) {
	posX = x;
	posY = y;
	posZ = z;
	glop = _glop;
	heading = _heading;
}


void Teges::View::bound() {
	if(heading < -90) heading = -90;
	if(heading > 90) heading = 90;

	if(glop < 0) glop += 360;
	if(glop >= 360) glop -= 360;

	if(radius < 1) radius = 1;
	if(radius > 50) radius = 50;
}

void Teges::View::logic() {
	if(mode == TPP) {
		if(posX < followX) posX += (followX-posX)/10;
		if(posX > followX) posX -= (posX-followX)/10;
		if(posY < followY) posY += (followY-posY)/10;
		if(posY > followY) posY -= (posY-followY)/10;
		if(posZ < followZ) posZ += (followZ-posZ)/10;
		if(posZ > followZ) posZ -= (posZ-followZ)/10;
	}
}

#ifdef WIN32
int Teges::gettimeofday(struct timeval *tp, void *tzp)
{
    struct _timeb timebuffer;
    
    _ftime(&timebuffer);
    tp->tv_sec = timebuffer.time;
    tp->tv_usec = timebuffer.millitm * 1000;
    
    return 0;
}
#endif
