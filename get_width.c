#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: WIDTH.
 */
int get_width(const char *format, int *i, va_list list)
{
	int CURR_i;
	int WIDTH = 0;

	for (CURR_i = *i + 1; format[CURR_i] != '\0'; CURR_i++)
	{
		if (is_digit(format[CURR_i]))
		{
			WIDTH *= 10;
			WIDTH += format[CURR_i] - '0';
		}
		else if (format[CURR_i] == '*')
		{
			CURR_i++;
			WIDTH = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = CURR_i - 1;

	return (WIDTH);
}
