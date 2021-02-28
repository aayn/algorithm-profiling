#include <integer_multiplication.h>
#include <karatsuba.h>

#include <chrono>
#include <cstdio>
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
  std::ofstream outfile;
  outfile.open("out_t.txt");

  BinInt bin_n1, bin_n2;
  for (int k = 0; k < 16384; k++) {
    bin_n1.push_back(0);
    bin_n1.push_back(1);
    bin_n2.push_back(1);
    bin_n2.push_back(0);
  }

  for (int T = 2; T < 100; T++) {
    auto start = std::chrono::high_resolution_clock::now();
    auto large = bin_n1.kaMult(bin_n2, T);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    outfile << T << ", " << diff.count() << "\n";
  }

  return 0;
}