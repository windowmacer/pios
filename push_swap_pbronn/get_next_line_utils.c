/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:51:07 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/27 14:21:33 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	end;

	i = 0;
	if (!s || ((start + 1) == 0) || (len + 1) == 0)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (len) + 1);
	if (!str)
		return (NULL);
	end = start + len;
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return ((char *)str);
}

char	*ft_strdup(const char *s1)
{
	char	*a;
	int		i;

	i = 0;
	a = (char *)malloc(sizeof(*s1) * ft_strlen(s1) + 1);
	if (!a)
		return (NULL);
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strc(const char *s, int c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	while (i != len + 1)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
