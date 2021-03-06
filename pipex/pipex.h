/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkang <tkang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:48:40 by tkang             #+#    #+#             */
/*   Updated: 2022/05/31 15:48:40 by tkang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/libft.h"

void	exit_trap(char *str, int sig);
void	two_d_free(char **temp);
char	*set_up_path(char *cmd, char *envp[]);
void	run_cmd(char *argv, char *envp[]);
void	child_process(char *argv[], char *envp[], int *fd);
void	parent_process(char *argv[], char *envp[], int *fd);

#endif
