#include "GameRenderer.h"
#include "framework.h"

GameRenderer::GameRenderer(const int fieldSize, const int padding)
{
    this->fieldSize = fieldSize;
    this->padding = padding;
}

void GameRenderer::DrawFrame(const IGame* const game, const HDC const hdc)
{
    // Draw the world bounds.
    Rectangle(
        hdc,
        this->padding,
        this->padding,
        this->padding + game->GetGameWorld().GetWidth() * this->fieldSize,
        this->padding + game->GetGameWorld().GetHeight() * this->fieldSize);

    // Draw the snake.
    for (auto field : game->GetSnake().GetFields())
    {
        Rectangle(
            hdc,
            this->padding + field.x * this->fieldSize,
            this->padding + field.y * this->fieldSize,
            this->padding + field.x * this->fieldSize + this->fieldSize,
            this->padding + field.y * this->fieldSize + this->fieldSize);
    }

    TCHAR text[256];
    swprintf_s(text, 256, L"Snake Size: %d", game->GetSnake().GetFields().size());
    TextOut(hdc, 5, 5, text, wcslen(text));
}