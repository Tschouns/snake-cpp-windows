#pragma once

#include "framework.h"
#include "IGame.h"

// FOCUS POINT: const correctness
class GameRenderer
{
public:
	GameRenderer() = delete;
	GameRenderer(const int fieldSize, const int padding);
	void DrawFrame(const IGame& game, const HDC& hdc);

private:
	void DrawFilledRectangle(const HDC& hdc, const HBRUSH& brush, int x, int y, int width, int height);

	int fieldSize = 5;
	int padding = 10;
};