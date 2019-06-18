#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"
#include <glm/vec3.hpp>

TEST_CASE("Sphere and Box Shapes")
{
  sphere s1(5.0f);
  REQUIRE(s1.area() == 314.15927f);
  REQUIRE(s1.volume() == 523.58569f);
 
  glm::vec3 min = {0,0,0};
  glm::vec3 max = {5,5,2};
  box b1(min, max);
  REQUIRE(b1.area() == 90);
  REQUIRE(b1.volume() == 50);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
