INC_DIR		= .
MANDA_DIR	= .

MANDA_NAMES	=	five_numbers.c ft_list_utils.c ft_utils.c index.c \
				push_swap.c quick_sort.c radix_sort.c actions.c

				
MANDA_SRCS	= $(MANDA_DIR)/$(MANDA_NAMES)

MANDA_OBJS	= $(MANDA_SRCS:.c=.o)

NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar rc

RM			= rm -f

RL			= ranlib

$(NAME):	$(MANDA_OBJS)
			$(CC) $(CFLAGS) $(MANDA_OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(MANDA_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re