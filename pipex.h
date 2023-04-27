/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:29:00 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/26 18:20:00 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

char	*ft_path_validator(char **envp, char *cmd);
char	**ft_path_finder(char **envp);
int		ft_input_check(int argc, char **argv);

#endif