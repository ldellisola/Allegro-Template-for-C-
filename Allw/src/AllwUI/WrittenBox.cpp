#include "AllwUI/WrittenBox.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

namespace Allw {
	namespace UI {



		AllegroWrittenBox::~AllegroWrittenBox()
		{
		}

		void AllegroWrittenBox::setText(std::string text)
		{
			this->text = text;
			setUp();
		}


		void AllegroWrittenBox::setUp()
		{
			AllegroBox::setUp();

			ALLEGRO_BITMAP * c = al_get_backbuffer(al_get_current_display());
			al_set_target_bitmap(this->bitmap);

			this->font->drawCentredText(this->text, this->fontColor, this->width, this->height);

			al_set_target_bitmap(c);
		}


	}
}