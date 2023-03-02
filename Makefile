# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:58:27 by ccosta-c          #+#    #+#              #
#    Updated: 2023/03/02 10:38:48 by ccosta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COLORS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COMMANDS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CC = cc
RM = rm -f
AR = ar -rcs

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FLAGS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CFLAGS		= -Wall -Wextra -Werror 
MKFLAGS		= --no-print-directory
LIBXFLAGS	= -L ./mlx -lmlx -Ilmlx -lXext -lX11 -lm 
LIBFTFLAGS	= -L ./libft -lft

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FOLDERS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
DEPS		= includes 
SRCS		= .
SRCS_BONUS	= srcs_bonus
LIBFT		= libft
LIBX 		= mlx

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FILES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
SRC				= check_map.c ft_print_array.c get_map.c map_size.c utils.c draw_windows.c free_array.c draw_map.c enemies.c overhaul.c
OBJS 			:= $(SRC:.c=.o)
OBJS_BONUS		= 
NAME			= so_long
NAME_BONUS		= so_long
TARGET			= $(addprefix $(SRCS)/, $(OBJS))
TARGET_BONUS	= $(addprefix $(SRCS_BONUS)/, $(OBJS_BONUS))


#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RULES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
all: $(NAME)

$(NAME): $(TARGET)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/*$(RESET)"
	make $(MKFLAGS) -C $(LIBFT)
	
	$(CC) $(CFLAGS) main.c $(TARGET) $(LIBFTFLAGS) $(LIBXFLAGS) -g -o $(NAME) -I $(DEPS)
	
	echo "$(GREEN)Done.$(RESET)"
	
%.o : %.c 
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

clean:
	make clean $(MKFLAGS) -C $(LIBFT)
	echo "[$(RED) Deleted $(RESET)] $(GREEN)*/*.o$(RESET)"
	$(RM) $(TARGET) $(TARGET_BONUS)

fclean: clean
	make fclean $(MKFLAGS) -C $(LIBFT)
	echo "[$(RED) Deleted $(RESET)] $(GREEN)so_long$(RESET)"
	$(RM) $(NAME)

debug:
	$(CC) $(CFLAGS) $(LIBXFLAGS) main.c $(SRC) libft/libft.a mlx/libmlx.a -g

#bonus: $(TARGET_BONUS)
#	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/*$(RESET)"
#	make $(MKFLAGS) -C $(LIBFT)
#	
#	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)get_next_line/*$(RESET)"
#	make $(MKFLAGS) -C $(GNL)
#	
#	echo "[$(CYAN) Linking $(RESET)] $(GREEN)*$(RESET)"
#	$(CC) $(CFLAGS) main.c $(TARGET_BONUS) $(LIBFTFLAGS) $(GNLFLAGS) $(LIBXFLAGS) -o $(NAME) -I $(DEPS)
#	
#	echo "$(GREEN)Done.$(RESET)"

.SILENT:
re: fclean all