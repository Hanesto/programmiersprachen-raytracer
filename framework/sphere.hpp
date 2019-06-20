#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <string>
#include "color.hpp"
#include "shape.hpp"

class Sphere : public Shape 
{
    public:
    virtual float area() override;
    virtual float volume() override;
    virtual std::ostream& print(std::ostream& os) const override; 
    
    Sphere();
    Sphere(std::string const& name, Color const& color, float radius);

    private:
    glm::vec3 center_;
    float radius_;
    Color color_;
    std::string name_;
};

#endif 