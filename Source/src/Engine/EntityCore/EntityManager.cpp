#ifndef __APPLE__
#include "Engine/EntityCore/EntityManager.h"
#else
#include "EntityManager.h"
#endif

namespace Engine
{
	EntityManager::EntityManager( EventManager* eManager )
	:
	eventManager( eManager ),
	nextID( 0 ),
	usedIDs(),
	entities()
	{
		components.resize( COMPONENT_LAST );
	}

	EntityManager::~EntityManager()
	{
		for( std::vector< Entity* >::iterator it = entities.begin(); it != entities.end(); ++it )
			destroyEntity( *it );

		entities.clear();

		usedIDs.clear();

		for( unsigned int i = 0; i < COMPONENT_LAST; i++ )
			components[ i ].clear();

		components.clear();
	}

	Entity& EntityManager::genEntity()
	{
		EntityID id;

		if( usedIDs.size() )
		{
			id = usedIDs.back();
			usedIDs.pop_back();
		}
		else
		{
			id = nextID++;
		}

		if( id >= entities.size() )
			entities.resize( id + 1, nullptr );

        // TODO: Remove
        // Temp. return...
		Entity* entity;

		entities[ id ] = entity;

		// Notify systems
		eventManager->pushEvent( EntityEvent( EVENT_ENTITY_CREATED, entity ) );

		return *entity;
	}

	void EntityManager::destroyEntity( Entity* entity )
	{
		usedIDs.push_back( entity->getID() );

		//destroyAllComponents( entity );

		// Notify systems
		eventManager->pushEvent( EntityEvent( EVENT_ENTITY_DESTROYED, entity ) );

		delete entity;
	}
	/*
	Component* EntityManager::addComponent( Entity* entity, Component* comp )
	{
		std::vector< Component* >& entList = components[ comp->getType() ];

		if( entity->getID() >= entList.size() )
			entList.resize( entity->getID() + 1 );

		if( entList[ entity->getID() ] != nullptr )
		{
			std::cout << "Component already added!\n";
			return nullptr;
		}

		entList[ entity->getID() ] = comp;

		entity->typeBits |= comp->getTypeBits();

		// Notify systems
		eventManager->pushEvent( EntityEvent( EVENT_ENTITY_COMPONENT_ADDED, entity ) );

		return comp;
	}*/
}
