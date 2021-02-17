#include "minishell.h"

static	int		cmp(char *a, char *b)
{
	int	index;

	index = 0;
	while (a[index])
	{
		a[index] = ft_toupper(a[index]);
		index++;
	}
	index = 0;
	while (b[index])
	{
		b[index] = ft_toupper(b[index]);
		index++;
	}
	index = ft_strcmp(a, b);
	free(a);
	free(b);
	return (index);
}

static	void	env_sort(t_env *lst)
{
	t_env	*begin_list;
	t_env	*tmp;
	t_env	swap;

	begin_list = lst;
	while (lst != NULL)
	{
		tmp = begin_list;
		while (tmp->next != NULL)
		{
			if (cmp(ft_strdup(tmp->key), ft_strdup(tmp->next->key)) > 0)
			{
				swap = *tmp;
				*tmp = *tmp->next;
				tmp->next = swap.next;
				swap.next = tmp->next->next;
				*tmp->next = swap;
			}
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

static	t_env	*env_copy(t_env *lst)
{
	t_env	*new;
	int		check;
	t_env	*head;

	check = 0;
	head = NULL;
	while (lst)
	{
		new = (t_env *)malloc(sizeof(t_env));
		*new = *lst;
		new->next = NULL;
		ft_lstadd_back((t_list**)&head, (t_list*)new);
		lst = lst->next;
	}
	return (head);
}

void	print_export(t_env *list)
{
	t_env	*new;
	t_env	*tmp;

	new = env_copy(list);
	env_sort(new);
	while (new)
	{
		ft_fprintf(1, "declare -x %s\n", new->full_var);
		tmp = new;
		new = new->next;
		free(tmp);
	}
}