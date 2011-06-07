#ifndef __Orz_WheelGameUIRegister_h__
#define __Orz_WheelGameUIRegister_h__	


#include "WheelGobalConfig.h"
#include "WheelUIListener.h"
namespace Orz
{
	class WheelEngineInterface;
	//class WheelGameInterface;
	class WheelUIInterface;

	
	
	typedef boost::shared_ptr<WheelEngineInterface> WheelEngineInterfacePtr;
	typedef boost::shared_ptr<WheelUIInterface> WheelUIInterfacePtr;



	class _OrzWheelGobalExport WheelGameUIRegister : public Singleton<WheelGameUIRegister>
	{
	public:
		virtual ~WheelGameUIRegister(void);
		
		
		WheelGameUIRegister(void);
	
		void active(WheelUIInterfacePtr ui);
		void deactive(WheelUIInterfacePtr ui);
	public:

		void setTheTime(int second); 

		void setStartVisible(bool visible);
		void setEndVisible(bool visible);
		void setLogoShow(bool visible);
		void addBottom(void);
		void runWinner(void);

		void update(TimeType i);
	protected:
		
		WheelUIInterfacePtr _ui;
	
	};

	//typedef boost::shared_ptr<WheelGameInterface> WheelGameInterfacePtr;
}
	
#endif



