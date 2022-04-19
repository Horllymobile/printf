#include "main.h"

/**
 * _printf - entry point of printf like function
 * @format: argument that specify the format type
 * @...: variable length argument
 * Return: number of character printed
 **/

int _printf(const char *format, ...)
{

int track = 0;
va_list args;

char *pointer, *start;
param_func flags = {0,0,0,0,0,0,0,0,0,0};

va_start(args, format);

if (!format || (format[0] == '%' && !format[1])
return -1;
if (format[0] == '%' && format[1] == ' ' && !format[2])
return -1;

for (pointer = (char *)format; *pointer; pointer++)
{
init_params(&flag, args);
if (*pointer != '%')
{
track += _putchar(*pointer);
continue;
}
start = pointer;
pointer++;
while (get_flag(pointer, &flags)
{
pointer++;
}

pointer = get_width(pointer, &flags, args);
pointer = get_precision(pointer, &flags, args);

if (get_mods(pointer, &flags))
pointer++;

if (!func_parse(pointer))
track += print_range(start, pointer,
flags.l_mod || flags.h_mod ? pointer - 1 : 0);
else
track += print_func(pointer, args, &flags);
}
_putchar(-1);
va_end(args);
return (track);
}
