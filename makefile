#--STANDARD--
NAME		= fractol
CFLAGS		= -g3 -O3 -Imlx -Lmlx -lmlx -lXext -lX11 -lm -Wall -Wextra -Werror
OBJ_D		= ./objects

#--MANDATORY--
SRC_DIR		= ./mandatory/src/
SRC			= init.c fractal.c hooks.c mandelbrot.c errors.c julia.c fract-ol.c
OBJ			= $(addprefix $(OBJ_D)/, $(SRC:.c=.o))

#--BONUS--
SRCB_DIR	= ./bonus/src/
SRC_B		= init_bonus.c fractal_bonus.c hooks_bonus.c mandelbrot_bonus.c errors_bonus.c \
			julia_bonus.c tricorn_bonus.c hook_utils_bonus.c fract-ol_bonus.c
OBJ_B		= $(addprefix $(OBJ_D)/, $(SRC_B:.c=.o))

#--LIBFT--
LIBFT	= $(addprefix $(LPATH)/, libft.a)
LPATH	= ./Libft/

all: $(NAME)

bonus:
	@make OBJ="$(OBJ_B)" all --no-print-directory

$(NAME): $(LIBFT) $(OBJ)
	@cc $(OBJ) $(LIBFT) $(CFLAGS) -o $(NAME)
	@echo "\033[0;32m$(NAME) created!\033[0m"
	@echo "\033[0;34mrun ./fractol and follow the instructions\033[0m"

$(LIBFT):
	@$(MAKE) --silent -C $(LPATH) && echo "\033[0;32mLibft Compiled!\033[0m"

$(OBJ_D)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_D)
	@cc -c $< -o $@ && echo "\033[0;32mObjects compiled!\033[0m"

$(OBJ_D)/%.o: $(SRCB_DIR)/%.c
	@mkdir -p $(OBJ_D)
	@cc -c $< -o $@ && echo "\033[0;32mObjects bonus compiled!\033[0m"

clean:
	@rm -rf $(OBJ_D)
	@$(MAKE) clean --silent -C $(LPATH) && echo "\033[1;31mobjects cleaned!\033[0m"

fclean: clean
	@rm $(NAME)
	@$(MAKE) --silent fclean -C $(LPATH) && echo "\033[1;31mfractol deleted!\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus