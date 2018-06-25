#pragma once
#include <vector>
#include <string>

#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>

#include "AllegroBox.h"

struct Drawing
{
	ALLEGRO_BITMAP * bitmap;
	float x, y;
	float scaledHeight, scaledWidth, height, width;

};


enum class CursorSprite
{
	None, Default, Arrow, Busy, Question, Edit, ResizeUp, ResizeLeft, ResizeDown, ResizeRight,
	ResizeUpLeft, ResizeDownLeft, ResizeDownRight, ResizeUpRight, Progress, Precision, Link,
	AltSelect, Unavailable
};

enum class ScreenMode
{
	Regular, FullScreen, Maximized,Frameless
};

using namespace std;

class AllegroWindow
{
public:
	// Constructor: it create a window
	//
	//		- float w: the width of the window.
	//		- float h: the height of the window.
	//		- string name: the name of the window.
	//		- string icon: the path to the icon of the window.
	AllegroWindow(float w, float h, string name = "", string icon = "");

	// Destructor.
	~AllegroWindow();

	// It adds a bitmap to the window. This bitmap will be drawn everytime the window is updated.
	//
	//		- ALLEGRO_BITMAP * bitmap:	bitmap to be drawn.
	//		- float x:					initial X coordinate.
	//		- float y:					initial Y coordinate.
	//		- float scaledHeight:		new height for the bitmap to be printed in.
	//		- float scaledWidth:		new width for the bitmap to be printed in.
	void addDrawing(ALLEGRO_BITMAP * bitmap, float x, float y, float scaledHeight = 0, float scaledWidth = 0);

	// It adds an AllegroBox to the window. It will be printed everytime the window is updatesd by its own draw function
	void addBoxes(AllegroBox* box);

	// It removes a bitmap that was being drawn on the window.
	void removeDrawing(ALLEGRO_BITMAP *bitmap);

	// It removes an AllegroBox htat was being drawn on the window
	void removeBox(AllegroBox& box);

	// It moves a given draw to another place.
	void moveDrawing(ALLEGRO_BITMAP *bitmapToMove, float newX, float newY);
	
	// Sets the window as the main window.
	void setAsMain();

	// It opens the window.
	void open();

	// It closes the window.
	void close();

	// It sets the color of the display.
	void setBackground(ALLEGRO_COLOR color);

	// It sets the image as the background of the display
	void setImageBackground(string image);

	// It sets a previusly loaded image as the background of the window
	void setImageAsBackground();

	// It sets a previusly selected color as the background of the window
	void setColorAsBackground();

	// It draws all the bitmaps of the display.
	void update();

	// It sets the name of the window.
	void setName(string name);

	// It sets the icon for the window.
	void setIcon(string icon);

	// It sets the position of the window on the computer's screen.
	void setPosition(float x, float y);

	// It sets the window into fullscreen mode.
	void setFullScreen();

	// It sets the window into frameless mode.
	void setFrameless();

	// It sets the window into maximized mode.
	void setMaximize();
	
	// It returns the window to its regular mode.
	void setRegular();

	// It resizes the window
	void resize(float newW, float newH);

	// It says if the window is open.
	bool isOpen();

	// It returns the width of the window.
	float getWidth();

	// It returns the Height of the window
	float getHeight();

	// It returns the event Source of the window. That event source will change everytime
	ALLEGRO_EVENT_SOURCE * getEventSource();

	// Overloaded operator to check for equality with allegro displays ( for compatibility)
	bool operator==(ALLEGRO_DISPLAY* disp);

	// Overloaded operator to check for equality with another allegroWindow
	bool operator==(AllegroWindow& window);

	// It allows the user to use a custom sprite instead of the regular mouse cursor;
	//
	//		- string iconPath: path to the sprite
	//		- xFocus: X coordinate of the sprite where the mouse will click
	//		- yFocus: Y coordinate of the sprite where the mouse will click
	void setCustomMouseCursor(string iconPath, float xFocus = 0, float yFocus = 0);

	// it sets a custom mouse cursor as the main cursor for this window
	void useCustomMouseCursor();

	// It sets the system mouse cursor as the main cursor for this window
	void useSystemMouseCursor();

	// It allows the user to select what kind of system mouse cursor will be used in this window
	void setDifferentSystemMouseCursor(CursorSprite sprite);

	// It hides the mouse cursor in this window
	void hideMouseCursor();

	// It unhides (Yes, it is an actual word) the mouse cursor in this window
	void showMouseCursor();

	// It forces the cursor to stay on this window
	void catchMouseCursor();

	//It allows the cursor to leave the window. THIS WILL RELEASE THE CURSOR FROM ANY OTHER WINDOW
	void releaseMouseCursor();

private:
	// Display
	ALLEGRO_DISPLAY * display = nullptr;
	float width, height;
	bool on = false;
	void setUp();

	// Draw
	vector<Drawing>drawings;
	vector<AllegroBox *> boxes;
	bool backgroundImage;
	ALLEGRO_BITMAP * image = nullptr;
	ALLEGRO_COLOR color;

	// Screen
	ALLEGRO_BITMAP * icon = nullptr;
	string name;
	ScreenMode screenMode = ScreenMode::Regular;
	void clearScreenMode();
	
	// Cursor
	bool useCustomCursor = false;
	bool cursorHidden = false;
	bool cursorCaught = false;
	CursorSprite systemCursorSprite = CursorSprite::Default;

	ALLEGRO_MOUSE_CURSOR *	customMouseCursor = nullptr;
	ALLEGRO_BITMAP * customCursorSprite = nullptr;
};

