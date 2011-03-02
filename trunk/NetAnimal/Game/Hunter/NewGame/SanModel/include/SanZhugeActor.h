#ifndef __Orz_SanZhugeActor__
#define __Orz_SanZhugeActor__
#include "CUpdateInterface.h"
namespace Orz

{
	class SanZhugeActor:public Actor
	{
	public:
		SanZhugeActor(const std::string & name, parameter_type);
		virtual ~SanZhugeActor(void);
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
		ComponentPtr _process;
		ComponentPtr _debugger;
		ComponentPtr _zhuge;
		CUpdateInterface  * _update;
		Ogre::Vector3 _pos;
		Ogre::Vector3 _scale;
		float _radian;
	};

	/*extern char const SanDirectorType[]= "SanDirector";
	typedef Orz::GameFactory<Director, SanDirector, SanDirectorType> SanDirectorFactory;*/
};
#endif