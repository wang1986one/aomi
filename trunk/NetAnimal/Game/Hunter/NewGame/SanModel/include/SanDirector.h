#ifndef __Orz_SanDirector__
#define __Orz_SanDirector__
namespace Orz

{
	class SanDirector:public Director
	{
	public:
		SanDirector(const std::string & name, parameter_type);
		virtual ~SanDirector(void);

	};

	/*extern char const SanDirectorType[]= "SanDirector";
	typedef Orz::GameFactory<Director, SanDirector, SanDirectorType> SanDirectorFactory;*/
};
#endif