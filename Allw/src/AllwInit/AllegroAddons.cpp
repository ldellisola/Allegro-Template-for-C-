#include "AllwInit/AllegroAddons.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_video.h>
#include <allegro5/allegro_native_dialog.h>

namespace Allw {
	namespace Init {

		ImageAddon::ImageAddon()
		{
			if (al_init_image_addon())
				this->initSuccess();
			else
				throw Exception::AllegroInitException();
		}

		ImageAddon::~ImageAddon()
		{
			al_shutdown_image_addon();
		}

		NativeDialogAddon::NativeDialogAddon()
		{
			if (al_init_native_dialog_addon())
				this->initSuccess();
			else
				throw Exception::AllegroInitException();
		}

		NativeDialogAddon::~NativeDialogAddon()
		{
			al_shutdown_native_dialog_addon();
		}

		AudioAddon::AudioAddon()
		{
			if (al_install_audio() && al_init_acodec_addon())
				this->initSuccess();
			else
				throw Exception::AllegroInitException();
		}

		AudioAddon::~AudioAddon()
		{
			al_uninstall_audio();
		}

		FontAddon::FontAddon()
		{
			if (al_init_font_addon() && al_init_ttf_addon())
				this->initSuccess();
			else
				throw Exception::AllegroInitException();
		}

		FontAddon::~FontAddon()
		{
			al_shutdown_font_addon();
			al_shutdown_ttf_addon();
		}

		KeyboardAddon::KeyboardAddon()
		{
			if (al_install_keyboard())
				this->initSuccess();
			else
				throw Exception::AllegroInitException();
		}

		KeyboardAddon::~KeyboardAddon()
		{
			al_uninstall_keyboard();
		}

		DisplayAddon::DisplayAddon(float x, float y)
		{
			if (x != Init::NoValue && y != Init::NoValue)
				display = al_create_display(x, y);
			else if (x == Init::NoValue || y == Init::NoValue)
				this->initSuccess();
			else if (x != Init::NoValue && y != Init::NoValue && display != nullptr)
				this->initSuccess();
			else
				throw Exception::AllegroInitException();
		}

		void DisplayAddon::setDisplayColor(Color::AllegroColor color)
		{
			al_clear_to_color(color.GetColor());
		}

		void DisplayAddon::updateDisplay()
		{
			al_flip_display();
		}

		ALLEGRO_DISPLAY* DisplayAddon::getDisplay()
		{
			return display;
		}

		DisplayAddon::~DisplayAddon()
		{
			if (display != nullptr)
				al_destroy_display(display);
		}

		MouseAddon::MouseAddon()
		{
			if (al_install_mouse())
				this->initSuccess();
			else
				throw Exception::AllegroInitException();
		}

		MouseAddon::~MouseAddon()
		{
			al_uninstall_mouse();
		}

		TimerAddon::TimerAddon()
		{
			this->initSuccess();
		}

		TimerAddon::TimerAddon(float fps)
		{
			if (refresh = al_create_timer(1 / (double)fps)) {
				this->initSuccess();
				al_start_timer(this->refresh);
			}
			else
				throw Exception::AllegroInitException();
		}

		ALLEGRO_TIMER* TimerAddon::getRefreshTimer()
		{
			return refresh;
		}

		TimerAddon::~TimerAddon()
		{
			if (refresh != nullptr)
				al_destroy_timer(refresh);
		}

		PrimitivesAddon::PrimitivesAddon()
		{
			if (al_init_primitives_addon())
				this->initSuccess();
			else
				throw Exception::AllegroInitException();
		}

		PrimitivesAddon::~PrimitivesAddon()
		{
			al_shutdown_primitives_addon();
		}

		EventsAddon::EventsAddon()
		{
			if (eventQueue = al_create_event_queue())
				this->initSuccess();
			else
				throw Exception::AllegroInitException();
		}

		void EventsAddon::registerEventSourceAddon(MouseAddon * mouse)
		{
			al_register_event_source(eventQueue, al_get_mouse_event_source());
		}

		void EventsAddon::registerEventSourceAddon(KeyboardAddon * keyboard)
		{
			al_register_event_source(eventQueue, al_get_keyboard_event_source());
		}

		void EventsAddon::registerEventSourceAddon(DisplayAddon * display)
		{
			al_register_event_source(eventQueue, al_get_display_event_source(display->getDisplay()));
		}

		void EventsAddon::registerEventSourceAddon(TimerAddon * timer)
		{
			al_register_event_source(eventQueue, al_get_timer_event_source(timer->getRefreshTimer()));
		}

		void EventsAddon::registerEventSource(ALLEGRO_VIDEO * video)
		{
			al_register_event_source(eventQueue, al_get_video_event_source(video));
		}

		void EventsAddon::registerEventSource(ALLEGRO_DISPLAY * disp)
		{
			al_register_event_source(eventQueue, al_get_display_event_source(disp));
		}

		void EventsAddon::registerEventSource(ALLEGRO_TIMER * timer)
		{
			al_register_event_source(eventQueue, al_get_timer_event_source(timer));
		}

		ALLEGRO_EVENT_QUEUE* EventsAddon::getEventQueue()
		{
			return eventQueue;
		}

		EventsAddon::~EventsAddon()
		{
			if (eventQueue != nullptr) al_destroy_event_queue(eventQueue);
		}

		VideoAddon::VideoAddon()
		{
			if (al_init_video_addon())
				this->initSuccess();
			else
				throw Exception::AllegroInitException();
		}

		VideoAddon::~VideoAddon()
		{
			al_shutdown_video_addon();
		}
	}
}




