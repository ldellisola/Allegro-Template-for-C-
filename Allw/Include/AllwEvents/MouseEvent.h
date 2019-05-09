#pragma once

#include "AllwEvents/AllegroEvent.h"


namespace Allw {
	namespace Event {

		enum class MouseButton {
			None,
			Left,
			Right
		};


		class MouseButtonEvent : public AllegroEvent {
		public:

			MouseButton getMouseButton();

			EVENT_CLASS_CATEGORY(Category::Mouse)

		protected:
			MouseButtonEvent(double timeStamp, int x, int y, MouseButton button);

			private:
			MouseButton pressedButton = MouseButton::None;
			int x = 0, y = 0;
		};

		class MouseButtonPressedEvent : public MouseButtonEvent {
		public:
			MouseButtonPressedEvent(double timeStamp, int x, int y, MouseButton button)
				: MouseButtonEvent(timeStamp,x,y,button){}
			EVENT_CLASS_TYPE(MouseDown)
		};
		
		class MouseButtonReleasedEvent : public MouseButtonEvent {
		public:
			MouseButtonReleasedEvent(double timeStamp, int x, int y, MouseButton button)
				: MouseButtonEvent(timeStamp,x,y,button){}
			EVENT_CLASS_TYPE(MouseUp)
		};

		class MouseMovedEvent : public AllegroEvent {
		public:
			MouseMovedEvent(double timeStamp, int x, int y);
			int getX();
			int getY();

			EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(Category::Mouse)

		private:
			int x = 0, y = 0;
		};

		

	}
}