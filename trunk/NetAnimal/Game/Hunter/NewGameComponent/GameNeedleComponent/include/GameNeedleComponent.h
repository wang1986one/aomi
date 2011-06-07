#ifndef __Orz_GameNeedleComponent__
#define __Orz_GameNeedleComponent__

namespace Ogre
{
class SceneNode;
}

class SubEntityMaterialInstance;
namespace Orz
{
class CGameNeedleInterface;
class  GameNeedleComponent: public Component//ÄÚÈ¦¼ýÍ·
{ 
public :
	GameNeedleComponent(void);
	virtual ~GameNeedleComponent(void);
private:
	virtual ComponentInterface * _queryInterface(const TypeInfo & info) const;
	void setLeafVisible(bool visible);
	boost::scoped_ptr<CGameNeedleInterface> _needleInterface;
	bool load(Ogre::SceneNode * node);
	ComponentPtr _flowerComp;
	boost::scoped_ptr<SubEntityMaterialInstance> _semi;

};
}
#endif