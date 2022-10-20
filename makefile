NAME	= fractol.a
SOURCE	= ./src/init.c ./src/fractal.c ./src/hooks.c ./src/mandelbrot.c ./src/errors.c ./src/julia.c \
		./src/tricorn.c
OBJ		= $(SOURCE:.c=.o)
INCLUDE	= ./include/
MAIN	= ./src/fract-ol.c
CFLAGS	= -I$(INCLUDE)

#--LIBFT--
LIBFT	= ./Libft/libft.a
LIB.H	= libft.h
LPATH	= ./Libft/

all:	$(LIBFT) $(NAME)
	gcc $(CFLAG) $(MAIN) fractol.a -lbsd -lmlx -lXext -lX11
	./a.out Tricorn
val:	$(LIBFT) $(NAME)
	gcc $(CFLAG) $(MAIN) fractol.a -lbsd -lmlx -lXext -lX11
	valgrind ./a.out
$(LIBFT):
	$(MAKE) -C $(LPATH)
$(NAME): $(OBJ)
	mv $(LIBFT) $(NAME)
	ar -rcs $@ $^
clean:
	rm $(NAME)
	rm ./src/*.o
re: clean all