// Define u32 as uint32_t (unsigned 32-bit integer)
#include <cstdint>
using u32 = uint32_t;

// fn adder(a: u32, b: u32) -> u32;
u32 adder(u32 a, u32 b) {
  u32 carry;

  while (b != 0b0) {
    carry = a & b;
    a = a ^ b;
    b = carry << 0b1;
  }
  return (a);
}

// tests ///////////////////////////////////////////////////////////////////////

#include <iostream>
static void test(u32 a, u32 b) {
  std::cout << a << " + " << b << " = " << adder(a, b) << std::endl;
}

int main(void) {
  test(0, 0);
  test(0, 1);
  test(1, 0);
  test(1, 1);
  test(1, 2);
  test(2, 1);
  test(2, 2);
}
