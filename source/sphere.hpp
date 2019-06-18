#include "shape.hpp"
#include <glm/vec3.hpp>

class sphere : public shape 
{
    public:
    virtual float area();
    virtual float volume();
    sphere();
    sphere(float radius);

    private:
    glm::vec3 center_;
    float radius_;
};