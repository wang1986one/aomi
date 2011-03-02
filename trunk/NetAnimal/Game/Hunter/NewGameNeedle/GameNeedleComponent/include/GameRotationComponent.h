#ifndef __Orz_GameRotationComponent__
#define __Orz_GameRotationComponent__

namespace Ogre
{
class SceneNode;
}
namespace Orz
{

	
class WinnerAnimationInterface;
class CGameRotationInterface;
class  GameRotationComponent: public Component//ƒ⁄Õ‚»¶
{ 
public :
	GameRotationComponent(void);
	virtual ~GameRotationComponent(void);
private:
	virtual ComponentInterface * _queryInterface(const TypeInfo & info);

	boost::scoped_ptr<CGameRotationInterface> _gameRotationInterface;


	ComponentPtr _needleComp;
	ComponentPtr _needleRotationComp;

	ComponentPtr _baseComp;
	ComponentPtr _baseRotationComp;

	Ogre::SceneNode * _needleNode;
	Ogre::SceneNode * _baseNode;
	Ogre::SceneNode * _node;
private:

	
	bool play(int needle, TimeType needleTime, int base, TimeType baseTime);//> PlayFunction;
	bool update(TimeType i);//> UpdateFunction;
	bool winnerUpdate(TimeType i);
	bool winner(int id, bool move);
	void reset(void);
	
	boost::scoped_ptr<WinnerAnimationInterface> _winnerAnimation;

	bool init(ComponentPtr sceneComp);
	int _base;
	int _needle;
};
}
#endif