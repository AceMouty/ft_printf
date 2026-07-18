#include "ft_printf.h"

int ft_putstr(char *s)
{
  int count;

  if(s == NULL)
    s = "(null)";

  count = 0;
  while(s[count]) {
    if(ft_putchar(s[count]) < 0)
      return -1;
    count++;
  }

  return count;
}
