#ifndef __Orz_SanScene__
#define __Orz_SanScene__
#include <WheelGobal/WinData.h>
#include "SanTranslate.h"
namespace CCS
{
	class FixedCameraMode;
}
namespace Orz
{


	class GameTranslate;
	class CUpdateInterface;
	class SanScene:public Scene
	{
	public:
		SanScene(const std::string & name, parameter_type);
		virtual ~SanScene(void);
	private:


		///重载，被用于处理消息调用
		void doExecute(Event * evt);


		///重载，被用于进入消息管理调用
		void doEnable(void);


		///重载，被用于离开消息管理调用
		void doDisable(void);

		///重载，被用于更新调用
		void doFrame(unsigned int step);

	private:
		//ComponentPtr _sceneComp;
		//ComponentPtr _ccs;
		CUpdateInterface  * _update;

		boost::scoped_ptr<CCS::FixedCameraMode> _fixed;//(new CCS::FixedCameraMode(ccs));
		//ActorPtr _zhuge;
		typedef std::vector<ComponentPtr> ActorList;
		ActorList _actors;
	/*		ComponentPtr _zhuge;*/
		static const int _size;
		ComponentPtr _process;
		ComponentPtr _sceneComp;
		ComponentPtr _needleComp;
		ComponentPtr _diamondComp;
		ComponentPtr _uiComp;
		//WinData WinData::getInstance();
		typedef boost::function<void (Event * evt)> MessageFunction;
		typedef std::map<int, MessageFunction> MessageMap;
	
		ComponentPtr _translate_c;//(new CCS::FixedCameraMode(ccs));
		MessageMap _messgaeMap;

	private:
		void setWinner(int winner);
		void processDisable( Event * evt);
		void processEnable(Event * evt);
		void processEnableProRun( Event * evt);
		void processEnableLogo(Event * evt);
		void _needleAngle(float angle, bool isEnd);
		int _hLight;
		int _gLight;
	};
}
#endif