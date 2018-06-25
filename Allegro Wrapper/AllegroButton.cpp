#include "AllegroButton.h"






AllegroButton::~AllegroButton()
{
}

void AllegroButton::click(float mouseX, float mouseY)
{
	if (!((mouseX < this->x) || (this->x + this->width < mouseX) || (mouseY < this->y) || (this->y + this->height < mouseY)))
		if (pressed)
			unpress();
		else
			press();

}

bool AllegroButton::doubleClick(float mouseX, float mouseY, double timestamp)
{
	if (!((mouseX < this->x) || (this->x + this->width < mouseX) || (mouseY < this->y) || (this->y + this->height < mouseY)))
		if (pressed) {
			if (MinDoubleClickThreshold < timestamp - lastClickTimeStamp) {
				unpress();
				if (timestamp - lastClickTimeStamp < MaxDoubleClickThreshold)
					return true;
				else
					return false;
			}
			else return false;
				
		}
		else {
			press();
			lastClickTimeStamp = timestamp;
			return false;
		}
	else {
		unpress();
		lastClickTimeStamp = 0;
		return false;
	}


}

bool AllegroButton::isPressed()
{
	if (lastClickTimeStamp == 0)
		return pressed;
	else
		return false;
}

void AllegroButton::draw()
{
	if (lastClickTimeStamp == 0) {
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
