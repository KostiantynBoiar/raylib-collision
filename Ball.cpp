#include "Ball.h"

Ball::Ball(Color color, double radius, float mass, Vector2 ballPosition)
{
    this->color = color;
    this->radius = radius;
    this->ballPosition = ballPosition;
    this->ballSpeed = ballSpeed;
    this->mass = mass;
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

float Ball::getMass()
{
    return this->mass;
}

void Ball::setMass(float mass)
{
    this->mass = mass;
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
    if (ballSpeed.x >= 10) {
        this->ballSpeed.x = 10;
    }
    if (ballSpeed.y >= 10) {
        this->ballSpeed.y = 10;
    }
    this->ballSpeed.x = ballSpeed.x;
    this->ballSpeed.y = ballSpeed.y;
}

void Ball::ballsCollision(std::vector<Ball>& balls)
{

    /* Vector 1 is other while vector2 is this-> */
    for (auto& other : balls) {
        
        if (&other == this) continue;
        float distance = std::sqrt(((other.getBallPosition().x - this->getBallPosition().x) * (other.getBallPosition().x - this->getBallPosition().x)) + 
            ((other.getBallPosition().y - this->getBallPosition().y) * (other.getBallPosition().y - this->getBallPosition().y)));
        
        float v1_abs = std::sqrt((other.getBallSpeed().x * other.getBallSpeed().x) + (other.getBallSpeed().y * other.getBallSpeed().y));
        float v2_abs = std::sqrt((this->getBallSpeed().x * this->getBallSpeed().x) + (this->getBallSpeed().y * this->getBallSpeed().y));;

        float norm_x = (this->getBallPosition().x - other.getBallPosition().x) / distance;
        float norm_y = (this->getBallPosition().y - other.getBallPosition().y) / distance;

        float p_val = (2 * (other.getBallSpeed().x * norm_x + other.getBallSpeed().y * norm_y - this->getBallSpeed().x * norm_x + this->getBallSpeed().y * norm_y)) / (other.getMass() + this->getMass());
        //std::cout << "Vector norm x: " << norm_x << " " << "Vector norm y: " << norm_y << " " << "v1_abs: " << v1_abs << " " << "v2_abs: " << v2_abs << std::endl;
        //std::cout << "Vector norm x: " << norm_x << " " << "Vector norm y: " << norm_y << std::endl;

        if (distance <= this->getRadius() + other.getRadius()) {
            other.setBallSpeed(
                {
                    (other.getBallSpeed().x - p_val * other.getMass() * norm_x),
                    (other.getBallSpeed().y - p_val * other.getMass() * norm_y)
                }
            );
            this->setBallSpeed(
                {
                    (this->getBallSpeed().x + p_val * this->getMass() * norm_x),
                    (this->getBallSpeed().y + p_val * this->getMass() * norm_y)
                }
            );
        }
    }
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

void Ball::move()
{

    this->currentTime = std::chrono::steady_clock::now();

    std::chrono::duration<double> deltaTime = this->currentTime - this->previousTime;

    double deltaTimeSeconds = deltaTime.count();

    this->previousTime = this->currentTime;

    Vector2 velocity = this->getBallSpeed();
    double vi_x = velocity.x;
    double vi_y = velocity.y;

    double dx = vi_x * deltaTimeSeconds;
    double dy = vi_y * deltaTimeSeconds;

    Vector2 energy_vel = energy_loose(dx, dy);

    this->setBallPosition(
        { energy_vel.x, energy_vel.y }
    );
    
}

/* vf = sqrt((2*u*g*d+v^2i)) */
Vector2 Ball::energy_loose(float dx, float dy)
{
    float vi_x = this->getBallSpeed().x;
    float vi_y = this->getBallSpeed().y;

    float vf_x, vf_y;

    if (vi_x < 0) {
        vf_x = -std::sqrt((2 * (u * g * dx + (vi_x * vi_x))) / this->getMass());
    }
    else {
        vf_x = std::sqrt((2 * (u * g * dx + (vi_x * vi_x))) / this->getMass());
    }

    if (vi_y < 0) {
        vf_y = -std::sqrt((2 * (u * g * dy + (vi_y * vi_y))) / this->getMass());
    }
    else {
        vf_y = std::sqrt((2 * (u * g * dy + (vi_y * vi_y))) / this->getMass());
    }

    if (vf_x > 8) {
        vf_x = 8;
    }
    if (vf_y > 8) {
        vf_y = 8;
    }
    std::cout << "vf_x: " << vf_x << " " << "vf_y: " << vf_y << std::endl;

    return { vf_x, vf_y };
}
