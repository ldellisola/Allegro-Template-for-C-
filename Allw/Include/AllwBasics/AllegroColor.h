#pragma once
#include <string>
#include "AllwMisc/AllegroException.h"

typedef struct ALLEGRO_COLOR ALLEGRO_COLOR;

namespace Allw {
	namespace Color {

		class AllegroColor {
		public:
			AllegroColor(std::string name);
			AllegroColor();
			AllegroColor(unsigned char r, unsigned char g, unsigned char b);
			AllegroColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

			void operator=(const AllegroColor& color);

			void decode(unsigned char& r, unsigned char& g, unsigned char& b);
			void decode(unsigned char& r, unsigned char& g, unsigned char& b, unsigned char&a);
			std::string decode();

			ALLEGRO_COLOR& GetColor();

		private:
			void init();
			ALLEGRO_COLOR* color = nullptr;
		};

	}
}