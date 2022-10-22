#include "main.h"

/**
 * _printf - copy of C's printf
 *
 * @format: the string to be printed to screen, may contain directives
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned long int i, length;
	char character, next_character;
	char buffer[BUFFSIZE];

	if (format == NULL || buffer == NULL)
		return (-1);

	initialize_buffer(buffer);

	va_start(args, format);

	for (i = 0; *(format + i); i++)
	{
		character = *(format + i);
		next_character = *(format + i + 1);
		if (character == '%')
		{
			make_substitution(&character, &next_character,
					  args, buffer);

			i++;
		}
		else if (character == '\\')
		{
			print_special_char(&next_character, args, buffer);
			i++;
		}
		else
			add_to_buffer(character, buffer);
	}

	length = cleanup(buffer, args);

	return (length);
}

/**
 * cleanup - clean up function for _printf, clears buffer from memory
 *           and ends va_args list
 * @buffer: buffer used to store characters to be printed
 * @args: va_list object, holds arguments passed to _printf function
 * Return: the length of buffer
 */
size_t cleanup(char *buffer, va_list args)
{
	size_t length;

	length = print_buffer(buffer);
	va_end(args);
	return (length);
}
