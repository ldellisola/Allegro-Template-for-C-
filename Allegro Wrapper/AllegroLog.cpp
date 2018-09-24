#include "AllegroLog.h"
#include <fstream>



AllegroLog::AllegroLog(std::string title, bool logToFile , TextLogFlag flag)
{
	if (this->logWindow == nullptr)
	{
		this->logWindow = al_open_native_text_log(title.c_str(), (int)flag);
	}
	this->logToFile = logToFile;
}


AllegroLog::~AllegroLog()
{
	if (this->logWindow != nullptr)
		al_close_native_text_log(this->logWindow);
	if (this->logToFile) {
		std::ofstream output("debug.log", std::ofstream::out);

		output << this->log << std::endl;
		output.close();
	}
}

void AllegroLog::close()
{
	if (this->logWindow != nullptr) {
		al_close_native_text_log(logWindow);
		logWindow = nullptr;
	}
}

ALLEGRO_EVENT_SOURCE * AllegroLog::getEventSource()
{
	return al_get_native_text_log_event_source(this->logWindow);
}

AllegroLog & AllegroLog::operator<<(std::string text)
{
	if (logWindow != nullptr)
		al_append_native_text_log(this->logWindow, text.c_str());
	if (this->logToFile)
		this->log += text;
	return *this;
}

AllegroLog & AllegroLog::operator<<(char letter)
{
	char text[2] = { letter,0 };
	if (logWindow != nullptr)
		al_append_native_text_log(this->logWindow,text );
	if (this->logToFile)
		this->log += text;
	return *this;

}

AllegroLog & AllegroLog::operator<<(int num)
{
	if (logWindow != nullptr)
		al_append_native_text_log(this->logWindow, std::to_string(num).c_str());
	if (this->logToFile)
		this->log += std::to_string(num);
	return *this;
}

AllegroLog & AllegroLog::operator<<(float num)
{
	if (logWindow != nullptr)
		al_append_native_text_log(this->logWindow, std::to_string(num).c_str());
	if (this->logToFile)
		this->log += std::to_string(num);
	return *this;
}

AllegroLog & AllegroLog::operator<<(double num)
{
	if (logWindow != nullptr)
		al_append_native_text_log(this->logWindow, std::to_string(num).c_str());
	if (this->logToFile)
		this->log += std::to_string(num);
	return *this;
}
