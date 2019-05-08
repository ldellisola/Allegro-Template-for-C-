#pragma once
#include <exception>

namespace Allw {
	namespace Exception {


		class InvalidLoadException :
			public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return "The file couldn't be loaded";
			}
		};

		class AllegroInitException :
			public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return "Allegro could't be initialized";
			}
		};

		class AllegroNotImplementedException : public std::exception {
			virtual const char* what() const throw()
			{
				return "This is not implemented";
			}
		};

		class AllegroColorEmptyException : public std::exception {
			virtual const char* what() const throw()
			{
				return "The color was not initializated";
			}
		};

	}
}