#include "AllwInit/Allw.h"
#include "AllwBasics/AllegroWindow.h"
#include "AllwEvents/AllegroEventHandler.h"
#include "AllwBasics/AllegroSound.h"
#include "AllwAnimation/AllegroSprite.h"
#include <iostream>
#include <math.h>


int main(void) {
	

	Allw::Allw allegro(Allw::Init::Mode::Full,Allw::Init::NoValue, Allw::Init::NoValue,10);

	Allw::AllegroWindow window(2000, 1000, allegro.getEventQueue());

	Allw::Event::AllegroEventHandler eventH(allegro.getEventQueue());

	Allw::Animation::AllegroSprite point = Allw::Animation::AllegroSprite("a.png", 2, 2);




	for (int i = 0; i < window.getWidth(); i++) {

		int x = i;
		int y = 100 * cos( (double)(x/400.0) * 3.14157 )  + window.getHeight()/2 ;

		point.draw(x, y);

	}

	window.update();








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



