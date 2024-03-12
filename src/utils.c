/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:05:09 by cgray             #+#    #+#             */
/*   Updated: 2024/02/12 17:47:39 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* display error and exit program */
void	error(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}

/* returns cmd_path in the correct format
cmd path needs to be freed at a later point */
char	*path_format(char *path, char *cmd)
{
	char	*add_slash;
	char	*cmd_path;

	add_slash = ft_strjoin(path, "/");
	cmd_path = ft_strjoin(add_slash, cmd);
	free(add_slash);
	return (cmd_path);
}

/* Search envp for PATH value
return path to given command, freeing memory as it is used
envp[i] = PATH=/nfs/homes/cgray/bin:/nfs/homes/cgray/bin...
Finds first cmd_path that exists, 0/error if not found */
char	*extract_path(char *cmd, char **envp)
{
	int		i;
	char	**paths_tab;
	char	*cmd_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	envp[i] += 5;
	paths_tab = ft_split(envp[i], ':');
	i = 0;
	while (paths_tab[i])
	{
		cmd_path = path_format(paths_tab[i], cmd);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	i = 0;
	while (paths_tab[i])
		free(paths_tab[i++]);
	free(paths_tab);
	return (0);
}
