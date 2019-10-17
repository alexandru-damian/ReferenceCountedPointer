#include "RefCounter.h"

namespace smart_ptr 
{
	RefCounter::RefCounter() :counter(new long long(1)) {}
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