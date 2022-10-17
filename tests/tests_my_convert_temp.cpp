#include "../includes/my_convert_temp.hpp"
#include "./tests_includes/tests_my_convert_temp.hpp"

Test (check_nb_params, result_with_null_param, .init=redirect_all_stdout)
{
	const unsigned int 		ac0 = 0; // just binary without parameters as arguments
	// unsigned int 			result = check_nb_params(ac0); 

	cr_assert(ac0 == 2, "The ac result is %d, EXPECTED ac < 2", ac0);
	// cr_assert_stderr_eq_str("my_cat : Usage : ./my_cat file [...]\n",
	// "STDERR don't matches. EXPECTED : my_cat : Usage : ./my_cat file [...]\n");
	// cr_assert(result == 1,
	// "The result is %d, EXPECTED EXIT_FAILURE or %d", result, EXIT_FAILURE);
}