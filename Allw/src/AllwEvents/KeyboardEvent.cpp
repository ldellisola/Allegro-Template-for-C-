#include "AllwEvents/KeyboardEvent.h"

#include "allegro5/keyboard.h"

namespace Allw {
	namespace Event {





		KeyboardEvent::KeyboardEvent(ALLEGRO_KEYBOARD_EVENT& data)
			:AllegroEvent(data.timestamp)
		{
			this->keyCode = data.keycode;
			this->modifier = data.modifiers;
			this->unicode = data.unichar;
			this->repeat = data.repeat;
		}



		int KeyboardEvent::getKeyCode()
		{
			return keyCode;
		}

		int KeyCharEvent::getChar()
		{
			return unicode;
		}

		bool KeyCharEvent::isRepeated()
		{
			return repeat;
		}
		unsigned int KeyCharEvent::getModifier()
		{
			return modifier;
		}

	}
}