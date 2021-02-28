#include <integer_multiplication.h>
#include <karatsuba.h>

BinInt karatsubaMult(const BinInt& n1, const BinInt& n2, const int T) {
  BinInt n1_copy, n2_copy;
  if (n1.size() > n2.size()) {
    n1_copy = n1;
    n2_copy = n1;
    for (size_t i = 0; i < n1.size(); i++) {
      n2_copy[i] = (i > n2.size()) ? false : n2[i];
    }
  } else {
    n1_copy = n2;
    n2_copy = n2;
    for (size_t i = 0; i < n2.size(); i++) {
      n1_copy[i] = (i > n1.size()) ? false : n1[i];
    }
  }

  return kHelper(n1_copy, n2_copy);
}

BinInt kHelper(const BinInt& n1, const BinInt& n2, const int T) {
  if (n1.size() < T || n2.size() < T) return n1.naiveMult(n2);
  size_t m1 = n1.size() / 2, m2 = n2.size() / 2;

  BinInt n1L = n1.slice(0, m1), n1R = n1.slice(m1, n1.size());
  BinInt n2L = n2.slice(0, m2), n2R = n2.slice(m2, n2.size());

  BinInt x = kHelper(n1R, n2R);
  BinInt y = kHelper(n1L, n2L);
  BinInt z = kHelper((n1L + n1R), (n2L + n2R));
  z = z - (x + y);

  for (size_t i = 0; i < m1 + m2; i++) x.push_front(false);
  for (size_t i = 0; i < m1; i++) z.push_front(false);

  return x + y + z;
}