#ifndef __Orz_JsComponent__
#define __Orz_JsComponent__
#include "JsInterface.h"
#include "GameInterface.h"
namespace Orz
{
	class  JsComponent: public Component
	{

	public :
		JsComponent(void);
		virtual ~JsComponent(void);
	private:            
		ComponentInterface * _queryInterface(const TypeInfo & info);
		ComponentQueryInterface _query;
		boost::scoped_ptr<JsInterface> _jsInterface;
		boost::scoped_ptr<GameInterface<0> > _gameInterface;

		
	};



}
#endif