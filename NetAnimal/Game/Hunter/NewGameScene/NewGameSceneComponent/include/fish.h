
namespace Ogre
{
	class Ogre::SceneNode;
	class Ogre::AnimationState;
	class Ogre::SimpleSpline;
	class Ogre::Entity;
}
namespace Orz
{
	using namespace Ogre;
	class fish
	{
	public:
		fish(void):NUM_FISH(5),NUM_FISH_WAYPOINTS(9),FISH_PATH_LENGTH(50),FISH_SCALE(12)
		{
			mFishNodes.resize(NUM_FISH);
			mFishAnimStates.resize(NUM_FISH);
			mFishSplines.resize(NUM_FISH);
			srand( (unsigned)time( NULL ) );//初始化随机数
			Ogre::Ray ray;
			Ogre::Sphere sphere(Ogre::Vector3(0,50,0),70);
			std::pair<bool, Real> result;
			for (unsigned int i = 0; i < NUM_FISH; i++)
			{
				// create fish entity
				Ogre::Entity* ent = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->createEntity("Fish" + StringConverter::toString(i + 1), "fish.mesh");
				if (Ogre::Math::UnitRandom()>0.5)
				{
					ent->setMaterialName("newgame/fish");
				}
				mSubmergedEnts.push_back(ent);

				// create an appropriately scaled node and attach the entity
				mFishNodes[i] = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->createChildSceneNode();
				mFishNodes[i]->setScale(Vector3::UNIT_SCALE * FISH_SCALE * Ogre::Math::RangeRandom(0.7,1));
				mFishNodes[i]->attachObject(ent);
				Ogre::MaterialPtr mp = ent->getSubEntity(0)->getMaterial();
				mp->getTechnique(0)->getPass(0)->setLightingEnabled(false);//适合没有光照的环境
				// enable and save the swim animation state
				mFishAnimStates[i] = ent->getAnimationState("swim");
				mFishAnimStates[i]->setEnabled(true);

				mFishSplines[i].setAutoCalculate(false);  // save the tangent calculation for when we are all done

				// generate random waypoints for the fish to swim through
				for (unsigned int j = 0; j < NUM_FISH_WAYPOINTS; j++)
				{
					Vector3 pos;
					for(int k=0;k<100;k++)
					{
						pos = Vector3(Math::SymmetricRandom() * 150, Math::RangeRandom(30,70), Math::SymmetricRandom() * 150);
						if(j==0)
						{
							if(pos.squaredDistance(Ogre::Vector3(0,50,0))>4900)
								break;
						}
						else
						{
							ray.setOrigin(mFishSplines[i].getPoint(j-1));
							ray.setDirection(pos-mFishSplines[i].getPoint(j-1));
							result=Ogre::Math::intersects(ray,sphere);
							std::cout<<"Origin="<<ray.getOrigin().x<<" "<<ray.getOrigin().y<<" "<<ray.getOrigin().z;
							std::cout<<"pos="<<pos.x<<" "<<pos.y<<" "<<pos.z<<std::endl;
							if(result.first==false || (result.first==true && 
								result.second*result.second> pos.squaredDistance(mFishSplines[i].getPoint(j-1))))
							{
								if(j==NUM_FISH_WAYPOINTS-1)
								{
									ray.setOrigin(pos);
									ray.setDirection(mFishSplines[i].getPoint(0)-pos);
									result=Ogre::Math::intersects(ray,sphere);
									std::cout<<"Origin="<<ray.getOrigin().x<<" "<<ray.getOrigin().y<<" "<<ray.getOrigin().z;
									std::cout<<"pos="<<pos.x<<" "<<pos.y<<" "<<pos.z<<std::endl;
									if(result.first==false || (result.first==true && 
										result.second*result.second> pos.squaredDistance(mFishSplines[i].getPoint(j-1))))
									{
										std::cout<<"lastOne:OK"<<std::endl;
										break;
									}
								}
								else
								{
									std::cout<<"OK"<<std::endl;
									break;
								}
							}
						}

					}
					mFishSplines[i].addPoint(pos);

				}

				// close the spline and calculate all the tangents at once
				mFishSplines[i].addPoint(mFishSplines[i].getPoint(0));
				mFishSplines[i].recalcTangents();
			}

			mFishAnimTime = 0;
		}
		virtual ~fish()
		{
			mSubmergedEnts.clear();
			mFishNodes.clear();
			mFishAnimStates.clear();
			mFishSplines.clear();

		}
		bool update(TimeType interval)
		{
			mFishAnimTime += interval;
			while (mFishAnimTime >= FISH_PATH_LENGTH) mFishAnimTime -= FISH_PATH_LENGTH;

			for (unsigned int i = 0; i < NUM_FISH; i++)
			{
				mFishAnimStates[i]->addTime(interval * Math::RangeRandom(2,3));  // update fish swim animation

				// set the new position based on the spline path and set the direction based on displacement
				Vector3 lastPos = mFishNodes[i]->getPosition();
				mFishNodes[i]->setPosition(mFishSplines[i].interpolate(mFishAnimTime / FISH_PATH_LENGTH));
				mFishNodes[i]->setDirection(mFishNodes[i]->getPosition() - lastPos, Node::TS_PARENT, Vector3::NEGATIVE_UNIT_X);
				mFishNodes[i]->setFixedYawAxis(true);
			}

			return true;
		}
	private:
		const unsigned int NUM_FISH;
		const unsigned int NUM_FISH_WAYPOINTS;
		const unsigned int FISH_PATH_LENGTH; 
		const Real FISH_SCALE;
		std::vector<SceneNode*> mFishNodes;
		std::vector<AnimationState*> mFishAnimStates;
		std::vector<SimpleSpline> mFishSplines;
		std::vector<Ogre::Entity*> mSubmergedEnts;
		Real mFishAnimTime;
	};
}