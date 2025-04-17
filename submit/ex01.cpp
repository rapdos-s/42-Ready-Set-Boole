// Define u32 as uint32_t (unsigned 32-bit integer)
#include <cstdint>
using u32 = uint32_t;

// fn multiplier(a: u32, b: u32) -> u32;
u32 multiplier(u32 a, u32 b) {
  u32 result = 0b0;
  u32 carry;
  u32 addend;

  while (a != 0b0) {
    if (a & 0b1) {
      addend = b;

      while (addend != 0b0) {
        carry = result & addend;
        result = result ^ addend;
        addend = carry << 0b1;
      }
    }
    a = a >> 0b1;
    b = b << 0b1;
  }
  return (result);
}

// tests ///////////////////////////////////////////////////////////////////////

#include <iostream>
static void test(u32 a, u32 b, u32 expected) {
  std::cout << a << " * " << b << " = " << multiplier(a, b) << " => "
            << expected << std::endl;
}

int main(void) {
  test(0, 0, 0);
  test(0, 1, 0);
  test(1, 0, 0);
  test(2, 1, 2);
  test(2, 3, 6);
  test(3, 2, 6);
  test(3, 3, 9);
}
