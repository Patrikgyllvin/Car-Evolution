#if !defined(__APPLE__) || defined(_MAC_MAKEFILE)
#include "../../include/Game/Game.h"
#else
#include "Game.h"
#endif

Game::Game()
:
eventManager( new Engine::EventManager() ),
entityManager( new Engine::EntityManager( eventManager ) )
//moveSys( new Engine::MovementSystem( eventManager, entityManager ) )
{}

Game::~Game()
{
	delete entityManager;
	delete eventManager;
}

void Game::init()
{
}

void Game::tick()
{
}

void Game::render()
{}
