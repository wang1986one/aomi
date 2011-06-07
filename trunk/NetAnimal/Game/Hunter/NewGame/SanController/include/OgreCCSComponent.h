#ifndef __Orz_OgreCCSComponent__
#define __Orz_OgreCCSComponent__
#include "SanControllerConfig.h"
#include "CUpdateInterface.h"
namespace CCS
{
	class CameraControlSystem;
	class FreeCameraMode;
}
namespace Orz
{
	
	class COgreCCSInterface;
	class  OgreCCSComponent: public Component, public KeyListener, public MouseListener
	{
	public :
		OgreCCSComponent(void);
		virtual ~OgreCCSComponent(void);
	private:
		virtual bool onMousePressed(const MouseEvent & evt);
		///通知鼠标释放事件
		virtual bool onMouseReleased(const MouseEvent & evt);
		///通知鼠标移动事件
		virtual bool onMouseMoved(const MouseEvent & evt);

		///通知键盘按下事件
		virtual bool onKeyPressed(const KeyEvent & evt);
		///通知键盘释放事件
		virtual bool onKeyReleased(const KeyEvent & evt);

		void printCameras(void);

		CCS::CameraControlSystem * getCCS(void);
		bool update(TimeType interval);
		virtual ComponentInterface * _queryInterface(const TypeInfo & info) const;
		boost::scoped_ptr<COgreCCSInterface> _ccsInterface;
		boost::scoped_ptr<CUpdateInterface> _updateInterface;
		
		boost::scoped_ptr<CCS::CameraControlSystem> _ccs;
		boost::scoped_ptr<CCS::FreeCameraMode> _freeCameraMode;
		//boost::scoped_ptr<CCS::FixedCameraMode> _fixedCameraMode;

	
		bool _KC_A;
		bool _KC_D;
		bool _KC_UP;
		bool _KC_W;
		bool _KC_DOWN;
		bool _KC_S;
		bool _KC_PGUP;
		bool _KC_PGDOWN;
		bool _KC_RIGHT;
		bool _KC_LEFT;

	};
}
#endif