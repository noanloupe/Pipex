NAME		=	pipex

FILES		=	main.c\
				pipex.c\
				utils.c\
				execute.c\
				error.c\

SRCS		=	$(addprefix srcs/, $(FILES))

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

SANITIZE	=	-fsanitize=address -g

### LIBS ###

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

PRINTF_DIR	=	ft_printf
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

GNL_DIR		=	gnl
GNL			=	$(GNL_DIR)/gnl.a

### RULES ###

$(NAME):		dirs $(OBJS)
				@echo "Compiling..."
				@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(GNL) -o $(NAME)
				@echo "Done."

dirs:
				@echo "Making libft..."
				@make -C $(LIBFT_DIR)
				@echo "Libft done."
				@echo "Making printf..."
				@make -C $(PRINTF_DIR)
				@echo "Printf done."
				@echo "Making gnl..."
				@make -C $(GNL_DIR)
				@echo "Gnl Done."

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

sanitize:		dirs $(OBJS)
				@echo "Compiling..."
				@$(CC) $(CFLAGS) $(SANITIZE) $(OBJS) $(LIBFT) $(PRINTF) $(GNL) -o $(NAME)
				@echo "Done."

all:			$(NAME)

clean:
				@echo "Cleaning..."
				@make clean -C $(LIBFT_DIR)
				@make clean -C $(PRINTF_DIR)
				@make clean -C $(GNL_DIR)
				@rm -f $(OBJS)
				@echo "Cleaned."

fclean:			clean
				@make fclean -C $(LIBFT_DIR)
				@make fclean -C $(PRINTF_DIR)
				@make fclean -C $(GNL_DIR)
				@rm -f $(NAME)

re :			fclean $(NAME)

.PHONY: sanitize dirs all clean fclean re