# 42-Ready-Set-Boole
An introduction to Boolean Algebra

PDF Version: 2

ex00
Time complexity: O(n) where n = bits of largest number at 32 max.
Space complexity: O(1).

ex01
Time complexity: O(n²) where n = bits of largest number at 32 max.
Space complexity: 0(1).

Uses Russian Peasant Multiplication

ex02
Time complexity: O(1).
Space complexity: O(1).

To calculate gray code in a simple way, follow:
Find MSB (Most Significant Bit) of the number. Use MSB as first bit of gray code.
Then, for each bit from MSB to LSB (Least Significant Bit), XOR the current bit with the previous bit.

To calculate gray code in a more efficient way, follow:
G(n) = n ^ (n >> 0b1)

