#include "Game.h"
#include "Apple.h"
#include "IGameWorld.h"
#include "IInputs.h"
#include <cstddef>
#include <cstdlib>

Game::Game(int const worldDimension, int const initialSnakeLength)
{
	this->worldDimensions = worldDimension;
	this->initialSnakeLength = initialSnakeLength;

	this->InitializeGame();
}

Game::~Game()
{
	delete this->gameWorld;
	delete this->snake;
	delete this->food;
}

IGameWorld& Game::GetGameWorld() const
{
	return *this->gameWorld;
}

ISnake& Game::GetSnake() const
{
	return *this->snake;
}

IFood& Game::GetFood() const
{
	return *this->food;
}

int Game::GetPoints() const
{
	return this->points;
}

bool Game::IsFinished() const
{
	return this->isFinished;
}

void Game::Restart()
{
	delete this->gameWorld;
	delete this->snake;
	delete this->food;

	this->InitializeGame();
}

void Game::UpdateStep(const IInputs& inputs)
{
	if (this->isFinished)
	{
		return;
	}

	// Update the snake.
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

	// Check for / eat food.
	if (this->snake->GetHead() == this->food->GetPosition())
	{
		this->points += this->food->GetPointsAward();
		this->snake->Grow(this->food->GetPartsToGrow());

		// Spawn new food.
		delete this->food;
		this->food = CreateFood();
	}

	// Check for death / loose condition.
	bool isHead = true;
	for (auto bodyPart : this->snake->GetFields())
	{
		// Skip the head itself.
		if (isHead)
		{
			isHead = false;
			continue;
		}

		if (bodyPart == this->snake->GetHead())
		{
			// Collision with itself - the game is lost!
			this->isFinished = true;
		}
	}
}

void Game::InitializeGame()
{
	this->gameWorld = new GameWorld(this->worldDimensions, this->worldDimensions);
	this->snake = new Snake(
		*this->gameWorld,
		{ this->worldDimensions / 2, this->worldDimensions / 2 },
		this->initialSnakeLength);

	this->food = this->CreateFood();
	this->points = 0;
	this->isFinished = false;
}

IFood* Game::CreateFood()
{
	FieldCoordinates position =
	{
		rand() % this->GetGameWorld().GetWidth(),
		rand() % this->GetGameWorld().GetHeight()
	};

	return new Apple(position);
}