
#include <unistd.h>
#include <stdlib.h>

#define SIZE 30000

void	find_br(char **argv, char **array, int *i, int *k)
{
	int j;

	*argv += 1;
	*k += 1;

	while (1)
	{
		j = 0;
		while (**argv != ']')
		{
			if (**argv == '+')
				(*array)[*i] += 1;
			if (**argv == '-')
				(*array)[*i] -= 1;
			if (**argv == '>')
				*i += 1;
			if (**argv == '<')
				*i -= 1;
			if (**argv == '.')
				write(1, &((*array)[*i]), 1);
			if (**argv == '[')
				find_br(&(*argv), &(*array), &(*i), &j);
			*argv += 1;
			j += 1;
			*k += 1;
		}
		if (!((*array)[*i]))
			return ;
		*argv -= j;
		*k -= j;
	}
}

int		main(int argc, char **argv)
{
	char	*array;
	int		i;
	int		k;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	
	array = (char *)malloc(sizeof(char) * SIZE);
	i = 0;
	while (i < SIZE)
	{
		array[i] = 0;
		i += 1;
	}

	i = 0;
	while (*argv[1] != '\0')
	{
		if (*argv[1] == '+')
			array[i] += 1;
		if (*argv[1] == '-')
			array[i] -= 1;
		if (*argv[1] == '>')
			i += 1;
		if (*argv[1] == '<')
			i -= 1;
		if (*argv[1] == '.')
			write(1, &(array[i]), 1);
		if (*argv[1] == '[')
			find_br(&(argv[1]), &array, &i, &k);
		argv[1] += 1;
	}
	return (0);
}
