#pragma once
#include "Ball.h"
#include <vector>
#include <iostream>

class Game
{
private:
	Ball ball;
	std::vector<Ball> ballVector;
public:
	Game(std::vector<Ball> ballVector);
	Game(std::vector<Ball> ballVector, Ball ball);
	Game();

	void addBall(Ball ball);
	void delBoll(Ball ball);
	std::vector<Ball> getBallVector();
	void setBallVector(std::vector<Ball> ballVector);

	void mainGame(int height, int width, const char* title);
};

