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

	~AllegroFontFactory() { for (AllegroFont * font : all) destroy(font); }

	AllegroFont * create(std::string file, int size) {

		AllegroFont * temp = new AllegroFont(file, size);

		all.push_back(temp);
	
		return temp;
	}

	void destroy(AllegroFont * font) {
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
private:
	std::vector<AllegroFont *> all;
};


class AllegroFont
{
public:
	AllegroFont(std::string fileName, int size);
	

private:
	~AllegroFont();
	friend void AllegroFontFactory::destroy(AllegroFont * font);
	ALLEGRO_FONT * font = nullptr;

};

