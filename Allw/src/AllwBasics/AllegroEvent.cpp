#include "AllwBasics/AllegroEvent.h"

namespace Allw {
	namespace Event {

		AllegroEventHandler::AllegroEventHandler(ALLEGRO_EVENT_QUEUE * queue)
		{
			this->eventF = new Allw::Factories::AllegroEventFactory(queue);
			this->evnt = new AllegroEvent(Type::Empty, 0);
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

				switch (this->eventF->getEventType()) {
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					evnt->setType(Type::DisplayClose);
					break;
				case ALLEGRO_EVENT_KEY_DOWN:
					evnt->setType(Type::KeyDown);
					evnt->setValue(eventF->getKeyboardEvent().keycode);
					evnt->setTimestamp(eventF->getKeyboardEvent().timestamp);
					break;
				case ALLEGRO_EVENT_KEY_UP:
					evnt->setType(Type::KeyUp);
					evnt->setValue(eventF->getKeyboardEvent().keycode);
					evnt->setTimestamp(eventF->getKeyboardEvent().timestamp);
					break;
				case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
					evnt->setType(Type::MouseDown);
					evnt->setValue(eventF->getMouseEvent().button);
					evnt->setCoordinates(eventF->getMouseEvent().x, eventF->getMouseEvent().y);
					evnt->setTimestamp(eventF->getMouseEvent().timestamp);
					break;
				case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
					evnt->setType(Type::MouseUp);
					evnt->setValue(eventF->getMouseEvent().button);
					evnt->setCoordinates(eventF->getMouseEvent().x, eventF->getMouseEvent().y);
					evnt->setTimestamp(eventF->getMouseEvent().timestamp);
					break;
				case ALLEGRO_EVENT_MOUSE_AXES:
					evnt->setType(Type::MouseMoved);
					evnt->setCoordinates(eventF->getMouseEvent().x, eventF->getMouseEvent().y);
					break;
				case ALLEGRO_EVENT_TIMER:
					evnt->setType(Type::Timer);
					break;
				}
				if (evnt->getType() != Type::Empty) {
					eventQueue.push(*evnt);
					evnt->setType(Type::Empty);
				}
			}





		}

		AllegroEvent AllegroEventHandler::ObtainEvent()
		{
			AllegroEvent temp = this->eventQueue.front();
			this->eventQueue.pop();
			return temp;
		}

	}
}