#include <iostream>
#include <stack>
#include <string>

static bool is_operator(char c) {
  return c == '!' || c == '&' || c == '|' || c == '^' || c == '>' || c == '=';
}

static bool is_variable(char c) { return (c >= 'A' && c <= 'Z'); }

static bool is_valid_char(char c) { return is_variable(c) || is_operator(c); }

static bool eval_formula(const std::string &formula) {
  std::stack<bool> stack;

  for (char c : formula) {
    if (c == '0' || c == '1') {
      stack.push(c - '0');
    } else if (c == '!') {
      if (stack.empty())
        throw std::runtime_error("Stack underflow on '!'");
      bool a = stack.top();
      stack.pop();
      stack.push(!a);
    } else {
      if (stack.size() < 2)
        throw std::runtime_error("Stack underflow on binary operator!");
      bool b = stack.top();
      stack.pop();
      bool a = stack.top();
      stack.pop();
      bool result;

      if (c == '&')
        result = a & b;
      else if (c == '|')
        result = a | b;
      else if (c == '^')
        result = a ^ b;
      else if (c == '>')
        result = (!a) | b;
      else if (c == '=')
        result = (a == b);
      else
        throw std::invalid_argument("Invalid operator!");

      stack.push(result);
    }
  }

  if (stack.size() != 1)
    throw std::runtime_error("Invalid formula: leftover values");
  return stack.top();
}

static void print_truth_table(const std::string &input) {
  char vars[26];
  int var_count = 0;

  for (char c : input) {
    if (c >= 'a' && c <= 'z')
      c -= 32;
    if (!is_valid_char(c))
      throw std::invalid_argument("Invalid character in formula!");
    if (is_variable(c)) {
      bool exists = false;
      for (int i = 0; i < var_count; i++) {
        if (vars[i] == c) {
          exists = true;
          break;
        }
      }
      if (!exists)
        vars[var_count++] = c;
    }
  }

  std::cout << "|";
  for (int i = 0; i < var_count; i++)
    std::cout << " " << vars[i] << " |";
  std::cout << " = |\n";

  std::cout << "|";
  for (int i = 0; i < var_count; i++)
    std::cout << "---|";
  std::cout << "---|\n";

  int total = 1 << var_count;
  for (int i = 0; i < total; i++) {
    std::string formula = input;

    for (int j = 0; j < var_count; j++) {
      char v = ((i >> (var_count - j - 1)) & 1) ? '1' : '0';
      for (int k = 0; k < (int)formula.size(); k++) {
        if (formula[k] == vars[j] || formula[k] == vars[j] + 32)
          formula[k] = v;
      }
    }

    std::cout << "|";
    for (int j = 0; j < var_count; j++) {
      char bit = ((i >> (var_count - j - 1)) & 1) ? '1' : '0';
      std::cout << " " << bit << " |";
    }

    bool res = eval_formula(formula);
    std::cout << " " << (res ? '1' : '0') << " |\n";
  }
}

// tests ///////////////////////////////////////////////////////////////////////
int main(void) {
  try {
    print_truth_table("AB&C|");
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
  }
}
