#include <stack>     // std::stack
#include <stdexcept> // std::invalid_argument
#include <string>    // std::string

static bool is_valid_char(char c) {
  // Valid chars: '0' '1' '!' '&' '|' '^' '>' '='
  return (c == '0' || c == '1' || c == '!' || c == '&' || c == '|' ||
          c == '^' || c == '>' || c == '=');
}

// fn eval_formula(formula: &str) -> bool;
bool eval_formula(const std::string &str) {
  if (str.empty()) {
    throw std::invalid_argument("Empty formula!");
  }

  if (str.size() == 1) {
    if (str[0] == '1' || str[0] == '0') {
      return (str[0] - '0');
    } else {
      throw std::invalid_argument("Invalid single character formula!");
    }
  }

  std::stack<bool> stack;
  for (char c : str) {
    if (!is_valid_char(c)) {
      throw std::invalid_argument("Invalid character in formula!");
    }

    if (c == '1' || c == '0') {
      stack.push(c - '0');
    } else if (c == '!') {
      if (stack.empty()) {
        throw std::runtime_error("Stack underflow on '!'");
      }

      bool a = stack.top();
      stack.pop();
      stack.push(!a);

    } else {
      if (stack.size() < 2) {
        throw std::runtime_error("Stack underflow on binary operator!");
      }

      bool b = stack.top();
      stack.pop();
      bool a = stack.top();
      stack.pop();

      bool result;

      switch (c) {
      case '&':
        result = a & b;
        break;
      case '|':
        result = a | b;
        break;
      case '^':
        result = a ^ b;
        break;
      case '>':
        result = (!a) | b;
        break;
      case '=':
        result = (a == b);
        break;
      default:
        throw std::invalid_argument("Invalid operator!");
      }
      stack.push(result);
    }
  }

  if (stack.size() != 1) {
    throw std::runtime_error("Invalid formula: There are still values on the "
                             "stack after execution!");
  }

  return (stack.top());
}

// tests ///////////////////////////////////////////////////////////////////////

#include <iostream>  // std::cout
#include <stdexcept> // std::invalid_argument
#include <string>    // std::string

static void test(const std::string &str, bool expected) {
  try {
    bool result = eval_formula(str);

    std::cout << str << " = " << (result ? "true" : "false") << " => "
              << (expected ? "true" : "false") << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

int main(void) {
  test("10&", false);
  test("10|", true);
  test("11>", true);
  test("10=", false);
  test("1011||=", true);
  test("", false);
}
