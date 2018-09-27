#include "AllegroFont.h"

AllegroFont::AllegroFont(std::string fileName, int size, unsigned int ID)
{
	this->font = al_load_ttf_font(fileName.c_str(), -size, 0);
	this->size = size;
	this->ID = ID;
}

void AllegroFont::drawCentredText(std::string text, ALLEGRO_COLOR color, float width, float height)
{
	al_draw_text(this->font, color, width / 2.0, (height - this->previewTextHeight()) / 2.0, ALLEGRO_ALIGN_CENTRE, text.c_str());
}

void AllegroFont::drawLeftText(std::string text, ALLEGRO_COLOR color, float x, float y)
{
	al_draw_text(this->font, color, x, y, ALLEGRO_ALIGN_LEFT, text.c_str());

}

void AllegroFont::drawRightText(std::string text, ALLEGRO_COLOR color, float x, float y)
{
	al_draw_text(this->font, color, x, y, ALLEGRO_ALIGN_RIGHT, text.c_str());

}

float AllegroFont::previewTextWidth(std::string text)
{
	return al_get_text_width(this->font,text.c_str());
}

float AllegroFont::previewTextHeight()
{
	return al_get_font_line_height(this->font);
}

unsigned int AllegroFont::getID()
{
	return this->ID;
}

AllegroFont::~AllegroFont()
{
	if (this->font != nullptr)
		al_destroy_font(this->font);
}

AllegroFont * AllegroFontFactory::create(std::string file, int size, unsigned int ID)
{
	AllegroFont * temp = new AllegroFont(file, size, ID);

	all.push_back(temp);

	return temp;
}

void AllegroFontFactory::destroy(AllegroFont * font)
{
	int i;
	bool kill = false;
	for (i = 0; i < all.size(); i++) {
		if (all[i] == font)
			kill = true;
	}
	i--;
	if (kill) {
		all.erase(all.begin() + i);
		delete font;
	}
}

void AllegroFontFactory::destroy(unsigned int ID)
{
	int i;
	bool kill = false;
	for (i = 0; i < all.size(); i++) {
		if (all[i]->getID() == ID)
			kill = true;
	}
	i--;
	if (kill) {
		delete all[i];
		all.erase(all.begin() + i);
		
	}
}

AllegroFont * AllegroFontFactory::recover(unsigned int ID)
{
	int i;
	bool kill = false;
	for (i = 0; i < all.size(); i++) {
		if (all[i]->getID() == ID)
			return all[i];
	}
	return nullptr;
}

void AllegroFontFactory::deleteFont(AllegroFont * font)
{
	delete font;
}
