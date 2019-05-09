#include "AllwEvents/WindowEvent.h"





namespace Allw {
	namespace Event {


		WindowEvent::WindowEvent(double timeStamp) 
		: AllegroEvent(timeStamp)
		{}






		WindowClosedEvent::WindowClosedEvent(double timeStamp)
			:WindowEvent(timeStamp)
		{
		}

	}
}