// Define u32 as uint32_t (unsigned 32-bit integer)
#include <cstdint>
using u32 = uint32_t;

// fn adder(a: u32, b: u32) -> u32;
u32 adder(u32 a, u32 b) {
  u32 carry;

  while (b != 0) {
    carry = a & b;
    a = a ^ b;
    b = carry << 1;
  }
  return (a);
}

// tests ///////////////////////////////////////////////////////////////////////

#include <iostream>
static void test(u32 a, u32 b, u32 expected) {
  std::cout << a << " + " << b << " = " << adder(a, b) << " => " << expected
            << std::endl;
}

int main(void) {
  test(0, 0, 0);
  test(0, 1, 1);
  test(1, 0, 1);
  test(1, 1, 2);
  test(1, 2, 3);
  test(2, 1, 3);
  test(2, 2, 4);
}
