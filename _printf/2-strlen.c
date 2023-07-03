#include "main.h"

/**
 * _strlen - counts the character in string array
 * @s: pointer to a string
 *
 * Return: strlen- the length of the string array
 */
int _strlen(char *s)
{
	int i;
	int strlen;

	i = 0;
	strlen = 0;
	while (*(s + i) != '\0')
	{
		strlen = strlen + 1;
		i++;
	}
	return (strlen);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
