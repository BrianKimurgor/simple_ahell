#include "shell.h"

/**
 * get_environ - returns string array copy of our environ
 * @info: sruc containing arguments maintaining func prototype
 * Retrun: 0
 */

char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_string(info->environ);
		info->env_changed = 0;
	}
	return (info->environ);
}

/**
 * _unsetev - emove an environ variable
 * @info: struc
 * @var: string env var property
 * Return: 1on delete 0 otherwise
 */

int _unsetenv(info_t *info, var *var)
{
	char *p;
	size_t i = 0;
	list_t *node = info->env;

	if (!node || !var)
		return (0);
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_change = delete_node_at_index(&(info->env), i);

			i = 0;
			node = info->env;
			continue;
		}

		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - initializing new environment variable or modify an existing one
 * @info: struc
 * @var: property
 * @value: string env var value
 * Return: 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, value);
	_strcat(vuf, "=");
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '-')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

