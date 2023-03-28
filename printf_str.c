#include "main.h"

/**
 * printf_string - function
 * Desription: prints a string
 * @args: argument
 * @printed_characters: characters printed
 *
 * Return: prt
 */
int printf_string(va_list args, int printed_characters)
{
	char *str = va_arg(args, char *);

	while (*str != '\0')
	{
	_putchar(*str);
	printed_characters++;
	str++;
	}

	return(printed_characters);
}
