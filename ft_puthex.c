#include "ft_printf.h"

int ft_puthex(unsigned int n, char specifier)
{
  char *base;
  int count;
  int printed;

  if(specifier == 'X')
    base = "0123456789ABCDEF";
  else
    base = "0123456789abcdef";

  count = 0;
  if(n >= 16) // 16 because hex is base 16
  {
    printed = ft_puthex(n / 16, specifier);
    if(printed < 0)
      return -1;
    count += printed;
  }

  printed = ft_putchar(base[n % 16]);
  if(printed < 0)
    return -1;
  count += printed;

  return count;
}
