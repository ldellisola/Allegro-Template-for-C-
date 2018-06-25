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
		}
	}
}

void AllegroWindow::close()
{
	if (this->on) {
		this->on = false;
		al_destroy_display(this->display);
		this->display = nullptr;
	}
}

void AllegroWindow::setBackground(ALLEGRO_COLOR color)
{
	this->color = color;
}

void AllegroWindow::disableImageBackground()
{
	this->backgroundImage = false;
}

void AllegroWindow::enableImageBackground()
{
	if (image != nullptr);
		backgroundImage = true;
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
}

void AllegroWindow::setIcon(string icon)
{
	this->icon = al_load_bitmap(icon.c_str());
}

void AllegroWindow::setPosition(float x, float y)
{
	al_set_window_position(this->display, x, y);
}

void AllegroWindow::setFullScreen()
{
	this->screenMode = ScreenMode::FullScreen;
	if (this->on) {
		al_set_display_flag(this->display, ALLEGRO_FULLSCREEN_WINDOW, true);
		this->update();
	}
}

void AllegroWindow::setFrameless()
{
	this->screenMode = ScreenMode::Frameless;
	if (this->on) {
		al_set_display_flag(this->display, ALLEGRO_FRAMELESS, true);
		this->update();
	}
}

void AllegroWindow::setMaximize()
{
	this->screenMode = ScreenMode::Maximized;
	if (this->on) {
		al_set_display_flag(this->display, ALLEGRO_MAXIMIZED, true);
		this->update();
	}
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

bool AllegroWindow::operator==(ALLEGRO_DISPLAY * disp)
{
	if (this->display == disp)
		return true;
	else
		return false;
}

void AllegroWindow::clearScreenMode()
{
	if (on) {
		al_set_display_flag(this->display, ALLEGRO_FULLSCREEN_WINDOW, false);
		al_set_display_flag(this->display, ALLEGRO_MAXIMIZED, false);
		al_set_display_flag(this->display, ALLEGRO_FRAMELESS, false);
		this->update();
	}

	screenMode = ScreenMode::Regular;
}
