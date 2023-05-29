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
	IGameWorld& GetGameWorld() const;
	ISnake& GetSnake() const;
	IFood& GetFood() const;
	int GetPoints() const;
	bool IsFinished() const;

	void Restart();
	void UpdateStep(const IInputs& inputs);

private:
	void InitializeGame();
	IFood* CreateFood();

	int worldDimensions;
	int initialSnakeLength;
	GameWorld* gameWorld;
	Snake* snake;
	IFood* food;
	int points;
	bool isFinished;
};