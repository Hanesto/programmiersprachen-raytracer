#include "shape.hpp"
#include <glm/vec3.hpp>

class box : public shape
{
    public:
    virtual float area();
    virtual float volume();
    box();
    box(glm::vec3 min, glm::vec3 max);

    private:
    glm::vec3 min_;
    glm::vec3 max_;
};