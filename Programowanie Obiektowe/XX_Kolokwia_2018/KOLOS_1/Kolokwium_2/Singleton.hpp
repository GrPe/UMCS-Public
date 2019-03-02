#pragma once // dziala tak samo jak #ifndef, #define #endif, de facto nie jest to standard jezyka ale GCC i VS go obsluguja

namespace singleton
{
	class Singleton
	{
		static Singleton* object;
		Singleton() {};
		~Singleton() {};
	public:
		static Singleton * getObject();
		static void remove();
	};
}

