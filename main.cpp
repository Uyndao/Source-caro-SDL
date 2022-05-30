#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stdlib.h>    
#include <time.h>  

#include "Math.hpp"
#include "Entity.hpp"
#include "RenderWindow.hpp"
#include "config.h"
#include "botbaseline.h"

RenderWindow window("Caro", 1200, 800);

int board_game[HEIGHT][WIDTH];

void init_board_game();
Point player1_run();
Point player2_run();
int who_win();

Vector2f unitswh(30, 30);
Vector2f unitsdstwh(24, 24);
Vector2f bgwh(1500, 900);
Vector2f bgdstwh(1200, 720);
Vector2f bgpos(0, 0);
Vector2f barpos(0, 720);
Vector2f barwh(1500, 100);
Vector2f bardstwh(1200, 80);
Vector2f startwh(1500, 1000);
Vector2f startdstwh(1200, 800);

SDL_Texture* X_Texture = window.loadTexture("rc/gfx/X.png");
SDL_Texture* O_Texture = window.loadTexture("rc/gfx/O.png");
SDL_Texture* Xwin_Texture = window.loadTexture("rc/gfx/Xwin.png");
SDL_Texture* Owin_Texture = window.loadTexture("rc/gfx/Owin.png");
SDL_Texture* backgroud_Texture = window.loadTexture("rc/gfx/backgroud.png");
SDL_Texture* Owinbar_Texture = window.loadTexture("rc/gfx/Owinbar.png");
SDL_Texture* Xwinbar_Texture = window.loadTexture("rc/gfx/Xwinbar.png");
SDL_Texture* createbar_Texture = window.loadTexture("rc/gfx/createbar.png");
SDL_Texture* start_Texture = window.loadTexture("rc/gfx/startgame.png");

std::vector <Entity> Units;
std::vector <Entity> winUnits;
Entity start(bgpos, start_Texture, startwh);
Entity backgroud(bgpos,backgroud_Texture, bgwh);
Entity Owinbar(barpos, Owinbar_Texture, barwh);
Entity Xwinbar(barpos, Xwinbar_Texture, barwh);
Entity createbar(barpos, createbar_Texture, barwh);

int main(int argc, char* args[]) 
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "Failed. Error"<< SDL_GetError()<<std::endl;
	}
	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "Failed. Error"<< SDL_GetError()<<std::endl;
	bool GameRunning = true;
	int mouseX = 0;
	int mouseY = 0;
	bool turn_player1 = true;
	int turn_limit = 3000;
	Point position;
	SDL_Event event;
	init_board_game();
	while (GameRunning)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				GameRunning = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if (started && !turn_player1) {
						SDL_GetMouseState(&mouseX, &mouseY);
						position.x = int(mouseY / 24);
						position.y = int(mouseX / 24);
						if (board_game[position.x][position.y] != 0) {
							goto again;
						}
						Vector2f Xpos(position.y * 24, position.x * 24);
						Entity X_entity(Xpos, X_Texture, unitswh);
						Units.push_back(X_entity);
						board_game[position.x][position.y] = -1;
						check_player_win(board_game, -1);
						turn_player1 = !turn_player1;
					}
					else if(!end) {
						started = true;
					}
					else if (end) {
						init_board_game();
						turn_player1 = true;
						started = false;
						end = false;
						winner = 0;
						Units.erase(Units.begin(),Units.end());
						winUnits.erase(winUnits.begin(), winUnits.end());
						for (int i = 0; i < 5; i++) {
							win_path[i] = Point(0, 0);
						}
					}
				}
				break;
			}
		}
		again:
		window.clear();
		window.render(backgroud, bgdstwh);
		if(!started&&!end)
			window.render(start, startdstwh);
		window.render(createbar, bardstwh);
		for (Entity& u : Units)
		{
			window.render(u, unitsdstwh);

		}
		if (end) {
			for (Entity& w : winUnits) {
				window.render(w, unitsdstwh);
			}
			if (winner==1) {
				window.render(Owinbar, bardstwh);
			}
			else
			{
				window.render(Xwinbar, bardstwh);
			}
		}
		SDL_Delay(1000 / 60);
		window.display();
		if (turn_player1 && started) {
			do {
				position = player1_run();
			} while (board_game[position.x][position.y] != 0);
			if (position.x != 14 || position.y != 24) {
				SDL_Delay(1000);
			}
			Vector2f Opos(position.y*24, position.x*24);
			Entity O_entity(Opos, O_Texture, unitswh);
			Units.push_back(O_entity);
			board_game[position.x][position.y] = 1;
			turn_player1 = !turn_player1;
		}
		if (winner != 0 && !end) {
			end = true;
			for (int i = 0; i < 5; i++) {
				Vector2f winpos(win_path[i].x * 24, win_path[i].y * 24);
				if (winner == 1) {
					winUnits.push_back(Entity(winpos, Owin_Texture, unitswh));
				}
				else {
					winUnits.push_back(Entity(winpos, Xwin_Texture, unitswh));
				}
			}
		}
		turn_limit--;
		//Sleep(2000);
	
	}
	window.cleanup();
	SDL_Quit();
	return 0;
}
void init_board_game() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			board_game[i][j] = 0;
		}
	}
}
Point player1_run() {
	//return player_rand(board_game, 1);
	return player_baseline(board_game, 1);
	//return Point(1, 0);
}
