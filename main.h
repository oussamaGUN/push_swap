#ifndef MAIN_H
# define MAIN_H

typedef struct s_list
{
    int data;
    struct s_list *next;
}t_list;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
t_list	*ft_lstnew(int content);
t_list *sa(t_list *stack_a);
t_list *sb(t_list *stack_b);
void ss(t_list **a, t_list **b);
void pa(t_list **stack_a, t_list **stack_b);
t_list *ra(t_list *stack_a, char c);
t_list *rra(t_list *stack_a,char c);
void rr(t_list **a, t_list **b);
void rrr(t_list **a, t_list **b);
void pb(t_list **stack_a, t_list **stack_b);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
int	ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
int	ft_isdigit(char *c);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list *sort_three_numbers(t_list *a);
#endif