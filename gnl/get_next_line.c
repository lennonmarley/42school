/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 22:12:15 by yismail           #+#    #+#             */
/*   Updated: 2016/03/16 12:52:48 by yismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		return_value(int ret, char **tmp, char *buf)
{
	if (ret == -1)
		return (-1);
	if (ret == 0 && *tmp && !*buf)
	{
		*tmp = NULL;
		return (1);
	}
	if ((ret == 0 && !*buf) || (*tmp == NULL && !*buf))
		return (0);
	return (1);
}

int		f_read(char **buffer, char **tmp, int fd)
{
	int		ret;
	char	*pos;
	char	buf[BUFF_SIZE + 1];

	buf[0] = '\0';
	if ((pos = ft_strchr(*buffer, '\n')))
	{
		pos[0] = '\0';
		pos++;
		*tmp = pos[0] == '\0' ? NULL : ft_strdup(pos);
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*buffer = ft_strjoin_free(*buffer, buf);
		if ((pos = ft_strchr(*buffer, '\n')))
		{
			pos[0] = '\0';
			pos++;
			*tmp = pos[0] == '\0' ? NULL : ft_strdup(pos);
			return (1);
		}
	}
	return (return_value(ret, tmp, buf));
}

int		get_next_line(int const fd, char **line)
{
	static char *tmp = NULL;
	char		*buffer;
	int			ret;
	char		*cpy;

	if (!(buffer = ft_strnew(sizeof(char) * 1)))
		return (-1);
	if (fd < 0 || !line)
		return (-1);
	if (tmp && (cpy = buffer))
	{
		if (!(buffer = ft_strjoin(tmp, buffer)))
			return (-1);
		free(cpy);
	}
	ret = f_read(&buffer, &tmp, fd);
	*line = ft_strdup(buffer);
	free(buffer);
	return (ret);
}
