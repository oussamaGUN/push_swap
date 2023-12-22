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
t_list	*ft_lstnew(int content);
t_list *sa(t_list *stack_a);
t_list *sb(t_list *stack_b);
t_list *pb(t_list *stack_a);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
int	ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
int	ft_isdigit(char *c);
#endif