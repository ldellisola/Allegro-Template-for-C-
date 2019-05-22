#pragma once

#include "AllwEvents/AllegroEvent.h"

typedef struct ALLEGRO_KEYBOARD_EVENT ALLEGRO_KEYBOARD_EVENT;


namespace Allw {


	enum class KeyCode
	{
		KeyA = 1,
		KeyB = 2,
		KeyC = 3,
		KeyD = 4,
		KeyE = 5,
		KeyF = 6,
		KeyG = 7,
		KeyH = 8,
		KeyI = 9,
		KeyJ = 10,
		KeyK = 11,
		KeyL = 12,
		KeyM = 13,
		KeyN = 14,
		KeyO = 15,
		KeyP = 16,
		KeyQ = 17,
		KeyR = 18,
		KeyS = 19,
		KeyT = 20,
		KeyU = 21,
		KeyV = 22,
		KeyW = 23,
		KeyX = 24,
		KeyY = 25,
		KeyZ = 26,

		Key0 = 27,
		Key1 = 28,
		Key2 = 29,
		Key3 = 30,
		Key4 = 31,
		Key5 = 32,
		Key6 = 33,
		Key7 = 34,
		Key8 = 35,
		Key9 = 36,

		KeyPad0 = 37,
		KeyPad1 = 38,
		KeyPad2 = 39,
		KeyPad3 = 40,
		KeyPad4 = 41,
		KeyPad5 = 42,
		KeyPad6 = 43,
		KeyPad7 = 44,
		KeyPad8 = 45,
		KeyPad9 = 46,

		KeyFn0 = 47,
		KeyFn2 = 48,
		KeyFn3 = 49,
		KeyFn4 = 50,
		KeyFn5 = 51,
		KeyFn6 = 52,
		KeyFn7 = 53,
		KeyFn8 = 54,
		KeyFn9 = 55,
		KeyFn10 = 56,
		KeyFn11 = 57,
		KeyFn12 = 58,

		KeyEscape = 59,
		KeyTilde = 60,
		KeyMinus = 61,
		KeyEquals = 62,
		KeyBackspace = 63,
		KeyTab = 64,
		KeyOpenBrace = 65,
		KeyCloseBrace= 66,
		KeyEnter = 67,
		KeySemicolon = 68,
		KeyQuote = 69,
		KeyBackSlash = 70,
		KeyBackSlash2 = 71, /* DirectInput calls this DIK_OEM_102: "< > | on UK/Germany keyboards" */
		KeyComma = 72,
		KeyFullStop = 73,
		KeySlash = 74,
		KeySpace = 75,

		KeyInsert = 76,
		KeyDelete = 77,
		KeyHome = 78,
		KeyEnd = 79,
		KeyPageUp = 80,
		KeyPageDown = 81,
		KeyArrowLeft = 82,
		KeyArrowRight = 83,
		KeyArrowUp = 84,
		KeyArrowDown = 85,

		KeyPadSlash = 86,
		KeyPadAsterisk = 87,
		KeyPadMinus = 88,
		KeyPadPlus = 89,
		KeyPadDelete = 90,
		KeyPadEnter = 91,

		KeyPrintScreen = 92,
		KeyPause = 93,

		KeyABNTC1 = 94,
		KeyYen = 95,
		KeyKana = 96,
		KeyConvert = 97,
		KeyNoConvert = 98,
		KeyAt = 99,
		KeyCircumflex = 100,
		KeyColon2 = 101,
		KeyKanji = 102,


		KeyUnknown = 128,

		/* All codes up to before ALLEGRO_KEY_MODIFIERS can be freely
		 * assignedas additional unknown keys, like various multimedia
		 * and application keys keyboards may have.
		 */

		KeyModifiers = 215,

		KeyLeftShift = 215,
		KeyRightShift = 216,
		KeyLeftControl = 217,
		KeyRightControl = 218,
		KeyAlt = 219,
		KeyAltGr = 220,
		KeyLeftWin = 221,
		KeyRightWin = 222,
		KeyMenu = 223,
		KeyScrollLock = 224,
		KeyNumLock = 225,
		KeyCapsLock = 226,

		KeyMax
	};



	enum class Modificators
	{
		KeyModShift = 0x00001,
		KeyModControl = 0x00002,
		KeyModAlt = 0x00004,
		KeyModLeftWin = 0x00008,
		KeyModRightWin = 0x00010,
		KeyModMenu = 0x00020,
		KeyModeAltGr = 0x00040,
		KeyModCommand = 0x00080,
		KeyModScrollLock = 0x00100,
		KeyModNumLock = 0x00200,
		KeyModCapsLock = 0x00400,
		KeyModINALTSEQ = 0x00800,
		KeyModAccent1 = 0x01000,
		KeyModAccent2 = 0x02000,
		KeyModAccent3 = 0x04000,
		KeyModAccent4 = 0x08000
	};



	namespace Event {

		class KeyboardEvent : public AllegroEvent {
		public:

			int getKeyCode();
			


			EVENT_CLASS_CATEGORY(Category::Keyboard)

		protected:			
			KeyboardEvent(ALLEGRO_KEYBOARD_EVENT& data);

		protected:
			int keyCode = 0;
			unsigned int modifier = 0;
			int unicode = 0;
			bool repeat = false;
		};

		class KeyCharEvent : public KeyboardEvent {
		public:
			KeyCharEvent(ALLEGRO_KEYBOARD_EVENT& data)
				:KeyboardEvent(data){}

			int getChar();
			bool isRepeated();
			unsigned int getModifier();

			EVENT_CLASS_TYPE(KeyChar)
		};

		class KeyPressedEvent : public KeyboardEvent {
		public:
			KeyPressedEvent(ALLEGRO_KEYBOARD_EVENT& data)
				: KeyboardEvent(data){}
			EVENT_CLASS_TYPE(KeyDown)
		private:
		};

		class KeyReleasedEvent : public KeyboardEvent {
		public:
			KeyReleasedEvent(ALLEGRO_KEYBOARD_EVENT& data)
				: KeyboardEvent(data) {}
			EVENT_CLASS_TYPE(KeyUp)

		};
	}
}