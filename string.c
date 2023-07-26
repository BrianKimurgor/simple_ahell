#include "shell.h"

/**
 * _strlen - returns string length
 * @s: string whose length to check
 * Return: integer legth of str
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while ( *s){
		i++;
		s++;
	}
	return (i);
}


/**
 * _strcmp - performs lexicogarphic comparison of two strings
 * @s1: first string
 * @s2: second string
 * Retuen: - | + | 0
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}


/**
 * starts_with - checks if needle starts with hastack
 * @haystack: str to research
 * @needle: substring to find
 * Return:address of next char of haystack or NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle){
		if (*needle++ != *haystack++)
			return (NULL);
		needle++;
		haystack++;
	}
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination buffer
 * @src: sor=urce buffer
 * Return: ptr to dest  buffer
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	*dest = *src;
	return (ret);
}
