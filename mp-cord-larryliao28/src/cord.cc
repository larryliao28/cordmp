#include "cord.hpp"

#include <stdexcept>

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
  size_t length = 0;
  if (left_cord != nullptr) {
    length += left_cord->length_;
  }
  if (right_cord != nullptr) {
    length += right_cord->length_;
  }
  length_ = length;
}

size_t Cord::Length() const { return length_; }

std::shared_ptr<Cord> Cord::GetLeft() const { return left_; }

std::shared_ptr<Cord> Cord::GetRight() const { return right_; }

const std::string& Cord::GetData() const { return data_; }

std::string Cord::ToString() const {
  // TODO
  std::string str;
  if (left_ != nullptr) {
    str += left_->ToString();
  }
  if (right_ != nullptr) {
    str += right_->ToString();
  }
  str += data_;
  return str;
}

std::shared_ptr<Cord> Cord::SubString(size_t lower_idx, size_t upper_idx) {
  // TODO
  std::string str = this->ToString().substr(lower_idx, upper_idx);

  // leaf node
  if (left_ == nullptr && right_ == nullptr) {
    std::shared_ptr<Cord> to_return = std::make_shared<Cord>(str);
    return to_return;
  }
  if (left_ != nullptr && right_ == nullptr) {
    return left_->SubString(lower_idx, upper_idx);
  }
  if (left_ == nullptr && right_ != nullptr) {
    return right_->SubString(lower_idx, upper_idx);
  }
  if (lower_idx >= left_->length_) {
    return right_->SubString(lower_idx - left_->length_,
                             upper_idx - left_->length_);
  }
  if (upper_idx <= left_->length_) {
    return left_->SubString(lower_idx, upper_idx);
  }
  std::shared_ptr<Cord> concat =
      std::make_shared<Cord>(left_->SubString(lower_idx, left_->length_),
                             right_->SubString(0, upper_idx - left_->length_));

  return concat;
}

char Cord::At(size_t idx) const {
  // TODO
  if (idx >= length_ || idx < 0) {
    throw std::runtime_error("invalid input");
  }
  if (left_ == nullptr && right_ == nullptr) {
    return data_.at(idx);
  }
  if (left_ != nullptr && idx < left_->length_) {
    return left_->At(idx);
  }
  if (left_ != nullptr) {
    if (right_ != nullptr && idx >= left_->length_) {
      return right_->At(idx - (left_->length_));
    }
  } else {
    if (right_ != nullptr && idx >= 0) {
      return right_->At(idx);
    }
  }
  return '?';
}

bool Cord::IsValidCord() const {
  // TODO

  return false;
}

std::shared_ptr<Cord> Cord::RuduceHelp(
    std::map<std::string, std::shared_ptr<Cord>>& data_string) {
  if (data_string.find(this->ToString()) != data_string.end()) {
    return data_string.at(ToString());
  }
  if (left_ != nullptr) {
    left_ = left_->RuduceHelp(data_string);
  }
  if (right_ != nullptr) {
    right_ = right_->RuduceHelp(data_string);
  }
  data_string.insert(
      std::pair<std::string, std::shared_ptr<Cord>>(ToString(), this));

  return this->shared_from_this();
}
