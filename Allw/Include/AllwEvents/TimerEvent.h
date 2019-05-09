#pragma once
#include "AllwEvents/AllegroEvent.h"





namespace Allw {
	namespace Event {

		class TimerEvent :public AllegroEvent {
		public:
			TimerEvent(double timeStamp) :AllegroEvent(timeStamp){}
			EVENT_CLASS_CATEGORY(Category::Timer)
			EVENT_CLASS_TYPE(Timer)
		};
	}
}