#include "Singleton.hpp"

namespace singleton
{
	Singleton* Singleton::object = nullptr;

	Singleton * Singleton::getObject()
	{
		if (object == nullptr)
		{
			object = new Singleton();
		}
		return object;
	}

	void Singleton::remove()
	{
		if (object != nullptr)
		{
			delete object;
			object = nullptr;
		}
	}
}

