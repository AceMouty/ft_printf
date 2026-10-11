#include "ft_printf.h"

static int putlong(long n);

int ft_putnbr(int n)
{
  long nb; // make the container wider than int to account for INT_MIN
  int count;
  int printed;

  nb = n;
  count = 0;
  // account for negative numbers
  if(nb < 0)
  {
    printed = ft_putchar('-');
    if(printed < 0)
      return -1;
    count += printed;
    nb = -nb;
  }


  printed = putlong(nb);
  if (printed < 0)
    return -1;
  return count + printed;
}

static int putlong(long n)
{
  int count;
  int printed;

  count = 0;
  if(n >= 10)
  {
   printed = putlong(n / 10); // recursive trick to print int chars in correct order
   if(printed < 0)
    return -1;
   count += printed;
  }

  printed = ft_putchar((n % 10) + '0'); // trick to get ASCII offset of int and provide ASCII char
  if(printed < 0)
    return -1;
  return count + printed;
}
