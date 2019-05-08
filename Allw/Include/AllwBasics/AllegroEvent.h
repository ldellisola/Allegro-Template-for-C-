#pragma once
#include <queue>
#include "AllwInit/AllegroFactory.h"

class AllegroEventFactory;
typedef struct ALLEGRO_EVENT_QUEUE ALLEGRO_EVENT_QUEUE;

namespace Allw {
	namespace Event {


		enum class Type
		{
			KeyDown, KeyUp, MouseDown, MouseUp, MouseMoved, DisplayClose, Timer, Empty
		};

		class AllegroEvent
		{
		public:
			AllegroEvent(Type type, int value) {
				this->value = value;
				this->type = type;
				x = 0;
				y = 0;
			}
			Type getType() { return type; }
			int getValue() { return value; }
			void setType(Type type) { this->type = type; }
			void setValue(int value) { this->value = value; }
			void setTimestamp(double timestamp) { this->timeStamp = timestamp; }
			void setCoordinates(float x, float y) { this->x = x; this->y = y; }
			float getX() { return x; }
			float getY() { return y; }
			double getTimestamp() { return timeStamp; }
		private:
			Type type;
			int value;
			float x, y;
			double timeStamp = 0;
		};


		class AllegroEventHandler {
		public:
			AllegroEventHandler(ALLEGRO_EVENT_QUEUE * queue);
			~AllegroEventHandler();
			bool isThereEvent();
			void getEvent();

			AllegroEvent ObtainEvent();

			AllegroEvent * evnt = nullptr;


		private:
			AllegroEventFactory * eventF = nullptr;
			std::queue<AllegroEvent> eventQueue;

		};

	}
}