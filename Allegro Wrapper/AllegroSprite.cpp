#include "AllegroSprite.h"






AllegroSprite::AllegroSprite(std::string file)
{
	this->bitmap = al_load_bitmap(file.c_str());
	this->angle = 0;
	this->height = al_get_bitmap_height(this->bitmap);
	this->width = al_get_bitmap_width(this->bitmap);
	this->scaledHeight = height;
	this->scaledWidth = width;
}

AllegroSprite::AllegroSprite(std::string file, float height, float width)
{
	this->bitmap = al_load_bitmap(file.c_str());
	this->angle = 0;
	this->height = al_get_bitmap_height(this->bitmap);
	this->width = al_get_bitmap_width(this->bitmap);
	this->scaledHeight = height;
	this->scaledWidth = width;
}

AllegroSprite::AllegroSprite(std::string file, float height, float width, float angle)
{
	this->bitmap = al_load_bitmap(file.c_str());
	this->angle = angle;
	this->height = al_get_bitmap_height(this->bitmap);
	this->width = al_get_bitmap_width(this->bitmap);
	this->scaledHeight = height;
	this->scaledWidth = width;
}

AllegroSprite::AllegroSprite(std::string file, float angle)
{
	this->bitmap = al_load_bitmap(file.c_str());
	this->angle = angle;
	this->height = al_get_bitmap_height(this->bitmap);
	this->width = al_get_bitmap_width(this->bitmap);
	this->scaledHeight = height;
	this->scaledWidth = width;
}

AllegroSprite::~AllegroSprite()
{
	if (this->bitmap != nullptr)
		al_destroy_bitmap(this->bitmap);
}

void AllegroSprite::draw(float x, float y)
{
	//al_draw_scaled_rotated_bitmap(this->bitmap, this->width / 2.0, this->height / 2.0, x + this->width / 2.0, y + this->height / 2.0, this->angle, ,);


}



