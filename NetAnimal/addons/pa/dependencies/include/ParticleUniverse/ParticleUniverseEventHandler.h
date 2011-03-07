/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#ifndef __PU_EVENT_HANDLER_H__
#define __PU_EVENT_HANDLER_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseIAlias.h"
#include "ParticleUniverseIElement.h"
#include "OgreVector3.h"

namespace ParticleUniverse
{
	/** A ParticleEventHandlers is used to perform a task in case a certain event happens.
	@remarks
		A ParticleEventHandler is associated with a ParticleObserver; The ParticleObserver signals what event occurs,
		while the ParticleEventHandler performs some action.
	*/
	class _ParticleUniverseExport ParticleEventHandler : public IAlias, public IElement
	{
		protected:
			// Observer to which the eventhandler is associated.
			ParticleObserver* mParentObserver;

			// Type of event handler
			Ogre::String mEventHandlerType;

			// Name of the eventHandler (optional)
			Ogre::String mName;

			/** Although the scale is on a Particle System level, the event handler can also be scaled.
			*/
			Ogre::Vector3 _mEventHandlerScale;

		public:
			ParticleEventHandler(void) : 
				IElement(),
				mParentObserver(0),
				mName(Ogre::StringUtil::BLANK),
				_mEventHandlerScale(Ogre::Vector3::UNIT_SCALE)
			{
				mAliasType = AT_HANDLER;
			};
			virtual ~ParticleEventHandler(void) {};

			/** Todo
	        */
			const Ogre::String& getName(void) const {return mName;};
			void setName(const Ogre::String& name) {mName = name;};

			/** Todo
	        */
			ParticleObserver* getParentObserver(void) const {return mParentObserver;};
			void setParentObserver(ParticleObserver* parentObserver) {mParentObserver = parentObserver;};

			/** Todo
	        */
			const Ogre::String& getEventHandlerType(void) const {return mEventHandlerType;};
			void setEventHandlerType(const Ogre::String& eventHandlerType) {mEventHandlerType = eventHandlerType;};

			/** Notify that the event handler is rescaled.
	        */
			virtual void _notifyRescaled(const Ogre::Vector3& scale){_mEventHandlerScale = scale;};

			/** Todo
	        */
			virtual void _handle(ParticleTechnique* particleTechnique, Particle* particle, Ogre::Real timeElapsed) = 0;

			/** Copy attributes to another event handler.
	        */
			virtual void copyAttributesTo (ParticleEventHandler* eventHandler)
			{
				copyParentAttributesTo(eventHandler);
			};

			/** Copy parent attributes to another event handler.
	        */
			virtual void copyParentAttributesTo (ParticleEventHandler* eventHandler)
			{
				eventHandler->setName(mName);
				eventHandler->mParentObserver = mParentObserver;
				eventHandler->_mEventHandlerScale = _mEventHandlerScale;
			};
	};

}
#endif
