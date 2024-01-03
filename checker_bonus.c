/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:33:01 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/03 18:00:39 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
# include "get_next_line.h"

void ft_free_1(t_list *a, t_list *b)
{
	ft_lstclear(&a);
	ft_lstclear(&b);
}
int empty_stack(t_list *b)
{
	if (b == NULL)
		return 1;
	return 0;
}
void conditions_bonus(t_list *stack_a, t_list *stack_b, char *s)
{	
	if (!s)
	{
		if (!isorted(stack_a) && empty_stack(stack_b) == 1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free(s);
	}
	else
		free(s);
}
t_list *check_for_b(t_list *stack_b, char *s)
{
		if (strcmp(s, "rb\n") == 0)
			stack_b = ra(stack_b, 's');
		else if (strcmp(s, "rrb\n") == 0)
			stack_b = rra(stack_b, 's');
		else if (strcmp(s, "sb\n") == 0)
			stack_b = sa(stack_b, 's');
		return stack_b;	
}
t_list *check_for_a(t_list *stack_a, char *s)
{
		if (strcmp(s, "ra\n") == 0)
			stack_a = ra(stack_a, 's');
		else if (strcmp(s, "rra\n") == 0)
			stack_a = rra(stack_a, 's');
		else if (strcmp(s, "sa\n") == 0)
			stack_a = sa(stack_a, 's');
		return stack_a;
}
void rrr_and_rr(t_list **stack_a, t_list **stack_b, char *s)
{
	if (strcmp(s, "rrr\n") == 0)
		rrr(stack_a, stack_b, 'g');
	else if (strcmp(s, "rr\n") == 0)
		rr(stack_a, stack_b, 'g');
	else if (strcmp(s, "ss\n") == 0)
		ss(stack_a, stack_b, 'g');
}
void checks(t_list *stack_a, t_list *stack_b)
{
	char	*s;

	s = get_next_line(0);
	while (s != NULL)
	{
		if (strcmp(s, "pb\n") == 0 && stack_a)	
			pb(&stack_a, &stack_b, 's');
		else if (strcmp(s, "pa\n") == 0 && stack_b)
			pa(&stack_a, &stack_b, 's');
		else if ((strcmp(s, "ra\n") == 0
			|| strcmp(s, "rra\n") == 0 || strcmp(s, "sa\n") == 0) && stack_a)
			stack_a = check_for_a(stack_a, s);
		else if ((strcmp(s, "rb\n") == 0 || strcmp(s, "rrb\n") == 0
			|| strcmp(s, "sb\n") == 0) && stack_b)
			stack_b = check_for_b(stack_b, s);
		else if ((strcmp(s, "rrr\n") == 0 || strcmp(s, "rr\n") == 0 || strcmp(s, "ss\n") == 0)
			&& stack_b && stack_a && ft_lstsize(stack_a) > 1 && ft_lstsize(stack_b) > 1)
			rrr_and_rr(&stack_a, &stack_b, s);
		else
		{
			write(1, "Error\n", 6);
			break;
		}
		free(s);
		s = get_next_line(0);
	}
	conditions_bonus(stack_a,stack_b, s);
}
int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		j;

	j = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	while (++j < ac)
	{
		if (ft_check_space(av[j], stack_a) == 0)
			stack_a = check_error2_spaces_and_creat_list(av[j], stack_a);
		else
			stack_a = create_a_list(av[j], stack_a);
	}
	if (!isorted(stack_a))
	{
		ft_lstclear(&stack_a);
		return (0);
	}
	checks(stack_a, stack_b);
	ft_free_1(stack_a, stack_b);
	return (0);       
}
