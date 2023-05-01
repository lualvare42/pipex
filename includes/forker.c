/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:30:23 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/30 19:46:59 by lualvare         ###   ########.fr       */
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

int	forker(char **argv, pid_t *pid, char **envp, int *fd)
{
	char	cmd_index;
	char	**cmd;
	char	*path;
	int		error_handle;

	cmd_index = *pid;
	cmd = ft_split(argv[cmd_index], ' ');
	path = ft_path_validator(envp, cmd[0]);
	if (path != NULL)
	{
		*pid = fork();
		if (*pid == -1)
		{
			perror("");
			return (-1);
		}
		else if (*pid == 0)
		{
			if (cmd_index == 2)
				error_handle = ft_first_cmd(argv[1], cmd, envp, fd);
			else if ((cmd_index + 2) == ft_dbptr_len(argv))
				error_handle = ft_last_cmd(argv[cmd_index + 1], cmd, envp, fd);
			/*
			else
				ft_n_cmd(cmd, envp, fd);
			dup2(open(argv[]))
			execve(ft_path_validator(envp, cmd[0]), cmd, envp);
			*/
		}
		
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

int	fork_maker(int argc, char **argv, char **envp, int *fd)
{
	pid_t	*pid1;
	int		n;
	int		error_handle;
	int		status;

	n = 0;
	pid1 = pid_array(argc);
	if (pid1 == 0)
		return (-1);
	while (n < (argc - 3))
	{
		if (forker(argv, &pid1[n], envp, fd) == -1)
			return (-1);
		if ((n + 1) == (argc - 3))
		{
			close(fd[0]);
			close(fd[1]);
		}
		waitpid(pid1[n], &status, 0);
		ft_printf("Parent my child #%d id is %d\n", pid1[n]);
		n++;
	}
	write(5, "test", ft_strlen("test"));
	return (0);
}

int	piper(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (pipe(fd) == -1)
		return (-1);
	fork_maker(argc, argv, envp, fd);
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