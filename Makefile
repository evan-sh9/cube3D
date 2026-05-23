# 

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
        src/utils/exit_free.c \
        src/utils/count_element.c \
        src/parsing/claim/claim_map.c \
        src/parsing/claim/claim_content.c \
        src/parsing/claim/claim_color.c \
        src/parsing/check/file_validity.c \
        src/parsing/check/map_validity.c \
        src/parsing/check/texture_validity.c \
        src/parsing/check/color_validity.c \
        src/parsing/player_pos.c \
        src/parsing/config/config.c \
        src/parsing/config/find_conf_color.c \
        src/parsing/debug.c \
        src/parsing/config/config_utils.c \
        src/garbage_collector/garbage_collector.c \
        src/garbage_collector/ft_lstnew.c \
        src/garbage_collector/ft_lstadd_back.c \
        src/garbage_collector/ft_calloc.c \
        src/game/algo.c \
        src/game/hook.c \
        src/game/game.c \
        src/game/utils.c \
        src/game/sword.c \
		src/game/minimap.c

CFLAGS = -Wall -Wextra -Werror
NAME = cub3D
OBJS = $(CFILE:.c=.o)

# Couleurs ANSI
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
CYAN    := \033[1;36m
RESET   := \033[0m

MINILIBX = minilibx-linux/libmlx.a
MINILIBX_OBJ = minilibx-linux/obj
INCLUDES = -Iminilibx-linux

all: $(MINILIBX)
	@printf "$(CYAN)"
	@printf "  ____ _   _ ____ _____ ____  \n"
	@printf " / ___| | | | __ )___ /|  _ \ \n"
	@printf "| |   | | | |  _ \ |_ \| | | |\n"
	@printf "| |___| |_| | |_) |__) | |_| |\n"
	@printf " \____|\___/|____/____/|____/ \n"
	@printf "$(RESET)\n"
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@printf "\n$(GREEN)[Compilation] Compilation principale ...$(RESET)\n\n"
	cc $(OBJS) $(CFLAGS) -o $(NAME) -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -g3

%.o: %.c
	cc -c $(CFLAGS) $(INCLUDES) $< -o $@

$(MINILIBX):
	@printf "\n$(GREEN)[Compilation] Compilation minilibx ...$(RESET)\n\n"
	$(MAKE) -C minilibx-linux

clean:
	@printf "\n$(YELLOW)[Nettoyage] Nettoyage fichiers objets ...$(RESET)\n\n"
	$(RM) $(OBJS)
	$(MAKE) -C minilibx-linux clean

fclean: clean
	@printf "\n$(YELLOW)[Nettoyage] Nettoyage global ...$(RESET)\n\n"
	$(RM) $(NAME)
	$(MAKE) -C minilibx-linux clean

re: fclean all

.PHONY: all clean fclean re