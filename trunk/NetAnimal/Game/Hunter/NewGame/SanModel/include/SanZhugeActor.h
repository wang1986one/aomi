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
		///���أ������ڴ�����Ϣ����
		void doExecute(Event * evt);


		///���أ������ڽ�����Ϣ�������
		void doEnable(void);


		///���أ��������뿪��Ϣ�������
		void doDisable(void);

		///���أ������ڸ��µ���
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