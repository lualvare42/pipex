/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:34:37 by lualvare          #+#    #+#             */
/*   Updated: 2023/05/01 15:43:43 by lualvare         ###   ########.fr       */
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
	char	*temp;

	index = ft_path_index(envp);
	start_removed = ft_substr(envp[index], 5, ft_strlen(envp[index]));
	paths = ft_split(start_removed, ':');
	n = 0;
	while (paths[n])
	{
		temp = paths[n];
		paths[n] = ft_strjoin(paths[n], "/");
		free (temp);
		n++;
	}
	free (start_removed);
	return (paths);
}

char	*ft_path_validator(char **envp, char *cmd)
{
	char	*verified_path;
	char	**paths;
	int		n;

	if (path_val(cmd, 0) != 0)
		return (cmd);
	paths = ft_path_finder(envp);
	n = 0;
	while (paths[n])
	{
		verified_path = ft_strjoin(paths[n], cmd);
		if (access(verified_path, F_OK | X_OK) == 0)
		{
			ft_free_doubleptr((void **)paths);
			return (verified_path);
		}
		free (verified_path);
		n++;
	}
	ft_free_doubleptr((void **)paths);
	return (NULL);
}	
