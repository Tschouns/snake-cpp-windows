#pragma once

#include "IInputs.h"
#include "IGameWorld.h"

/// <summary>
/// Represents the Snake game itself. Contains the entire game logic.
/// </summary>
class IGame
{
public:
	/// <summary>
	/// Gets the game world.
	/// </summary>
	/// <returns>
	/// The game world
	/// </returns>
	virtual IGameWorld& GetGameWorld() const = 0;

	/// <summary>
	/// Gets the snake.
	/// </summary>
	/// <returns>
	/// The snake
	/// </returns>
	virtual ISnake& GetSnake() const = 0;

	/// <summary>
	/// Restarts the game.
	/// </summary>
	virtual void Restart() = 0;

	/// <summary>
	/// Performs an update step.
	/// </summary>
	/// <param name="inputs">
	/// The user inputs
	/// </param>
	virtual void UpdateStep(const IInputs& inputs) = 0;
};