#pragma once
#include <queue>

#include "AllwEvents/AllegroEvent.h"
#include "AllwEvents/KeyboardEvent.h"
#include "AllwEvents/MouseEvent.h"
#include "AllwEvents/TimerEvent.h"
#include "AllwEvents/WindowEvent.h"

class AllegroEventFactory;
typedef struct ALLEGRO_EVENT_QUEUE ALLEGRO_EVENT_QUEUE;

namespace Allw {
	namespace Event {
		class AllegroEventHandler {
		public:
			AllegroEventHandler(ALLEGRO_EVENT_QUEUE* queue);
			~AllegroEventHandler();
			bool isThereEvent();
			void getEvent();

			AllegroEvent& ObtainEvent();

			void killEvent();

			AllegroEvent* evnt = nullptr;


		private:


			AllegroEvent* deployedEvent = nullptr;
			AllegroEventFactory* eventF = nullptr;
			std::queue<AllegroEvent *> eventQueue;

		};
	}
}