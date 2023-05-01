/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executioner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:39:22 by lualvare          #+#    #+#             */
/*   Updated: 2023/05/01 15:41:45 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_first_cmd(char **cmd, char **envp, int **fd)
{
	ft_printf("Hi child 1 here starting process file1 fd %d\n", fd[0][0]);
	dup2(fd[0][0], 0);
	dup2(fd[1][1], 1);
	close(fd[1][0]);
	close(fd[1][1]);
	execve(ft_path_validator(envp, cmd[0]), cmd, envp);
	return (0);
}

int	ft_last_cmd(char **cmd, char **envp, int **fd)
{
	ft_printf("Hi child 2 here starting process file2 fd %d\n", fd[0][1]);
	dup2(fd[1][0], 0);
	dup2(fd[0][1], 1);
	close(fd[1][0]);
	close(fd[1][1]);
	execve(ft_path_validator(envp, cmd[0]), cmd, envp);
	return (0);
}

//Old working
/*int	ft_first_cmd(char *infile_path, char **cmd, char **envp, int *fd)
{
	int	fd_infile;

	fd_infile = open(infile_path, O_RDONLY);
	ft_printf("Hi child 1 here starting process file1 fd %d\n", fd_infile);
	if (fd_infile == -1)
		return (-1);
	dup2(fd_infile, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	execve(ft_path_validator(envp, cmd[0]), cmd, envp);
	return (0);
}

int	ft_last_cmd(char *outfile_path, char **cmd, char **envp, int *fd)
{
	int	fd_outfile;

	fd_outfile = open(outfile_path, (O_TRUNC) | O_RDWR | O_CREAT, 0777);
	ft_printf("Hi child 2 here starting process file2 fd %d\n", fd_outfile);
	if (fd_outfile == -1)
		return (-1);
	dup2(fd[0], 0);
	dup2(fd_outfile, 1);
	close(fd[0]);
	close(fd[1]);
	execve(ft_path_validator(envp, cmd[0]), cmd, envp);
	return (0);
}*/
