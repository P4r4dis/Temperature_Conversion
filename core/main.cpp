#include "../includes/my_convert_temp.hpp"

int     main(int ac, char **av)
{
    if (ac < 2 && av) {
        my_convert_fahrenheit_to_celsius(46.400);
        my_convert_celsius_to_fahrenheit(-34.444);
    }
    return 0;
}