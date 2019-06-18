#include "sphere.hpp"
#include "math.h"

sphere::sphere()
{
    center_ = {0,0,0};
    radius_ = 1.0f;
}

sphere::sphere(float radius)
{
    radius_ = radius;
}

float sphere::volume()
{
    float volume = 1.3333 * M_PI * pow(radius_, 3.0f);
    return volume;
}

float sphere::area()
{
    float area = 4 * M_PI * pow(radius_, 2);
    return area;
}