#ifndef REF_COUNTER_H
#define REF_COUNTER_H
namespace smart_ptr
{
	class RefCounter
	{
	public:
		RefCounter();
		~RefCounter();

		void addRef();
		void removeRef();

		const long long get_count() const 
		{
			return *counter;
		}

	private:
		long long* counter;
	};

}

#endif // REF_COUNTER_H
