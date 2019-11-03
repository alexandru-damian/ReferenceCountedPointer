#include "include/RefCountedPointer.h"
#include <iostream>
#include <memory>


using namespace smart_ptr;

struct A 
{
	int x = 10;

	~A()
	{
	}

	bool operator !=(const A& other) 
	{
		return (x != other.x);
	}
};

int main() 
{
	A* a = new A();
	A* b = new A();

	b->x = 14;

	RefCountedPointer<A> test(a);
	RefCountedPointer<A> test1(b);
	RefCountedPointer<A> test2(test1);

	std::cout << test.use_count() << std::endl;
	std::cout << test1.use_count() << std::endl;

	test = test1;

	std::cout << test.use_count() << std::endl;

	return 0;
}