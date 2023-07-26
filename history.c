#inlcude "shell.h"

/**
 * get_history_file - gets the history file
 * @info: parameter struct
 * Return: history file
 */

char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return NULL;
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	return (buf);
}

/**
 * write_history - create or append to existging file
 * @info: param struct
 * Rerurn: 1 0r -1
 */

int write_history(info_t *info)
{
	ssize_t fd;
	list_t *node = NULL;
	char *filename = get_history_file(info);

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
	return (-1);
}
/**
 * read_history - read file
 * @info: param
 * Return: success or 0
 */

int read_history(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename =  get_history_file(info);

	if (!namefile)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[size] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++);
	if (buf[i] == '\n')
	{buf[i] = 0;
		build_history_list(info, buf + last, linecount++);
		last = i + 1;
	}
	if ( last != i)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history). 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_hitory_list - adds entry to a history linked list
 * @info: struct containing potential arg
 * @buf: buffer
 * @linecount: history line count
 * Return: 0
 */

int build_history_list(into_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - renumbers the history linked list after changes
 * @info: struct containing pontential arg
 * Return: new hist
 */
int renumber_history(info_t *info)
{
	lit_t *node = info->history;
	int i = 0;
	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}