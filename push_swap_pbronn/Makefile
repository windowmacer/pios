NAME = push_swap

NAMEB = checker

CC = cc

FLAGS = -Wall -Wextra -Werror -I.

HEADER = push_swap.h

SRC = push_swap.c ft_lib.c ft_list.c ft_list_utils.c \
		option.c ft_split.c parser.c parser_utils.c \
		sort_2_to_5.c sort_in.c sort_in_utils.c sort.c

OBJ = $(SRC:c=o)

SRCB = checker.c ft_strjoin.c get_next_line.c \
		get_next_line_utils.c ft_lib.c ft_list.c ft_list_utils.c \
		option.c ft_split.c parser.c parser_utils.c \
		sort_2_to_5.c sort_in.c sort_in_utils.c sort.c

OBJB = $(SRCB:c=o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS)$(HEADER) -o $(NAME) $(OBJ)

bonus: $(OBJB) $(HEADER)
	@make OBJ="$(OBJB)" NAME="$(NAMEB)" all

%.o: %.c $(HEADER)
	$(CC) $(FLAGS)$(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean:
	rm -f $(OBJ) $(OBJB)
	rm -f $(NAME) $(NAMEB)

re: fclean all

.PHONY: clean fclean re bonus
