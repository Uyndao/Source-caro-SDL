#include "Entity.hpp"
#include <SDL.h>
#include <SDL_image.h>

#include "Math.hpp"

#include <cmath>

Entity::Entity(Vector2f& p_pos, SDL_Texture* p_tex, Vector2f& p_wh)
	:pos(p_pos), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = p_wh.x;
	currentFrame.h = p_wh.y;
}



void Entity::setPos(float p_x, float p_y)
{
	pos.x = p_x;
	pos.y = p_y;
}

SDL_Texture* Entity::getTex()
{
	return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}

