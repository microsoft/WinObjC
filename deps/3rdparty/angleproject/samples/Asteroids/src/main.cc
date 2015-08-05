#ifndef WIN32
#include "../config.h"
#endif
#include "engine/teges.h"
#include "game/tegris.h"

#include <stdio.h>
#include <getopt.h>

int main(int argc, char* argv[]) {
	Teges teges;
	Tegris tegris;
	teges.registerGame(&tegris);

	teges.startFullScreen = false;
	teges.resWidth = 800;
	teges.resHeight = 600;

#ifndef WIN32
	// BEGIN Getopt
	int index;
	int c;

	opterr = 0;

	while((c = getopt(argc, argv, "hfnlmx:y:")) != -1) {
		switch(c) {
			case 'f':
				teges.startFullScreen = true;
				break;
			case 'x':
				teges.resWidth = atoi(optarg);
				break;
			case 'y':
				teges.resHeight = atoi(optarg);
				break;
			case 'n':
				teges.noSound = true;
				break;
			case 'l':
				teges.noLinear = true;
				break;
			case 'm':
				teges.noMipMaps = true;
				break;
			case 'h':
				printf("%s [-f] [-n] [-x <width>] [-y <height>] [-m] [-l]\n"
					"-f           - start fullscreen\n"
					"-n           - no sound\n"
					"-x <width>   - width of resolution in pixels\n"
					"-y <height>  - height of resolution in pixels\n"
					"-m           - no mipmaps\n"
					"-l           - no linear filtering\n",
					argv[0]);
				exit(0);
			case '?':
				if(optopt == 'c')
					fprintf(stderr, "Option -%c requires an argument.\n", optopt);
				else if(isprint (optopt))
					fprintf(stderr, "Unknown option `-%c'.\n", optopt);
				else
					fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
				return 1;
			default:
				abort();
		}
	}

	for (index = optind; index < argc; index++)
		printf ("Non-option argument %s\n", argv[index]);

	// END Getopt	
#endif

	if(teges.Init() == false) {
		return -1;
	}

	int ret = teges.Execute();

    teges.CleanUp();

	return ret;
}

