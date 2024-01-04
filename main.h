/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:47:29 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/04 15:25:27 by ousabbar         ###   ########.fr       */
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
	int				mid_a;
	int				data;
	int				closest;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
t_list	*sa(t_list *stack_a, char c);
void	pa(t_list **stack_a, t_list **stack_b, char c);
t_list	*ra(t_list *stack_a, char c);
t_list	*rra(t_list *stack_a, char c);
void	pb(t_list **stack_a, t_list **stack_b, char c);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
int		ft_isdigit(char *c);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*sort_three_numbers(t_list *a);
void	handle_error(void);
int		conditions(char *s, t_list *stack_a);
int		ft_check_space(char *s, t_list *a);
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
void	ft_lstclear(t_list **lst);
t_list	*find_cheapest(t_list *a, t_list *b);
void	rr(t_list **a, t_list **b, char c);
void	rrr(t_list **a, t_list **b, char c);
void	adjust(t_list **a, t_list **b, t_list *perfect);
int		set_target(int data, t_list *b);
int		ft_median(t_list *b, int data, int len);
void	if_median_first_con(t_list **a, t_list **b,
			int closest, t_list *perfect);
void	if_median_second_con(t_list **a, t_list **b,
			int closest, t_list *perfect);
void	if_median_third_con(t_list **a, t_list **b,
			int closest, t_list *perfect);
void	if_median_four_con(t_list **a, t_list **b,
			int closest, t_list *perfect);
void	ss(t_list **a, t_list **b, char c);
void	ft_free_1(t_list **a, t_list **b);
int		empty_stack(t_list *b);
void	conditions_bonus(t_list *stack_a, t_list *stack_b, char *s);
void	checks(t_list *stack_a, t_list *stack_b);
void	push(t_list **stack_a, t_list **stack_b, char *s);
void	rrr_and_rr(t_list **stack_a, t_list **stack_b, char *s);
t_list	*check_for_a(t_list *stack_a, char *s);
t_list	*check_for_b(t_list *stack_b, char *s);
int		c(char *s1, char *s2);
#endif