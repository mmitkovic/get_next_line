# The name of the final executable
NAME = gnl

# The compiler to use
CC = cc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Source files
SRCS = src/get_next_line_utils.c \
       src/get_next_line.c

# Main function for testing
SRCS_MAIN = main.c

# Object files
OBJS = $(SRCS:.c=.o)
OBJS_MAIN = $(SRCS_MAIN:.c=.o)

# The default rule when we run 'make'
all: $(NAME)

# Rule to link all object files into the final executable
$(NAME): $(OBJS) $(OBJS_MAIN)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(OBJS_MAIN)

# Rule to compile .c files into .o files
%.o: %.c includes/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to remove object files
clean:
	rm -f $(OBJS) $(OBJS_MAIN)

# Rule to remove object files and the final executable
fclean: clean
	rm -f $(NAME)

# Rule to force a full re-compilation
re: fclean all

# Phony targets are not files
.PHONY: all clean fclean re


