#pragma once

#include <list>
#include "FieldCoordinates.h"

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
	virtual std::list<FieldCoordinates> GetFields() const = 0;
};