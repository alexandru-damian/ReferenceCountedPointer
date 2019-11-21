
#include <RefCounter.h>
namespace smart_ptr
{
	RefCounter::RefCounter() :counter(new u_long_long(0)) {}
	RefCounter::~RefCounter()
	{
		if (counter != nullptr) 
		{
			delete counter;
		}

		counter = nullptr;
	}

	void RefCounter::addRef() 
	{
		(*counter)++;
	}

	void RefCounter::removeRef()
	{
		if (*counter > 0) 
		{
			(*counter)--;
		}
	}
}