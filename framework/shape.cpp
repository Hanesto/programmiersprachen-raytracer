#include "shape.hpp"

Shape::Shape():
    name_{"Nobody"},
    color_{0,0,0}{}


Shape::Shape(std::string const& name, Color const& color):
    name_{name},
    color_{color}{}


std::ostream& Shape::print(std::ostream& os) const
{
    return os << "Name: " << name_ << " Farbe: " << color_ << std::endl;
}

std::ostream& operator<<(std::ostream& os, Shape const& s)
{
   return s.print(os);
}