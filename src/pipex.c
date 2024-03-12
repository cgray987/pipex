/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:48:44 by cgray             #+#    #+#             */
/*   Updated: 2024/02/15 15:30:55 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Split command
find path to command line
exec command and error check
**cmd = commandd array (av[2] and av[3]) {ls, -l} {wc -l}
*path = path to command program*/
void	run_cmd(char *av, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	cmd = ft_split(av, ' ');
	path = extract_path(cmd[0], envp);
	i = 0;
	if (!path)
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		error("Path to command not found.\n");
	}
	i = 0;
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		exit(EXIT_FAILURE);
	}
}

/* Child process that runs inside of fork.
Creates input file,
Takes the infile av[1], puts output to pipe p_fd[1]
close pipe input
execute av[2]
*/
void	child_process(char **av, char **envp, int *p_fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY, 0666);
	if (infile == -1)
	{
		error("open av[1] failed\n");
		return ;
	}
	dup2(p_fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(p_fd[0]);
	run_cmd(av[2], envp);
}

/* parent process of fork
 create file, write-only, create file, erase if already exists
open av[4], redirect input to pipe fd[0] ->stdin
output outfile to stdout
close pipe output
execute av[3]*/
void	parent_process(char **av, char **envp, int *p_fd)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfile == -1)
		error("open av[4] failed\n");
	dup2(p_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(p_fd[1]);
	run_cmd(av[3], envp);
}

/* Main Function
-checks arguments
-creates pipe and fork
-calls child and parent process after child process finishes */
int	main(int ac, char **av, char **envp)
{
	int		p_fd[2];
	pid_t	pid1;

	if (ac == 5)
	{
		if (pipe(p_fd) == -1)
			error("pipe failed\n");
		pid1 = fork();
		if (pid1 == -1)
			error("fork failed\n");
		if (pid1 == 0)
			child_process(av, envp, p_fd);
		waitpid(pid1, NULL, 0);
		parent_process(av, envp, p_fd);
	}
	else
	{
		error("Error: bad arguments\n");
		ft_printf("Expected format:\n./pipex infile cmd1 cmd2 outfile\n");
	}
	return (0);
}
