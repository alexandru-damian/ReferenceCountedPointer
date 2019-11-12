#ifndef REF_COUNTED_POINTER_H
#define REF_COUNTED_POINTER_H

#include "RefCounter.h"

#include <utility>

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
		RefCountedPointer(RefCountedPointer&&);

		RefCountedPointer& operator=(RefCountedPointer&&);
		RefCountedPointer& operator=(const RefCountedPointer&);

		void reset()
		{
			if (refCounter) {

				refCounter->removeRef();

				if (refCounter->get_count() == 0)
				{
					if (m_object)
					{
						delete m_object;
					}

					delete refCounter;

					refCounter = nullptr;
				}
			}

			m_object = nullptr;
		}

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
		reset();
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
		if (m_object && refCounter) 
		{
			refCounter->addRef();
		}
	}

	template<class T>
	RefCountedPointer<T>::RefCountedPointer(RefCountedPointer<T> && other):
		m_object{other.m_object},
		refCounter{other.refCounter}
	{
		other.m_object = nullptr;
	}

	template<class T>
	RefCountedPointer<T> & RefCountedPointer<T>::operator=(RefCountedPointer && other)
	{
		if (*m_object != *(other.m_object)) 
		{
			reset();

			m_object = other.m_object;
			refCounter = other.refCounter;

			other.m_object = nullptr;
			other.refCounter = nullptr;
		}

		return *this;
	}

	template<class T>
	RefCountedPointer<T>& RefCountedPointer<T>::operator=(const RefCountedPointer<T>& other)
	{
		if (*m_object != *(other.m_object))
		{
			refCounter->removeRef();
			
			if (m_object) 
			{
				m_object = nullptr;
			}

			m_object = other.m_object;
			refCounter = other.refCounter;

			refCounter->addRef();
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