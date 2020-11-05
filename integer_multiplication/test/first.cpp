#define CATCH_CONFIG_MAIN
#include <integer_multiplication.h>

#include <catch.hpp>
#include <chrono>

TEST_CASE("BinInt addition", "[binintadd]") {
  REQUIRE((BinInt(10) + BinInt(20)).to_long() == BinInt(30).to_long());
  REQUIRE((BinInt(10) + BinInt(20)).to_long() == 30);
  REQUIRE((BinInt(1) + BinInt(0)).to_long() == BinInt(1).to_long());
  REQUIRE(
      (BinInt(123132184) + BinInt(1984165189) + BinInt(5165786431)).to_long() ==
      (1984165189 + 123132184 + 5165786431));
}

TEST_CASE("BinInt subtraction", "[binintsub]") {
  REQUIRE((BinInt(20) - BinInt(10)).to_long() == BinInt(10).to_long());
  REQUIRE((BinInt(342342) - BinInt(9232)).to_long() == 342342 - 9232);
}

TEST_CASE("BinInt naive multiplication", "[binintnmult]") {
  REQUIRE((BinInt(10).naiveMult(BinInt(5))).to_long() == 50);
  REQUIRE((BinInt(1156).naiveMult(BinInt(5165))).to_long() == 5165ll * 1156ll);
  REQUIRE((BinInt(115619).naiveMult(BinInt(516519))).to_long() ==
          516519ll * 115619ll);
}

TEST_CASE("BinInt karatsuba multiplication", "[binintkamult]") {
  REQUIRE((BinInt(10).kaMult(BinInt(5))).to_long() == 50);
  REQUIRE((BinInt(1156).kaMult(BinInt(51655))).to_long() == 51655ll * 1156ll);
  REQUIRE((BinInt(115619).naiveMult(BinInt(516519))).to_long() ==
          516519ll * 115619ll);
}

TEST_CASE("Karatsuba vs Naive time", "[kavnatime]") {
  BinInt large1(423412341234ll), large2(3412341234ll);
  size_t n = 2000;
  for (size_t i = 0; i < n; i++) {
    large1.push_back(true);
    large1.push_back(false);
    large2.push_back(false);
    large2.push_back(true);
  }

  auto start = std::chrono::high_resolution_clock::now();
  auto large3 = large1.naiveMult(large2);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;

  std::cout << "Naive multiplication took " << diff.count() << " s.\n";

  start = std::chrono::high_resolution_clock::now();
  auto large4 = large1.kaMult(large2);
  end = std::chrono::high_resolution_clock::now();
  diff = end - start;

  std::cout << "Karatsuba multiplication took " << diff.count() << " s.\n";
}