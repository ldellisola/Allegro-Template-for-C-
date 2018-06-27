#include "AllegroMenu.h"



AllegroMenu::AllegroMenu()
{
}

AllegroMenu::AllegroMenu(ALLEGRO_MENU_INFO * completedMenu)
{
	this->menus.push_back(al_build_menu(completedMenu));
}

AllegroMenu::~AllegroMenu()
{
	for (ALLEGRO_MENU * menu : menus)
		al_destroy_menu(menu);
}

void AllegroMenu::appendItem(string title, uint16_t uniqueID, MenuFlags flag)
{
	al_append_menu_item(menus[0], title.c_str(), uniqueID, (int)flag, nullptr, nullptr);
}

void AllegroMenu::insertItem(string title, uint16_t uniqueID, MenuFlags flag, unsigned int pos)
{
	al_insert_menu_item(menus[0], (0-pos), title.c_str(), uniqueID, (int)flag, nullptr, nullptr);
	position[uniqueID] = pos;
}

void AllegroMenu::appendSubItem(uint16_t parentID, string title, uint16_t uniqueID, MenuFlags flag)
{
	ALLEGRO_MENU * father = al_find_menu(menus[0], parentID);
	if (father != nullptr) {		// Me fijo si es un menu o no

		al_append_menu_item(father, title.c_str(), uniqueID, (int)flag, nullptr, nullptr);
	}
	else {
		ALLEGRO_MENU * parentMenu;
		int parentIndex;
		if (al_find_menu_item(menus[0], parentID, &parentMenu, &parentIndex)) {
			int parentFlag = al_get_menu_item_flags(parentMenu, -parentIndex);
			string parentTitle = al_get_menu_item_caption(parentMenu, -parentIndex);
			al_remove_menu_item(menus[0], parentIndex);

			menus.push_back(al_create_menu());
			al_append_menu_item(menus[menus.size() - 1], title.c_str(), uniqueID, (int)flag, nullptr, nullptr);

			al_insert_menu_item(menus[0],-parentIndex, parentTitle.c_str(), parentID, parentFlag, nullptr, menus[menus.size() - 1]);
		}
	}


	
}




