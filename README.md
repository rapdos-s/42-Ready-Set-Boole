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

ex03
Time complexity: O(n), where n is the size of the input string.
Space complexity: 0(n), where n is the size of the input string.

- If the formula is empty, throw an exception.
- If the formula has only one character:
  - Return true if it's '1', false if it's '0'.
  - Otherwise, throw an exception.
- Iterate over each character in the formula:
  - If it's '0' or '1', push its boolean value onto the stack.
  - If it's '!', pop one value, apply NOT, and push the result.
  - If it's a binary operator ('&', '|', '^', '>', '='):
    - Pop two values, apply the operator, and push the result.
    - If there are fewer than two values, throw an exception.
- After processing, the stack must contain exactly one value.
  - If not, throw an exception.
  - Otherwise, return the final result.

ex04
Time complexity: O(2^n * m) where n is the number of variables and m is the length of the formula.
Space complexity: O(m + n) where n is the number of variables and m is the length of the formula.

- Validate input
  - Convert formula to uppercase.
  - Ensure only valid characters: `A–Z`, `! & | ^ > =`.
  - Throw an exception if an invalid character is found.

- Extract variables
  - Collect all distinct uppercase letters `A–Z`.
  - Sort them in alphabetical order.

- Generate combinations
  - For `n` variables, generate all `2^n` possible binary combinations.

- Evaluate each row
  - For each combination:
    - Replace variables in the formula with the current values.
    - Evaluate using `eval_formula`.
    - Store the result.

- Print table
  - Print header: variable names followed by a result column (`=`).
  - Print each row with variable values and the corresponding result, formatted as in the example.
