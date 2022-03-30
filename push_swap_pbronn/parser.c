/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:52:08 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/27 13:52:09 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	*ft_clear(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

int	check_num(char *str)
{
	int	i;

	i = -1;
	if ((str[0] == '-' || str[0] == '+') && str[1])
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

void	check_in(int ac, char **av, t_list **a)
{
	int		i;
	char	**str;
	char	**arr;

	i = 0;
	while (++i < ac)
	{
		str = ft_split(av[i]);
		arr = str;
		if (!*str)
			ft_exit(a);
		while (*str)
		{
			if (((ft_atoi(*str)) == -1) && (ft_strlen(*str) > 2))
				ft_exit(a);
			if (!check_num(*str) || !check_str(ft_atoi(*str)))
				ft_exit(a);
			else
				add_back(new_node(ft_atoi(*str)), a);
			str++;
		}
		ft_clear(arr);
	}
}
