// Define u32 as uint32_t (unsigned 32-bit integer)
#include <cstdint>
using u32 = uint32_t;

// fn gray_code(n: u32) -> u32;
u32 gray_code(u32 n) { return (n ^ (n >> 0b1)); }

// tests ///////////////////////////////////////////////////////////////////////

#include <iostream>
static void test(u32 n, u32 expected) {
  std::cout << "G(" << n << ") = " << gray_code(n) << " => " << expected
            << std::endl;
}

int main(void) {
  test(0, 0);
  test(1, 1);
  test(2, 3);
  test(3, 2);
  test(4, 6);
  test(5, 7);
  test(6, 5);
  test(7, 4);
  test(8, 12);
}
