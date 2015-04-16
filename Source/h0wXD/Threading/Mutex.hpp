
#ifndef H0WXD_THREADING_MUTEX_HPP
#define H0WXD_THREADING_MUTEX_HPP

#include <mutex>

namespace h0wXD
{
	namespace Threading
	{
		class mutex
		{
			std::mutex m_mutex;

		public:
			explicit mutex(bool _bAutoLock = false)
			{
				if (_bAutoLock)
				{
					m_mutex.lock();
				}
			}

			~mutex()
			{
				m_mutex.lock();
				m_mutex.unlock();
			}
	
			inline void lock()
			{
				m_mutex.lock();
			}

			inline bool try_lock()
			{
				return m_mutex.try_lock();
			}

			inline void unlock()
			{
				m_mutex.unlock();
			}
		};

		class AutoMutex
		{
			mutex* m_pMutex;

		public:
			explicit AutoMutex(mutex* _pMutex) :
				m_pMutex(_pMutex)
			{
				m_pMutex->lock();
			}

			virtual ~AutoMutex()
			{
				Release();
			}

			inline void Release()
			{
				if (m_pMutex)
				{
					m_pMutex->unlock();
					m_pMutex = nullptr;
				}
			}
		};
	}
}

#endif
