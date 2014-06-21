#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include "System.h"

#include "../CoreComponents/MovementComponent.h"
#include "../CoreComponents/TransformComponent.h"

namespace Engine
{
	class MovementSystem : public System
	{
	public:
		MovementSystem( EventManager* evtManager, EntityManager* entManager );
		virtual ~MovementSystem();

	protected:
		virtual void init();

		virtual void preUpdate();
		virtual void updateEntities( const std::set< Entity* >& entities );
		virtual void postUpdate();

	private:
		void updateEntityPosition( Entity* entity );
	};
}

#endif
