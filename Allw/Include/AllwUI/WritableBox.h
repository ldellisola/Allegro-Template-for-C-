#pragma once

#include <string>
#include <vector>




#include "AllwBasics/AllegroFont.h"
#include "AllwUI/AllegroBox.h"
#include "AllwBasics/AllegroColor.h"

typedef struct ALLEGRO_KEYBOARD_EVENT ALLEGRO_KEYBOARD_EVENT;

#define KeyPressedTimeThreshold (0.00001)

namespace Allw {
	namespace UI {

		enum class KeyboardMode
		{
			Numeric, Alphabetic, Alphanumeric
		};

		struct AllegroWritableBoxData
		{
			KeyboardMode mode;
			float x, y;
			unsigned int width, height;
			Font::AllegroFont * font;
			Color::AllegroColor fontColor;
		};


		class AllegroWritableBox :public AllegroBox {
		public:
			// Constructor: It creates a new font.
			//
			//		- KeyboardMode mode:		the mode of the keyboard. It can be Numeric, Alphanumeric or Alphabetic
			//		- float x:					the initial X coordinate.
			//		- float y:					the initial Y coordinate.
			//		- unsigned int width:		the width of the box.
			//		- unsigned int height:		the height of the box. 
			//		- int fontSize:				size of the font.
			//		- AllegroFont * font:		Font to be loaded
			//		- Color::AllegroColor fontColor:	color of the font.
			AllegroWritableBox(KeyboardMode mode, float x, float y, unsigned int width, unsigned int height, Font::AllegroFont * font, Color::AllegroColor fontColor, unsigned int boxID = DefaultID)
				:AllegroBox((unsigned int)x, (unsigned int)y, width, height, boxID) {
				this->setBoxType(BoxType::Writable);
				this->font = font;
				this->fontColor = fontColor;
				foreingFont = false;
				this->mode = mode;

			}


			// Constructor: It will take an existing font. This is a good option for when you have to create a lot of identical Boxes or you need to 
			//				create a box inside another function and you need all of this information from outside of it.
			//
			//		- AllegroWrittenBoxData& data: a structure with all the data of a box
			AllegroWritableBox(AllegroWritableBoxData& data, unsigned int boxID = DefaultID)
				: AllegroBox ((unsigned int)data.x, (unsigned int)data.y, data.width, data.height, boxID) {
				this->setBoxType(BoxType::Writable);
				this->fontColor = data.fontColor;
				foreingFont = true;
				this->mode = data.mode;
				this->font = data.font;
			}

			~AllegroWritableBox();

			// It returns the text that the user has typed
			std::string getText();

			// It takes a keyboard event and uses the key that was pressed. 
			void input(Event::KeyCharEvent& ev);

			// It restarts the texts that the user typed
			void clearText();

		private:
			// It updates the internal bitmap of the box.
			void setUp();
			// If the key is a number, it will add it to the text.
			void addNumber(int num);
			// If the key is a letter, it will add it to the text.
			void addLetter(int let, unsigned int modifiers);

			// If the text is 'backspace' it will delete a key.
			void deleteLetter(int let);

			double timeStamp = 0;

			std::string text = "";
			KeyboardMode mode;
			Color::AllegroColor fontColor;
			Font::AllegroFont * font = nullptr;
			bool foreingFont = false;
		};

	}
}