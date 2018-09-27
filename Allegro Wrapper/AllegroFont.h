#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>

#include <string>
#include <vector>

class AllegroFont;

class AllegroFontFactory
{
public:
	AllegroFontFactory() {}

	~AllegroFontFactory() { for (AllegroFont * font : all) deleteFont(font); }


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

	// DO NOT USE.
	void deleteFont(AllegroFont* font);
private:

	
	std::vector<AllegroFont *> all;
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

	// It returns the lenght of the text
	//
	//	-std::string text:			Text to be analized.
	float previewTextWidth(std::string text);

	// It returns the height of 1 line of text
	//
	//	-std::string text:			Text to be analized.
	float previewTextHeight(std::string text);

	// It retrieves the ID of a font.
	unsigned int getID();

private:
	~AllegroFont();
	friend void AllegroFontFactory::deleteFont(AllegroFont * font);
	friend void AllegroFontFactory::destroy(AllegroFont * font);
	friend void AllegroFontFactory::destroy(unsigned int ID);
	unsigned int ID;
	int size;
	ALLEGRO_FONT * font = nullptr;

};

