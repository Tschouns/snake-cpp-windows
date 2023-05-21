#pragma once

/// <summary>
/// Specifies the coordinates of a field in a 2-dimensional grid.
/// </summary>
struct FieldCoordinates
{
	/// <summary>
	/// The X coordinate.
	/// </summary>
	int x = 0;

	/// <summary>
	/// The Y coordinate.
	/// </summary>
	int y = 0;

	FieldCoordinates operator+(const FieldCoordinates& other)
	{
		return { x + other.x, y + other.y };
	}

	FieldCoordinates operator-(const FieldCoordinates& other)
	{
		return { x - other.x, y - other.y };
	}

	bool operator==(const FieldCoordinates& other)
	{
		return
			x == other.x &&
			y == other.y;
	}

	bool operator!=(const FieldCoordinates& other)
	{
		return
			x != other.x ||
			y != other.y;
	}
};