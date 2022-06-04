#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack{
    int data;
    struct s_stack *previous;
    struct s_stack *next;
} t_stack;

typedef struct s_var {
	int		i;
	int		j;
	int		count;
	int		len;
}	t_var;

void		print_linked_list(t_stack **head);
void    	parse_input_to_ll(t_stack **head, int value);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char *s1, char *s2);
long long   ft_atoi(char *s);
int			ft_lstsize(t_stack *lst);
t_stack 	*ft_new_node(int value);
void	ft_add_back(t_stack **s, int n);
t_stack	*ft_new_node(int n);

#endif