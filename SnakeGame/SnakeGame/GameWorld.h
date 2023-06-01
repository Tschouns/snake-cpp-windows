#pragma once

#include "IGameWorld.h"

class GameWorld : public IGameWorld
{
public:
	GameWorld() = delete;
	GameWorld(const int w, const int h)
	{
		this->width = w;
		this->height = h;
	}

	int GetWidth() const;
	int GetHeight() const;

private:
	int width = 100;
	int height = 100;
};

