#pragma once
#include <string>

#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

#include "AllegroBox.h"

using namespace std;


typedef struct textData
{
	float x, y, width, height;
	int fontSize;
	string text;
	const char * path;
	const char * color;
};


class WrittenBox : public AllegroBox
{
public:
	WrittenBox(float x_, float y_, float width_, float height_, string text_, ALLEGRO_FONT * font, ALLEGRO_COLOR fontColor)
		: AllegroBox(x_, y_, width_, height_) {

		this->text = text_;
		this->font = font;
		this->fontColor = fontColor;
		foreignFont = false;
		this->setUp();
	}
	WrittenBox(float x_, float y_, float width_, float height_, int fontSize_, string text_, const char * fontPath, ALLEGRO_COLOR fontColor)
		: AllegroBox(x_, y_, width_, height_) {

		this->text = text_;
		this->font = al_load_font(fontPath, -fontSize_, ALLEGRO_ALIGN_CENTRE);
		this->fontColor = fontColor;
		foreignFont = true;
		this->setUp();
	}

	~WrittenBox();

	string getText() { return text; }
	void setText(string text) { this->text = text; }
protected:
	//Actualiza al bitmap interno con los datos de la clase.
	bool foreignFont;
	void setUp();
	
	string text;
	ALLEGRO_COLOR fontColor;
	
	ALLEGRO_FONT * font;
	
};

