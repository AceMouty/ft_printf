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

OBJ_DIR = build
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

TEST_NAME = test_printf
TEST_SRC = test/test_ft_printf.c

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

$(OBJ_DIR)/%.o: src/%.c include/ft_printf.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# build and run test executable
test: $(NAME)
	$(CC) $(CFLAGS) test/test_ft_printf.c -L. -lftprintf -o test_printf 
	./test_printf

valgrind: test
	$(VALGRIND) $(VALGRINDFLAGS) ./$(TEST_NAME)

# remove obj files
clean:
	rm -rf $(OBJ_DIR)

# remove obj files and lib
fclean: clean
	rm -f $(NAME) $(TEST_NAME)

# full build
re: fclean all

# tell make these are not actual files
.PHONY: all test valgrind clean fclean re
