#pragma once
#include <string>

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

using namespace std;

enum class TextLogFlag
{
	Regular, NoClose, Monospace
};


// It creates a window to debug in case you don't want to use the terminal
class AllegroLog
{
public:
	AllegroLog(string title, TextLogFlag flag);
	~AllegroLog();

	void close();

	ALLEGRO_EVENT_SOURCE* getEventSource();

	AllegroLog& operator<< (string text);
	AllegroLog& operator<< (char letter);
	AllegroLog& operator<< (int num);
	AllegroLog& operator<< (float num);
	AllegroLog& operator<< (double num);

private:
	ALLEGRO_TEXTLOG * logFile = nullptr;
};

