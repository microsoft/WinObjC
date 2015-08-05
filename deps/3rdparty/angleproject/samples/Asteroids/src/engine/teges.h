#ifndef _TEGES_H_
#define _TEGES_H_ 

#include <sys/time.h>

#include "SDL.h"
#include "SDL_opengl.h"

#include "logger.h"
#include "teges_object.h"
#include "texturer.h"
#include "model.h"
#include "interactive.h"
#include "dj.h"
#include "scriber.h"
#include "shadower.h"
#include "objector.h"
//#include "stage.h"
//class Stage;

/**
 * Main engine object.
 * Initialises hardware, loops, renders and lets game objects make their job.
 */
class Teges {

	public:

		/**
		 * Defines interface to let engine talk to game.
		 */
		class Game {
			protected:
				Teges* engine;
			public:
				Game();
				virtual void registerEngine(Teges* _engine);
				virtual Teges* getEngine() { return engine; }
				virtual void logic() = 0;
				virtual void performEvent(const SDL_Event& event) = 0;
		};

		/**
		 * Means of camera position
		 */
		class View {
			public:
				enum modeType { FPP, SPHERE, TPP, FOLLOW };

				enum modeType mode;

				float posX, posY, posZ;
				float dirX, dirY, dirZ;
				float upX, upY, upZ;
				float glop, imopi, heading;
				float radius; // For shperical camera
				float followX, followZ, followY;  // For TPP camera, pos will move to this position in a while
				float fov, near, far;

				View()
					: posX(0), posY(0), posZ(0), glop(0),
					  followX(0), followY(0), followZ(0),
					  heading(0), imopi(3.14/180), mode(FPP), radius(5.0), 
					  fov(70), near(0.2), far(1024) { }

				void set(float x, float y, float z, float _glop, float _heading);
				void bound();
				void logic();
		};
		View view;

	public:
	
		//* Initial parameters *//
		
		bool startFullScreen, inputEnabled, noSound, noLinear, noMipMaps;
		int resWidth, resHeight;
		bool running, renderModels, renderForeFronts;

		//* Engine managing methods *//

		Teges();
		~Teges() { }
		int Init();
		int Execute();
		void CleanUp();
		void registerGame(Game* _game);


		//* Interface for Teges::Game *//

		void addModel(Model* model);
		void addInteractive(Interactive* interactive);
		void addWriting(Writing* writing);
		//void loadStage(const char* resourceDir, const char* sceneDir, const char* sceneFile);
		int removeFromLists(TegesObject* object);
		
		Texturer* getTexturer() { return texturer; }
		DJ* getDJ() { return dj; }
		Scriber* getScriber() { return scriber; }
		Shadower* getShadower() { return shadower; }
		Objector* getObjector() { return objector; }

		inline long ticks() {
			timeval time;
			gettimeofday(&time,NULL);
			return 1000*(time.tv_sec%1000) + time.tv_usec/1000;
		}

		void setLight(int lightNumber,
			float x, float y, float z, float w,
			float ambR, float ambG, float ambB, float ambA,
			float difR, float difG, float difB, float difA,
			float speR, float speG, float speB, float speA,
			float dirX, float dirY, float dirZ, float dirW
		);

		void globalAmbient(float r, float g, float b, float a);

		//* For Scriber *//

		float getZNear() { return view.near; }

	protected:

		void DoEvents(const SDL_Event& event);
		void DoLogic();
		void DoRender();

#ifdef WIN32
		int gettimeofday(struct timeval *tp, void *tzp);
#endif

		// Composite objects
		SDL_Surface* gameDisplay;
		Game*        game;
		Texturer*    texturer;
		DJ*          dj;
		Scriber*     scriber;
		Shadower*    shadower;
		Objector*    objector;
		//Stage*       stage;

		// Game Objects Lists
		ModelList models;
		InteractiveList interactives;
		WritingList writings;

		// Lights
		float lightPositions[8][4];

		// Steering flags
		bool moveLeft, moveRight,
		     moveUp, moveDown,
		     flyUp, flyDown;

		// Timing
		int fps, maxFps, dropFrame;

};

#endif
