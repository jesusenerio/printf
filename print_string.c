#include "main.h"

/**
 * print_string - writes a string from a va_list object type to a buffer
 *
 * @args: the va_list object
 * @buffer: the buffer to write to
 * Return: number of characters printed
 */
int print_string(va_list args, char *buffer)
{
	int i;
	char *s;

	s = va_arg(args, char *);

	if (s == NULL)
		s = "(nil)";

	for (i = 0; s[i]; i++)
		add_to_buffer(s[i], buffer);

	return (i);
}

/**
 * print_string_all - writes a string from a va_list object type to a buffer
 * Non printable characters (0 < ASCII value < 32 or >= 127)
 * are printed this way: \x, followed by the ASCII code value
 * in hexadecimal
 * @args: the va_list object
 * @buffer: the buffer to write to
 * Return: number of characters printed
 */
int print_string_all(va_list args, char *buffer)
{
	int i, base;
	char *s, caps;

	base = 16; /* Unprintable characters will be converted to base 16 */
	caps = 'y'; /* Capital letters will be used for substitutions
*	in base conversion
*/

	s = va_arg(args, char *);

	if (s == NULL)
		s = "(nil)";

	for (i = 0; s[i]; i++)
	{
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			write_string_to_buffer("\\x", buffer);
			if (s[i] < base)
				add_to_buffer('0', buffer);
			print_in_base(s[i], base, &caps, buffer);
		}
		else
			add_to_buffer(s[i], buffer);
	}

	return (i);
}


/**
 * write_string_to_buffer - writes a string to buffer
 *
 * @str: string to be written to buffer
 * @buffer: buffer to be written to
 * Return: the number of characters written
 */
size_t write_string_to_buffer(char *str, char *buffer)
{
	size_t i;

	for (i = 0; str[i]; i++)
		add_to_buffer(str[i], buffer);

	return (i);
}

/**
 * write_nil_to_buffer - writes (nil) to buffer
 *
 * @buffer: the buffer to be written to
 * Return: the number of characters written
 */
size_t write_nil_to_buffer(char *buffer)
{
	size_t i;
	char *s = "(nil)";

	i = write_string_to_buffer(s, buffer);

	return (i);
}
