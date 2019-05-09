#include "AllwEvents/KeyboardEvent.h"



namespace Allw {
	namespace Event {





		KeyboardEvent::KeyboardEvent(double timeStamp, int keycode, unsigned int modifier)
			:AllegroEvent(timeStamp)
		{
			this->keyCode = keycode;
			this->modifier = modifier;
		}

		unsigned int KeyboardEvent::getModifier()
		{
			return modifier;
		}

		int KeyboardEvent::getKeyCode()
		{
			return keyCode;
		}

	}
}