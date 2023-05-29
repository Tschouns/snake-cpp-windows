#pragma once

#include "FieldCoordinates.h"

/// <summary>
/// Represents a piece of food which awards points and makes the snake grow.
/// </summary>
class IFood
{
public:
	/// <summary>
	/// Gets the position of the piece of food.
	/// </summary>
	/// <returns>
	/// The position of the piece of food
	/// </returns>
	virtual FieldCoordinates GetPosition() const = 0;

	/// <summary>
	/// Gets the number of points awarded for eating the food.
	/// </summary>
	/// <returns>
	/// The number of points
	/// </returns>
	virtual int GetPointsAward() const = 0;

	/// <summary>
	/// Gets the number of body parts to grow the snake upon eating the food.
	/// </summary>
	/// <returns>
	/// The number of body parts to grow the snake
	/// </returns>
	virtual int GetPartsToGrow() const = 0;
};