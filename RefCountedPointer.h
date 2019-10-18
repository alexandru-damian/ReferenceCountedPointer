#ifndef REF_COUNTED_POINTER_H
#define REF_COUNTED_POINTER_H

#include "RefCounter.h"

namespace smart_ptr
{
	template <class T>
	class RefCountedPointer
	{
	public:
		RefCountedPointer();
		~RefCountedPointer();
		operator bool() const;

	private:
		T* m_object;
		RefCounter* refCounter;

	};

	template<class T>
	RefCountedPointer<T>::RefCountedPointer() :
		m_object(nullptr),
		refCounter(new RefCounter())
	{}

	template <class T>
	RefCountedPointer<T>::~RefCountedPointer()
	{
		if (m_object != nullptr)
		{
			delete m_object;
		}

		if (refCounter != nullptr)
		{
			delete refCounter;
		}

		m_object = nullptr;
		refCounter = nullptr;
	}

	template<class T>
	inline RefCountedPointer<T>::operator bool() const
	{
		return m_object != nullptr;
	}

}
#endif // !REF_COUNTED_POINTER_H

