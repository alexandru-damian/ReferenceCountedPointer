#include "ReferenceCountedPointer.h"

namespace smart_ptr 
{
	RefCount::RefCount() :counter(1) {}

	void RefCount::addRef() 
	{
		counter++;
	}

	void RefCount::removeRef()
	{
		if (counter > 0) 
		{
			counter--;
		}
	}
}