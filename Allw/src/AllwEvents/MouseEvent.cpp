#include "AllwEvents/MouseEvent.h"



namespace Allw {
	namespace Event {

		MouseButtonEvent::MouseButtonEvent(double timeStamp, int x, int y, MouseButton button)
			: AllegroEvent(timeStamp)
		{
			this->pressedButton = button;
			this->x = x;
			this->y = y;
		}

		MouseButton MouseButtonEvent::getMouseButton()
		{
			return this->pressedButton;
		}

		MouseMovedEvent::MouseMovedEvent(double timeStamp, int x, int y)
			:AllegroEvent(timeStamp)
		{
			this->x = x;
			this->y = y;
		}

		int MouseMovedEvent::getX()
		{
			return x;
		}

		int MouseMovedEvent::getY()
		{
			return y;
		}

	}
}