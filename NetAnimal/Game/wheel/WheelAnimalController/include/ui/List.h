#ifndef __Orz_List__
#define __Orz_List__
#include <boost/multi_array.hpp>
#include <iostream>
#include <CEGUI/cegui.h>

#include "WheelAnimalControllerConfig.h"
#include "Number.h"

#include "WinData.h"
namespace Orz
{
	
	
	
	class ListItem
	{

	public:
		ListItem(CEGUI::Window * all, 
			CEGUI::Window * main, 
			CEGUI::Window * banker, 
			CEGUI::Window * king,
			CEGUI::Window * theDouble
			);
		~ListItem(void);
		void hide(void);
		void show(const WinDataClone & data);
		bool isVisible(void) const;
		const WinDataClone & getData(void) const;
	private:
		CEGUI::Window * _all;
		CEGUI::Window * _main;
		CEGUI::Window * _banker;
		CEGUI::Window * _king;
		CEGUI::Window * _double;
		std::map<std::pair<WheelEnum::TYPE, WheelEnum::LIGHT_COLOR>, std::string> _picture;
		WinDataClone _winData;
	};
	class List
	{
	public:
		List(void);
		~List(void);
		void show(void);
		void hide(void);
		void add(void)
		{
			
			ListType::iterator it;
			WinDataClone  wt = Orz::WinData::getInstance().getClone();
			for(it = _list.begin(); it != _list.end(); ++it)
			{

				if(it->isVisible())
				{
					const WinDataClone temp = it->getData();
					it->show(wt);
					wt = temp;
				}
				else
				{
					it->show(wt);
					break;
				}
			}
			
		}
	private:
		typedef std::vector<ListItem>  ListType;
		ListType _list;
	};
}


#endif