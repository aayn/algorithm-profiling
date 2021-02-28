#include <integer_multiplication.h>
#include <karatsuba.h>

#include <chrono>
#include <cstdio>
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
  int num_inputs;
  std::cin >> num_inputs;

  std::ofstream outfile;
  outfile.open("out.txt");

  int num_digits;
  for (int t = 0; t < num_inputs; t++) {
    std::cin >> num_digits;
    outfile << t << ", " << num_digits << ", ";

    BinInt bin_n1, bin_n2;
    for (int k = 0; k < num_digits / 2; k++) {
      bin_n1.push_back(0);
      bin_n1.push_back(1);
      bin_n2.push_back(1);
      bin_n2.push_back(0);
    }
    auto start = std::chrono::high_resolution_clock::now();
    auto large = bin_n1.naiveMult(bin_n2);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    outfile << diff.count() << ", ";

    start = std::chrono::high_resolution_clock::now();
    large = bin_n1.kaMult(bin_n2);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    outfile << diff.count() << "\n";
  }

  return 0;
}