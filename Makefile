NAME		= path_finder

SRC_PATH	= src

OBJ_PATH	= obj

INCLUDES_PATH = includes

SRC_NAME	= main.c \
			  algo.c \
			  parser.c \
			  map_utils.c

OBJ_NAME	:= $(SRC_NAME:.c=.o)

SRC			= $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ			= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g #-g3 -fsanitize=address,undefined

.PHONY		: all clean fclean re

all			: $(NAME)

$(NAME)		: $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c 
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(CFLAGS) -o $@ -c $<

clean		:
	rm -f $(OBJ)
	rmdir $(OBJ_PATH) 2> /dev/null || true

fclean		: clean
	rm -f $(NAME)

re 			: fclean all