#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include <iostream>
#include <string>
#include "color.hpp"
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"


TEST_CASE("Sphere Shape")
{
  Color color(0.5f, 0.3f, 0.4f);
  glm::vec3 center1{3,1,4};
  Sphere s2{};
  Sphere s1{"Sabine", color, 5.0f, center1};

  std::cout << ">> Sphere Ausgabe <<" << std::endl;
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

  std::cout << ">> Box Ausgabe <<" << std::endl;
  std::cout << b1 << std::endl;
  REQUIRE(b1.area() == 90);
  REQUIRE(b1.volume() == 50);
}

TEST_CASE("intersect_ray_sphere" , "[intersect]")
{
  // Ray
  glm::vec3 ray_origin {0.0f, 0.0f, 0.0f};
  glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};
  // Sphere
  glm::vec3 sphere_center{0.0f, 0.0f, 5.0f};
  float sphere_radius{1.0f};
  float distance = 0.0f;
  auto result = glm::intersectRaySphere(ray_origin, ray_direction, sphere_center,
  sphere_radius * sphere_radius, distance);
  REQUIRE (distance == Approx (4.0f));
}

TEST_CASE("intersect fuction", "[intersect]")
{
  Color color(0.5f, 0.3f, 0.4f);
  glm::vec3 center1{1,3,1};
  Ray ray;
  HitPoint hitpoint;

  Sphere s1{"Sabine", color, 5.0f, center1};
  hitpoint = s1.intersect(ray);

  if(hitpoint.gotHit == true)
  {
    std::cout << hitpoint.gotHit << " Name: " << hitpoint.name << " Color: " << hitpoint.color 
        << " Schnittpunkt: " << hitpoint.point.x << " " << hitpoint.point.y << " " << hitpoint.point.z
        << " Distanz: " << hitpoint.distance << std::endl;
  }
  else{
    std::cout << hitpoint.gotHit;
  }

  Color color2(0.2f, 0.1f, 0.7f);
  glm::vec3 center2{-1,5,-4};
  
  Sphere s2("Joachim", color2, 2.0f, center2);
  hitpoint = s2.intersect(ray);

  if(hitpoint.gotHit == true)
  {
    std::cout << hitpoint.gotHit << " Name: " << hitpoint.name << " Color: " << hitpoint.color 
        << " Schnittpunkt: " << hitpoint.point.x << " " << hitpoint.point.y << " " << hitpoint.point.z
        << " Distanz: " << hitpoint.distance << std::endl;
  }
  else{
    std::cout << hitpoint.gotHit << std::endl;
  }

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
