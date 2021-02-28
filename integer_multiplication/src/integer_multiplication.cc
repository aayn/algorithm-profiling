#pragma once
#include <integer_multiplication.h>
#include <karatsuba.h>

#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <vector>

BinInt::BinInt(std::initializer_list<bool> init) : binarr_(init) {}

BinInt::BinInt(uint64_t n) {
  uint64_t mask = 1;
  for (size_t i = 0; i < 64; i++) {
    if (n & mask)
      binarr_.push_back(true);
    else
      binarr_.push_back(false);
    mask <<= 1;
  }
}

bool BinInt::operator[](size_t i) const { return binarr_[i]; }

bool& BinInt::operator[](size_t i) { return binarr_[i]; }

BinInt BinInt::operator+(const BinInt& other) {
  BinInt ans;
  size_t i = 0;
  bool v, carry = 0;
  while (i < size() && i < other.size()) {
    v = binarr_[i] != other[i] != carry;
    carry = binarr_[i] && other[i] || binarr_[i] && carry || carry && other[i];
    ans.push_back(v);
    i++;
  }
  while (i < size()) {
    v = binarr_[i] != carry;
    carry = binarr_[i] && carry;
    ans.push_back(v);
    i++;
  }

  while (i < other.size()) {
    v = other[i] != carry;
    carry = other[i] && carry;
    ans.push_back(v);
    i++;
  }
  if (carry) ans.push_back(carry);
  return ans;
}

BinInt BinInt::operator-(const BinInt& other) {
  BinInt ans;
  size_t i = 0;
  bool v, carry = 0;
  while (i < size() && i < other.size()) {
    v = binarr_[i] != other[i] != carry;
    carry = (binarr_[i] && other[i] && carry) || (!binarr_[i] && other[i]) ||
            (!binarr_[i] && carry);
    ans.push_back(v);
    i++;
  }
  while (i < size()) {
    v = binarr_[i] != carry;
    carry = (!binarr_[i] && carry);
    ans.push_back(v);
    i++;
  }

  return ans;
}

bool BinInt::operator==(const BinInt& other) const {
  size_t i = 0;
  while (i < size() && i < other.size()) {
    if (binarr_[i] != other[i]) return false;
    i++;
  }
  while (i < size()) {
    if (binarr_[i]) return false;
    i++;
  }

  while (i < other.size()) {
    if (other[i]) return false;
    i++;
  }
  return true;
}

BinInt BinInt::slice(size_t start, size_t end) const {
  BinInt num;
  end = std::min(end, size());
  for (size_t i = start; i < end; i++) num.push_back(binarr_[i]);
  return num;
}

BinInt BinInt::naiveMult(const BinInt& other) const {
  BinInt ans;

  for (size_t i = 0; i < size(); i++) {
    BinInt curr;
    for (size_t k = 0; k < i; k++) curr.push_back(false);

    for (size_t j = 0; j < other.size(); j++) {
      if (binarr_[i] && other[j])
        curr.push_back(true);
      else
        curr.push_back(false);
    }

    ans = ans + curr;
  }

  return ans;
}

BinInt BinInt::kaMult(const BinInt& other, const int T) {
  return karatsubaMult(*this, other, T);
}

size_t BinInt::size() const { return binarr_.size(); }

void BinInt::push_back(bool b) { binarr_.push_back(b); }

void BinInt::push_front(bool b) { binarr_.push_front(b); }

uint64_t BinInt::to_long() {
  uint64_t l = 0;
  uint64_t p = 1;
  for (size_t i = 0; i < size(); i++) {
    if (binarr_[i]) l += p;
    p *= 2;
  }
  return l;
}
