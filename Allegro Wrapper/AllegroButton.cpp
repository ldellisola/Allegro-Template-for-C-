#include "AllegroButton.h"






AllegroButton::~AllegroButton()
{
}

void AllegroButton::click(float mouseX, float mouseY, double timeStamp)
{
	if (!((mouseX < this->x) || (this->x + this->width < mouseX) || (mouseY < this->y) || (this->y + this->height < mouseY))) {
		if (clickTimeStamp == 0) {
			clickTimeStamp = timeStamp;
			if (pressedC)
				unpressC();
			else
				pressC();
		}
	}
	if (timeStamp -clickTimeStamp >= MinClickThreshold) {
		clickTimeStamp = 0;
	}

	

}

bool AllegroButton::doubleClick(float mouseX, float mouseY, double timestamp)
{
	if (!((mouseX < this->x) || (this->x + this->width < mouseX) || (mouseY < this->y) || (this->y + this->height < mouseY)))
		if (pressedDC) {
			if (MinClickThreshold < timestamp - doubleClickTimeStamp) {
				unpressDC();
				if (timestamp - doubleClickTimeStamp < MaxClickThreshold) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
				
		}
		else {
			pressDC();
			doubleClickTimeStamp = timestamp;
			return false;
		}
	else {
		unpressDC();
		doubleClickTimeStamp = 0;
		return false;
	}


}

bool AllegroButton::isPressed()
{
	if (doubleClickTimeStamp == 0)
		return pressedC;
	else
		return false;
}

void AllegroButton::draw()
{


	if (doubleClickTimeStamp == 0) {
		if (pressedC)
			al_draw_tinted_bitmap(this->bitmap, this->pressedColor, this->x, this->y, 0);
		else
			al_draw_bitmap(this->bitmap, this->x, this->y, 0);
	}
	else
		al_draw_bitmap(this->bitmap, this->x, this->y, 0);


	
}



void AllegroButton::pressC()
{
	pressedC = true;
}

void AllegroButton::unpressDC()
{
	pressedDC = false;
}


void AllegroButton::pressDC()
{
	pressedDC = true;
}

void AllegroButton::unpressC()
{
	pressedC = false;
}