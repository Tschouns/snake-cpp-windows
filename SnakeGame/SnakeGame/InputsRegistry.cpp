#include "InputsRegistry.h"

bool InputsRegistry::IsUp() const {return up; }
bool InputsRegistry::IsDown() const { return down; }
bool InputsRegistry::IsLeft() const { return left; }
bool InputsRegistry::IsRight() const { return right; }

void InputsRegistry::RegisterUp() { up = true; }
void InputsRegistry::RegisterDown() { down = true; }
void InputsRegistry::RegisterLeft() { left = true; }
void InputsRegistry::RegisterRight() { right = true; }

void InputsRegistry::Reset()
{
	up = false;
	down = false;
	left = false;
	right = false;
}