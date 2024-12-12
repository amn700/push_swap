#include "push_swap.h"

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
