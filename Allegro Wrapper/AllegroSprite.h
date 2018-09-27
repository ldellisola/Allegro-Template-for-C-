#pragma once
#include "allegro5/allegro.h"

#include <string>


class AllegroSprite
{
public:
	AllegroSprite(std::string file);
	AllegroSprite(std::string file,float height, float width);
	AllegroSprite(std::string file, float height, float width, float angle);
	AllegroSprite(std::string file, float angle);

	~AllegroSprite();

	void draw(float x, float y);

	void setDimensions(float height, float width);

	void setAngle(float angle);

	
private:
	ALLEGRO_BITMAP * bitmap = nullptr;
	float scaledHeight, scaledWidth, height, width, angle;
};

