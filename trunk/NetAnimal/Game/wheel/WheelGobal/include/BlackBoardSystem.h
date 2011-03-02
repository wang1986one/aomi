#ifndef __Orz_BlackBoardSystem_h__
#define __Orz_BlackBoardSystem_h__	


#include "WheelGobalConfig.h"
namespace Orz
{
	class _OrzWheelGobalExport BlackBoardSystem
	{
	public:

		template<class T>
		inline void write(const std::string & key, const T & value)
		{
			_write(key, VariantData<T>::set(value));
		}

		template<class T>
		inline T read(const std::string & key) const
		{
			return VariantData<T>::get(_read(key));
		}


		
		bool has(const std::string & key) const;

		static BlackBoardSystem & getInstance(void);
		static BlackBoardSystem * getInstancePtr(void);
		
		~BlackBoardSystem(void);
		
	private:
		BlackBoardSystem(void);
		
		void _write(const std::string & key, const Orz::Variant & value);
		Orz::Variant _read(const std::string & key) const;

		typedef OrzHashMap<std::string, Orz::Variant> BBSMap;
		BBSMap _map;

	};
}

#endif



