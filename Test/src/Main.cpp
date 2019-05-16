#include "AllwInit/Allw.h"
#include "AllwBasics/AllegroWindow.h"
#include "AllwEvents/AllegroEventHandler.h"
#include "AllwBasics/AllegroSound.h"
#include <iostream>


int main(void) {
	

	Allw::Allw allegro(Allw::Init::Mode::Full,Allw::Init::NoValue, Allw::Init::NoValue,10);

	Allw::AllegroWindow window(1000, 1000, allegro.getEventQueue());

	Allw::Event::AllegroEventHandler eventH(allegro.getEventQueue());



	while (true) {
		eventH.getEvent();
		if (eventH.isThereEvent()) {
			
			Allw::Event::AllegroEvent& ev = eventH.ObtainEvent();

			if (ev.GetCategoryFlags() == Allw::Event::Category::Keyboard && ev.GetEventType() == Allw::Event::Type::KeyDown) {
				Allw::Event::KeyCharEvent& aa = (Allw::Event::KeyCharEvent&) ev;

				std::cout << (char)( aa.getChar());
				int a = 0;
				a++;
			}

			

			eventH.killEvent();
		}
	}


	return 0;
}



