#ifndef __Orz_OgreNodeDebuggerComponent__
#define __Orz_OgreNodeDebuggerComponent__
#include "SanControllerConfig.h"
namespace Ogre
{
class SceneNode;
class Entity;
class Vector3;
}

namespace Orz
{
class COgreNodeDebuggerInterface;
class CUpdateInterface;
class  OgreNodeDebuggerComponent: public Component, public KeyListener
{ 
	typedef boost::function<void(TimeType)> KeyFunction;
	typedef std::pair<bool, KeyFunction> KeyFunctionEnable;
public :
	OgreNodeDebuggerComponent(void);
	virtual ~OgreNodeDebuggerComponent(void);

private:


	///通知键盘按下事件
	virtual bool onKeyPressed(const KeyEvent & evt);
	///通知键盘释放事件
	virtual bool onKeyReleased(const KeyEvent & evt);

	virtual ComponentInterface * _queryInterface(const TypeInfo & info);

	bool update(TimeType i);
	boost::scoped_ptr<COgreNodeDebuggerInterface> _debuggerInterface;
	boost::scoped_ptr<CUpdateInterface> _update;

	
	void pushNode(Ogre::SceneNode * sn);
	void removeNode(Ogre::SceneNode * sn);
	bool enable(void);
	void disable(void);
	void next(void);
	bool active(void);
	std::vector<Ogre::SceneNode *> _nodes;
	size_t _num;
	Ogre::SceneNode * _activeNode;
	Ogre::Vector3 _scale;
	/*bool _KC_A;
	bool _KC_D;
	bool _KC_UP;
	bool _KC_W;
	bool _KC_DOWN;
	bool _KC_S;
	bool _KC_PGUP;
	bool _KC_PGDOWN;
	bool _KC_RIGHT;
	bool _KC_LEFT;*/
	typedef std::map<Orz::KeyCode, KeyFunctionEnable> KeyMap;
	KeyMap _keyMap;
};
}
#endif