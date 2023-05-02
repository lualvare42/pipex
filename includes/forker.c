/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:30:23 by lualvare          #+#    #+#             */
/*   Updated: 2023/05/02 11:14:02 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*int	forker(char **cmd, pid_t *pid, char **envp, int *n, int *fd)
{
	*pid = fork();
	if (*pid == -1)
	{
		*n = -1;
		return (0);
	}
	else if (*pid == 0)
	{
		
		execve(ft_path_validator(envp, cmd[0]), cmd, envp);
	}
	return (0);
}*/

int	forker(char **argv, pid_t *pid, char **envp, int **fd)
{
	char	cmd_index;
	char	**cmd;
	char	*path;
	int		error_handle;

	cmd_index = *pid;
	cmd = ft_split(argv[cmd_index], ' ');
	path = ft_path_validator(envp, cmd[0]);
	error_handle = 0;
	if (path == NULL)
		return (-1);
	free(path);
	*pid = fork();
	if (*pid == -1)
		return (-1);
	else if (*pid == 0)
	{
		if (cmd_index == 2)
			error_handle = ft_first_cmd(cmd, envp, fd);
		else if ((cmd_index + 2) == ft_dbptr_len(argv))
			error_handle = ft_last_cmd(cmd, envp, fd);
		/*
		else
			ft_n_cmd(cmd, envp, fd);
		*/
	}
	return (error_handle);
}

int	fork_maker(int argc, char **argv, char **envp, int **fd)
{
	pid_t	*pid1;
	int		n;
	int		status;

	n = 0;
	//ft_printf("check fd file1 %d && fd file2 %d\n", fd[0][0], fd[0][1]);
	pid1 = pid_array(argc);
	if (pid1 == 0)
		return (-1);
	while (n < (argc - 3))
	{
		if (forker(argv, &pid1[n], envp, fd) == -1)
			return (-1);
		if ((n + 1) == (argc - 3))
		{
			if (ft_file_closer(fd) == -1)
				return (-1);
		}
		if (n != 0)
		{
			waitpid(pid1[n - 1], &status, 0);
			waitpid(pid1[n], &status, 0);
		}
		//ft_printf("Parent my child #%d\n", pid1[n]);
		n++;
	}
	free (pid1);
	return (0);
}

/**
 * @brief 
 * 
 * @param fd
		2D array used for storing required fd's for pipex.
			- fd[0]: fd's for file managing
				f[0][0] --> file1
				f[0][1] --> file2
			- fd[1]: fd's for pipe managing
				f[1][0] --> pipe's read end
				f[1][1] --> pipe's write end
 * @return int 
 */

int	piper(int argc, char **argv, char **envp)
{
	int	**fd;
	int	n;

	fd = ft_fd_array(0);
	if (fd == 0)
		return (-1);
	if (ft_file_opener(argc, argv, fd) == -1)
		return (-1);
	//ft_printf("check fd file1 %d && fd file2 %d\n", fd[0][0], fd[0][1]);
	if (pipe(fd[1]) == -1)
	{
		ft_free_doubleptr((void **)fd);
		return (-1);
	}
	if (fork_maker(argc, argv, envp, fd) == -1)
		return (-1);
	//ft_printf("is it close? %d", write(fd[0][1], "test", ft_strlen("test")));
	return (0);
}

//I need to handle any possible error

/*
void	fork_maker(int argc, char **argv, char **envp)
{
	pid_t	*pid1;
//	pid_t	pid2;
	int		n;
	int		status;

	n = 0;
	pid1 = pid_array(argc);
	forker(argv[2], &pid1[0], envp, &n);
	waitpid(pid1[0], &status, 0);
	ft_printf("Parent my child #%d id is %d\n", n, pid1[0]);
	forker(argv[3], &pid1[1], envp, &n);
	waitpid(pid1[1], &status, 0);
	ft_printf("Parent my child #%d id is %d", n, pid1[1]);
}
*/