#pragma once
#include <string>
#include <vector>
#include <stdint.h>
#include <map>

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>




using namespace std;

enum class MenuFlags
{
	Enabled, Disabled, Checkbox, checkedBox
};


class AllegroMenu
{
public:
	AllegroMenu();
	AllegroMenu(ALLEGRO_MENU_INFO * completedMenu);
	~AllegroMenu();

	// ID != 0
	void appendItem(string title, uint16_t uniqueid, MenuFlags flag);
	void insertItem(string title, uint16_t uniqueID, MenuFlags flag, unsigned int pos);
	void appendSubItem(uint16_t parentID, string title, uint16_t uniqueID, MenuFlags flag);
	void insertSubItem();

	ALLEGRO_EVENT_SOURCE * getMenuEventSource(int menuID);
	ALLEGRO_EVENT_SOURCE * getAllMenuEventSource();

private:
	vector<ALLEGRO_MENU *> menus;
	map<uint16_t, unsigned int> position;
};


