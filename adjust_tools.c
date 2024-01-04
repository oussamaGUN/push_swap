/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:56:57 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/04 16:09:35 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_median(t_list *b, int data, int len)
{
	int	i;

	i = 0;
	while (i <= len / 2)
	{
		if (b->data == data)
			return (0);
		b = b->next;
		i++;
	}
	return (1);
}

void	if_median_first_con(t_list **a, t_list **b,
	int closest, t_list *perfect)
{
	while ((*a)->data != perfect->data && (*b)->data != closest)
	{
		*a = ra(*a, 's');
		*b = ra(*b, 's');
		write(1, "rr\n", 3);
	}
	while ((*a)->data != perfect->data)
		*a = ra(*a, 'a');
	while ((*b)->data != closest)
		*b = ra(*b, 'b');
}

void	if_median_second_con(t_list **a, t_list **b,
	int closest, t_list *perfect)
{
	while ((*a)->data != perfect->data && (*b)->data != closest)
	{
		*a = rra(*a, 's');
		*b = rra(*b, 's');
		write(1, "rrr\n", 4);
	}
	while ((*a)->data != perfect->data)
		*a = rra(*a, 'a');
	while ((*b)->data != closest)
		*b = rra(*b, 'b');
}

void	if_median_third_con(t_list **a, t_list **b,
	int closest, t_list *perfect)
{
	while ((*a)->data != perfect->data)
		*a = rra(*a, 'a');
	while ((*b)->data != closest)
		*b = ra(*b, 'b');
}

void	if_median_four_con(t_list **a, t_list **b,
	int closest, t_list *perfect)
{
	while ((*a)->data != perfect->data)
		*a = ra(*a, 'a');
	while ((*b)->data != closest)
		*b = rra(*b, 'b');
}
