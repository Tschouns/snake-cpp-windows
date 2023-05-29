#pragma once

#include "IFood.h"

class Apple : public IFood
{
public:
	Apple() = delete;
	Apple(const FieldCoordinates position);
	FieldCoordinates GetPosition() const;
	int GetPointsAward() const;
	int GetPartsToGrow() const;
private:
	FieldCoordinates position;
};