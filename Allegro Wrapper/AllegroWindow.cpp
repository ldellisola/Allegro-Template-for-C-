#include "AllegroWindow.h"



AllegroWindow::AllegroWindow(float w, float h, string name, string icon)
{
	width = w;
	height = h;

	if (name.size() > 0)
		setName(name);
	if (icon.size() > 0)
		setIcon(icon);
}

AllegroWindow::~AllegroWindow()
{

	close();
	if (icon != nullptr)
		al_destroy_bitmap(icon);
	if (image != nullptr)
		al_destroy_bitmap(image);
	if (customCursorSprite != nullptr)
		al_destroy_bitmap(customCursorSprite);

}

void AllegroWindow::addDrawing(ALLEGRO_BITMAP * bitmap, float x, float y, float scaledHeight, float scaledWidth)
{ 
	Drawing temp;
	temp.bitmap = bitmap;
	temp.x = x;
	temp.y = y;
	temp.height = al_get_bitmap_height(bitmap);
	temp.width = al_get_bitmap_width(bitmap);

	if (scaledHeight == 0)
		temp.scaledHeight = temp.height;
	else
		temp.scaledHeight = scaledHeight;
	if (scaledWidth == 0)
		temp.scaledWidth = temp.width;
	else 
		temp.scaledWidth = scaledWidth;
	drawings.push_back(temp);
}

void AllegroWindow::addBoxes(AllegroBox * box)
{
	this->boxes.push_back(box);
}


void AllegroWindow::removeDrawing(ALLEGRO_BITMAP * bitmap)
{
	bool kill = false; int i = 0;
	for ( i = 0; i < drawings.size() && !kill; i++) {
		if (drawings[i].bitmap == bitmap)
			kill = true;
	}
	i--;
	if (kill) {
		drawings.erase(drawings.begin() + i);
	}
}

void AllegroWindow::removeBox(AllegroBox & box)
{
	bool kill = false; int i = 0;
	for (i = 0; i < boxes.size() && !kill; i++) {
		if (*boxes[i] == box)
			kill = true;
	}
	i--;
	if (kill) {
		boxes.erase(boxes.begin() + i);
	}
}

void AllegroWindow::moveDrawing(ALLEGRO_BITMAP * bitmapToMove, float newX, float newY)
{
	bool move = false; int i = 0;
	for (int i = 0; i < drawings.size(); i++) {
		if (drawings[i].bitmap == bitmapToMove)
			move = true;
	}
	i--;
	if (move) {
		drawings[i].x = newX;
		drawings[i].y = newY;

	}
}

void AllegroWindow::setAsMain()
{
	if (on)
		al_set_target_backbuffer(this->display);
}

void AllegroWindow::open()
{
	if (!this->on) {
		this->on = true;
		this->display = al_create_display(width, height);
		this->setUp();
	}
}

void AllegroWindow::close()
{
	if (this->on) {
		this->on = false;
		if (customMouseCursor != nullptr)
			al_destroy_mouse_cursor(customMouseCursor);
		
		al_destroy_display(this->display);
		this->display = nullptr;
	}
}

void AllegroWindow::setBackground(ALLEGRO_COLOR color)
{
	this->color = color;
}

void AllegroWindow::setImageAsBackground()
{
	if (image != nullptr);
	backgroundImage = true;
}

void AllegroWindow::setColorAsBackground()
{
	this->backgroundImage = false;
}

void AllegroWindow::setImageBackground(string image)
{
	this->image = al_load_bitmap(image.c_str());
}

void AllegroWindow::update()
{
	if (on) {
		if (backgroundImage)
			al_draw_scaled_bitmap(this->image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image), 0, 0, this->width, this->height, 0);
		else
			al_clear_to_color(color);

		for (Drawing& drawing : drawings)
			al_draw_scaled_bitmap(drawing.bitmap, 0, 0,drawing.width, drawing.height , drawing.x, drawing.y, drawing.scaledWidth, drawing.scaledHeight, 0);	

		for (AllegroBox* box : boxes)
			box->draw();

		al_flip_display();
	}

}

void AllegroWindow::setName(string name)
{
	this->name = name;
	this->setUp();
}

void AllegroWindow::setIcon(string icon)
{
	this->icon = al_load_bitmap(icon.c_str());
	this->setUp();
}

void AllegroWindow::setPosition(float x, float y)
{
	al_set_window_position(this->display, x, y);
}

