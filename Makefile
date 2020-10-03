NAME = 	endgame

SRCS = 	src/*.c	
INC = 	inc/*.h
SDL =   -F inc/framework -I inc/framework/SDL2.framework/SDL2

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic\
		 -framework SDL2_ttf \
	 	 -rpath inc/framework -framework SDL2 \
	 	 					  -framework SDL2_image \
	 	 					  -framework SDL2_mixer \
		-I inc/framework/SDL2_image.framework/Headers \
		-I inc/framework/SDL2_ttf.framework/Headers \
		-I inc/framework/SDL2_mixer.framework/Headers

all: $(NAME)

$(NAME): install clean

install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) $(SRCS) $(LIBS) $(SDL) -I inc

uninstall: clean
	@rm -rf $(NAME)

clean:
	@rm -rf *.h
	@rm -rf *.c

reinstall: uninstall all 
