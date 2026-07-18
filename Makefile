NAME = ftprintf.a

CC = clang
CFLAGS = -Wall -Wextra -Werror -I.

AR = ar
ARFLAGS = rsc
# r: replace/add files
# c: create archive if not exists
# s: create/update archive index

SRC = $(filter-out $(TEST_SRC), $(wildcard *.c))
OBJ = $(SRC:.c=.o)

TEST_SRC = main.c

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
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

# rule to combine each .c -> .o
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

# create testing executable
test: fclean $(NAME) $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) ./$(NAME)

valgrind:
	$(VALGRIND) $(VALGRINDFLAGS) ./a.out

# remove obj files
clean:
	rm -f $(OBJ)

# remove obj files and lib
fclean: clean
	rm -f $(NAME)

# full build
re: fclean all

# tell make these are not actual files
.PHONY: all clean fclean re
