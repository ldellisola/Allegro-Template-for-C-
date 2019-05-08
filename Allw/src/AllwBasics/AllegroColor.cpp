#include "AllwBasics/AllegroColor.h"
#include <allegro5/allegro_color.h>
#include <allegro5/allegro.h>

namespace Allw {
	namespace Color {



		AllegroColor::AllegroColor(std::string name)
		{
			init();
			*color = al_color_name(name.c_str());
		}

		AllegroColor::AllegroColor()
		{
		}

		AllegroColor::AllegroColor(unsigned char r, unsigned char g, unsigned char b)
		{
			init();
			*color = al_map_rgb(r, g, b);
		}

		AllegroColor::AllegroColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
		{
			init();
			*color = al_map_rgba(r, g, b,a);
		}

		void AllegroColor::operator=(const AllegroColor& color)
		{
			if (color.color != nullptr) {
				
				init();
				*this->color = *color.color;
				
			}
			else {
				throw new Exception::AllegroColorEmptyException();
			}
		}

		void AllegroColor::decode(unsigned char& r, unsigned char& g, unsigned char& b)
		{
			if(this->color != nullptr)
				al_unmap_rgb(*this->color,&r, &g, &b);
			else
				throw new Exception::AllegroColorEmptyException();

		}

		void AllegroColor::decode(unsigned char& r, unsigned char& g, unsigned char& b, unsigned char& a)
		{
			if (this->color != nullptr)
				al_unmap_rgba(*this->color, &r, &g, &b,&a);
			else
				throw new Exception::AllegroColorEmptyException();


		}

		std::string AllegroColor::decode()
		{
			if (this->color != nullptr) {

				unsigned char r, g, b;
				al_unmap_rgb(*this->color, &r, &g, &b);
				return al_color_rgb_to_name(r, g, b);
			}
			else
				throw new Exception::AllegroColorEmptyException();


		}

		ALLEGRO_COLOR& AllegroColor::GetColor()
		{
			if (this->color != nullptr)
				return *color;
			else
				throw new Exception::AllegroColorEmptyException();
		}

		void AllegroColor::init()
		{
			color = new ALLEGRO_COLOR;
		}

	}
}