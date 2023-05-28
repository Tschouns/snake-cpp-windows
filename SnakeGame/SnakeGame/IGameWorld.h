#pragma once

#include "ISnake.h"

/// <summary>
/// Represents the game world of the Snake game.
/// </summary>
class IGameWorld
{
public:
	/// <summary>
	/// Gets the game world's width.
	/// </summary>
	/// <returns>
	/// The game world's width
	/// </returns>
	virtual int GetWidth() const = 0;

	/// <summary>
	/// Gets the game world's height.
	/// </summary>
	/// <returns>
	/// The game world's height
	/// </returns>
	virtual int GetHeight() const = 0;
};