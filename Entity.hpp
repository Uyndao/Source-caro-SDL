#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "Math.hpp"

class Entity
{
public:
	Entity(Vector2f& p_pos, SDL_Texture* p_tex, Vector2f& p_wh);
	Vector2f& getPos()
	{
		return pos;
	}
	void setPos(float p_x, float p_y);
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
private:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};

