unsigned int adder(unsigned int a, unsigned int b) {
  unsigned int carry;

  while (b != 0) {
    carry = a & b;
    a = a ^ b;
    b = carry << 1;
  }
  return (a);
}
// tests ///////////////////////////////////////////////////////////////////////

#include <iostream>
static void test(unsigned int a, unsigned int b) {
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
