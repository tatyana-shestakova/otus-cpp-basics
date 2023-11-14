#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"
#include "Color.hpp"

class Ball {
public:
    Ball(const Velocity& velocity, const Point& center, const Color& newColor, double newRadius);
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
private: 
    Velocity newVelocity;
    Point newCenter;
    Color newColor;
    double newRadius;
};
