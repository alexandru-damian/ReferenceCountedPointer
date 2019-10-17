#include "RefCounter.h"
#include <iostream>


int main() 
{
	smart_ptr::RefCounter refCounter;
	std::cout << "current count:" << refCounter.get_count() << std::endl;

	refCounter.addRef();
	std::cout<<"current count:"<<refCounter.get_count()<<std::endl;

	refCounter.removeRef();
	std::cout << "current count:" << refCounter.get_count() << std::endl;

	return 0;
}