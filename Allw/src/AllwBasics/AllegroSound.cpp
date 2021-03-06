#include "AllwBasics/AllegroSound.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>

namespace Allw {
	namespace Sound {

		AllegroSound::AllegroSound(std::string fileName, Mode playMode, unsigned int ID, float speed, float gain, float pan)
		{
			this->sample = al_load_sample(fileName.c_str());
			if (this->sample == nullptr)
				throw Exception::InvalidLoadException();
			this->gain = gain;
			this->pan = pan;
			this->speed = speed;
			this->playMode = playMode;
			this->ID = ID;
			this->playID = new ALLEGRO_SAMPLE_ID;
		}

		void AllegroSound::play()
		{
			al_play_sample(this->sample, this->gain, this->pan, this->speed, (ALLEGRO_PLAYMODE)this->playMode, playID);
		}

		void AllegroSound::playAtSpeed(float speed)
		{
			if (this->sample != nullptr) {
				al_play_sample(this->sample, this->gain, this->pan, speed, (ALLEGRO_PLAYMODE)this->playMode, playID);
			}
		}

		void AllegroSound::playAtPan(float pan)
		{
			if (this->sample != nullptr) {
				al_play_sample(this->sample, this->gain, pan, this->speed, (ALLEGRO_PLAYMODE)this->playMode, playID);
			}
		}

		void AllegroSound::playAtGain(float gain)
		{
			if (this->sample != nullptr) {
				al_play_sample(this->sample, gain, this->pan, this->speed, (ALLEGRO_PLAYMODE)this->playMode, playID);
			}
		}

		void AllegroSound::stop()
		{
			al_stop_sample(this->playID);
		}

		AllegroSound::~AllegroSound()
		{
			if (this->sample != nullptr)
				al_destroy_sample(this->sample);
			delete playID;

		}



		AllegroSoundFactory::AllegroSoundFactory()
		{
		}

		AllegroSoundFactory::~AllegroSoundFactory()
		{
		}

		AllegroSound * AllegroSoundFactory::create(std::string fileName, Mode playMode, unsigned int ID, float speed, float gain, float pan)
		{

			AllegroSound * temp = new AllegroSound(fileName, playMode, ID, speed, gain, pan);
			this->sounds.push_back(temp);
			al_reserve_samples(++reservedSamples);
			return temp;
		}

		AllegroSound * AllegroSoundFactory::recover(unsigned int ID)
		{
			for (int i = 0; i < (int)sounds.size(); i++) {
				if (sounds[i]->getID() == ID)
					return sounds[i];
			}
			return nullptr;
		}

        bool AllegroSoundFactory::destroy(unsigned int ID)
        {
        	int i;
        	AllegroSound * temp = nullptr;
        	for (i = 0; i < (int)sounds.size(); i++) {
        		if (sounds[i]->getID() == ID)
        			temp = sounds[i];
        	}
        	i--;
        	if (temp != nullptr) {
        		sounds.erase(sounds.begin() + i);
        		delete temp;
        		al_reserve_samples(--reservedSamples);
        		
        		return true;
        	}
        	return false;
        }


		
		void AllegroSoundFactory::reserveMoreSamples(int add)
        {
        	this->reservedSamples += add;
        	al_reserve_samples(reservedSamples);
        }
        
        unsigned int AllegroSoundFactory::getNumberOfReservedSamples()
        {
        	return reservedSamples;
        }

		bool AllegroSoundFactory::destroy(AllegroSound * sound)
		{
			int i;
			bool kill = false;
			for (i = 0; i < (int)sounds.size(); i++) {
				if (sounds[i] == sound)
					kill = true;
			}
			i--;
			if (kill) {
				sounds.erase(sounds.begin() + i);
				al_reserve_samples(--reservedSamples);
				delete sound;
				;
				return true;
			}
			return false;
		}

	}

}

Allw::Sound::AllegroSoundFactory* Allw::Sound::AllegroSoundFactory::instance = nullptr;

