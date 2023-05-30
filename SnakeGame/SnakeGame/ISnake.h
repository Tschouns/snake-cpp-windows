#pragma once

#include <list>
#include "FieldCoordinates.h"
#include "IFood.h"

/// <summary>
/// Represents the snake as a list of fields.
/// </summary>
class ISnake
{
public:
	/// <summary>
	/// Gets the fields which constitute the snake -- i.e. the snake's body parts.
	/// </summary>
	/// <returns>
	/// The fields which constitute the snake
	/// </returns>
	virtual const std::list<FieldCoordinates>& GetFields() const = 0;

	/// <summary>
	/// Gets the snake's head (i.e. first field or body part).
	/// </summary>
	/// <returns>
	/// The snake's head
	/// </returns>
	virtual FieldCoordinates GetHead() const = 0;

	/// <summary>
	/// Makes the snake change its moving direction to up.
	/// </summary>
	virtual void Up() = 0;

	/// <summary>
	/// Makes the snake change its moving direction to down.
	/// </summary>
	virtual void Down() = 0;

	/// <summary>
	/// Makes the snake change its moving direction to left.
	/// </summary>
	virtual void Left() = 0;

	/// <summary>
	/// Makes the snake change its moving direction to right.
	/// </summary>
	virtual void Right() = 0;

	/// <summary>
	/// Makes the snake move (and grow) a step in its current moving direction.
	/// </summary>
	virtual void Move() = 0;

	/// <summary>
	/// Feeds the snake food, which makes it grow larger.
	/// </summary>
	/// <param name="food">
	/// The food to feed
	/// </param>
	virtual void Feed(const IFood& food) = 0;
};