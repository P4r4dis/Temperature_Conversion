#include "../includes/my_convert_temp.hpp"

double my_convert_fahrenheit_to_celsius(double temp_fahrenheit) {
	const double 		melting_point_of_ice = 32;
	const double		constant = 5.0 / 9.0;
	double				result = 0.0;

	result = (constant) * (temp_fahrenheit - melting_point_of_ice);
	std::cout.precision(3);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout << std::setw(16) << result << std::setw(16) 
    << "Celsius" << std::endl << std::flush;
	return result;
}

double my_convert_celsius_to_fahrenheit(double temp_celsius) {
    const double 		melting_point_of_ice = 32;
	const double		constant = 1.8;
	double				fahrenheit = 0.0;

	fahrenheit = (temp_celsius * constant) + melting_point_of_ice;
	std::cout.precision(3);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout << std::setw(16) << fahrenheit << std::setw(16) 
    << "Fahrenheit" << std::endl << std::flush;
	return fahrenheit;
}