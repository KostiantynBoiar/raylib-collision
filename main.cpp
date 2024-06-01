#include "Game.h"
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 900

int main() {
    srand(time(0)); 
    Ball ball(BLACK, 10., { WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2 }, { 5.0, 4.0 });
    std::vector<Ball> ballVector;
    Game game(ballVector);
    game.addBall(ball);
    game.mainGame(WINDOW_HEIGHT, WINDOW_WIDTH, "Collision game");

    return 0;
}