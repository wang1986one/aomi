#ifndef __Orz_WheelGameInterface_h__
#define __Orz_WheelGameInterface_h__	


#include "WheelGobalConfig.h"
#include "WheelUIListener.h"
namespace Orz
{
	class WheelEngineInterface;
	//class WheelGameInterface;
	class WheelUIInterface;

	
	
	typedef boost::shared_ptr<WheelEngineInterface> WheelEngineInterfacePtr;
	typedef boost::shared_ptr<WheelUIInterface> WheelUIInterfacePtr;
	//typedef boost::shared_ptr<WheelGameInterface> WheelGameInterfacePtr;



	class _OrzWheelGobalExport WheelGameInterface: /* public WheelUIListener, */public Singleton<WheelGameInterface>
	{
	public:
		virtual ~WheelGameInterface(void);
		
		
		WheelGameInterface(void);
	
		void active(WheelUIInterfacePtr ui);
		void deactive(WheelUIInterfacePtr ui);
	protected:
		
		WheelUIInterfacePtr _ui;
	
	};

	typedef boost::shared_ptr<WheelGameInterface> WheelGameInterfacePtr;
}
	
#endif



