#pragma once
#include "AllwEvents/AllegroEvent.h"

typedef struct ALLEGRO_TIMER_EVENT ALLEGRO_TIMER_EVENT;



namespace Allw {
	namespace Event {

		class TimerEvent :public AllegroEvent {
		public:
			TimerEvent(ALLEGRO_TIMER_EVENT& timer);
			EVENT_CLASS_CATEGORY(Category::Timer)
			EVENT_CLASS_TYPE(Timer)
		};
	}
}