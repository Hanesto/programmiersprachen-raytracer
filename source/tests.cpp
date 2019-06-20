#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include <iostream>
#include <string>
#include "color.hpp"
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"


TEST_CASE("Sphere Shape")
{
  Color color(0.5f, 0.3f, 0.4f);
  Sphere s2{};
  Sphere s1{"Sabine", color, 5.0f};

  std::cout << s1 << std::endl;
  REQUIRE(s1.area() == 314.15927f);
  REQUIRE(s1.volume() == 523.58569f);
}

TEST_CASE("Box Shape")
{
  Color color2(0.2f, 0.6f, 0.2f);
  glm::vec3 min = {0,0,0};
  glm::vec3 max = {5,5,2};

  Box b1("Herbert", color2, min, max);

  std::cout << b1 << std::endl;
  REQUIRE(b1.area() == 90);
  REQUIRE(b1.volume() == 50);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
