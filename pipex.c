/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:35:28 by lualvare          #+#    #+#             */
/*   Updated: 2023/05/01 18:30:31 by lualvare         ###   ########.fr       */
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
	if (ft_input_check(argc, argv) == 0)
		return (0);
	if (piper(argc, argv, envp) == -1)
	{
		perror("");
		return (0);
	}
	return (0);
}
