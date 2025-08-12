#include <iostream>
#include <string>
#include <SDL/SDL.h>

using namespace std;

int main(int argc, char *argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf( stderr, "Could not initialise SDL: %s\n", SDL_GetError() );
        exit( -1 );
	}
	
	if( !SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE){
        fprintf( stderr, "Could not set video mode: %s\n", SDL_GetError() );
        SDL_Quit();
        exit( -1 );
    }
    
    SDL_EnableUNICODE( 1 );
	
	char test_string[] = "This is a test String for you to type.";
	int unicodes[sizeof(test_string)/sizeof(char)] = {};
	
	for(int i = 0; i < (sizeof(test_string)/sizeof(char)) - 1; i++) {
		unicodes[i] = test_string[i];
		cout << "The unicode of the symbol " << test_string[i] << " is " << unicodes[i] << endl;
	}
	
	SDL_Event event;
	string user_input = "";
	cout << "Press ESC to exit." <<endl;
	
	int index = 0;
	bool quit = false;
	int mistakes = 0;
	while (!quit && index < sizeof(test_string) / sizeof(char) - 1) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;	
			}
			
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
				quit = true;
			}
			
			if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                    if (!user_input.empty()) {
                        char last_char = user_input.back();
                        user_input.pop_back();
                        index--;
                        if (last_char != test_string[index]) {
                            mistakes--;
                        }
                    }
                } else {
                    int user_unicode = event.key.keysym.unicode;

                    if (user_unicode == unicodes[index]) {
                        user_input += (char)user_unicode;
                    } else {
                        user_input += (char)user_unicode;
                        mistakes++;
                    }

                    index++;
				}
			}
		}
	}
	
	cout<<"Your input was: "<<user_input<<endl<<"Mistakes: "<<mistakes<<endl;
	return 0;
}