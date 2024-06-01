#include "Ball.h"

Ball::Ball(Color color, double radius, Vector2 ballPosition)
{
    this->color = color;
    this->radius = radius;
    this->ballPosition = ballPosition;
    this->ballSpeed = ballSpeed;
    ballSpeed.x = rand() % 5;
    ballSpeed.y = rand() % 5;
}

Ball::Ball()
{
    this->color = BLACK;
    this->radius = 10.f;
    this->ballPosition = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
    ballSpeed.x = rand() % 5;
    ballSpeed.y = rand() % 5;
}

Color Ball::getColor()
{
    return this->color;
}

void Ball::setColor(Color color)
{
    this->color = color;
}

double Ball::getRadius()
{
    return this->radius;
}

void Ball::setRadius(double radius)
{
    this->radius = radius;
}

Vector2 Ball::getBallPosition()
{
    return this->ballPosition;
}

void Ball::setBallPosition(Vector2 ballSpeed)
{
    this->ballPosition.x += ballSpeed.x;
    this->ballPosition.y += ballSpeed.y;
}

Vector2 Ball::getBallSpeed()
{
    return this->ballSpeed;
}

void Ball::setBallSpeed(Vector2 ballSpeed)
{
    this->ballSpeed.x = ballSpeed.x;
    this->ballSpeed.y = ballSpeed.y;
}

void Ball::ballsCollision(std::vector<Ball>& balls)
{
  
}

bool Ball::ballsWindowCollision(int windowWidth, int windowHeight)
{
    bool flag = false;
    if (this->ballPosition.x + this->radius >= windowWidth) {
        this->ballPosition.x = windowWidth - this->radius;
        this->ballSpeed.x *= -1;
        flag = true;
    }
    if (this->ballPosition.x - this->radius <= 0) {
        this->ballPosition.x = this->radius; 
        this->ballSpeed.x *= -1;
        flag = true;
    }
    if (this->ballPosition.y + this->radius >= windowHeight) {
        this->ballPosition.y = windowHeight - this->radius; 
        this->ballSpeed.y *= -1;
        flag = true;
    }
    if (this->ballPosition.y - this->radius <= 0) {
        this->ballPosition.y = this->radius; 
        this->ballSpeed.y *= -1;
        flag = true;
    }
    if (flag) {
        double newR = getRadius() + 0.5;
        setRadius(newR);
    }
    return flag;
}
