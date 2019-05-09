#pragma once

#include "AllwEvents/AllegroEvent.h"


namespace Allw {
	namespace Event {

		class KeyboardEvent : public AllegroEvent {
		public:

			unsigned int getModifier();
			int getKeyCode();


			EVENT_CLASS_CATEGORY(Category::Keyboard)

		protected:			
			KeyboardEvent(double timeStamp, int keycode, unsigned int modifier);

		private:
			int keyCode = 0;
			unsigned int modifier = 0;
		};

		class KeyPressedEvent : public KeyboardEvent {
		public:
			KeyPressedEvent(double timeStamp, int keycode, unsigned int modifier)
				: KeyboardEvent(timeStamp,keycode,modifier){}
			EVENT_CLASS_TYPE(KeyDown)
		private:
		};

		class KeyReleasedEvent : public KeyboardEvent {
		public:
			KeyReleasedEvent(double timeStamp, int keycode, unsigned int modifier)
				: KeyboardEvent(timeStamp, keycode, modifier) {}
			EVENT_CLASS_TYPE(KeyUp)

		private:

		};
	}
}