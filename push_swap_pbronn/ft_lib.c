/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:50:45 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/27 13:50:46 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int a)
{
	if ((a >= 48) && (a <= 57))
		return (1);
	return (0);
}

void	ft_putstr(char *s)
{
	if (s)
	{
		while (*s)
		{
			write(1, s, 1);
			s++;
		}
	}
}

int	ft_atoi(const char *str)
{
	unsigned long long int	a;
	int						z;

	a = 0;
	z = 1;
	while (*str && ((*str == ' ') || (*str == '\t') || (*str == '\n') \
	|| (*str == '\v') || (*str == '\f') || (*str == '\r')))
		++str;
	if (*str == '-')
		z = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str > 47 && *str < 58)
	{
		a = a * 10 + (*str - 48);
		++str;
	}
	if ((z) < 0 && a > 2147483648)
		return (-1);
	else if ((z) > 0 && a > 2147483647)
		return (-1);
	return (z * a);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
