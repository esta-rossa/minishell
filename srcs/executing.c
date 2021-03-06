/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 16:19:13 by arraji            #+#    #+#             */
/*   Updated: 2020/12/14 22:13:50 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	bool	peri_excuting(t_command *cmd, t_all *all)
{
	int		ret;

	if (cmd->simple && (g_pid = fork()) == -1)
		return (error(E_STANDARD, 1, NULL));
	if (g_pid == 0)
	{
		if ((execve(cmd->full_path, cmd->argv, reverse_env())) == -1 )
			return (error(E_STANDARD, 1, NULL));
	}
	return (true);
}

static	void	post_executing(t_command *cmd, int pipefd[2], int savefd[2])
{
	if (cmd->next)
	{
		dup_close(pipefd[READ_END], STDIN_FILENO);
	}
	else
	{
		dup2(savefd[0], STDIN_FILENO) == -1 ? error(E_STANDARD, 1, NULL) : 1;
		dup2(savefd[1], STDOUT_FILENO) == -1 ? error(E_STANDARD, 1, NULL) : 1;
	}
}

bool			executing(t_command *cmd, int pipefd[2], int savefd[2])
{
	int		builthin;
	bool	check;

	builthin = is_builtin(cmd->cmd_name);
	if (pre_execute(cmd, pipefd, savefd, builthin) == false)
		return (false);
	if (!cmd->simple)
		if ((g_pid = fork()) == -1)
			return (error(E_STANDARD, 1, NULL));
	if (g_pid == -2)
		check = (builthin < 0) ? peri_excuting(cmd, g_all) : exec_builthin(cmd, builthin);
	if (check == false)
		return (false);
	post_executing(cmd, pipefd, savefd);
	return (true);
}
