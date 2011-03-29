#include "JsComponentStableHeaders.h"
#include "Js.h"

using namespace Orz;


Js::Js(void)
{

}
Js::~Js(void)
{

}

Js & Js::getInstance(void)
{
	return *(getInstancePtr());
}
Js * Js::getInstancePtr(void)
{
	static Js instance;
	return &instance;
}