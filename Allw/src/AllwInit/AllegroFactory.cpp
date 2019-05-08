#include "AllwInit/AllegroFactory.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_video.h>
#include <allegro5/allegro_native_dialog.h>

namespace Allw {
	namespace Factories {
		AllegroDisplayFactory::~AllegroDisplayFactory()
		{
			for (ALLEGRO_DISPLAY* disp : all) 
				destroy(disp);
		}
		ALLEGRO_DISPLAY* AllegroDisplayFactory::create(unsigned int w, unsigned int h, bool automaticDestruction)
		{
			ALLEGRO_DISPLAY* temp = al_create_display(w, h);
			if (temp)
				if (automaticDestruction) {
					all.push_back(temp);
				}
			return temp;
		}
		void AllegroDisplayFactory::destroy(ALLEGRO_DISPLAY* display)
		{

			int i;
			bool kill = false;
			for (i = 0; i < (int)all.size(); i++) {
				if (all[i] == display)
					kill = true;
			}
			i--;
			if (kill) {
				all.erase(all.begin() + i);
				al_destroy_display(display);
			}
		}
		PopUpReturn AllegroPopUpFactory::create(std::string title, std::string heading, std::string text, PopUpType type, ALLEGRO_DISPLAY* display)
		{
			return (PopUpReturn)al_show_native_message_box(display, title.c_str(), heading.c_str(), text.c_str(), nullptr, (int)type);
		}
		

		AllegroBitmapFactory::~AllegroBitmapFactory()
		{
			for (ALLEGRO_BITMAP* bmap : all) 
				destroy(bmap);
		}
		ALLEGRO_BITMAP* AllegroBitmapFactory::create(unsigned int w, unsigned int h, bool automaticDestruction)
		{
			ALLEGRO_BITMAP* temp = al_create_bitmap(w, h);
			if (temp)
				if (automaticDestruction) {
					all.push_back(temp);
				}
			return temp;
		}
		void AllegroBitmapFactory::destroy(ALLEGRO_BITMAP* bitmap)
		{
			int i;
			bool kill = false;
			for (i = 0; i < (int)all.size(); i++) {
				if (all[i] == bitmap)
					kill = true;
			}
			i--;
			if (kill) {
				all.erase(all.begin() + i);
				al_destroy_bitmap(bitmap);
			}
		}



	
		
		AllegroTimerFactory::~AllegroTimerFactory()
		{
			for (ALLEGRO_TIMER* timer : all) al_destroy_timer(timer);
		}
		ALLEGRO_TIMER* AllegroTimerFactory::create(float time, bool automaticDestruction)
		{
			ALLEGRO_TIMER* temp = al_create_timer(time);
			if (temp) {
				if (automaticDestruction)
					all.push_back(temp);
				al_start_timer(temp);
			}
			return temp;
		}
		void AllegroTimerFactory::destroy(ALLEGRO_TIMER* timer)
		{
			int i;
			bool kill = false;
			for (i = 0; i < (int)all.size(); i++) {
				if (all[i] == timer)
					kill = true;
			}
			i--;
			if (kill) {
				all.erase(all.begin() + i);
				al_destroy_timer(timer);
			}
		}
		AllegroPrimitivesFactory::~AllegroPrimitivesFactory()
		{
			for (ALLEGRO_BITMAP* bitmap : all)
				al_destroy_bitmap(bitmap);
		}
		ALLEGRO_BITMAP* AllegroPrimitivesFactory::createEllipse(float radiusX, float radiusY, Color::AllegroColor color, bool filled, float thickness, bool automaticDestruction)
		{
			ALLEGRO_BITMAP* temp = al_create_bitmap(2 * (radiusX + thickness), (radiusY + thickness) * 2);

			if (temp) {
				al_set_target_bitmap(temp);

				if (filled)
					al_draw_filled_ellipse(radiusX, radiusY, radiusX, radiusY, color.GetColor());
				else
					al_draw_ellipse(radiusX + thickness, radiusY + thickness, radiusX, radiusY, color.GetColor(), thickness);
				al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));

				if (automaticDestruction)
					all.push_back(temp);
			}
			return temp;
		}
		ALLEGRO_BITMAP* AllegroPrimitivesFactory::createRoundedRectangle(float width, float height, float radius, Color::AllegroColor color, bool filled, float thickness, bool automaticDestruction)
		{
			ALLEGRO_BITMAP* temp = al_create_bitmap(width, height);

			if (temp) {
				al_set_target_bitmap(temp);

				if (filled)
					al_draw_filled_rounded_rectangle(0, 0, width, height, radius, radius, color.GetColor());
				else
					al_draw_rounded_rectangle(0, 0, width, height, radius, radius, color.GetColor(), thickness);
				al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));

				if (automaticDestruction)
					all.push_back(temp);
			}
			return temp;
		}
		ALLEGRO_BITMAP* AllegroPrimitivesFactory::createRectangle(float width, float height, Color::AllegroColor color, bool filled, float thickness, bool automaticDestruction)
		{
			ALLEGRO_BITMAP* temp = al_create_bitmap(width, height);

			if (temp) {
				al_set_target_bitmap(temp);

				if (filled)
					al_draw_filled_rectangle(0, 0, width, height, color.GetColor());
				else
					al_draw_rectangle(0, 0, width, height, color.GetColor(), thickness);
				al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));

				if (automaticDestruction)
					all.push_back(temp);
			}
			return temp;
		}
		ALLEGRO_BITMAP* AllegroPrimitivesFactory::createCircle(float radius, Color::AllegroColor color, bool filled, float thickness, bool automaticDestruction)
		{
			ALLEGRO_BITMAP* temp = al_create_bitmap((radius + thickness) * 2, (radius + thickness) * 2);
			if (temp) {
				al_set_target_bitmap(temp);
				if (filled)
					al_draw_filled_circle((radius + thickness), (radius + thickness), radius, color.GetColor());
				else
					al_draw_circle((radius + thickness), (radius + thickness), radius, color.GetColor(), thickness);
				al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));
				if (automaticDestruction)
					all.push_back(temp);
			}
			return temp;
		}
		void AllegroPrimitivesFactory::destroy(ALLEGRO_BITMAP* bitmap)
		{
			int i;
			bool kill = false;
			for (i = 0; i < (int)all.size(); i++) {
				if (all[i] == bitmap)
					kill = true;
			}
			i--;
			if (kill) {
				all.erase(all.begin() + i);
				al_destroy_bitmap(bitmap);
			}
		}
}
}