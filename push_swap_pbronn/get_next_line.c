/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbronn <pbronn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:51:11 by pbronn            #+#    #+#             */
/*   Updated: 2022/03/27 14:19:00 by pbronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	finish(char **str, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		*line = ft_strsub(*str, 0, len);
		tmp = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = NULL;
		*str = tmp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static int	returns(char **str, char **line, int val, int fd)
{
	if (val < 0)
		return (-1);
	else if (val == 0 && str[fd] == NULL)
		return (0);
	else
		return (finish(&str[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	int			rd;
	static char	*str[12000];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buff, BUFF_SIZE);
		if (rd <= 0)
			break ;
		buff[rd] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strc(str[fd], '\n'))
			break ;
	}
	return (returns(str, line, rd, fd));
}
