#include "Snake.h"

Snake::Snake(
	const IGameWorld& gameWorld,
	const FieldCoordinates startingField,
	const int initialLength)
{
	this->gameWorld = &gameWorld;

	// Add fields, i.e. body parts, head to tail.
	auto currentField = startingField;

	for (int i = 0; i < initialLength; i++)
	{
		this->fields.push_back(currentField);
		currentField = currentField - this->movingDirection;
	}
}

const std::list<FieldCoordinates>& Snake::GetFields() const
{
	return this->fields;
}

FieldCoordinates Snake::GetHead() const
{
	return this->fields.front();
}

void Snake::Up()
{
	if (this->movingDirection == this->DOWN)
	{
		return;
	}

	this->movingDirection = this->UP;
}

void Snake::Down()
{
	if (this->movingDirection == this->UP)
	{
		return;
	}

	this->movingDirection = this->DOWN;
}

void Snake::Left()
{
	if (this->movingDirection == this->RIGHT)
	{
		return;
	}

	this->movingDirection = this->LEFT;
}

void Snake::Right()
{
	if (this->movingDirection == this->LEFT)
	{
		return;
	}

	this->movingDirection = this->RIGHT;
}

void Snake::Move()
{
	auto potentialNewHead = this->fields.front() + this->movingDirection;

	// Apply world bounds.
	auto newHead = this->WrapAroundWorldBounds(*this->gameWorld, potentialNewHead);

	this->fields.push_front(newHead);

	if (this->partsToGrow > 0)
	{
		this->partsToGrow--;
		return;
	}

	this->fields.pop_back();
}

void Snake::Grow(const int numberOfParts)
{
	this->partsToGrow += numberOfParts;
}

FieldCoordinates Snake::WrapAroundWorldBounds(const IGameWorld& world, const FieldCoordinates field)
{
	auto x = field.x;
	auto y = field.y;

	if (x < 0)
	{
		x = world.GetWidth() - 1;
	}

	if (y < 0)
	{
		y = world.GetHeight() - 1;
	}

	if (x >= world.GetWidth())
	{
		x = 0;
	}

	if (y >= world.GetHeight())
	{
		y = 0;
	}

	return { x, y };
}