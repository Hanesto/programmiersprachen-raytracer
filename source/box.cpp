#include "box.hpp"

box::box()
{
    min_ = {0,0,0};
    max_ = {1,1,1};
}

box::box(glm::vec3 min, glm::vec3 max)
{
    min_ = min;
    max_ = max;
}

float box::area()
{
    float a = (min_.x - max_.x) * -1;
    float b = (min_.y - max_.y) * -1;
    float c = (min_.z - max_.z) * -1;

    float area = 2 *(a*b) + 2 *(a*c) + 2*(b*c);
    return area;
}

float box::volume()
{
   float a = (min_.x - max_.x) * -1;
   float b = (min_.y - max_.y) * -1;
   float c = (min_.z - max_.z) * -1;

   float volume = a * b * c;
   return volume; 
}
