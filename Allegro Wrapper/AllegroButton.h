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

class AllegroButton :
	public WrittenBox
{
public:
	AllegroButton(float x, float y, float width, float height, string text, ALLEGRO_FONT * font, ALLEGRO_COLOR fontColor)
		: WrittenBox(x,y,width,height,text,font,fontColor){
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

