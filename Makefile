NAME		= fdf
SRCS		= main.c hextoi.c read_map.c true_exit.c
OBJS		= ${SRCS:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LFLAGS		= -Llibft -L/usr/local/lib -lft -lmlx -lXext -lX11 -lm
LIB			= libft.a
LIB_DIR		= libft/
OBJS_DIR	= obj

all: $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

$(NAME): $(OBJS) $(LIB_DIR)$(LIB)
		$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $@

$(LIB_DIR)$(LIB) :;
		make -C $(LIB_DIR)

clean :
	rm -f $(OBJS) $(DEPS)
	make clean -C $(LIB_DIR)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)