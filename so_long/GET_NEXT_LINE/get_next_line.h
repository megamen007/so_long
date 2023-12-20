/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:16:44 by mboudrio          #+#    #+#             */
/*   Updated: 2023/04/16 05:33:49 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_get_line(char *stim);
char	*ft_save(char *stim);
char	*ft_read(int fd, char *stim);
int		ft_strlengnl(char *s);
char	*ft_strjoingnl(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_strchrgnl(char *s, char c);

#endif