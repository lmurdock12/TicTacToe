#include "SDL.h"
#include "Game.h"
//test
Game *game = nullptr;
int main(int argc, char*argv[]) {

	//Capping frame rate:
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;


	game = new Game();
	game->init("Tic Tac Toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, false); //Initialize the game
	while (game->running()) { //while isRunning = True, run the game loop


		frameStart = SDL_GetTicks();


		game->handleEvents(); //look for any keyboard events
		game->update(); //update objects
		game->render(); //render the new screen

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean(); //if game done running then clean everything.

	return 0;

}