#include "Apple.h"

Apple::Apple(const FieldCoordinates position)
{
	this->position = position;
}

FieldCoordinates Apple::GetPosition() const
{
	return this->position;
}

int Apple::GetPointsAward() const
{
	return 1;
}

int Apple::GetPartsToGrow() const
{
	return 3;
}