#ifndef __Orz_Js__
#define __Orz_Js__

namespace Orz
{
	class Js
	{

	public :
		Js(void);
		~Js(void);

		static Js & getInstance(void);
		static Js * getInstancePtr(void);
	};



}
#endif