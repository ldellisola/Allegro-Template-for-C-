#pragma once
#include "AllegroAddons.h"
#include "AllegroFactory.h"
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
		void setDisplayColor(ALLEGRO_COLOR color);
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
		ImageAddon * imageAddon = nullptr;
		AudioAddon * audioAddon = nullptr;
		FontAddon * fontAddon = nullptr;
		KeyboardAddon * keyboardAddon = nullptr;
		DisplayAddon * displayAddon = nullptr;
		MouseAddon * mouseAddon = nullptr;
		EventsAddon * eventsAddon = nullptr;
		TimerAddon * timerAddon = nullptr;
		PrimitivesAddon * primitivesAddon = nullptr;
		VideoAddon * videoAddon = nullptr;
		NativeDialogAddon * nativeDialogAddon = nullptr;
	};

}