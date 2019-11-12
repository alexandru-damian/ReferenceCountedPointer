#include "RefCountedPointer.h"
#include <iostream>
#include <string>
#include <memory>


using namespace smart_ptr;

struct A 
{
	std::string x = { "yellow" };

	A(){}

	A(const A& other) {}

	A& operator=(A&& other)  
	{
		x = std::move(other.x);

		return *this;
	}

	bool operator!() const  
	{
		return (this == nullptr);
	}

	bool operator !=(const A& other) 
	{
		if (!(*this)) 
		{
			return true;
		}

		return (x != other.x);
	}
};

int main() 
{
	//A* a = new A();
	{
	A* b = new A();

	b->x = "Hello";

	RefCountedPointer<A> test(new A());
	RefCountedPointer<A> test1(b);

	RefCountedPointer<A> test2(test1);

	std::cout << test.use_count() << std::endl;
	std::cout << test1.use_count() << std::endl;

	test = test1;

	std::cout << test.use_count() << std::endl;
	}

	RefCountedPointer<A> ttest(new A());
	A* c = new A();

	RefCountedPointer<A> moveCtorTest(RefCountedPointer<A>());

	RefCountedPointer<A> moveTest(c);

	c->x = "Hello";

	moveTest = std::move(ttest);

	std::cout << moveTest.use_count() << std::endl;

	return 0;
}