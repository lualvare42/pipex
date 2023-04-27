/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:35:28 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/27 18:35:28 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief 
 * 
 * @param fd1  
 * @param fd2
		open(argv[2], (O_TRUNC) | O_RDWR | O_CREAT, 0777) is what is needed to open
		file2
 * @param envp 
 
 */

int	main(int argc, char **argv, char **envp)
{
	char	**cmd1;
	char	**cmd2;
	pid_t	pid;
	pid_t	await;
	int		status;

	if (ft_input_check(argc, argv) == 0)
		return (0);
	fork_maker(argc, argv, envp);
	/*cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	pid = fork();
	if (pid == 0)
	{
		ft_printf("message from child: my number is %d\n", pid);
		execve(ft_path_validator(envp, cmd1[0]), cmd1, envp);
	}
	//execve(ft_path_validator(envp, "ls"), option, envp);
	await = wait(&status);
	if (WIFEXITED(status))
	{
		ft_printf("Parent here my child is %d", pid);
		ft_printf("\ncmd1: %s option1: %s \ncmd2: %s", cmd1[0], cmd1[1], cmd2[0]);
	}
	else
		ft_printf("something went wrong with ma child");
	//i = ft_path_index(envp);
	//ft_printf("%s", envp[i]);
	return (0);*/
}
