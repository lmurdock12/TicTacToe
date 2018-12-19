#pragma once
#include "SDL.h"
#include "SDL_image.h"
class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	
	void reset(); //Reset the game board
	void setCell(int ID, int Type); //Set the cell to a different symbol


	bool running() { return isRunning; }

private:
	int Grid[9];
	enum {
		GRID_TYPE_NONE = 0,
		GRID_TYPE_X,
		GRID_TYPE_O
	};

	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;

};

