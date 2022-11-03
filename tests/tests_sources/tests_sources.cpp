#include "../tests_includes/tests_my_convert_temp.hpp"

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}
// #include <iostream>
// #include <iomanip>
// int main() {
//     float	temp_fahrenheit;
// 	float	temp_celsius;

// 	temp_fahrenheit = 100;
// 	temp_celsius = (5.0 / 9.0) * (temp_fahrenheit - 32);
// 	std::cout.precision(3);
// 	std::cout.setf(std::ios::fixed, std::ios::floatfield);
// 	std::cout << std::setw(16) << temp_celsius << std::setw(16) << "Celsius" << std::endl;
//     return 0;
// }