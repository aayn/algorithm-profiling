#define CATCH_CONFIG_MAIN
#include <integer_multiplication.h>

#include <catch.hpp>
#include <chrono>
#include <iostream>

TEST_CASE("DecInt addition", "[decintadd]") {
  REQUIRE((DecInt(30) + DecInt(20)).to_long() == DecInt(30).to_long());
  REQUIRE((DecInt(10) + DecInt(20)).to_long() == 30);
  // REQUIRE((DecInt(1) + DecInt(0)).to_long() == DecInt(1).to_long());
  // REQUIRE(
  //     (DecInt(123132184) + DecInt(1984165189) + DecInt(5165786431)).to_long()
  //     == (1984165189 + 123132184 + 5165786431));
}

TEST_CASE("DecInt subtraction", "[decintsub]") {
  REQUIRE((DecInt(20) - DecInt(10)).to_long() == DecInt(10).to_long());
  REQUIRE((DecInt(342342) - DecInt(9232)).to_long() == 342342 - 9232);
}

// TEST_CASE("DecInt naive multiplication", "[decintnmult]") {
//   REQUIRE((DecInt(10).naiveMult(DecInt(5))).to_long() == 50);
//   REQUIRE((DecInt(1156).naiveMult(DecInt(5165))).to_long() == 5165ll *
//   1156ll); REQUIRE((DecInt(115619).naiveMult(DecInt(516519))).to_long() ==
//           516519ll * 115619ll);
// }

// TEST_CASE("DecInt karatsuba multiplication", "[decintkamult]") {
//   REQUIRE((DecInt(10).kaMult(DecInt(5))).to_long() == 50);
//   REQUIRE((DecInt(1156).kaMult(DecInt(51655))).to_long() == 51655ll *
//   1156ll); REQUIRE((DecInt(115619).naiveMult(DecInt(516519))).to_long() ==
//           516519ll * 115619ll);
// }

// TEST_CASE("Karatsuba vs Naive time", "[kavnatime]") {
//   DecInt large1(423412341234ll), large2(3412341234ll);
//   size_t n = 2000;
//   for (size_t i = 0; i < n; i++) {
//     large1.push_back(true);
//     large1.push_back(false);
//     large2.push_back(false);
//     large2.push_back(true);
//   }

//   auto start = std::chrono::high_resolution_clock::now();
//   auto large3 = large1.naiveMult(large2);
//   auto end = std::chrono::high_resolution_clock::now();
//   std::chrono::duration<double> diff = end - start;

//   std::cout << "Naive multiplication took " << diff.count() << " s.\n";

//   start = std::chrono::high_resolution_clock::now();
//   auto large4 = large1.kaMult(large2);
//   end = std::chrono::high_resolution_clock::now();
//   diff = end - start;

//   std::cout << "Karatsuba multiplication took " << diff.count() << " s.\n";
// }