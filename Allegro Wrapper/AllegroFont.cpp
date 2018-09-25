#include "AllegroFont.h"

AllegroFont::AllegroFont(std::string fileName, int size)
{
	this->font = al_load_ttf_font(fileName.c_str(), -size, 0);
}

AllegroFont::~AllegroFont()
{
	if (this->font != nullptr)
		al_destroy_font(this->font);
}
