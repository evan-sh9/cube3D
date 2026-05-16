CFILE = main.c \
		src/utils/ft_strchr.c \
		src/utils/ft_strdup.c \
		src/utils/ft_strjoin.c \
		src/utils/ft_strlen.c \
		src/utils/ft_substr.c \
		src/utils/ft_strncmp.c \
		src/utils/gnl.c \
		src/utils/ft_strcpy.c \
		src/utils/ft_split.c \
		src/utils/ft_atoi.c \
		src/parsing/claim/claim_map.c \
		src/parsing/claim/claim_content.c \
		src/parsing/check/file_validity.c \
		src/parsing/check/map_validity.c \
		src/parsing/check/color_validity.c \
		src/parsing/config.c

CFLAGS = -Wall -Wextra -Werror
NAME = cub3D
OBJS = $(CFILE:.c=.o)

GREEN   := \033[0;32m
YELLOW  := \033[0;33m
RESET   := \033[0m

MINILIBX = minilibx-linux/libmlx.a
MINILIBX_OBJ = minilibx-linux/obj
INCLUDES = -I libmlx.a

all: $(MINILIBX) $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(GREEN)[Compilation] Compilation principal ...$(RESET)\n\n"
	cc $(OBJS) $(FLAG) -o $(NAME) -L -I -lmlx_Linux -Lminilibx-linux -lXext -lX11 -lm

%.o: %.c
	cc -c $(FLAG) $(INCLUDES) $< -o $@

$(MINILIBX):
	@printf "\n$(GREEN)[Compilation] Compilation minilibx ...$(RESET)\n\n"
	$(MAKE) -C minilibx-linux

clean:
	@printf "\n$(YELLOW)[Nettoyage] Nettoyage fichiés objets ...$(RESET)\n\n"
	$(RM) $(OBJS)
	$(RM) $(BOBJS)
	$(MAKE) -C minilibx-linux clean

fclean: clean
	@printf "\n$(YELLOW)[Nettoyage] Nettoyage global ...$(RESET)\n\n"
	$(RM) $(NAME)
	$(RM) $(OBJS)
	$(MAKE) -C minilibx-linux clean

re: fclean all

.PHONY: all clean fclean re

#-lmlx -lXext -lX11