/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:55:33 by lualvare          #+#    #+#             */
/*   Updated: 2023/05/01 14:39:39 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_files_check(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*zsh;

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		zsh = ft_strjoin("zsh: ", argv[1]);
		perror(zsh);
		free (zsh);
		return (0);
	}
	fd2 = open(argv[4], (O_TRUNC) | O_RDWR | O_CREAT, 0777);
	if (fd2 == -1)
	{
		zsh = ft_strjoin("zsh: ", argv[4]);
		perror(zsh);
		free (zsh);
		return (0);
	}
	close(fd1);
	close(fd2);
	return (1);
}

/**
 * @brief 
		path_val checks if a command is given with its respective path.
 * 
 * @param path
 * @param parsing
		Checks whether path_val is called from parsing step or not.
		(1): True, perror messages should be displayed.
		(0): False, perror messages should not be displayed.
		
 * @return
		(1): True, command already given with a valid path.
		(0): False, command not given with a valid path.
 */
int	path_val(char *path, int parsing)
{
	char	**path_clean;
	char	*zsh;

	path_clean = ft_split(path, ' ');
	if (access(path_clean[0], F_OK | X_OK) == 0)
	{
		ft_free_doubleptr((void **)path_clean);
		return (1);
	}
	if (parsing == 1)
	{
		zsh = ft_strjoin("zsh: ", path);
		perror(zsh);
		free(zsh);
	}
	ft_free_doubleptr((void **)path_clean);
	return (0);
}

int	ft_path_check(char **argv)
{
	int	path_given;

	path_given = 0;
	if (ft_strnstr(argv[2], "/", ft_strlen(argv[2])) != NULL)
		path_given = path_given + 1;
	if (ft_strnstr(argv[3], "/", ft_strlen(argv[3])) != NULL)
		path_given = path_given + 2;
	if (path_given == 0)
		return (1);
	else if (path_given == 3 && path_val(argv[2], 1) && path_val(argv[3], 1))
		return (1);
	else if (path_given == 1 && path_val(argv[2], 1))
		return (1);
	else if (path_given == 2 && path_val(argv[3], 1))
		return (1);
	return (0);
}

int	ft_input_check(int argc, char **argv)
{
	if (argc - 1 != 4)
		return (0);
	else if (ft_files_check(argc, argv) == 0)
		return (0);
	else if (ft_path_check(argv) == 0)
		return (0);
	return (1);
}
