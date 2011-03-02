#ifndef __Orz_SetupUI_h__
#define __Orz_SetupUI_h__

#include "WheelControllerConfig.h"
#include "DanListener.h"
namespace Orz
{
class Dan;
class Dan2;

class _OrzWheelControlleExport SetupUIListener
{
public:
	/*virtual void askForData(void) = 0;*/
	virtual void updateUIData(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) = 0;
	virtual void uploadPassword(int password) = 0;
	virtual ~SetupUIListener(void){}
};

class _OrzWheelControlleExport SetupUI: public DanListener
{
public:

	
	void addListener(SetupUIListener * listener);
	void removeListener(SetupUIListener * listener);


	SetupUI(void);
	~SetupUI(void);



	void updateUIData(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);
	void uploadPassword(int password);

	void setMenuDataVisible(bool visible);
	void menuResult(bool result);
	void writeMenuXY(int x, int y, unsigned long n);

	void update(TimeType interval);
	void setSetupVisible(bool show);
	void setupResult(bool ret);
	void bao_zhang_ma(const std::string & n);
	void setDanData(int i, int data);


private:

	boost::scoped_ptr<Dan> _dan;
	boost::scoped_ptr<Dan2> _dan2;

protected:
	SetupUIListener * _listener;
};



typedef boost::shared_ptr<SetupUI> SetupUIPtr;
}

	

#endif