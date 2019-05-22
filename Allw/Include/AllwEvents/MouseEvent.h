#pragma once

#include "AllwEvents/AllegroEvent.h"

typedef struct ALLEGRO_MOUSE_EVENT ALLEGRO_MOUSE_EVENT;


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
			MouseButtonEvent(ALLEGRO_MOUSE_EVENT& mouse);

			private:
			MouseButton pressedButton = MouseButton::None;
			int x = 0, y = 0;
		};

		class MouseButtonPressedEvent : public MouseButtonEvent {
		public:
			MouseButtonPressedEvent(ALLEGRO_MOUSE_EVENT& mouse)
				: MouseButtonEvent(mouse){}
			EVENT_CLASS_TYPE(MouseDown)
		};
		
		class MouseButtonReleasedEvent : public MouseButtonEvent {
		public:
			MouseButtonReleasedEvent(ALLEGRO_MOUSE_EVENT& mouse)
				: MouseButtonEvent(mouse){}
			EVENT_CLASS_TYPE(MouseUp)
		};

		class MouseMovedEvent : public AllegroEvent {
		public:
			MouseMovedEvent(ALLEGRO_MOUSE_EVENT &mouse);
			int getX();
			int getY();

			EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(Category::Mouse)

		private:
			int x = 0, y = 0;
		};

		

	}
}