#pragma once
#include "raylib.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <chrono>

#define u 0.2
#define g 9.8

class Ball
{
private:
	Color color;
	double radius;
	Vector2 ballPosition;
	Vector2 ballSpeed;
	float mass;
	std::chrono::steady_clock::time_point previousTime;
	std::chrono::steady_clock::time_point currentTime;

public:
	Ball(Color color, double radius, float mass, Vector2 ballPosition);
	Ball();
	float getMass();
	void setMass(float mass);
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
	void move();
	Vector2 energy_loose(float dx, float dy);
};

