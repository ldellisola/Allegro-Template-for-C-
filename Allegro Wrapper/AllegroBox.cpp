#include "AllegroBox.h"


AllegroBox::AllegroBox(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->bitmap = al_create_bitmap(width, height);
	
	this->setUp();
}

AllegroBox::~AllegroBox()
{
	al_destroy_bitmap(this->bitmap);
}

void AllegroBox::draw()
{
	al_draw_bitmap(this->bitmap, this->x, this->y, 0);
}

void AllegroBox::setBackgroundColor(ALLEGRO_COLOR color)
{
	this->backgroundColor = color;
	setUp();
}

void AllegroBox::setBorderColor(ALLEGRO_COLOR color)
{
	this->borderColor = color;
	setUp();
}

void AllegroBox::setBorderThickness(float thickness)
{
	this->borderThickness = thickness;
	setUp();
}

void AllegroBox::setX(float x)
{
	this->x = x;
}

void AllegroBox::setY(float y)
{
	this->y = y;
}

void AllegroBox::resize(float width, float height)
{
	al_destroy_bitmap(this->bitmap);
	this->bitmap = al_create_bitmap(width, height);
	this->width = width;
	this->height = height;
	this->setUp();
}

ALLEGRO_BITMAP * AllegroBox::getBitmap()
{
	return this->bitmap;
}

ALLEGRO_COLOR AllegroBox::getBorderColor()
{
	return this->borderColor;
}

ALLEGRO_COLOR AllegroBox::getBackgroundColor()
{
	return this->backgroundColor;
}

float AllegroBox::getBorderThickness()
{
	return borderThickness;
}

float AllegroBox::getX()
{
	return this->x;
}

float AllegroBox::getY()
{
	return this->y;
}

float AllegroBox::getWidth()
{
	return this->width;
}

float AllegroBox::getHeight()
{
	return this->height;
}

bool AllegroBox::operator==(AllegroBox & box)
{
	if (box.bitmap == this->bitmap)
		return true;
	else
		return false;
}

void AllegroBox::setUp()
{
	ALLEGRO_DISPLAY * main = al_get_current_display();
	al_set_target_bitmap(this->bitmap);

	al_clear_to_color(backgroundColor);

	if (borderThickness > 0) {
		float x1 = borderThickness;
		float x2 = width - borderThickness;
		float y1 = borderThickness;
		float y2 = height - borderThickness;
		al_draw_rectangle(x1, y1, x2, y2, borderColor, borderThickness);
	}

	al_set_target_backbuffer(main);
}
