#include "Game.h"
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 900

int main() {
    srand(time(0)); 
    Vector2 ballSpeed;
    ballSpeed.x = rand() % 5;
    ballSpeed.y = rand() % 5;
    Ball ball(BLACK, 10., 3., { WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2 });
    std::vector<Ball> ballVector;
    Game game(ballVector);
    game.addBall(ball);
    game.mainGame(WINDOW_HEIGHT, WINDOW_WIDTH, "Collision game");

    return 0;
}