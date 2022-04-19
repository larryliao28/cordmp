#include <cassert>
#include <iostream>

#include "cord-utilities.hpp"
#include "cord.hpp"

int main() {
  std::shared_ptr<Cord> left_cord(new Cord("he"));
  std::shared_ptr<Cord> right_cord(new Cord("llo"));
  Cord helloCord(left_cord, right_cord);

  std::cout << "hello test: " << helloCord.ToString() << std::endl;
  std::cout << "hello test: " << helloCord.Length() << std::endl;
  std::cout << "hello test: " << helloCord.At(2) << std::endl;
  return 0;
}
