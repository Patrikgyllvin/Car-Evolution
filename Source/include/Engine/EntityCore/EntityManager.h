#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <iostream>
#include <iomanip>

#include <vector>

#include "../Events/EventManager.h"
#include "../Events/EntityEvent.h"

#include "Entity.h"

#include "../CoreComponents/Component.h"
#include "../../ComponentTypes.h"

namespace Engine
{
	class EntityManager
	{
	public:
		EntityManager( EventManager* eManager );
		~EntityManager();

		Entity* genEntity();
		void destroyEntity( Entity* entity );

		Component* addComponent( Entity* entity, Component* comp );
		void destroyComponent( Entity* entity, ComponentType compType );

		void destroyAllComponents( Entity* entity );

		Component* getComponent( Entity* entity, ComponentType compType );

	private:
		typedef std::vector< Entity* > EntityList;

		EventManager* eventManager;

		EntityID nextID;
	
		std::vector< unsigned int > usedIDs;
	
		EntityList entities;
		std::vector< std::vector< Component* > > components;
	};
}

#endif
