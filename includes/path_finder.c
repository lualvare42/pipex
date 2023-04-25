/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:34:37 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/25 17:11:25 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_path_index(char	**envp)
{
	int	n;

	n = 0;
	while (envp[n])
	{
		if (ft_strnstr(envp[n], "PATH=", 5) != NULL)
			return (n);
		n++;
	}
	return (0);
}

char	**ft_path_finder(char **envp)
{
	int		index;
	char	*start_removed;
	char	**paths;
	int		n;
//	int		i;

	index = ft_path_index(envp);
	start_removed = ft_substr(envp[index], 5, ft_strlen(envp[index]));
	paths = ft_split(start_removed, ':');
	n = 0;
	while (paths[n])
	{
		paths[n] = ft_strjoin(paths[n], "/");
		n++;
	}
	free (start_removed);
	return (paths);
	/*for (i = 0; paths[i]; i++)
	{
		ft_printf("%s\n", paths[i]);
	}*/
}
