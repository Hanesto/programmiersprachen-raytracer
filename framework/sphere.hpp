#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <glm/vec3.hpp>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "ray.hpp"
#include "hitPoint.hpp"
#include "color.hpp"
#include "shape.hpp"

class Sphere : public Shape 
{
    public:
    virtual float area() override;
    virtual float volume() override;
    virtual std::ostream& print(std::ostream& os) const override; 
    
    HitPoint intersect(Ray ray);

    Sphere();
    Sphere(std::string const& name, Color const& color, float radius, glm::vec3 const& center);

    private:
    glm::vec3 center_;
    float radius_;
    Color color_;
    std::string name_;
};

#endif 