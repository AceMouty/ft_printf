#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
  int count;

  count = ft_printf("hello\n");
  printf("hello has %i printed items\n", count);

  printf("=== %%c ===\n");
  ft_printf("char: %c\n", 'A');
  printf("char: %c\n", 'A');

  printf("=== %% ===\n");
  ft_printf("percent: %%\n");
  printf("percent: %%\n");

  printf("=== %%s ===\n");
  ft_printf("name: %s\n", "Kyle");
  printf("name: %s\n", "Kyle");

  ft_printf("null: %s\n", NULL);
  printf("null: %s\n", (char *)NULL);


  printf("==== %%d ===\n");
  ft_printf("%d\n", 0);
  printf("%d\n", 0);

  ft_printf("%d\n", 42);
  printf("%d\n", 42);

  ft_printf("%d\n", -42);
  printf("%d\n", -42);

  ft_printf("%d\n", INT_MIN);
  printf("%d\n", INT_MIN);

  printf("=== %%i ===\n");
  ft_printf("%i\n", 2147483647);
  printf("%i\n", 2147483647);


  int a;
  int b;
  int x;

  x = 42;

  a = printf("real: [%s] [%d] [%x] [%p] [%%]\n", "hello", -42, 255, &x);
  b = ft_printf("mine: [%s] [%d] [%x] [%p] [%%]\n", "hello", -42, 255, &x);

  printf("printf returned:    %d\n", a);
  printf("ft_printf returned: %d\n", b);

  return EXIT_SUCCESS;
}
