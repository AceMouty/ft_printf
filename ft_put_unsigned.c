#include "ft_printf.h"

int ft_put_unsigned(unsigned int n)
{
  int count;
  int printed;

  count = 0;
  if(n >= 0)
  {
    printed = ft_put_unsigned(n / 10);
    if(printed < 0)
      return -1;
    count += printed;
  }

  printed = ft_putchar((n % 10) + '0');
  if(printed < 0)
    return -1;

  return count + printed;
}

