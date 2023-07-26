#include "shell.h"

/**
 * is_chain - test if current char buffer is a chain delimeter
 * @info: parameter struct
 * @buf: char buffer
 * @p: buffer current position address
 * Return: 1 on chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND

