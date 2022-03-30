/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:51:54 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/27 13:51:55 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_str(unsigned int x)
{
	static char	map[536870912];

	if (!(map[x / 8] >> (7 - (x % 8)) & 1))
		map[x / 8] = map[x / 8] | 1 << (7 - (x % 8));
	else
		return (0);
	return (1);
}

void	ft_exit(t_list **a)
{
	(void)a;
	clr_list(a);
	ft_putstr("Error\n");
	exit(2);
}
