
#include <orz/View_SingleChip/ViewSingleChipConfig.h>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <orz/Framework_Base/System.h>
#include <orz/View_SingleChip/SingleChipManager.h>
#include <boost/circular_buffer.hpp>
#include <orz/Toolkit_Base/LogManager.h>
#include "ThreadQueue.h"
namespace Orz
{

	class _OrzViewSingleChipPrivate SingleChip
	{
	private:
		typedef boost::mutex::scoped_lock lock;

		void _writeToBuffer(unsigned char * c, boost::system::error_code ec, std::size_t bytes_transferred)
		{

			if(!ec && _isRuning)
			{
				_queue.enqueue(c[0]);
				boost::asio::async_read(*_serialPort, boost::asio::buffer(_buf), boost::bind(&SingleChip::_writeToBuffer, this, _buf, _1, _2)); 
			}
		}
		void _readFromBuffer(void)
		{

			unsigned char c;
			while(_queue.dequeue(c))
			{
				BOOST_FOREACH(SingleChipListener * listener, _listeners)
				{
					listener->readFromSCM(_id, c);
				}	
			}
		}


	public:

		SingleChip(void):_id(0)
		{
			
		}

		~SingleChip(void)
		{

		}
		void async_read(void)
		{


			boost::asio::async_read(*_serialPort, boost::asio::buffer(_buf), boost::bind(&SingleChip::_writeToBuffer, this, _buf, _1, _2)); 

			//_iosev.run();
		}
		bool enable(size_t id, const std::string & port, unsigned int rate, boost::asio::io_service & ioService)
		{
	
			_id = id;
			try{
				_serialPort.reset(new boost::asio::serial_port(ioService, port));
			}
			catch(...)
			{
				_serialPort.reset();
				return false;
			}

			if(_serialPort)
			{
				_serialPort->set_option(boost::asio::serial_port::baud_rate(rate));
				_serialPort->set_option(boost::asio::serial_port::flow_control(boost::asio::serial_port::flow_control::none)); 
				_serialPort->set_option(boost::asio::serial_port::parity(boost::asio::serial_port::parity::none)); 
				_serialPort->set_option(boost::asio::serial_port::stop_bits(boost::asio::serial_port::stop_bits::one)); 
				_serialPort->set_option(boost::asio::serial_port::character_size(8)); 
				
			}
			_isRuning = true;
			async_read();
			return true;
		}
		void disable(void)
		{

			_isRuning = false;
			if(_serialPort)
			{
			
				_serialPort->close();


				//_thread->join();
				//_thread.reset();
			}
			_serialPort.reset();
		}



		bool write(const unsigned char * data, int num)
		{
			if(_serialPort)
			{
				boost::asio::write(*_serialPort, boost::asio::buffer(data, num)); 
				return true;
			}
			return false;
		}

		bool write(const MsgBuffer & buffer)
		{
			if(_serialPort)
			{
				boost::asio::write(*_serialPort, boost::asio::buffer(buffer, buffer.size())); 
				return true;
			}
			return false;
		}
		bool write(const char * data, int num)
		{
			if(_serialPort)
			{
				boost::asio::write(*_serialPort, boost::asio::buffer(data, num)); 
				return true;
			}
			return false;
		}
		bool update(TimeType i)
		{
			_readFromBuffer();
			return true;
		}

		void addListener(SingleChipListener * listener)
		{
			_listeners.push_back(listener);
		}
		void removeListener(SingleChipListener * listener)
		{
			_listeners.erase(std::remove(_listeners.begin(), _listeners.end(), listener), _listeners.end());
		}

	private:
		boost::scoped_ptr<boost::asio::serial_port> _serialPort;
		std::vector<SingleChipListener *> _listeners;
		unsigned char _buf[1]; 
		ThreadQueue<unsigned char> _queue;
		bool _isRuning;
		size_t _id;

	};


}