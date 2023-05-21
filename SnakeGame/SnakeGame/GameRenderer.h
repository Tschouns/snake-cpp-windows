#pragma once

#include "framework.h"
#include "IGame.h"

// FOCUS POINT: const correctness
class GameRenderer
{
public:
	GameRenderer() = delete;
	GameRenderer(const int fieldSize, const int padding);
	void DrawFrame(const IGame* game, const HDC hdc);

private:
	int fieldSize = 5;
	int padding = 10;
};