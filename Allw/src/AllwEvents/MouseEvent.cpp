#include "AllwEvents/MouseEvent.h"

#include "allegro5/allegro.h"

namespace Allw {
	namespace Event {

		MouseButtonEvent::MouseButtonEvent(ALLEGRO_MOUSE_EVENT &mouse)  
			: AllegroEvent(mouse.timestamp)
		{
			this->pressedButton = (MouseButton) mouse.button;
			this->x = mouse.x;
			this->y = mouse.y;
		}

		MouseButton MouseButtonEvent::getMouseButton()
		{
			return this->pressedButton;
		}

		MouseMovedEvent::MouseMovedEvent(ALLEGRO_MOUSE_EVENT &mouse)
			:AllegroEvent(mouse.timestamp)
		{
			this->x = mouse.x;
			this->y = mouse.y;
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