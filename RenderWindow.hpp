#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "Entity.hpp"
#include "Math.hpp"
class RenderWindow
{
public:
	RenderWindow(const char* p_title,int p_w, int p_h) ;
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanup();
	void clear();
	void render(Entity& p_entity, Vector2f& p_dstwh);
	void display();
private:	
	SDL_Window* window;
	SDL_Renderer* renderer;
};

