NAME = libftprintf.a

CC = clang
CFLAGS = -Wall -Wextra -Werror -Iinclude

AR = ar
ARFLAGS = rsc
# r: replace/add files
# c: create archive if not exists
# s: create/update archive index

SRC = src/ft_printf.c src/ft_putchar.c src/ft_puthex.c src/ft_putnbr.c \
			src/ft_putptr.c src/ft_putstr.c src/ft_put_unsigned.c

OBJ = $(SRC:.c=.o)

VALGRIND = valgrind
VALGRINDFLAGS = --leak-check=full \
								--show-leak-kinds=all \
								--track-origins=yes \
								--errors-for-leak-kinds=all \
								--error-exitcode=1

# default target
all: $(NAME)

# build static lib from obj files
$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

# rule to combine each .c -> .o
%.o: %.c include/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

# create testing executable
test: $(NAME)
	$(CC) $(CFLAGS) test/test_ft_printf.c -L. -lftprintf -o test_printf 
	./test_printf

valgrind:
	$(VALGRIND) $(VALGRINDFLAGS) ./a.out

# remove obj files
clean:
	rm -f $(OBJ)

# remove obj files and lib
fclean: clean
	rm -f $(NAME) test_printf

# full build
re: fclean all

# tell make these are not actual files
.PHONY: all clean fclean re
