#ifndef __TESTS_MY_CONVERT_TEMP__
#   define __TESTS_MY_CONVERT_TEMP__

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <cmath>

struct parameter_tuple {
    double temp_fahrenheit;
    double temp_celsius;
};

void                redirect_all_stdout(void);

#endif  // !__TESTS_MY_CONVERT_TEMP__