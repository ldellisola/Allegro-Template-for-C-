#include "AllwEvents/TimerEvent.h"
#include "allegro5/allegro.h"

namespace Allw {
	namespace Event {
		TimerEvent::TimerEvent(ALLEGRO_TIMER_EVENT& timer)
			: AllegroEvent(timer.timestamp)
		{

		}
	}
}

