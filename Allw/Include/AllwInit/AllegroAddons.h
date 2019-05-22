#pragma once


#include "AllwMisc/AllegroException.h"
#include "AllwBasics/AllegroColor.h"


// Clase Padre de todos los addons, define los metodos para verificar que se instalaron con exito
class Addon {
public:
	virtual bool getSuccess() { return success; }
protected:
	virtual void initSuccess() { this->success = true; }
private:
	bool success = false;
}; 

typedef struct ALLEGRO_VIDEO ALLEGRO_VIDEO;
typedef struct ALLEGRO_DISPLAY ALLEGRO_DISPLAY;
typedef struct ALLEGRO_TIMER ALLEGRO_TIMER;
typedef struct ALLEGRO_EVENT_QUEUE ALLEGRO_EVENT_QUEUE;


namespace Allw {

	namespace Init {

		// Modos de inicializacion de allegro:
		// Modo Basic: Inicializa display,keyboard, Font, Primitives.
		// Modo Full: Inicializa todos los addons.
		// Modo Events: Inicializa lo mismo que el modo Basic pero agrega eventos, mouse y timer.
		// Modo Empty: Hay que inicializar todo manual luego de que se cree el objeto.
		enum class Mode
		{
			Basic, Full, Events, Empty
		};

		const unsigned int NoValue = 0;



		class ImageAddon : public Addon {
		public:
			ImageAddon();
			~ImageAddon();
		};


		class NativeDialogAddon : public Addon {
		public:
			NativeDialogAddon();
			~NativeDialogAddon();
		};


		class AudioAddon : public Addon {
		public:
			AudioAddon();
			~AudioAddon();
		};


		class FontAddon : public Addon {
		public:
			FontAddon();
			~FontAddon();
		};


		class KeyboardAddon : public Addon {
		public:
			KeyboardAddon();
			~KeyboardAddon();
		};

		
		class DisplayAddon : public Addon {
		public:
			DisplayAddon(float x = Init::NoValue, float y = Init::NoValue);

			void setDisplayColor(Color::AllegroColor color);
			void updateDisplay();

			ALLEGRO_DISPLAY* getDisplay();
			~DisplayAddon();
		private:
			ALLEGRO_DISPLAY* display = nullptr;
		};


		class MouseAddon : public Addon {
		public:
			MouseAddon();
			~MouseAddon();
		};


		class TimerAddon : public Addon {
		public:
			TimerAddon();
			TimerAddon(float fps);
			ALLEGRO_TIMER* getRefreshTimer();
			~TimerAddon();
		private:
			ALLEGRO_TIMER* refresh = nullptr;		// Este timer se encarga de los fps de la pantalla
		};


		class PrimitivesAddon : public Addon {
		public:
			PrimitivesAddon();
			~PrimitivesAddon();
		};


		class EventsAddon : public Addon {
		public:
			EventsAddon();

			void registerEventSourceAddon(MouseAddon* mouse);
			void registerEventSourceAddon(KeyboardAddon* keyboard);
			void registerEventSourceAddon(DisplayAddon* display);
			void registerEventSourceAddon(TimerAddon* timer);
			void registerEventSource(ALLEGRO_VIDEO* video);
			void registerEventSource(ALLEGRO_DISPLAY* disp);
			void registerEventSource(ALLEGRO_TIMER* timer);
			ALLEGRO_EVENT_QUEUE* getEventQueue();

			~EventsAddon();
		private:
			ALLEGRO_EVENT_QUEUE* eventQueue = nullptr;
		};

		class VideoAddon : public Addon {
		public:
			VideoAddon();
			~VideoAddon();
		};
	}
}