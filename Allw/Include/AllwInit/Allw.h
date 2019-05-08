#pragma once
#include "AllegroAddons.h"
#include "AllegroFactory.h"
#include "AllwBasics/AllegroColor.h"

typedef struct ALLEGRO_VIDEO ALLEGRO_VIDEO;
typedef struct ALLEGRO_DISPLAY ALLEGRO_DISPLAY ;
typedef struct ALLEGRO_TIMER ALLEGRO_TIMER;
typedef struct ALLEGRO_EVENT_QUEUE ALLEGRO_EVENT_QUEUE;

namespace Allw {

	class Allw
	{
	public:
		// Constructor Automatizado: le podes ingresar un modo y otros valores para olvidarte de la inicializacion de allegro.
		Allw(Init::Mode mode, float width = Init::NoValue, float height = Init::NoValue, float fps = Init::NoValue);
		// Constructor manual, solo inicializa allegro, si queres inicializar otro addon, hacelo a mano con las funciones que ofrece la clase.
		Allw();
		// Destructor: elimina todo lo que se haya creado dinamicamente.
		~Allw();
		// Miscelaneo

		bool inhibitScreenSaver();
		bool allowScreenSaver();
	    // The program stops for a given ammount of seconds
	    void wait(double seconds);


		// Funciones de Events
		void registerAllAvailableEventsSource();						// Se fija los Addons instalados y registra las event sources de estos
		void registerEventSource(ALLEGRO_VIDEO * video);
		void registerEventSource(ALLEGRO_DISPLAY *disp);
		void registerEventSource(ALLEGRO_TIMER * timer);

		void unregisterEventSource(ALLEGRO_VIDEO * video);
		void unregisterEventSource(ALLEGRO_DISPLAY *disp);
		void unregisterEventSource(ALLEGRO_TIMER * timer);

		ALLEGRO_EVENT_QUEUE * getEventQueue();

		// Funciones de Display
		void setDisplayColor(Color::AllegroColor color);
		void setDisplayColor(const char * color);
		void setDisplayName(const char * name);
		void setMainDisplay();
		void updateDisplay();
		ALLEGRO_DISPLAY * getDisplay();


		// instaladores
		void initImageAddon();
		void initAudioAddon();
		void initFontAddon();
		void initKeyboardAddon();
		void initDisplayAddon(float x = Init::NoValue, float y = Init::NoValue);						// Inicializa el display, si no se le pasan argumentos, no hace nada.
		void initMouseAddon();
		void initEventsAddon();
		void initTimerAddon(float fps);									// Inicializa al timer con un timer de refreshrate para la pantalla
		void initTimerAddon();											// Lo hace sin craer ningun timer
		void initPrimitivesAddon();
		void initVideoAddon();
		void initNativeDialogAddon();

		// eliminadores
		void uninstallImageAddon();
		void uninstallAudioAddon();
		void uninstallFontAddon();
		void uninstallKeyboardAddon();
		void uninstallDisplayAddon();
		void uninstallMouseAddon();
		void uninstallEventsAddon();
		void uninstallTimerAddon();
		void uninstallPrimitivesAddon();
		void uninstallVideoAddon();
		void uninstallNativeDialogAddon();
	private:
		bool success = false;

		// Addons de allegro
		Init::ImageAddon * imageAddon = nullptr;
		Init::AudioAddon * audioAddon = nullptr;
		Init::FontAddon * fontAddon = nullptr;
		Init::KeyboardAddon * keyboardAddon = nullptr;
		Init::DisplayAddon * displayAddon = nullptr;
		Init::MouseAddon * mouseAddon = nullptr;
		Init::EventsAddon * eventsAddon = nullptr;
		Init::TimerAddon * timerAddon = nullptr;
		Init::PrimitivesAddon * primitivesAddon = nullptr;
		Init::VideoAddon * videoAddon = nullptr;
		Init::NativeDialogAddon * nativeDialogAddon = nullptr;
	};

}