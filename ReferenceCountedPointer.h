
#ifndef REFERENCE_COUNTED_POINTER_H
#define REFERENCE_COUNTED_POINTER_H

#include <atomic>

namespace smart_ptr
{
	class RefCount
	{
	public:
		RefCount();

		void addRef();
		void removeRef();

		const uint64_t get_count() const 
		{
			return counter;
		}

	private:
		std::atomic_uint64_t counter;
	};

}

#endif // !REFERENCE_COUNTED_POINTER_H
