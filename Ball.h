#pragma once
#include "raylib.h"
#include <vector>
#include <cmath>

class Ball
{
private:
	Color color;
	double radius;
	Vector2 ballPosition;
	Vector2 ballSpeed;

public:
	Ball(Color color, double radius, Vector2 ballPosition, Vector2 ballSpeed);
	Ball();
	Color getColor();
	void setColor(Color color);
	double getRadius();
	void setRadius(double radius);
	Vector2 getBallPosition();
	void setBallPosition(Vector2 ballSpeed);
	Vector2 getBallSpeed();
	void setBallSpeed(Vector2 ballSpeed);
	void ballsCollision(std::vector<Ball>& balls);
	bool ballsWindowCollision(int windowWidth, int windowHeight);
};

