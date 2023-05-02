/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:29:00 by lualvare          #+#    #+#             */
/*   Updated: 2023/05/02 10:59:31 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

char	*ft_path_validator(char **envp, char *cmd);
char	**ft_path_finder(char **envp);
int		ft_input_check(int argc, char **argv);
int		fork_maker(int argc, char **argv, char **envp, int **fd);
int		piper(int argc, char **argv, char **envp);
int		ft_first_cmd(char **cmd, char **envp, int **fd);
int		ft_last_cmd(char **cmd, char **envp, int **fd);
int		**ft_fd_array(int n);
pid_t	*pid_array(int argc);
int		path_val(char *path, int parsing);
int		ft_file_opener(int argc, char **argv, int **fd);
int		ft_file_closer(int **fd);

#endif