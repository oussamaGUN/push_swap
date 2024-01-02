/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:01:36 by ousabbar          #+#    #+#             */
/*   Updated: 2024/01/02 21:59:23 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	adjust(t_list **a, t_list **b, t_list *perfect)
{
	int	len;
	int	len_b;
	int	closest;

	len = ft_lstsize(*a);
	len_b = ft_lstsize(*b);
	closest = set_target(perfect->data, *b);
	if (ft_median(*a, perfect->data, len) == 0
		&& ft_median(*b, closest, len_b) == 0)
		if_median_first_con(a, b, closest, perfect);
	else if (ft_median(*a, perfect->data, len) == 1
		&& ft_median(*b, closest, len_b) == 1)
		if_median_second_con(a, b, closest, perfect);
	else if (ft_median(*a, perfect->data, len) == 1
		&& ft_median(*b, closest, len_b) == 0)
		if_median_third_con(a, b, closest, perfect);
	else if (ft_median(*a, perfect->data, len) == 0
		&& ft_median(*b, closest, len_b) == 1)
		if_median_four_con(a, b, closest, perfect);
}
