#include "AllwEvents/AllegroEventHandler.h"
#include <allegro5/allegro.h>




class AllegroEventFactory
{
public:
	AllegroEventFactory(ALLEGRO_EVENT_QUEUE* eventQueue) {
		this->eventQueue = eventQueue;
	}

	~AllegroEventFactory() {
		for (ALLEGRO_EVENT_SOURCE* eventSource : sources)
			al_unregister_event_source(eventQueue, eventSource);
	}
	void flushQueue() {
		al_flush_event_queue(this->eventQueue);
	}

	bool getEvent() {

		return al_get_next_event(eventQueue, &ev);

	}
	ALLEGRO_EVENT_TYPE& getEventType() { return ev.type; }
	ALLEGRO_DISPLAY_EVENT& getDisplayEvent() { return ev.display; }
	ALLEGRO_KEYBOARD_EVENT& getKeyboardEvent() { return ev.keyboard; }
	ALLEGRO_TIMER_EVENT& getTimerEvent() { return ev.timer; }
	ALLEGRO_MOUSE_EVENT& getMouseEvent() { return ev.mouse; }
	ALLEGRO_USER_EVENT& getUserEvent() { return ev.user; }
	void registerEventSource(ALLEGRO_EVENT_SOURCE * eventSource) {
		al_register_event_source(eventQueue, eventSource);
		sources.push_back(eventSource);
	}
	void unregisterEventSource(ALLEGRO_EVENT_SOURCE * eventSource) {
		int i;
		bool kill = false;
		for (i = 0; i < (int)sources.size() && !kill; i++) {
			if (sources[i] == eventSource)
				kill = true;
		}
		i--;
		if (kill) {
			sources.erase(sources.begin() + i);
			al_unregister_event_source(eventQueue, eventSource);
		}
	}

private:
	ALLEGRO_EVENT_QUEUE* eventQueue = nullptr;
	ALLEGRO_EVENT ev;
	std::vector<ALLEGRO_EVENT_SOURCE*>sources;
};


namespace Allw {
	namespace Event {

		AllegroEventHandler::AllegroEventHandler(ALLEGRO_EVENT_QUEUE* queue)
		{
			this->eventF = new AllegroEventFactory(queue);
		}

		AllegroEventHandler::~AllegroEventHandler()
		{
			if (this->eventF != nullptr)
				delete this->eventF;
			if (this->evnt != nullptr)
				delete this->evnt;
		}

		bool AllegroEventHandler::isThereEvent()
		{
			if (this->eventQueue.size() != 0)
				return true;
			else return false;
		}

		void AllegroEventHandler::getEvent()
		{

			if (this->eventF->getEvent()) {

				bool eventExisted = true;

				switch (this->eventF->getEventType()) {
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					evnt = new WindowClosedEvent(eventF->getDisplayEvent().timestamp);
					break;
				case ALLEGRO_EVENT_KEY_DOWN:
					evnt = new KeyPressedEvent(eventF->getKeyboardEvent());
					break;
				case ALLEGRO_EVENT_KEY_UP:
					evnt = new KeyReleasedEvent(eventF->getKeyboardEvent());
					break;
				case ALLEGRO_EVENT_KEY_CHAR:
					evnt = new KeyCharEvent(eventF->getKeyboardEvent());
				case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
					auto mouseDown = eventF->getMouseEvent();
					evnt = new MouseButtonPressedEvent(eventF->getMouseEvent());
					break;
				case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
					auto mouseUp = eventF->getMouseEvent();
					evnt = new MouseButtonReleasedEvent(eventF->getMouseEvent());
					break;
				case ALLEGRO_EVENT_MOUSE_AXES:
					auto mouse = eventF->getMouseEvent();
					evnt = new MouseMovedEvent(eventF->getMouseEvent());
					break;
				case ALLEGRO_EVENT_TIMER:
					evnt = new TimerEvent(eventF->getTimerEvent());
					break;
				default:
					eventExisted = false;
				}

				if (eventExisted) {
					eventQueue.push(evnt);
				}

			}





		}

		AllegroEvent& AllegroEventHandler::ObtainEvent()
		{
			deployedEvent = this->eventQueue.front();
			this->eventQueue.pop();
			return *deployedEvent;
		}
		void AllegroEventHandler::killEvent()
		{
			delete deployedEvent;
		}
	}
}