#pragma once
#include <string>

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

namespace Allw {
	namespace Log {
		enum class Flag
		{
			Regular, NoClose, Monospace
		};


		// It creates a window to debug in case you don't want to use the terminal
		class AllegroLog
		{
		public:

			// Constructor:
			//
			//		- string title: the title of the debug window.
			//		- Flag flag: an optional paramenter that affects the debug window. It can be Regular, NoClose or Monospace.
			AllegroLog(std::string title, bool logToFile = false, Flag flag = Flag::Regular);

			//Destructor
			~AllegroLog();

			// It closes the debug window
			void close();

			// It return the event source
			ALLEGRO_EVENT_SOURCE* getEventSource();

			AllegroLog& operator<< (std::string text);
			AllegroLog& operator<< (char letter);
			AllegroLog& operator<< (int num);
			AllegroLog& operator<< (float num);
			AllegroLog& operator<< (double num);

		private:
			ALLEGRO_TEXTLOG * logWindow = nullptr;
			std::string log;
			bool logToFile;
		};

	}
}