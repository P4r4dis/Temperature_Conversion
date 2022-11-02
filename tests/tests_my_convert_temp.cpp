#include "../includes/my_convert_temp.hpp"
#include "./tests_includes/tests_my_convert_temp.hpp"

ParameterizedTestParameters(temp_fahrenheit, temp_celsius) {
    static struct parameter_tuple temperatures[] = {
		{-459.670, -273.150},
		{-50, -45.556},
		{-40, -40.000},
		{-30, -34.444},
		{-20, -28.889},
		{-10, -23.333},
		{0, -17.778},
		{10, -12.222},
		{20, -6.667},
		{30, -1.111},
		{32, 0},
		{40, 4.444},
        { 46.400, 8},
		{50, 10},
		{60, 15.556},
		{70, 21.111},
		{80, 26.667},
		{90, 32.222},
		{95, 35},
        {100, 37.778},
    };

    return cr_make_param_array(struct parameter_tuple, temperatures, sizeof (temperatures) / sizeof (struct parameter_tuple));
}

Test(my_convert_fahrenheit_to_celsius, simple, .init=redirect_all_stdout) {
    my_convert_fahrenheit_to_celsius(-459.670);
	cr_assert_stdout_eq_str("        -273.150         Celsius\n");
}

ParameterizedTest(struct parameter_tuple *tup, temp_fahrenheit, temp_celsius, .init=redirect_all_stdout) {
	const double 		melting_point_of_ice = 32;
	const double		constant = 5.0 / 9.0;
	double				result = 0.0;
	std::ostringstream 	a;

	result = (constant) * (tup->temp_fahrenheit - melting_point_of_ice);
	std::cout.precision(3);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
    a << std::setw(16) << floor((result * pow(10, 3) + 0.5)) / pow(10, 3) << std::setw(16) 
    << "Celsius" << std::endl;
	std::cout << a.str().c_str() << std::flush;
	cr_assert_stdout_eq_str(a.str().c_str(),"        %f         Celsius\n", tup->temp_celsius);//"        -273.150         Celsius\n"
}

ParameterizedTestParameters(temp_fahrenheit_eq, temp_celsius_eq) {
    static struct parameter_tuple temperatures[] = {
		{-459.670, -273.150},
		{-50, -45.556},
		{-40, -40.000},
		{-30, -34.444},
		{-20, -28.889},
		{-10, -23.333},
		{0, -17.778},
		{10, -12.222},
		{20, -6.667},
		{30, -1.111},
		{32, 0},
		{40, 4.444},
        { 46.400, 8},
		{50, 10},
		{60, 15.556},
		{70, 21.111},
		{80, 26.667},
		{90, 32.222},
		{95, 35},
        {100, 37.778},
    };

    return cr_make_param_array(struct parameter_tuple, temperatures,
	sizeof (temperatures) / sizeof (struct parameter_tuple));
}

ParameterizedTest(struct parameter_tuple *tup, temp_fahrenheit_eq, temp_celsius_eq) {
	double result = floor(
		(my_convert_fahrenheit_to_celsius(tup->temp_fahrenheit)
			* pow(10, 3) + 0.5)) / pow(10, 3);
	cr_assert_eq(result, tup->temp_celsius);
}
///////////////////////////////////////////////////////////////////////////////
ParameterizedTestParameters(temp_fahrenheit2, temp_celsius2) {
    static struct parameter_tuple temperatures[] = {
		{-459.670, -273.150},
		{-50, -45.556},
		{-40, -40.000},
		{-30, -34.444},
		{-20, -28.889},
		{-10, -23.333},
		{0, -17.778},
		{10, -12.222},
		{20, -6.667},
		{30, -1.111},
		{32, 0},
		{40, 4.444},
        { 46.400, 8},
		{50, 10},
		{60, 15.556},
		{70, 21.111},
		{80, 26.667},
		{90, 32.222},
		{95, 35},
        {100, 37.778},
    };

    return cr_make_param_array(struct parameter_tuple,
	temperatures, sizeof (temperatures) / sizeof (struct parameter_tuple));
}

// Test(my_convert_fahrenheit_to_celsius, simple2, .init=redirect_all_stdout) {
// 	const double 		melting_point_of_ice = 32;
// 	const double		constant = 9.0 / 5.0;
// 	double				result = 0.0;
// 	result = (temp_celsius2 * constant) + melting_point_of_ice;//(constant) * (temp_fahrenheit - melting_point_of_ice);
// 	std::cout.precision(3);
// 	std::cout.setf(std::ios::fixed, std::ios::floatfield);
//     std::cout << std::setw(16) << result << std::setw(16) 
//     << "Celsius" << std::endl << std::flush;
// 	return result;
//     my_convert_fahrenheit_to_celsius(-273.150);
// 	cr_assert_stdout_eq_str("        -459.670         Celsius\n");
// }

ParameterizedTest(struct parameter_tuple *tup, temp_fahrenheit2, temp_celsius2, .init=redirect_all_stdout) {
	const double 		melting_point_of_ice = 32;
	const double		constant = 5.0 / 9.0;
	double				result = 0.0;
	std::ostringstream 	a;

	result = (constant) * (tup->temp_fahrenheit - melting_point_of_ice);
	std::cout.precision(3);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
    a << std::setw(16) << floor((result * pow(10, 3) + 0.5)) / pow(10, 3) << std::setw(16) 
    << "Celsius" << std::endl;
	std::cout << a.str().c_str() << std::flush;
	cr_assert_stdout_eq_str(a.str().c_str(),"        %f         Celsius\n", tup->temp_celsius);//"        -273.150         Celsius\n"
}

