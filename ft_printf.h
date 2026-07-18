#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int ft_printf(const char *format, ...);

int ft_putchar(char c);
int ft_putstr(char *s);
int ft_putnbr(int n);
int ft_put_unsigned(unsigned int n);
int ft_puthex(unsigned int n, char specifier);
int ft_putptr(void *ptr);

#endif
