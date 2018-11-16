#include <iostream>
#include"AllwInit/AllegroFactory.h"
#include"AllwInit/Allw.h"

int main(void) {

	Allw allegro(Allegro::InitMode::Basic);

	AllegroColorFactory colorF;
	colorF.create("white");
	std::cin.get();


	return 0;
}