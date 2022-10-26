#--STANDARD--
NAME	= fractol.a
SOURCE	= ./mandatory/src/init.c ./mandatory/src/fractal.c ./mandatory/src/hooks.c \
		./mandatory/src/mandelbrot.c ./mandatory/src/errors.c ./mandatory/src/julia.c
OBJ		= $(SOURCE:.c=.o)
INCLUDE	= ./mandatory/include/
MAIN	= ./mandatory/src/fract-ol.c
FLAGS	= -I$(INCLUDE)

#--BONUS--
NAME_B		= fractol_b.a
SOURCE_B	= ./bonus/src/init.c ./bonus/src/fractal.c ./bonus/src/hooks.c \
			./bonus/src/mandelbrot.c ./bonus/src/errors.c ./bonus/src/julia.c ./bonus/src/tricorn.c
OBJ_B		= $(SOURCE_B:.c=.o)
INCLUDE_B	= ./bonus/include/
MAIN_B		= ./bonus/src/fract-ol.c
FLAGS_B		= -I$(INCLUDE_B)

#--LIBFT--
LIBFT	= ./Libft/libft.a
LIB.H	= libft.h
LPATH	= ./Libft/

all:	$(LIBFT) $(NAME)
	gcc $(FLAGS) $(MAIN) $(NAME) -lbsd -lmlx -lXext -lX11

bonus:	$(LIBFT) $(NAME_B)
	gcc $(FLAGS_B) $(MAIN_B) $(NAME_B) -lbsd -lmlx -lXext -lX11

$(LIBFT):
	$(MAKE) -C $(LPATH)

$(NAME): $(OBJ)
	mv $(LIBFT) $(NAME)
	ar -rcs $@ $^

$(NAME_B): $(OBJ_B)
	mv $(LIBFT)	$(NAME_B)
	ar -rcs $@ $^
	
clean:
	rm $(NAME)

fclean: clean 
	rm a.out ;
	$(MAKE) -C fclean $(LPATH) ;
	
re: clean all