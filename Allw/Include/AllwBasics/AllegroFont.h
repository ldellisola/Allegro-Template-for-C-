#pragma once
#include <string>
#include <vector>


#include "AllwBasics/AllegroColor.h"
#include "AllwMisc/AllegroException.h"

typedef struct ALLEGRO_FONT ALLEGRO_FONT;

namespace Allw {
	namespace Font {


		class AllegroFont;

		class AllegroFontFactory
		{
		public:

			// It creates a font and stores it in the factory. The font will be automatically destroyed after the factory is destroyed
			//
			// -std::string file:			The name of the file of your font.
			//	-int size:					The size of your font. If it is a positive number, it will be in pixels.
			//	-unsigned int ID:			Unique ID given to any font in order to recognize it.
			AllegroFont * create(std::string file, int size, unsigned int ID);

			// It destroys a font from the factory given a pointer to the font.
			void destroy(AllegroFont * font);

			// It destroys a font from the factory given the ID of the font.
			void destroy(unsigned int ID);

			// It recovers a pointer to a font given its ID.
			AllegroFont * recover(unsigned int ID);

			static AllegroFontFactory& getInstance() {
				if (instance == nullptr) {
					instance = new AllegroFontFactory();
				}

				return *instance;
			}

			AllegroFontFactory(AllegroFontFactory const&) = delete;
			void operator=(AllegroFontFactory const&) = delete;

		private:

			
			AllegroFontFactory(){}
			static AllegroFontFactory * instance;
			~AllegroFontFactory();

			std::vector<AllegroFont *> fonts;
		};


		class AllegroFont
		{
		public:
			// Creates a font. IT SOULD ONLY BE CREATED VIA AllegroFontFactory!
			//
			//	-std::string fileName:		The name of the file of your font.
			//	-int size:					The size of your font. If it is a positive number, it will be in pixels.
			//	-unsigned int ID:			Unique ID given to any font in order to recognize it.
			AllegroFont(std::string fileName, int size, unsigned int ID);

			// Draws a given text in the middle of a given rectangle
			//
			//	std::string text:			Text to be written.
			//	Color::AllegroColor color:		The color in which the text will be written.
			//	float width:				The width of the rectangle.
			//	float height:				The height of the rectangle.
			void drawCentredText(std::string text, Color::AllegroColor color, float width, float height);

			// Draws a given text from left to right
			//
			//	std::string text:			Text to be written.
			//	Color::AllegroColor color:		The color in which the text will be written.
			//	float x:					X coordinate.
			//	float y:					Y coordinate.
			void drawLeftText(std::string text, Color::AllegroColor color, float x, float y);

			// Draws a given text from right to left
			//
			//	std::string text:			Text to be written.
			//	Color::AllegroColor color:		The color in which the text will be written.
			//	float x:					X coordinate.
			//	float y:					Y coordinate.
			void drawRightText(std::string text, Color::AllegroColor color, float x, float y);

			// It returns the lenght of the text
			//
			//	-std::string text:			Text to be analized.
			float previewTextWidth(std::string text);

			// It returns the height of 1 line of text
			//
			//	-std::string text:			Text to be analized.
			float previewTextHeight();

			// It retrieves the ID of a font.
			unsigned int getID();

			~AllegroFont();
		private:

			unsigned int ID;
			int size;
			ALLEGRO_FONT * font = nullptr;

		};

	}
}

