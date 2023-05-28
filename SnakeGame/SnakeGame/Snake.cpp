#include "Snake.h"

Snake::Snake(
	const IGameWorld& const gameWorld,
	const FieldCoordinates const startingField,
	const int const initialLength)
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

std::list<FieldCoordinates> Snake::GetFields() const
{
	return this->fields;
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
	this->fields.pop_back();
}

FieldCoordinates Snake::WrapAroundWorldBounds(const IGameWorld& const world, const FieldCoordinates const field)
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