#include "main.h"

/**
 * get_precision - precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int CUR_i = *i + 1;
	int precision = -1;

	if (format[CUR_i] != '.')
		return (precision);

	precision = 0;

	for (CUR_i += 1; format[CUR_i] != '\0'; CUR_i++)
	{
		if (is_digit(format[CUR_i]))
		{
			precision *= 10;
			precision += format[CUR_i] - '0';
		}
		else if (format[CUR_i] == '*')
		{
			CUR_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = CUR_i - 1;

	return (precision);
}