void AllegroWindow::setFullScreen()
{
	this->screenMode = ScreenMode::FullScreen;
	if (this->on) 
		al_set_display_flag(this->display, ALLEGRO_FULLSCREEN_WINDOW, true);

}

void AllegroWindow::setFrameless()
{
	this->screenMode = ScreenMode::Frameless;
	if (this->on) 
		al_set_display_flag(this->display, ALLEGRO_FRAMELESS, true);

}

void AllegroWindow::setMaximize()
{
	this->screenMode = ScreenMode::Maximized;
	if (this->on)
		al_set_display_flag(this->display, ALLEGRO_MAXIMIZED, true);

}

void AllegroWindow::setRegular()
{
	this->clearScreenMode();
	this->screenMode = ScreenMode::Regular;
}

void AllegroWindow::resize(float newW, float newH)
{
	this->width = newW;
	this->height = newH;
	al_resize_display(this->display, newW, newH);
	this->setUp();
}

bool AllegroWindow::isOpen()
{
	return on;
}

float AllegroWindow::getWidth()
{
	return this->width;
}

float AllegroWindow::getHeight()
{
	return this->height;
}

ALLEGRO_EVENT_SOURCE * AllegroWindow::getEventSource()
{
	return al_get_display_event_source(display);
}

ALLEGRO_DISPLAY * AllegroWindow::getDisplay()
{
	return display;
}

bool AllegroWindow::operator==(ALLEGRO_DISPLAY * disp)
{
	if (this->display == disp)
		return true;
	else
		return false;
}

bool AllegroWindow::operator==(AllegroWindow& window)
{
	if (this->display == window.display)
		return true;
	else
		return false;
}

void AllegroWindow::setCustomMouseCursor(string iconPath, float xFocus , float yFocus )
{
	this->customCursorSprite = al_load_bitmap(iconPath.c_str());
	this->customMouseCursor = al_create_mouse_cursor(customCursorSprite, xFocus, yFocus);
}

void AllegroWindow::useCustomMouseCursor()
{
	useCustomCursor = true;
	this->setUp();
}

void AllegroWindow::useSystemMouseCursor()
{
	useCustomCursor = false;
	this->setUp();
}

void AllegroWindow::setDifferentSystemMouseCursor(CursorSprite sprite)
{
	this->systemCursorSprite = sprite;
	this->setUp();
}

void AllegroWindow::hideMouseCursor()
{
	cursorHidden = true;
	this->setUp();
}

void AllegroWindow::showMouseCursor()
{
	cursorHidden = false;
	this->setUp();
}

void AllegroWindow::catchMouseCursor()
{
	cursorCaught = true;
	this->setUp();
}

void AllegroWindow::releaseMouseCursor()
{
	this->cursorCaught = false;
	this->setUp();
}

void AllegroWindow::setMenu(ALLEGRO_MENU * menu)
{
	if (on)
		al_set_display_menu(this->display, menu);
}

void AllegroWindow::setUp()
{
	if (on) {
		if (customMouseCursor != nullptr && useCustomCursor)
			al_set_mouse_cursor(this->display, this->customMouseCursor);
		else
			al_set_system_mouse_cursor(this->display, (ALLEGRO_SYSTEM_MOUSE_CURSOR)systemCursorSprite);

		if (cursorHidden)
			al_hide_mouse_cursor(this->display);
		else
			al_show_mouse_cursor(this->display);

		if (cursorCaught)
			al_grab_mouse(this->display);
		else
			al_ungrab_mouse();

		if (name.size() > 0)
			al_set_window_title(display, name.c_str());
		if (icon != nullptr)
			al_set_display_icon(display, icon);

		switch (this->screenMode) {
		case ScreenMode::Frameless:
			this->setFrameless(); break;
		case ScreenMode::FullScreen:
			this->setFullScreen(); break;
		case ScreenMode::Maximized:
			this->setMaximize(); break;
		case ScreenMode::Regular:
			this->setRegular(); break;
		}
		this->update();
	}
}

void AllegroWindow::clearScreenMode()
{
	if (on) {
		al_set_display_flag(this->display, ALLEGRO_FULLSCREEN_WINDOW, false);
		al_set_display_flag(this->display, ALLEGRO_MAXIMIZED, false);
		al_set_display_flag(this->display, ALLEGRO_FRAMELESS, false);
	}

	screenMode = ScreenMode::Regular;
}
