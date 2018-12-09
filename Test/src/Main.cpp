#include <iostream>

#include <AllwInit/Allw.h>
#include <AllwBasics/AllegroWindow.h>

#include <string>
#include <vector>
#include <exception>

int main(void) {
	

	Allw allw(Allegro::InitMode::Full);

	AllegroWindow window(300, 300, allw.getEventQueue());



	return 0;
}



