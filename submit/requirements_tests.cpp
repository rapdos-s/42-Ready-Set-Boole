// generic_types_test //////////////////////////////////////////////////////////
#include <iostream>

template <typename T>
T ft_add(T a, T b) { return a + b; }

static void generic_types_test(void) {
	std::cout << "\nSupport generic types" << std::endl;
	std::cout << "4 + 2 = " << ft_add<int>(4, 2) << std::endl;
	std::cout << "4.2 + 2.4 = " << ft_add<double>(4.2, 2.4) << std::endl;
	std::cout << "\"Zaphod\" + \"Beeblebrox\" = \"" << ft_add<std::string>("Zaphod", "Beeblebrox") << "\"" <<std::endl;
}

// first_class_citizens_test ///////////////////////////////////////////////////
static int ft_double(int a) {
	return (a * 2);
}

#include <iostream>
static void test_callback(int (*callback_function)(int), int value) {
	std::cout << "Callback: " << callback_function(value) << std::endl;
}

#include <iostream>
#include <functional>
static void test_wrapper(int (*callback_function)(int), int value) {
	std::function<int(int)> func = callback_function;

	std::cout << "Wrapper:  " << func(value) << std::endl;
}

#include <functional>
static std::function<int(int)> ft_multiplier(int a) {
	std::function<int(int)> lambda_b = [a](int b) { return (b * a); };

	return (lambda_b);
};

#include <iostream>
static void test_lambda(int value) {
	auto lambda = ft_multiplier(6);

	std::cout << "Lambda:   " << lambda(7) << std::endl;
}

#include <iostream>
static void first_class_citizens_test(void) {
	std::cout << "\nSupport functions as first class citizens" << std::endl;
	test_callback(ft_double, 21);
	test_wrapper(ft_double, 21);
	test_lambda(21);
}

// bitwise_test ////////////////////////////////////////////////////////////////

#include <iostream>
static void bitwise_test(void) {
	int a = 42;

	std::cout << "\nSupport bitwise operations" << std::endl;
	std::cout << "&  with integers: " << ((int)'*' & 42) << std::endl;
	std::cout << "|  with integers: " << (0 | 42) << std::endl;
	std::cout << "^  with integers: " << (0 ^ 42) << std::endl;
	std::cout << "<< with integers: " << (21 << 1) << std::endl;
	std::cout << ">> with integers: " << (168 >> 2) << std::endl;
	std::cout << "=  with integers: " << (a) << std::endl;
	std::cout << "== with integers: " << ((42 == 42) * 42) << std::endl;
	std::cout << "!= with integers: " << ((42 != 21) * 42) << std::endl;
	std::cout << "<  with integers: " << ((21 < 42) * 42) << std::endl;
	std::cout << ">  with integers: " << ((42 > 21) * 42) << std::endl;
	std::cout << "<= with integers: " << ((42 <= 42) * 42) << std::endl;
	std::cout << ">= with integers: " << ((42 >= 21) * 42) << std::endl;
}

// operator_overloading ////////////////////////////////////////////////////////
class Ft_robot {
	private:
		std::string	name;
		int					hp;

	public:
		Ft_robot(std::string const& robot_name, int robot_hp) : name(robot_name), hp(robot_hp) {}

		std::string get_name(void) const { return (this->name); }
		int get_hp(void) const { return (this->hp); }

		Ft_robot& operator -= (int damage) { this->hp -= damage; return (*this); }
		Ft_robot& operator += (int heal) { this->hp += heal; return (*this); }
};

std::ostream& operator << (std::ostream& os, Ft_robot const& robot) {
	os << "[" << robot.get_name() << "] HP: " << robot.get_hp();
	return (os);
}

#include <iostream>
static void operator_overloading(void) {
	std::cout << "\nSupport operator overloading" << std::endl;
	Ft_robot marvin("Marvin", 42);
	std::cout << marvin << std::endl;
	marvin -= 21;
	std::cout << marvin << std::endl;
	marvin += 21;
	std::cout << marvin << std::endl;
}

// main ////////////////////////////////////////////////////////////////////////
#include <iostream>
int	main(void) {
	std::cout << "Language constraints:" << std::endl;
	generic_types_test();
	first_class_citizens_test();
	bitwise_test();
	operator_overloading();
	return (0);
}
