#include "main.h"

/**
 * print_char - writes a single character from
 *              a va_list object type to a buffer
 *
 * @args: the va_list object
 * @buffer: the buffer to write to
 * Return: 1
 */
int print_char(va_list args, char *buffer)
{
	char s;

	s = va_arg(args, int);

	add_to_buffer(s, buffer);

	return (1);
}
