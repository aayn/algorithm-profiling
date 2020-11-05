#include <integer_multiplication.h>

int main(int argc, char** argv) {
  auto x = BinInt(5) + BinInt(10) + BinInt(45);
  std::cout << x.to_long() << std::endl;

  auto y = BinInt(10).naiveMult(BinInt(5));
  std::cout << y.to_long() << std::endl;

  return 0;
}