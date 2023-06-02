#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/*FLAGS*/
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/*SIZES*/

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct op
 *
 * @fmt: format
 * @fn: function associated
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - struct op
 *
 * @fmt: format
 * @fm_t: function associated
 */
typedef struct fmt fmt_t;


int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

/*functions to print chars and strings*/
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_precent(va_list types, char buffer[], int flags, int width, int precision, int size);

/*functions to print numbers*/
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa(va_list types, char buffer[], int flags, int width, int precision, int size);

/*functions to print non_printable characters*/
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);

/*functions to print memory address*/
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);

/*functions to handle other specifiers*/
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*functions to print string in reverse*/
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);

/*functions to print string in rot13*/
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);

/*width hnadler*/
int print_write_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_number(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_num(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsgnd(va_list types, char buffer[], int flags, int width, int precision, int size);

/*UTILS*/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /*MAIN_H*/
