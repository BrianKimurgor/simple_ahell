#include "shell.h"

ssize_t read_buf(info_t *info, char *buf, size_t *len);

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address to buffer
 * @len: var len address
 * Return: bytes read
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
        ssize_t r = 0;
        size_t len_p = 0;

        if (!*len) /* nothing left? fill it */
        {
                /*nfree ((void **)info->cmd_buf);*/
                free(*buf);
                *buf = NULL;
                signal(SIGINT, sigintHandler);
#if USE_GETLINE
                r = getline(buf, &len_p, stdin);
#else
                r = _getline(info, buf, &len_p);
#endif
                if (r > 0)
                {
                        if ((*buf)[r - 1] == '\n')
                        {
                                (*buf)[r - 1] = '\0';
                                r--;
                        }
                        info->linecount_flag = 1;
                        remove_comments(*buf);
                        build_history_list(info, *buf, info->histcount++);
                        {
                                *len = r;
                                info->cmd_buf = buf;
                        }
                }
        }
        return (r);
}

