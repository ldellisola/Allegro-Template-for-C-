#pragma once
#include <string>
#include <vector>

#include "AllwBasics/AllegroColor.h"


typedef struct ALLEGRO_BITMAP ALLEGRO_BITMAP;
typedef struct ALLEGRO_TIMER ALLEGRO_TIMER;
typedef union ALLEGRO_EVENT ALLEGRO_EVENT;
typedef struct ALLEGRO_DISPLAY ALLEGRO_DISPLAY;
typedef struct  ALLEGRO_EVENT_QUEUE ALLEGRO_EVENT_QUEUE;

namespace Allw {
	namespace Factories {

		class AllegroDisplayFactory
		{
		public:
			AllegroDisplayFactory() {}
			~AllegroDisplayFactory();
			/*
				El modo de destruccion automatico hace que se destruyan todas las pantallas cuando se destruye al objeto. De estar desactivado se tienen que destruir manualemente
			*/
			ALLEGRO_DISPLAY* create(unsigned int w, unsigned int h, bool automaticDestruction = true);
			void destroy(ALLEGRO_DISPLAY * display);

		private:
			std::vector<ALLEGRO_DISPLAY *> all;
		};

		enum class PopUpReturn
		{
			Yes, No, Closed
		};
		enum class PopUpType
		{
			Warn = 1, Error = 2, OkCancel = 4, YesNo = 8, Question = 16,
		};

		class AllegroPopUpFactory
		{
		public:
			AllegroPopUpFactory() {}
			~AllegroPopUpFactory() {}

			PopUpReturn create(std::string title, std::string heading, std::string text, PopUpType type, ALLEGRO_DISPLAY* display = nullptr);
		};

		/*
			Crea bitmaps
		*/

		class AllegroBitmapFactory
		{
		public:
			AllegroBitmapFactory() {}
			~AllegroBitmapFactory();
			ALLEGRO_BITMAP* create(unsigned int w, unsigned int h, bool automaticDestruction = true);
			void destroy(ALLEGRO_BITMAP* bitmap);
		private:
			std::vector<ALLEGRO_BITMAP *> all;
		};


		// Dudo si esto deberia ser una factory o un tipo nuevo de dato
		



		class AllegroTimerFactory
		{
		public:
			AllegroTimerFactory() {}

			~AllegroTimerFactory();
			ALLEGRO_TIMER* create(float time, bool automaticDestruction = true);

			void destroy(ALLEGRO_TIMER* timer);

		private:
			std::vector<ALLEGRO_TIMER*>all;
		};


		class AllegroPrimitivesFactory
		{
		public:
			AllegroPrimitivesFactory() {}

			~AllegroPrimitivesFactory();

			ALLEGRO_BITMAP* createEllipse(float radiusX, float radiusY, Color::AllegroColor color, bool filled = true, float thickness = 0, bool automaticDestruction = true);

			ALLEGRO_BITMAP* createRoundedRectangle(float width, float height, float radius, Color::AllegroColor color, bool filled = true, float thickness = 0, bool automaticDestruction = true);

			ALLEGRO_BITMAP* createRectangle(float width, float height, Color::AllegroColor color, bool filled = true, float thickness = 0, bool automaticDestruction = true);

			ALLEGRO_BITMAP* createCircle(float radius, Color::AllegroColor color, bool filled = true, float thickness = 0, bool automaticDestruction = true);


			void destroy(ALLEGRO_BITMAP* bitmap);


		private:
			std::vector<ALLEGRO_BITMAP *> all;

		};

	}
}