ParameterizedTestParameters(temp_fahrenheit_eq2, temp_celsius_eq2) {
    static struct parameter_tuple temperatures[] = {
		{-459.670, -273.150},
		{-50, -45.556},
		{-40, -40.000},
		{-30, -34.444},
		{-20, -28.889},
		{-10, -23.333},
		{0, -17.778},
		{10, -12.222},
		{20, -6.667},
		{30, -1.111},
		{32, 0},
		{40, 4.444},
        { 46.400, 8},
		{50, 10},
		{60, 15.556},
		{70, 21.111},
		{80, 26.667},
		{90, 32.222},
		{95, 35},
        {100, 37.778},
    };

    return cr_make_param_array(struct parameter_tuple, temperatures,
	sizeof (temperatures) / sizeof (struct parameter_tuple));
}

ParameterizedTest(struct parameter_tuple *tup, temp_fahrenheit_eq2, temp_celsius_eq2) {
	double result = floor(
		(my_convert_fahrenheit_to_celsius(tup->temp_fahrenheit)
			* pow(10, 3) + 0.5)) / pow(10, 3);
	cr_assert_eq(result, tup->temp_celsius);
}

///////////////////////////////////////////////////////////////////////////////

Test(my_convert_celsius_to_fahrenheit, simple, .init=redirect_all_stdout) {
    const double 		melting_point_of_ice = 32;
	const double		constant = 1.8;
	double				fahrenheit = 0.0;
	std::ostringstream 	a;

	fahrenheit = (-10 * constant) + melting_point_of_ice;
	a << std::setw(16) << floor((fahrenheit * pow(10, 3) + 0.5)) / pow(10, 3) << std::setw(16) << "Fahrenheit" << std::endl;
	std::cout << a.str().c_str() << std::flush;
	// cr_log_warn(a.str().c_str());
	cr_assert_stdout_eq_str(a.str().c_str());//"        -273.150         Celsius\n"
	// cr_assert_stdout_eq_str("              14      Fahrenheit\n");     
}

Test(my_convert_celsius_to_fahrenheit, simple2, .init=redirect_all_stdout) {
   my_convert_celsius_to_fahrenheit(-10);
   cr_assert_stdout_eq_str("          14.000      Fahrenheit\n");//"          14.000      Fahrenheit\n"
}

ParameterizedTestParameters(temp_fahrenheit3, temp_celsius3) {
    static struct parameter_tuple temperatures[] = {
		{-459.670, -273.150},
		{-50, -45.556},
		{-40, -40.000},
		{-30, -34.444},
		{-20, -28.889},
		{-10, -23.333},
		{0, -17.778},
		{10, -12.222},
		{14, -10.000},
		{20, -6.667},
		{30, -1.111},
		{32, 0},
		{40, 4.444},
        { 46.400, 8},
		{50, 10},
		{60, 15.556},
		{70, 21.111},
		{80, 26.667},
		{90, 32.222},
		{95, 35},
        {100, 37.778},
    };

    return cr_make_param_array(struct parameter_tuple, temperatures, sizeof (temperatures) / sizeof (struct parameter_tuple));
}

ParameterizedTest(struct parameter_tuple *tup, temp_fahrenheit3, temp_celsius3, .init=redirect_all_stdout) {
    const double 			melting_point_of_ice = 32;
	const double			constant = 1.8;
	double					fahrenheit = 0.0;
	std::ostringstream 		a;

	fahrenheit = (tup->temp_celsius * constant) + melting_point_of_ice;
	std::cout.precision(3);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
    a << std::setw(16) << fahrenheit << std::setw(16) 
    << "Fahrenheit" << std::endl;
	std::cout << a.str().c_str() << std::flush;
	cr_assert_stdout_eq_str(a.str().c_str(),"          %f      Fahrenheit\n", tup->temp_fahrenheit);//"        -273.150         Celsius\n"
	// cr_assert_stdout_eq_str("        -459.670      Fahrenheit\n","          %f      Fahrenheit\n", tup->temp_fahrenheit);//"        -273.150         Celsius\n"
}

ParameterizedTestParameters(temp_fahrenheit_eq3, temp_celsius_eq3) {
    static struct parameter_tuple temperatures[] = {
		{-459.670, -273.150},
		{-50.001, -45.556},
		{-40, -40.000},
		{-29.999, -34.444},
		{-20, -28.889},
		{-9.999, -23.333},
		{0, -17.778},
		{10, -12.222},
		{14, -10},
		{19.999, -6.667},
		{30, -1.111},
		{32, 0},
		{39.999, 4.444},
        { 46.400, 8},
		{50, 10},
		{60.001, 15.556},
		{70, 21.111},
		{80.001, 26.667},
		{90, 32.222},
		{95, 35},
        {100, 37.778},
    };

    return cr_make_param_array(struct parameter_tuple, temperatures, sizeof (temperatures) / sizeof (struct parameter_tuple));
}

ParameterizedTest(struct parameter_tuple *tup, temp_fahrenheit_eq3, temp_celsius_eq3) {
	double result = floor(
		(my_convert_celsius_to_fahrenheit(tup->temp_celsius)
			* pow(10, 3) + 0.5)) / pow(10, 3);
	cr_assert_eq(result, tup->temp_fahrenheit,"RESULT : %f, EXPECTED : %f\n",result, tup->temp_fahrenheit);
}