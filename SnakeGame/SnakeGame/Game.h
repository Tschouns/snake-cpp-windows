#pragma once

#include "IGame.h"
#include "GameWorld.h"
#include "IFood.h"

class Game : public IGame
{
public:
	Game() = delete;
	Game(int worldDimension, int initialSnakeLength);
	~Game();
	const IGameWorld& GetGameWorld() const;
	const ISnake& GetSnake() const;
	const IFood& GetFood() const;
	int GetPoints() const;
	bool IsFinished() const;

	void Restart();
	void UpdateStep(const IInputs& inputs);

private:
	void InitializeGame();
	const IFood* CreateFood();

	int worldDimensions;
	int initialSnakeLength;
	const GameWorld* gameWorld;
	Snake* snake;
	const IFood* food;
	int points;
	bool isFinished;
};