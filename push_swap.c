#include "push_swap.h"

int main(int argc, char **argv)
{
	static char	**args;
	static char *tab;
    int		i;
    t_stack *a;

    i = 1;
	(void)argc;
	(void)a;
	while (argv[i])
		tab = ft_strjoin(tab, argv[i++]);
	args = ft_split(tab, ' ');
	i = 0;
	while(args[i])
	{
		ft_add_back(&a, ft_atoi(args[i]));
		i++;
	}
	print_linked_list(&a);
}