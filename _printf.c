#include "main.h"

void print_buffer(char buffer[], int *buff_count);

/**
 * _printf - function definition
 * Description: prints
 * @format: a character string
 * Return: Printed characters
 */
int _printf(const char *format, ...)
{
	int n, count = 0, printed_characters = 0;
	int width, flags, size, precision, buff_count = 0;
	char buffer[BUFF_SIZE];
	va_list arglist;

	if (format == NULL)
		return (-1);

	va_start(arglist, format);

	for (n = 0; format && format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			buffer[buff_count++] = format[n];
			if (buff_count == BUFF_SIZE)
				print_buffer(buffer, &buff_count);

			printed_characters++;
		}
		else
		{

			print_buffer(buffer, &buff_count);
			width = get_width(format, &n, arglist);
			flags = get_flags(format, &n);
			precision = get_precision(format, &n, arglist);
			size = get_size(format, &n);
			n++;
			count = handle_print(format, &n, arglist, buffer,
				flags, width, precision, size);

			if (count == -1)
				return (-1);
			printed_characters += count;
		}
	}

	print_buffer(buffer, &buff_count);

	va_end(arglist);

	return (printed_characters);
}

/**
 * print_buffer - function
 * Description: prints contents of a buffer
 * @buffer: array
 * @buff_count: index to add next
 */
void print_buffer(char buffer[], int *buff_count)
{
	if (*buff_count > 0)
		write(1, &buffer[0], *buff_count);

	*buff_count = 0;
}

