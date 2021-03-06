/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:19:51 by tkang             #+#    #+#             */
/*   Updated: 2022/04/09 17:19:52 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
void	gnl_strlcpy(char *dest, char *src, int read_len);
char	*gnl_strdup(char	*s1);
#endif
