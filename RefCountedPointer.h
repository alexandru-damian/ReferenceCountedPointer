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
		RefCountedPointer(T*);
		RefCountedPointer(const RefCountedPointer&);
		RefCountedPointer& operator=(const RefCountedPointer&);

		T& operator*() const;
		operator bool() const;

		unsigned long long use_count() const
		{
			return refCounter->get_count();
		}

	private:
		T* m_object;
		RefCounter* refCounter;

	};

	template<class T>
	RefCountedPointer<T>::RefCountedPointer() :
		m_object{ nullptr },
		refCounter{ new RefCounter()}
	{}

	template <class T>
	RefCountedPointer<T>::~RefCountedPointer()
	{

		if(refCounter != nullptr)
		{
			refCounter->removeRef();
			if (refCounter->get_count() == 0) 
			{
				delete m_object;
				delete refCounter;
				refCounter = nullptr;
			}
		}

		m_object = nullptr;
	}

	template<class T>
	RefCountedPointer<T>::RefCountedPointer(T * other) :
		m_object{ other },
		refCounter{new RefCounter()}
	{
		if (m_object) 
		{
			refCounter->addRef();
		}
	}

	template<class T>
	RefCountedPointer<T>::RefCountedPointer(const RefCountedPointer<T>& other):
		m_object{other.m_object},
		refCounter{other.refCounter}
	{
		if (m_object) 
		{
			refCounter->addRef();
		}
	}

	template<class T>
	RefCountedPointer<T>& RefCountedPointer<T>::operator=(const RefCountedPointer<T>& other)
	{
		if (*m_object != *(other.m_object))
		{
			if (other)
			{
				m_object = other.m_object;
				refCounter = other.refCounter;
				refCounter->addRef();
			}
		}

		return *this;
	}

	template<class T>
	inline T & RefCountedPointer<T>::operator*() const
	{
		return *m_object;
	}

	template<class T>
	inline RefCountedPointer<T>::operator bool() const
	{
		return m_object != nullptr;
	}

}
#endif // !REF_COUNTED_POINTER_H