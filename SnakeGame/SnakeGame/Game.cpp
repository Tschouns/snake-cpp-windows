#include "IGameWorld.h"
#include "IInputs.h"
#include "Game.h"
#include <cstddef>

Game::Game(int const worldDimension, int const initialSnakeLength)
{
	this->gameWorld = new GameWorld(worldDimension, worldDimension);
	this->snake = new Snake(*this->gameWorld, { worldDimension / 2, worldDimension / 2 }, initialSnakeLength);
}

Game::~Game()
{
	delete this->gameWorld;
	delete this->snake;
}

IGameWorld& Game::GetGameWorld() const
{
	return *this->gameWorld;
}

ISnake& Game::GetSnake() const
{
	return *this->snake;
}

void Game::Restart()
{
}

void Game::UpdateStep(const IInputs& const inputs)
{
	if (inputs.IsUp())
	{
		this->snake->Up();
	}

	if (inputs.IsDown())
	{
		this->snake->Down();
	}

	if (inputs.IsLeft())
	{
		this->snake->Left();
	}

	if (inputs.IsRight())
	{
		this->snake->Right();
	}

	this->snake->Move();
}