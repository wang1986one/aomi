#ifndef __Orz_DUI_h__
#define __Orz_DUI_h__	

#include "DUI/DanListener.h"
#include "GSMInterface.h"
//#include "WheelAnimalControllerConfig.h"
//#include "WheelUIInterface.h"
//#include "WheelEnum.h"
//#include <orz/Toolkit_Base/FSMLogic.h>
namespace Orz
{
	class Dan;
	class Dan2;
	class DUI: public Singleton<DUI>,public DanListener
	{
	public:

		DUI(/*ComponentPtr dataServer, GSMInterface * gsm*/);
		virtual ~DUI(void);


		virtual void updateUIData(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);
		virtual void uploadPassword(int password);

		virtual void setMenuDataVisible(bool visible);
		virtual void menuResult(bool result);
		virtual void writeMenuXY(int x, int y, unsigned long n);
		bool update(TimeType i);
		
		void setSetupVisible(bool show);
		void setupResult(bool ret);
		void bao_zhang_ma(const std::string & n);
		void setDanData(int i, int data);

	private:
		boost::scoped_ptr<Dan> _dan;
		boost::scoped_ptr<Dan2> _dan2;
		
	};

	typedef boost::shared_ptr< DUI> DUIPtr;
}

#endif

