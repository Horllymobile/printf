#ifndef PRINT_H /* PRINT_H */
#define PRINT_H /* PRINT_H */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct param_flags - struct containing flags to get
 * when a flag specifier is passed to _printf()
 * @plus_flag: flag for the '+' character
 * @space_flag: flag for the ' ' character
 * @hash_flag: flag for the '#' character
 * @zero_flag: flag for the '0' character
 * @minus_flag: flag for the '-' character
 * @unsign: flag for the unsigned values
 * @width: width of the value
 * @precision: precision of the value
 * @l_mod: length modifier
 * @h_mod: short length modifier
 **/

typedef struct param_flags
{
  unsigned int plus_flag: 1;
  unsigned int space_flag: 1;
  unsigned int hash_flag: 1;
  unsigned int h_mod: 1;
  unsigned int l_mod: 1;
  unsigned int zero_flag: 1;
  unsigned int minus_flag: 1;
  unsigned int unsign: 1;

  unsigned int width;
  unsigned int precision;

} param_func;


/**
 * struct func_convert - gets structure for the symbols and functions
 *@type: operator symbols
 *@func: the associated function
 **/

typedef struct func_convert
{
  char *type;
  int (*func)(va_list, param_func *);
} f_convert;


int _printf(const char *format, ...);


/* putchar function */
int _putchar(int c);
int _puts(char *str);


/* helper functions */
int get_flags(char *s, param_func *func);
int get_digits(int i);
int is_digit(int c);
int print_right_shift(char *str, param_func *func);
int print_num(char *str, param_func *func);
int get_mods(char *str, param_func *func);
char *convert_num(long int num, int base, int flags, param_func *func);
char *get_precision(char *str, param_func *func, va_list list);
void init_params(param_func *func, va_list list);
char *get_width(char *str, param_func *func, va_list list);
int print_range(char *start, char *stop, char *except);
int print_func(char *s, va_list list, param_func *func);
int print_left_shift(char *str, param_func *func);
int _strlen(char *s);

#endif /* PRINT_H */