#ifndef __Orz_KeyEngineDecorator_h__
#define __Orz_KeyEngineDecorator_h__	


#include "WheelControllerConfig.h"
#include "WheelEngineInterface.h"
namespace Orz
{

	class _OrzMyWheelControlleExport KeyEngineDecorator:public WheelEngineInterface, public KeyListener//, public EventHandler//,  public KeyListener 
	{
	public:
		KeyEngineDecorator(WheelEngineInterfacePtr engine);
		~KeyEngineDecorator(void);

		
		virtual void startGame(size_t time);
	//	virtual void pushRate(void);
		virtual void runGame(void);

	//	virtual void clickButton(int id, int button);
		
		virtual TimeType getTime(void) const;
	private:

		virtual bool onKeyPressed(const KeyEvent & evt);
		
		virtual bool onKeyReleased(const KeyEvent & evt);
		WheelEngineInterfacePtr _engine;
	private:

	};

	
	typedef boost::shared_ptr<KeyEngineDecorator> KeyEngineDecoratorPtr;
}

#endif

