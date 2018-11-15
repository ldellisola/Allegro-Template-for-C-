#include <iostream>
#include"AllwInit/AllegroFactory.h"
#include"AllwInit/Allw.h"

int main(void) {

	Allw allegro(Allegro::InitMode::Basic, 1000, 1000, 0);

	AllegroColorFactory colorF;
	colorF.create("white");
	std::cin.get();


	return 0;
}