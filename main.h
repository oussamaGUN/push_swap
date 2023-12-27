/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:47:29 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/27 10:52:21 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
t_list	*sa(t_list *stack_a);
t_list	*sb(t_list *stack_b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **stack_a, t_list **stack_b);
t_list	*ra(t_list *stack_a, char c);
t_list	*rra(t_list *stack_a, char c);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
int		ft_isdigit(char *c);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*sort_three_numbers(t_list *a);
void	handle_error(void);
void	conditions(char *s, t_list *stack_a);
int		ft_check_space(char *s);
int		empty(char *s);
int		isorted(t_list *a);
t_list	*create_a_list(char *s, t_list *stack_a);
t_list	*check_error2_spaces_and_creat_list(char *s, t_list *stack_a);
t_list	*sort_two(t_list *a);
void	ft_sort(t_list **stack_a, t_list **stack_b);
t_list	*sort_list(t_list *a, t_list *b);
long	find_closest_smaller(int data, t_list *b);
int		find_max_in_list(t_list *b);
t_list	*turn_closest(t_list *b, int closest, char c);
t_list	*sort_b_from_biggest_to_smallest(t_list *b);
t_list	*push_all_the_nodes_to_a(t_list *a, t_list *b);
t_list	*sort_a_from_smallest_to_biggest(t_list *a);
long	find_closest_bigger(int data, t_list *a);
int		find_min_in_list(t_list *a);

#endif