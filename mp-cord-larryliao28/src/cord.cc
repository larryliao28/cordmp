#include "cord.hpp"

#include "cord-utilities.hpp"

Cord::Cord(const std::string& dat) {
  data_ = dat;
  length_ = dat.length();
}

Cord::Cord(const std::shared_ptr<Cord>& left_cord,
           const std::shared_ptr<Cord>& right_cord) {
  // TODO
  left_ = left_cord;
  right_ = right_cord;
  length_ = left_cord->length_ + right_cord->length_;
}

size_t Cord::Length() const { return length_; }

std::shared_ptr<Cord> Cord::GetLeft() const { return left_; }

std::shared_ptr<Cord> Cord::GetRight() const { return right_; }

const std::string& Cord::GetData() const { return data_; }

std::string Cord::ToString() const {
  // TODO
  // std::string str = "";
  // if (left_ == nullptr) {
  //   left_ ->
  // }
  // left_ -> ToString();
  // right_ -> ToString();

  // return "";
}

std::shared_ptr<Cord> Cord::SubString(size_t lower_idx, size_t upper_idx) {
  // TODO
  return nullptr;
}

char Cord::At(size_t idx) const {
  // TODO
}

bool Cord::IsValidCord() const {
  // TODO
  return false;
}
