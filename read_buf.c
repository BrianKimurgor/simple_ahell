#include "shell.h"

ssize_t read_buf(info_t *info, char *buf, size_t *i);
/**
 * read_buf -reads buffer
 * @info: parameterstruct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */

ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}
