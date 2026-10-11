#include "ft_printf.h"

int ft_putchar(char c)
{
  if(write(1, &c, 1) < 0)
    return -1;

  return 1;
}
