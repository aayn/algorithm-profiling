#pragma once
#include <cstdint>
#include <deque>
#include <initializer_list>
#include <iostream>
#include <vector>

class BinInt {
 public:
  BinInt() = default;
  BinInt(const BinInt&) = default;
  BinInt& operator=(const BinInt&) = default;

  BinInt(BinInt&&) = default;
  BinInt& operator=(BinInt&&) = default;

  virtual ~BinInt() = default;

  BinInt(std::initializer_list<bool> init);
  BinInt(uint64_t n);

  bool operator[](size_t i) const;
  bool& operator[](size_t i);
  BinInt operator+(const BinInt& other);
  BinInt operator-(const BinInt& other);
  bool operator==(const BinInt& other) const;

  BinInt slice(size_t start, size_t end) const;

  BinInt naiveMult(const BinInt& other) const;
  BinInt kaMult(const BinInt& other);

  size_t size() const;
  void push_back(bool b);
  void push_front(bool b);
  uint64_t to_long();

 private:
  std::deque<bool> binarr_;
};
