#include "ft_printf.h"

static int ft_handle_conversion(char specifier, va_list *args);

int ft_printf(const char *format, ...)
{
  va_list args;
  int count;
  int printed;

  if(!format)
    return -1;

  va_start(args, format);
  count = 0;

  while(*format)
  {
    if(*format == '%' && *(format +1))
    {
      format++;
      printed = ft_handle_conversion(*format, &args);
    }
    else
    {
      printed = ft_putchar(*format);
    }

    if(printed < 0)
    {
      va_end(args);
      return -1;
    }

    count += printed;
    format++;
  }

  va_end(args);
  return count;
}

static int ft_handle_conversion(char specifier, va_list *args)
{
    if (specifier == 'c')
        return ft_putchar(va_arg(*args, int));
    if (specifier == 's')
        return ft_putstr(va_arg(*args, char *));
    if (specifier == 'p')
        return ft_putptr(va_arg(*args, void *));
    if (specifier == 'd' || specifier == 'i')
        return ft_putnbr(va_arg(*args, int));
    if (specifier == 'u')
        return ft_put_unsigned(va_arg(*args, unsigned int));
    if (specifier == 'x' || specifier == 'X')
        return ft_puthex(va_arg(*args, unsigned int), specifier);
    if (specifier == '%')
        return ft_putchar('%');
    return (0);
}
