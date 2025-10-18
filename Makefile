NAME    = get_next_line
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

SRC     = get_next_line.c get_next_line_utils.c main.c
OBJ     = $(SRC:src/%.c=obj/%.o)
HEADER  = include/get_next_line.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

obj/%.o: src/%.c $(HEADER)
	@mkdir -p obj
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
