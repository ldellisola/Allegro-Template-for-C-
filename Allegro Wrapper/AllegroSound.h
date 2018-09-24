#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <string>

enum class PlayMode
{
	Once = ALLEGRO_PLAYMODE_ONCE,Loop = ALLEGRO_PLAYMODE_LOOP, Bidir = ALLEGRO_PLAYMODE_BIDIR
};

class AllegroSound
{
public:
	AllegroSound(std::string fileName, PlayMode playMode,float speed = 1, float gain = 1.0, float pan = 0.0);
	
	void play();
	void stop();

	void setSpeed(float speed) { this->speed = speed; }
	float getSpeed() { return speed; }
	void setGain(float gain) { this->gain = gain; }
	float getGain() { return gain; }
	void setPan(float pan) { this->pan = pan; }
	float getPan() { return pan; }


private:
	ALLEGRO_SAMPLE *sample = nullptr;
	ALLEGRO_SAMPLE_ID playID;
	float gain,pan,speed;
	ALLEGRO_PLAYMODE playMode;

	~AllegroSound();
};

