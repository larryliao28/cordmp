#include "cord-utilities.hpp"

#include <map>
#include <stdexcept>
#include <string>

std::shared_ptr<Cord> ConcatCords(std::shared_ptr<Cord> left_cord,
                                  std::shared_ptr<Cord> right_cord) {
  // TODO
  if (left_cord->IsValidCord() && right_cord->IsValidCord()) {
    std::shared_ptr<Cord> to_return =
        std::make_shared<Cord>(left_cord, right_cord);
    return to_return;
  }
  throw std::runtime_error("unable to concat");
}

void ReduceCords(cs128::ReferenceList<std::shared_ptr<Cord>> cords) {
  // TODO
  std::map<std::string, std::shared_ptr<Cord>> data_pointer;
  for (std::shared_ptr<Cord>& c : cords) {
    c = c->RuduceHelp(data_pointer);
  }
}