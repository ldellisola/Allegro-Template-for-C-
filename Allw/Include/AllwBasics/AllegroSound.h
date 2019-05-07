#pragma once
#include <string>
#include <vector>


#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>

#include "AllwMisc/AllegroException.h"

namespace Allw {
	namespace Sound {




		enum class Mode
		{
			Once = ALLEGRO_PLAYMODE_ONCE, Loop = ALLEGRO_PLAYMODE_LOOP, Bidir = ALLEGRO_PLAYMODE_BIDIR
		};


	
	


			AllegroSound * create(std::string fileName, Mode playMode, unsigned int ID, float speed = 1, float gain = 1.0, float pan = 0.0);
			AllegroSound * recover(unsigned int ID);
			bool destroy(unsigned int ID);
			bool destroy(AllegroSound * sound);

			static AllegroSoundFactory& getInstance() {
				if (instance == nullptr) {
					instance = new AllegroSoundFactory();
				}

				return *instance;
			}

			AllegroSoundFactory(AllegroSoundFactory const&) = delete;
			void operator=(AllegroSoundFactory const&) = delete;
	        void reserveMoreSamples(int add);
	        unsigned int getNumberOfReservedSamples();

		private:
			static AllegroSoundFactory * instance;
			AllegroSoundFactory();
			~AllegroSoundFactory();
			std::vector<AllegroSound *> sounds;
			unsigned int reservedSamples = 0;

		};

		


		class AllegroSound
		{
		public:
			AllegroSound(std::string fileName, Mode playMode, unsigned int ID, float speed = 1, float gain = 1.0, float pan = 0.0);

			void play();
			void playAtSpeed(float speed);
			void playAtPan(float pan);
			void playAtGain(float gain);
			void stop();

			void setSpeed(float speed) { this->speed = speed; }
			float getSpeed() { return speed; }
			void setGain(float gain) { this->gain = gain; }
			float getGain() { return gain; }
			void setPan(float pan) { this->pan = pan; }
			float getPan() { return pan; }

			unsigned int getID() { return this->ID; }

			friend bool AllegroSoundFactory::destroy(unsigned int ID);
			friend bool AllegroSoundFactory::destroy(AllegroSound * sound);

		private:
			ALLEGRO_SAMPLE * sample = nullptr;
			ALLEGRO_SAMPLE_ID playID;
			unsigned int ID = NAN;
			float gain, pan, speed;
			ALLEGRO_PLAYMODE playMode;

			~AllegroSound();
		};

	}
}


