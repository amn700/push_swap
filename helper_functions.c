#include "push_swap.h"

//transform all argvs into numbers
//check duplicated numbers
//function to check if the argv is a number
//custom atoi that checks if the argv is within the min and max of int
//handle multiple numbers in a single argv
//skips empty argvs
//re_test duplicated function
//split that shit boi
//consider joining the full argv for is degit check

//dont touch it !!
char *ft_holy_joint(char **argv, int argc)
{
	int i = 1;
	char * temp;
	char * str = ft_strdup("");
	while (i < argc)
	{
		temp = ft_strjoin(str, argv[i++]);
		if (!temp)
			return (free(str), str = NULL, NULL);
		free(str);
		str = temp;

		temp = ft_strjoin(str, " ");
		if (!temp)
			return (free(str), str = NULL, NULL);
		free(str);
		str = temp;
	}
	return (str);
}
