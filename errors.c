#include "shell.h"

/**
 * _eputs - prints input string
 * @str: string to be printed
 * Return: 0
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - write the char c to the stderr
 * @c: char to print
 * Return: 1 on success
 */

int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
}

/**
 * _putsfd - prints an input string
 * @str: string to e printed
 * @fd: file descriptor to write to
 * Return: no of chars put
 */
void _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return;
#include "shell.h"

/**
 * _eputs - prints input string
 * @str: string to be printed
 * Return: 0
 */

void _eputs(char *str)
{
        int i = 0;

        if (!str)
                return;
        while (str[i] != '\0')
        {
                _eputchar(str[i]);
                i++;
        }
}

/**
 * _eputchar - write the char c to the stderr
 * @c: char to print
 * Return: 1 on success
 */

int _eputchar(char c)
{
        static int i;	while (*str)
	{
		i += _putchar(*str++);
	}
}
