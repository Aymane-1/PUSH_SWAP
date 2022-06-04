#include "push_swap.h"
/*
t_stack *ft_new_node(int value)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (node);
	node->data = value;
	node->next = NULL;
	return (node);
}

*/
int	ft_lstsize(t_stack *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*ft_new_node(int n)
{
	t_stack	*a;

	a = (t_stack *)malloc(sizeof(t_stack));
	a->data = n;
	a->next = NULL;
	return (a);
}

void	ft_add_back(t_stack **s, int n)
{
	t_stack	*tmp;
	t_stack	*new;

	new = ft_new_node(n);
	tmp = *s;
	if (tmp)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
	else
	{
		*s = new;
	}
}


void	print_linked_list(t_stack **head)
{
	t_stack *temp = *head;
	while(temp)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

// int ft_check_args(char **args)
// {
//     if(args >= 0 && args <= 9)
//         return (0);
//     if(args <= 2147483647 && args >= -2147483648)
//         return (0);
//     else    
//         return (1);
// }

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	while (s1[++i])
		s[i] = s1[i];
	s[i] = ' ';
	while (s2[++j])
		s[i + j + 1] = s2[j];
	s[i + j + 1] = '\0';
	free(s1);
	return (s);
}

long long   ft_atoi(char *s)
{
    long long   i;
    long long   sign;
    long long   res;

    sign = 1;
    i = 0;
    res = 0;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign *= -1;
        i++;
    }
    while (s[i])
    {
        res = res * 10 + (s[i] - 48);
        i++;
    }
	return(res *sign);
}