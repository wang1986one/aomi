#ifndef __Orz_VedioUIComponent__
#define __Orz_VedioUIComponent__

namespace Ogre
{
	class SceneNode;
}
namespace CEGUI
{
	class Window;
}
namespace Orz
{
	class VedioUIInterface;

	class  VedioUIComponent: public Component
	{ 
	public :
		VedioUIComponent(void);
		virtual ~VedioUIComponent(void);
	private:
		virtual ComponentInterface * _queryInterface(const TypeInfo & info);
		boost::scoped_ptr<VedioUIInterface> _vedioInterface;

		bool load(const std::string & filename);
		bool isEnd(void);
		bool play(void);
		void reset(void);
		void createTexture(const std::string & filename);
		CEGUI::Window * getWindow(void);
	private:
		CEGUI::Window * _window;
		std::string _filename;

	};
}
#endif