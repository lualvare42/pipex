/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:30:23 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/28 17:42:56 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	forker(char **argv, pid_t *pid, char **envp, int *n)
{
	int		cmd_index;
	char	**cmd;
	char	*path;

	*n = *n + 1;
	cmd_index = *pid;
	cmd = ft_split(argv[cmd_index], ' ');
	path = ft_path_validator(envp, cmd[0]);
	if (path != NULL)
	{
		*pid = fork();
		if (*pid == -1)
		{
			*n = -1;
			return (0);
		}
		else if (*pid == 0)
		{
			ft_printf("message from child #%d: my number is %d\n", *n, *pid);
			execve(ft_path_validator(envp, cmd[0]), cmd, envp);
		}
	}
	return (0);
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

int	fork_maker(int argc, char **argv, char **envp)
{
	pid_t	*pid1;
	int		n;
	int		error_handle;
	int		status;

	n = 0;
	error_handle = 0;
	pid1 = pid_array(argc);
	if (pid1 == 0)
		return (-1);
	//ft_printf("pid[0] = %d\n pid[1] = %d\n", pid1[0], pid1[1]);
	while (n < (argc - 3))
	{
		forker(argv, &pid1[n], envp, &error_handle);
		waitpid(pid1[n], &status, 0);
		if (error_handle == -1)
			return (-1);
		ft_printf("Parent my child #%d id is %d\n", error_handle, pid1[n]);
		n++;
	}
	return (0);
}

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