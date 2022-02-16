NAME		= fdf
SRCS_DIR	= srcs/
OBJS_DIR	= objs/
INCS_DIR	= includes
SRCS_F		= main.c read_map.c true_exit.c render_map.c bresenham_line_algo.c events_handler.c
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_F))
OBJS_F		= $(patsubst %.c, %.o, $(SRCS_F))
DEPS_F		= $(patsubst %.c, %.d, $(SRCS_F))
OBJS		= $(addprefix $(OBJS_DIR), $(OBJS_F))
DEPS		= $(addprefix $(OBJS_DIR), $(DEPS_F))
SRCS_FB		= main_bonus.c utils_bonus.c read_map_bonus.c true_exit_bonus.c \
				render_map_bonus.c bresenham_line_algo_bonus.c events_handler_bonus.c
SRCS_B		= $(addprefix $(SRCS_DIR), $(SRCS_FB))
OBJS_FB		= $(patsubst %.c, %.o, $(SRCS_FB))
DEPS_FB		= $(patsubst %.c, %.d, $(SRCS_FB))
OBJS_B		= $(addprefix $(OBJS_DIR), $(OBJS_FB))
DEPS_B		= $(addprefix $(OBJS_DIR), $(DEPS_FB))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -MMD
LFLAGS		= -Llibft -L/usr/local/lib -lft -lmlx -lXext -lX11 -lm
LIB			= libft.a
LIB_DIR		= libft/

all: $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
		$(CC) $(CFLAGS) -I$(INCS_DIR) -c $< -o $@

$(OBJS_DIR) :
		mkdir -p $@

$(NAME):  $(OBJS_DIR) $(OBJS) $(LIB_DIR)$(LIB) Makefile
		$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $@

bonus: $(OBJS_DIR) $(OBJS_B) $(LIB_DIR)$(LIB) Makefile
		make OBJS="$(OBJS_B)" $(NAME)

$(LIB_DIR)$(LIB) : ;
		make -C $(LIB_DIR)

clean :
	rm -rf $(OBJS_DIR)
	make clean -C $(LIB_DIR)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all

.PHONY:
		all clean fclean re bonus

-include $(DEPS) $(DEPS_B)