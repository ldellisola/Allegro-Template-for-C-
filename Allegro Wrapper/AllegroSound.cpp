#include "AllegroSound.h"

AllegroSound::AllegroSound(std::string fileName, PlayMode playMode, float speed, float gain, float pan)
{
	this->sample = al_load_sample(fileName.c_str());
	this->gain = gain;
	this->pan = pan;
	this->speed = speed;
	this->playMode = (ALLEGRO_PLAYMODE) playMode;
}

void AllegroSound::play()
{
	al_play_sample(this->sample, this->gain, this->pan, this->speed, this->playMode, &playID);
}

void AllegroSound::stop()
{
	al_stop_sample(&this->playID);
}

AllegroSound::~AllegroSound()
{
	al_destroy_sample(this->sample);
}
