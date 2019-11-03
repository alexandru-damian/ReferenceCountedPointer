#ifndef REF_COUNTER_H
#define REF_COUNTER_H
namespace smart_ptr
{
	class RefCounter
	{
		typedef unsigned long long u_long_long;

	public:
		RefCounter();
		~RefCounter();

		void addRef();
		void removeRef();

		const u_long_long get_count() const 
		{
			return *counter;
		}

	private:
		u_long_long* counter;
	};

}

#endif // REF_COUNTER_H
