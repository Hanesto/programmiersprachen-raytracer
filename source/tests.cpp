#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"

TEST_CASE("Sphere and Box Shapes")
{
  sphere s1(5.0f);
  REQUIRE(s1.area() == 314.15927f);
  REQUIRE(s1.volume() == 523.58569f);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
