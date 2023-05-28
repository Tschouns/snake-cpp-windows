#include "GameRenderer.h"
#include "framework.h"

GameRenderer::GameRenderer(const int fieldSize, const int padding)
{
    this->fieldSize = fieldSize;
    this->padding = padding;
}

void GameRenderer::DrawFrame(const IGame& const game, const HDC& hdc)
{
    auto lightBlueBrush = CreateSolidBrush(RGB(230, 230, 255));
    auto greenBrush = CreateSolidBrush(RGB(0, 150, 100));
    auto redBrush = CreateSolidBrush(RGB(200, 50, 50));

    // Draw the world.
    this->DrawFilledRectangle(
        hdc,
        lightBlueBrush,
        this->padding,
        this->padding,
        game.GetGameWorld().GetWidth() * this->fieldSize,
        game.GetGameWorld().GetHeight() * this->fieldSize);

    // Draw the snake.
    for (auto field : game.GetSnake().GetFields())
    {
        this->DrawFilledRectangle(
            hdc,
            greenBrush,
            this->padding + field.x * this->fieldSize,
            this->padding + field.y * this->fieldSize,
            this->fieldSize,
            this->fieldSize);
    }

    // Draw the food.
    auto foodPos = game.GetFood().GetPosition();
    this->DrawFilledRectangle(
        hdc,
        redBrush,
        this->padding + foodPos.x * this->fieldSize,
        this->padding + foodPos.y * this->fieldSize,
        this->fieldSize,
        this->fieldSize);

    // Continuously display points.
    TCHAR pointsText[256];
    swprintf_s(pointsText, 256, L"Points: %d", game.GetPoints());

    TextOut(hdc, 5, 5, pointsText, wcslen(pointsText));

    // Display a "finished" message.
    if (game.IsFinished())
    {
        TCHAR finishText[256];
        swprintf_s(finishText, 256, L"Finished with %d points!", game.GetPoints());
        auto textPosX = game.GetGameWorld().GetWidth() / 3 * this->fieldSize;
        auto textPosY = game.GetGameWorld().GetHeight() / 2 * this->fieldSize;

        TextOut(hdc, textPosX, textPosY, finishText, wcslen(finishText));
    }

    DeleteObject(lightBlueBrush);
    DeleteObject(greenBrush);
    DeleteObject(redBrush);
}

void GameRenderer::DrawFilledRectangle(const HDC& hdc, const HBRUSH& brush, int x, int y, int width, int height)
{
    RECT fieldRect;
    fieldRect.left = x;
    fieldRect.top = y;
    fieldRect.right = x + width;
    fieldRect.bottom = y + height;

    FillRect(hdc, &fieldRect, brush);
}