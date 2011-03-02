#ifndef __Orz_WheelAnimalProcessManager_h__
#define __Orz_WheelAnimalProcessManager_h__	

#include <orz/Toolkit_Base/EventSystem.h>

#include "WheelAnimalControllerConfig.h"

#include "WheelAnimalProcess.h"

#include "ReferenceCount.h"
#include "WinData.h"

#include <orz/Toolkit_Base/FSMLogic.h>


namespace Orz
{
	class ReferenceCount;
	class Process0LightRunning;
	class WheelAnimalProcess;
	typedef boost::shared_ptr<Process0LightRunning> Process0Ptr;
	typedef boost::shared_ptr<WheelAnimalProcess> ProcessPtr;
	

	class RotateAnimation;
	class AnimalChange;
	class ColorChange;
	class TV;
	class Gold;
	class ObjectLights;
	class WinEffect;
	class WheelAnimalSceneObj;
	class WheelAnimalUI;

	typedef  boost::shared_ptr<RotateAnimation> RotateAnimationPtr;
	typedef  boost::shared_ptr<AnimalChange> AnimalChangePtr;
	typedef  boost::shared_ptr<ColorChange> ColorChangePtr;
	typedef  boost::shared_ptr<TV> TVPtr;
	typedef  boost::shared_ptr<Gold> GoldPtr;
	typedef  boost::shared_ptr<ObjectLights> ObjectLightsPtr;
	typedef  boost::shared_ptr<WinEffect> WinEffectPtr;
	typedef  boost::shared_ptr<WheelAnimalSceneObj> WheelAnimalScenePtr;
	typedef boost::shared_ptr< WheelAnimalUI> WheelAnimalUIPtr;



	class _OrzWheelAnimalControllerExport WheelAnimalProcessManager
	{
	private:
		typedef boost::function< void ( Event * ) > EventFunction;
		typedef boost::function< bool ( TimeType ) > UpdateFunction;
		typedef std::map<Event::message_type, EventFunction > EventFunctionMap;
		typedef boost::array<ProcessPtr, WheelAnimalProcess::PROCESS_ALL - WheelAnimalProcess::PROCESS1> ProcessArray;
	public:
		WheelAnimalProcessManager(
			WheelAnimalScenePtr scene,
				RotateAnimationPtr rotate,
				RotateAnimationPtr needle,
				AnimalChangePtr ac,
				ColorChangePtr cc,
				TVPtr tv,
				GoldPtr gold,
				ObjectLightsPtr objLights,
				WinEffectPtr effect
				);
		~WheelAnimalProcessManager(void);
		void notice(Orz::Event * evt);
		void init(void);
		void shutdown(void);
		void update(TimeType interval);
	private:
		void lightRunning(bool isIn, Orz::Event * evt);
		void resetProcess(Orz::Event * evt);
		void runProcess( WheelAnimalProcess::PROCESS, Orz::Event * evt);
		void clearProcess(Orz::Event * evt);
		void startDisable(Orz::Event * evt);
		void sound(Orz::Event * evt);

		EventFunctionMap _map;
		Process0Ptr _process0;
	
	private:
		RotateAnimationPtr _rotate;
		RotateAnimationPtr _needle;
		AnimalChangePtr _ac;
		ColorChangePtr _cc;
		TVPtr _tv;
		GoldPtr _gold;
		ObjectLightsPtr _objLights;
		WinEffectPtr _effect;
		UpdateFunction _updateFun;
		WheelAnimalUIPtr _ui;

		WheelAnimalScenePtr _scene;
		//WinData WinData::getSingleton();
		
		ProcessArray _processes;
		ReferenceCount::Referenced _referenced;
	private:
		
		SoundPlayerPtr _music;
	};
}

#endif

