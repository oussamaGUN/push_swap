/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:33:01 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/27 17:41:35 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int ac, char **av)
{
    
    if (ac < 2)
    {
        write(2, "Error\n", 1);
        return (0);
    }
    char *s;
    while (1)
    {
        s = get_next_line(0);
        if (!s)
            break;
    }
}