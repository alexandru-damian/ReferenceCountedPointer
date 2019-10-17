#include "ReferenceCountedPointer.h"

#include "pch.h"
#include <iostream>


int main() 
{
	smart_ptr::RefCount refCount;
	std::cout << "current count:" << refCount.get_count() << std::endl;

	refCount.addRef();
	std::cout<<"current count:"<<refCount.get_count()<<std::endl;

	refCount.addRef();
	std::cout << "current count:" << refCount.get_count() << std::endl;


	return 0;
}