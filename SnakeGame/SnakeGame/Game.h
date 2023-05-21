#pragma once

#include "IGame.h"
#include "GameWorld.h"

class Game : public IGame
{
public:
	Game() = delete;
	Game(int worldDimension, int initialSnakeLength);
	~Game();
	IGameWorld& GetGameWorld() const;
	ISnake& GetSnake() const;

	void Restart();
	void UpdateStep(const IInputs& inputs);

private:
	GameWorld* gameWorld;
	Snake* snake;
};