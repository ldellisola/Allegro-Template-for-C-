#pragma once


#include "AllwEvents/AllegroEvent.h"

namespace Allw {
	namespace Event {

		class WindowEvent :public AllegroEvent {
		public :

			EVENT_CLASS_CATEGORY(Category::Window)

		protected:
			WindowEvent(double timeStamp);
		};

		class WindowClosedEvent :public WindowEvent {
		public :
			WindowClosedEvent(double timeStamp);
			EVENT_CLASS_TYPE(WindowClosed)

		private:
		};
	}
}

