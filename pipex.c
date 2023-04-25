/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:35:28 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/25 18:01:23 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*command[3] = {"ls", "-la", NULL};

	execve(ft_path_validator(envp, "ls"), command, envp);
	//i = ft_path_index(envp);
	//ft_printf("%s", envp[i]);
	return (0);
}
