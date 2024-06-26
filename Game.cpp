#include "Game.h"

Game::Game(std::vector<Ball> ballVector)
{
    this->ballVector = ballVector;
}

Game::Game(std::vector<Ball> ballVector, Ball ball)
{
    this->ballVector = ballVector;
    this->ball = ball;
}

void Game::addBall(Ball ball) {
    this->ballVector.push_back(ball);
}

void Game::delBoll(Ball ball)
{
    // Implementation needed
}

std::vector<Ball> Game::getBallVector()
{
    return this->ballVector;
}

void Game::setBallVector(std::vector<Ball> ballVector)
{
    this->ballVector = ballVector;
}

void Game::mainGame(int height, int width, const char* title)
{
    InitWindow(width, height, title);
    SetTargetFPS(100);

    if (ballVector.empty()) {
        std::cerr << "Error: ballVector is empty" << std::endl;
        return;
    }

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            
            int red = rand() % 256;
            int green = rand() % 256;
            int blue = rand() % 256;
           
            Color color{ red, green, blue, 255 };

            Ball newBall(color, BALL_RADIUS, 3, GetMousePosition());
            std::cout << "Key has been pressed " << std::endl;
            addBall(newBall);
        }
        for (auto& ball : ballVector) {
            DrawCircle(ball.getBallPosition().x, ball.getBallPosition().y, BALL_RADIUS, ball.getColor());
            
            ball.ballsWindowCollision(width, height);
            ball.ballsCollision(this->ballVector);
            ball.move();
        }

        EndDrawing();
    }
}
