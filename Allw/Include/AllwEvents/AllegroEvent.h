#pragma once
#include <queue>
#include "AllwInit/AllegroFactory.h"






#define BIT(x) (1 << x)

namespace Allw {
	namespace Event {

		#define EVENT_CLASS_TYPE(type) static Type GetStaticType() { return Type::##type; } virtual Type GetEventType() const override { return GetStaticType(); } virtual const char* GetName() const override { return #type; }

		#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


		enum class Type
		{
			KeyDown, KeyUp, KeyChar,
			MouseDown, MouseUp, MouseMoved, 
			WindowClosed, 
			Timer, 
			Empty
		};

		enum Category
		{
			None = 0,
			Keyboard = BIT(1),
			Window = BIT(2),
			Timer = BIT(3),
			Mouse = BIT(4)
		};

		class AllegroEvent
		{
		public:
			AllegroEvent(double timeStamp);

			virtual double getTimeStamp();

			virtual Type GetEventType() const = 0;

			virtual const char* GetName() const = 0;

			virtual int GetCategoryFlags() const = 0;

		protected:
			int CategoryFlag = 0;
			double timeStamp = 0;
		};

		



	}
}