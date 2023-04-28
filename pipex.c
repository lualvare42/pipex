/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:35:28 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/27 21:39:34 by lualvare         ###   ########.fr       */
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
	piper(argc, argv, envp);
	return (0);
}
