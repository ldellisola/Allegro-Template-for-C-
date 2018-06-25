#include "AllegroButton.h"






AllegroButton::~AllegroButton()
{
}

void AllegroButton::click(float mouseX, float mouseY, double timeStamp)
{
	if (!((mouseX < this->x) || (this->x + this->width < mouseX) || (mouseY < this->y) || (this->y + this->height < mouseY))) {
		if (clickTimeStamp == 0) {
			clickTimeStamp = timeStamp;
			if (pressed)
				unpress();
			else
				press();
		}
	}
	if (clickTimeStamp >= MinClickThreshold)
		clickTimeStamp = 0;

}

bool AllegroButton::doubleClick(float mouseX, float mouseY, double timestamp)
{
	if (!((mouseX < this->x) || (this->x + this->width < mouseX) || (mouseY < this->y) || (this->y + this->height < mouseY)))
		if (pressed) {
			if (MinClickThreshold < timestamp - doubleClickTimeStamp) {
				unpress();
				if (timestamp - doubleClickTimeStamp < MaxClickThreshold)
					return true;
				else
					return false;
			}
			else return false;
				
		}
		else {
			press();
			doubleClickTimeStamp = timestamp;
			return false;
		}
	else {
		unpress();
		doubleClickTimeStamp = 0;
		return false;
	}


}

bool AllegroButton::isPressed()
{
	if (doubleClickTimeStamp == 0)
		return pressed;
	else
		return false;
}

void AllegroButton::draw()
{
	if (doubleClickTimeStamp == 0) {
		if (pressed) 
			al_draw_tinted_bitmap(this->bitmap, this->pressedColor, this->x, this->y, 0);
		else
			al_draw_bitmap(this->bitmap, this->x, this->y, 0);
	}
	else
		al_draw_bitmap(this->bitmap, this->x, this->y, 0);
}

void AllegroButton::press()
{
	pressed = true;
}

void AllegroButton::unpress()
{
	pressed = false;
}
