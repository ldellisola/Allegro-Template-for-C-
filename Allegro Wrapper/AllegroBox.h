#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

class AllegroBox
{
public:
	// Constructor
	//
	//		- float x:		initial X coordinate.
	//		- float y:		initial Y coordinate.
	//		- float width:	width of the box.
	//		- float height: height of the box.
	AllegroBox(float x, float y, float width, float height);
	 virtual ~AllegroBox();

	// Draws the bitmap to the actual screen.
	//
	virtual void draw();

	// Setters: each function set a given variable of the box
	//
	virtual void setBackgroundColor(ALLEGRO_COLOR color);
	virtual void setBorderColor(ALLEGRO_COLOR color);
	virtual void setBorderThickness(float thickness);
	virtual void setX(float x);
	virtual void setY(float y);
	virtual void resize(float width, float height);

	// Getters: each function returns a given variable of the box

	virtual ALLEGRO_BITMAP * getBitmap();
	virtual ALLEGRO_COLOR getBorderColor();
	virtual ALLEGRO_COLOR getBackgroundColor();
	virtual float getBorderThickness();
	virtual float getX();
	virtual float getY();
	virtual float getWidth();
	virtual float getHeight();

	// Overloaded operators.

	bool operator==(AllegroBox&box);

protected:
	// This function is called everytime a change is made in the box to reflect that change on the bitmap
	// it should only be called from within the clases.
	virtual void setUp();
	ALLEGRO_BITMAP * bitmap;
	ALLEGRO_COLOR borderColor;
	ALLEGRO_COLOR backgroundColor;
	float borderThickness;
	float x;
	float y;
	float width;
	float height;
};

