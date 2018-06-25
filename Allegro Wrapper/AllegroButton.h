#pragma once
#include <string>

#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

#include "WrittenBox.h"

#define MinDoubleClickThreshold (0.001)
#define MaxDoubleClickThreshold (0.2)

typedef struct AllegroButtonData
{
	float x, y, width, height;
	string text;
	ALLEGRO_FONT* font;
	ALLEGRO_COLOR fontColor;
};

class AllegroButton :
	public AllegroWrittenBox
{
public:
	// Constructor: It needs a pointer to a font.
	//
	//		- float x: initial X coordinate.
	//		- float y: initial Y coordinate.
	//		- float width: width of the button.
	//		- float height: height of the button.
	//		- string text: text of the button.
	//		- ALLEGRO_FONT * font: pointer to the font
	//		- ALLEGRO_COLOR fontColor: color of the font
	AllegroButton(float x, float y, float width, float height, string text, ALLEGRO_FONT * font, ALLEGRO_COLOR fontColor)
		: AllegroWrittenBox(x,y,width,height,text,font,fontColor){
		pressedColor = al_map_rgb(100, 100, 100);
	}

	// Constructor: It will take an existing font. This is a good option for when you have to create a lot of identical Boxes or you need to 
	//				create a box inside another function and you need all of this information from outside of it.
	//
	//		- AllegroWrittenBoxData& data: a structure with all the data of a box
	AllegroButton(AllegroButtonData& data)
		:AllegroWrittenBox(data.x, data.y, data.width, data.height, data.text,data.font,data.fontColor) {
		pressedColor = al_map_rgb(100, 100, 100);
	}

	~AllegroButton();
	void click(float mouseX, float mouseY);
	bool doubleClick(float mouseX, float mouseY, double timestamp);
	bool isPressed();
	void draw();
private:
	void press();
	void unpress();
	bool pressed = false;
	double lastClickTimeStamp = 0;
	ALLEGRO_COLOR pressedColor;
};

