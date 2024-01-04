/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_conditions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:32:49 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/04 09:58:45 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "get_next_line.h"

t_list	*check_for_b(t_list *stack_b, char *s)
{
	if (c(s, "rb\n") == 0)
		stack_b = ra(stack_b, 's');
	else if (c(s, "rrb\n") == 0)
		stack_b = rra(stack_b, 's');
	else if (c(s, "sb\n") == 0)
		stack_b = sa(stack_b, 's');
	return (stack_b);
}

t_list	*check_for_a(t_list *stack_a, char *s)
{
	if (c(s, "ra\n") == 0)
		stack_a = ra(stack_a, 's');
	else if (c(s, "rra\n") == 0)
		stack_a = rra(stack_a, 's');
	else if (c(s, "sa\n") == 0)
		stack_a = sa(stack_a, 's');
	return (stack_a);
}

void	rrr_and_rr(t_list **stack_a, t_list **stack_b, char *s)
{
	if (c(s, "rrr\n") == 0)
		rrr(stack_a, stack_b, 'g');
	else if (c(s, "rr\n") == 0)
		rr(stack_a, stack_b, 'g');
	else if (c(s, "ss\n") == 0)
		ss(stack_a, stack_b, 'g');
}

void	push(t_list **stack_a, t_list **stack_b, char *s)
{
	if (c(s, "pb\n") == 0 && stack_a)
		pb(stack_a, stack_b, 's');
	else if (c(s, "pa\n") == 0 && stack_b)
		pa(stack_a, stack_b, 's');
}

void	checks(t_list *a, t_list *b)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		if ((c(s, "pb\n") == 0 && a) || (c(s, "pa\n") == 0 && b))
			push(&a, &b, s);
		else if ((c(s, "ra\n") == 0 || c(s, "rra\n") == 0
				|| c(s, "sa\n") == 0) && a)
			a = check_for_a(a, s);
		else if ((c(s, "rb\n") == 0 || c(s, "rrb\n") == 0
				|| c(s, "sb\n") == 0) && b)
			b = check_for_b(b, s);
		else if (b && a && ft_lstsize(a) > 1 && ft_lstsize(b) > 1
			&& (c(s, "rrr\n") == 0 || c(s, "rr\n") == 0 || c(s, "ss\n") == 0))
			rrr_and_rr(&a, &b, s);
		else
		{
			write(1, "Error\n", 6);
			break ;
		}
		free(s);
		s = get_next_line(0);
	}
	conditions_bonus(a, b, s);
}
