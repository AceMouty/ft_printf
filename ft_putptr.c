#include "ft_printf.h"

static int ft_putptr_hex(uintptr_t n);

int ft_putptr(void *ptr)
{
  int count;
  int printed;

  if(!ptr)
    return ft_putstr("(nil)");

  count = ft_putstr("0x");
  if(count < 0)
    return -1;

  printed = ft_putptr_hex((uintptr_t)ptr);
  if(printed < 0)
    return -1;

  return count + printed;
}

static int ft_putptr_hex(uintptr_t n)
{
    char *base;
    int  count;
    int  printed;

    base = "0123456789abcdef";
    count = 0;
    if (n >= 16)
    {
        printed = ft_putptr_hex(n / 16);
        if (printed < 0)
            return -1;
        count += printed;
    }
    printed = ft_putchar(base[n % 16]);
    if (printed < 0)
        return -1;
    return count + printed;
}
