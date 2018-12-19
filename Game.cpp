#include "Game.h"
#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"

GameObject* board;
GameObject* x;
GameObject* o;

Game::Game()
{
}


Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	
	int flags = 0;//init the unit32 flag
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN; //if fullscreen is true set the flag to fullscreen
	}
	//Checks to see is SDL library is initialized successfully and prints statement
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) { //If Init() == 0; that means success.
		std::cout << "Subsystems Initialized!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) { //if window is true then it has been successfully created
			std::cout << "Window created!" << std::endl;
		}
	
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 244, 244, 24);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true; //if init works successfully then continue to run
	}
	else {
		isRunning = false; //stop the game if it does not initialize 
	}

	board = new GameObject("assets/grid.png", renderer,0,0,600,600);
	o = new GameObject("assets/o.png", renderer,200,400,200,200);
	x = new GameObject("assets/x.png", renderer,0,400,200,200);
}

void Game::handleEvents() {
	SDL_Event event; //look for the event
	SDL_PollEvent(&event); //get the event

	switch (event.type) {
		case SDL_QUIT://if the X is pressed then end the game
			isRunning = false;
			break;

		default:
			break;

	}


}

void Game::update() {
	board->Update();


}

void Game::reset() {
	for (int i = 0; i < 9; i++) {
		Grid[i] = GRID_TYPE_NONE;
	}

}

void Game::setCell(int ID, int Type) {
	if (ID < 0 || ID >= 9) return;
	if (Type<0 || Type > GRID_TYPE_O) return;

	Grid[ID] = Type;

}

void Game::render() {
	SDL_RenderClear(renderer); // clear the render
	//this is where we would add stuff to render

	//source rect being part of the texture u want to draw: passing null uses entier image
	//dest rect: where you want it drawn on screen: passing null draws to whole render frame
	board->Render();


	//x->Update(200, 200);
	//x->Render();
	/*
	for loop
		if x = render using gameobj
		if y = render using gameobj
		*/

	for (int i = 0; i < 9; i++) {
		int X = (i % 3) * 200; //0, 1, 2, 0, 1, 2, 0, 1, 2
		int Y = (i / 3) * 200; //0, 0, 0, 1, 1, 1, 2, 2, 2

		if (Grid[i] == GRID_TYPE_O) {
			o->Update(X, Y);
			o->Render();
		} else if (Grid[i] == GRID_TYPE_X) {
				x->Update(X, Y);
				x->Render();
		}
	}
	SDL_RenderPresent(renderer); //render all the objects
}


void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;

}

