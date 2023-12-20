/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:17:26 by mboudrio          #+#    #+#             */
/*   Updated: 2023/02/14 22:52:46 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stim;
	char		*line;
	char		*rst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stim = ft_read(fd, stim);
	rst = stim;
	if (!stim)
	{
		free(stim);
		return (NULL);
	}
	line = ft_get_line(stim);
	if (!line)
		return (NULL);
	stim = ft_save(stim);
	free(rst);
	return (line);
}

char	*ft_read(int fd, char *stim)
{
	char	*buff;
	int		r;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (1)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			free(stim);
			free(buff);
			return (NULL);
		}
		if (r == 0)
			break ;
		buff[r] = '\0';
		stim = ft_strjoingnl(stim, buff);
		if (ft_strchrgnl(buff, '\n'))
			break ;
	}
	free(buff);
	return (stim);
}

char	*ft_get_line(char *stim)
{
	int		i;
	char	*s;

	i = 0;
	if (!stim)
		return (NULL);
	while (stim[i] && stim[i] != '\n')
		i++;
	s = malloc(i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (stim[i] && stim[i] != '\n')
	{
		s[i] = stim[i];
		i++;
	}
	if (stim[i] == '\n')
		s[i++] = '\n';
	s[i] = 0;
	return (s);
}

char	*ft_save(char *stim)
{
	int		i;
	int		j;
	char	*rst;

	i = 0;
	if (!stim)
		return (NULL);
	while (stim[i] != 0 && stim[i] != '\n')
		i++;
	if (stim[i] == 0 || (stim[i] == '\n' && stim[i + 1] == 0))
		return (NULL);
	rst = malloc((ft_strlengnl(stim) - i + 1));
	i++;
	j = 0;
	while (stim[i])
		rst[j++] = stim[i++];
	rst[j] = '\0';
	return (rst);
}
