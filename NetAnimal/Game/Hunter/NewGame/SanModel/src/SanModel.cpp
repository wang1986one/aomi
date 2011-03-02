#include "SanModelBaseStableHeaders.h"
/*#include "OgreDotSceneLoaderComponent.h"
#include "OgreCCSComponent.h"
#include "ZhugeLiangComponent.h"
#include "OgreNodeDebuggerComponent.h"

#include "WheelPlaceComponent.h"

#include "SanProcessComponent.h"*/

#include "SanDirector.h"
#include "SanScene.h"
#include "SanZhugeActor.h"
//#include "SanArmyComponent.h"
//#include "SanSceneComponent.h"
using namespace Orz;
GameRegisterPtr game;
//
//extern char const SanDirectorStr[]= "SanDirector";
//typedef Orz::GameFactory<Director, SanDirector, SanDirectorStr> SanDirectorFactory;

extern char const SanSceneStr[]= "HunterScene";
typedef Orz::GameFactory<Scene, SanScene, SanSceneStr> SanSceneFactory;
//extern char const SanZhugeStr[]= "SanZhugeActor";
//typedef Orz::GameFactory<Actor, SanZhugeActor, SanZhugeStr> SanZhugeActorFactory;


extern "C" void dllStartPlugin(void)
{

	game.reset(new GameRegisterList<boost::mpl::list<SanSceneFactory> >());
}

extern "C" void dllStopPlugin(void)
{
	game.reset();


}
