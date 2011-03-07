
#ifndef __Orz_ToolkitBase_ThreadQueue_h__
#define __Orz_ToolkitBase_ThreadQueue_h__

namespace Orz
{

	template<typename T>
	class ThreadQueue {
		typedef T value_type;
		typedef std::queue<T> C;
	public:
		ThreadQueue(void) {}
		~ThreadQueue(void) {}


		void enqueue(const value_type& _Val)
		{	
			boost::mutex::scoped_lock lock(_mutex);
			_c.push(_Val);
		}

		bool dequeue(value_type & ret)
		{
			{
				boost::mutex::scoped_lock lock(_mutex);
				if(_c.empty())
					return false;
				ret = _c.front();
				_c.pop();
			}
			return true;
		}

	private:
		C _c;
		boost::mutex _mutex;
	};
}


#endif