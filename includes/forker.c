/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:30:23 by lualvare          #+#    #+#             */
/*   Updated: 2023/05/01 13:52:32 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	forker(char *raw_cmd, pid_t *pid, char **envp, int *n)
{
	char	**cmd;
	char	*path;
	int		error_handle;
	//int		status;
	//int		file_fd;

	*n = *n + 1;
	cmd = ft_split(raw_cmd, ' ');
	path = ft_path_validator(envp, cmd[0]);
	if (path != NULL)
	{
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
		//waitpid(*pid, &status, 0);
		//ft_printf("Does it read this? if so, which process? %d\n", *pid);
		return (error_handle);
	}
	return (-1);
}

pid_t	*pid_array(int argc)
{
	int		number_of_cmd;
	pid_t	*pid_array;

	number_of_cmd = argc - 3;
	pid_array = (pid_t *) malloc(sizeof(pid_t) * number_of_cmd);
	if (pid_array == 0)
		return (0);
	while (number_of_cmd > 0)
	{
		pid_array[number_of_cmd - 1] = number_of_cmd + 1;
		number_of_cmd--;
	}
	return (pid_array);
}

int	fork_maker(int argc, char **argv, char **envp, int **fd)
{
	pid_t	*pid1;
	int		n;
	int		status;

	n = 0;
	ft_printf("check fd file1 %d && fd file2 %d\n", fd[0][0], fd[0][1]);
	pid1 = pid_array(argc);
	if (pid1 == 0)
		return (-1);
	//ft_printf("pid[0] = %d\n pid[1] = %d\n", pid1[0], pid1[1]);
	while (n < (argc - 3))
	{
		forker(argv[2 + n], &pid1[n], envp, &error_handle);
		waitpid(pid1[n], &status, 0);
		ft_printf("Parent my child #%d\n", pid1[n]);
		n++;
	}
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
	fd[0][0] = open(argv[1], O_RDONLY);
	if (fd[0][0] == -1)
		return (-1);
	fd[0][1] = open(argv[argc - 1], (O_TRUNC) | O_RDWR | O_CREAT, 0777);
	if (fd[0][1] == -1)
		return (-1);
	ft_printf("check fd file1 %d && fd file2 %d\n", fd[0][0], fd[0][1]);
	if (pipe(fd[1]) == -1)
		return (-1);
	if (fork_maker(argc, argv, envp, fd) == -1)
		return (-1);
	ft_printf("is it close? %d", write(fd[0][1], "test", ft_strlen("test")));
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