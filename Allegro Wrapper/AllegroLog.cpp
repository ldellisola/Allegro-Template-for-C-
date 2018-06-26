#include "AllegroLog.h"



AllegroLog::AllegroLog(string title, TextLogFlag flag)
{
	if (this->logFile == nullptr)
	{
		this->logFile = al_open_native_text_log(title.c_str(), (int)flag);
	}
}


AllegroLog::~AllegroLog()
{
	if (this->logFile != nullptr)
		al_close_native_text_log(this->logFile);
}

void AllegroLog::close()
{
	if (this->logFile != nullptr) {
		al_close_native_text_log(logFile);
		logFile = nullptr;
	}
}

ALLEGRO_EVENT_SOURCE * AllegroLog::getEventSource()
{
	return al_get_native_text_log_event_source(this->logFile);
}

AllegroLog & AllegroLog::operator<<(string text)
{
	if (logFile != nullptr)
		al_append_native_text_log(this->logFile, text.c_str());
	return *this;
}

AllegroLog & AllegroLog::operator<<(char letter)
{
	char text[2] = { letter,0 };
	if (logFile != nullptr)
		al_append_native_text_log(this->logFile,text );
	return *this;

}

AllegroLog & AllegroLog::operator<<(int num)
{
	if (logFile != nullptr)
		al_append_native_text_log(this->logFile, to_string(num).c_str());
	return *this;
}

AllegroLog & AllegroLog::operator<<(float num)
{
	if (logFile != nullptr)
		al_append_native_text_log(this->logFile, to_string(num).c_str());
	return *this;
}

AllegroLog & AllegroLog::operator<<(double num)
{
	if (logFile != nullptr)
		al_append_native_text_log(this->logFile, to_string(num).c_str());
	return *this;
}
