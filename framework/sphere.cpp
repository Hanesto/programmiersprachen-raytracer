#include <iostream>
#include "sphere.hpp"
#include "math.h"

Sphere::Sphere():
    Shape{},
    center_{0,0,0},
    radius_{1.0f}{}


Sphere::Sphere(std::string const& name, Color const& color,  float radius):
    Shape{name, color},
    radius_{radius}{}


std::ostream& Sphere::print(std::ostream& os) const
{
   return os << "Name: " << name_ << " Radius: " << radius_ << " Farbe: " 
    << color_.r << " " << color_.g << " " << color_.b << std::endl;
}

float Sphere::volume()
{
    float volume = 1.3333 * M_PI * pow(radius_, 3.0f);
    return volume;
}

float Sphere::area()
{
    float area = 4 * M_PI * pow(radius_, 2);
    return area;
}