#pragma once

#include "ISnake.h"
#include "IGameWorld.h"

class Snake : public ISnake
{
public:
	Snake() = delete;
	Snake(const IGameWorld& gameWorld, const FieldCoordinates startingField, const int initialLength);

	std::list<FieldCoordinates> GetFields() const;
	FieldCoordinates GetHead() const;
	void Up();
	void Down();
	void Left();
	void Right();
	void Move();
	void Grow(const int numberOfParts);

private:
	FieldCoordinates WrapAroundWorldBounds(const IGameWorld& world, const FieldCoordinates field);

	const FieldCoordinates UP = { 0, -1 };
	const FieldCoordinates DOWN = { 0, 1 };
	const FieldCoordinates LEFT = { -1, 0 };
	const FieldCoordinates RIGHT = { 1, 0 };

	const IGameWorld* gameWorld;
	// Contains the snake's fields, i.e. body parts. The first field represents the head.
	std::list<FieldCoordinates> fields;
	FieldCoordinates movingDirection = this->RIGHT;
	int partsToGrow = 0;
};