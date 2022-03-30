/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:57:01 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/23 13:14:43 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sep(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

static int	ft_words(char *str)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (!ft_sep(str[i])
			&& ft_sep(str[i + 1]))
			w++;
		i++;
	}
	return (w);
}

void	ft_write_word(char *dest, char *src)
{
	int	i;

	i = 0;
	while (!ft_sep(src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	ft_write_split(char **split, char *str)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (ft_sep(str[i]))
			i++;
		else
		{
			j = 0;
			while (!ft_sep(str[i + j]))
				j++;
			split[w] = (char *)malloc(sizeof(char) * (j + 1));
			if (!(split + w))
				return (0);
			ft_write_word(split[w], str + i);
			i += j;
			w++;
		}
	}
	return (1);
}

char	**ft_split(char const *s)
{
	int		w;
	char	**rtn;

	if (!s)
		return (NULL);
	w = ft_words((char *)s);
	rtn = (char **)malloc(sizeof(char *) * (w + 1));
	if (!rtn)
		return (NULL);
	if (!(ft_write_split(rtn, (char *) s)))
	{
		w = -1;
		while (rtn + ++w)
			free(rtn + w);
		free(rtn);
	}
	rtn[w] = 0;
	return (rtn);
}
