#include "shell.h"

ssize_t read_buf(info_t *info, char *buf, size_t *len);
/**
 * get_input - gets a line -new line
 * @info: parameter struct
 * Return: bytes read
 */

ssize_t get_input(info_t *info)
{
        static char *buf;
        static size_t i, j, len;
        ssize_t r = 0;
        char **buf_p = &(info->arg), *p;

        _putchar(BUF_FLUSH);
        r = input_buf(info, &buf, &len);
        if (r == -1)
                return (-1);
        if (len)
        {
                j = i;
                p = buf + i;

                check_chain(info, buf, &j, i, len);
                while (j < len)
                {
                        if (is_chain(info, buf, &j))
                                break;
                        j++;
                }

                i = j + 1;
                if (i >= len)
                {
                        i = len = 0;
                        info->cmd_buf_type = CMD_NORM;
                }

                *buf_p = p;
                return (_strlen(p));
        }
        *buf_p = buf;
        return (r);
}

