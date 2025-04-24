# Output file name
NAME			= cub3D

# Output file debugger name
DEBUG			= cub3D_debug


# Define sources
SRC				=	cub3D.c \
					debug/debug.c \
					debug/debug_more.c \
					exit/exit.c \
					exit/free.c \
					init/check_args.c \
					init/init_data.c \
					mlx/hooks.c \
					mlx/minimap_utils.c \
					mlx/show_minimap.c \
					mlx/window.c \
					parsing/check_contents.c \
					parsing/color_utils.c \
					parsing/handle_identifier.c \
					parsing/handle_map.c \
					parsing/handle_player.c \
					parsing/line_utils.c \
					parsing/parse_and_check.c \
					update/move_player.c \
					update/raycasting.c \
					update/textures.c

# Define dirs
SRC_DIR			= srcs/
OBJ_DIR			= objs/

# Full sources paths
SRCS			= $(addprefix $(SRC_DIR), $(SRC))

# Define targets requiring user input
INPUT_TARGETS	:= run debug

# Make flags for pretty output
export MAKEFLAGS	+= --no-print-directory

# Define uname
UNAME			= $(shell uname)

# Define libraries
LIBFT_DIR		= ./lib/libft/
LIBFT			= $(addprefix $(LIBFT_DIR), libft.a)
MAKELIBFT		= @$(ENTER_LDIR); $(MAKE) -C $(LIBFT_DIR)
MLX_DIR			= ./lib/mlx-linux/
MLX				= $(addprefix $(MLX_DIR), libmlx.a)
MAKEMLX			= @$(ENTER_MDIR); $(MAKE) -C $(MLX_DIR)

# Define object files
OBJS			= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

# Compilation message
TOT_FILES		= $(shell expr $(words $(SRC)))
COMPILED_FILES	= 0
MESSAGE			= "Compiling: $(COMPILED_FILES)/$(TOT_FILES) ($(shell expr $(COMPILED_FILES) \* 100 / $(TOT_FILES))%)"

# Text styling
GREEN			= \033[32m
RED				= \033[31m
BLUE			= \033[34m
GREY			= \033[90m
YELLOW			= \033[33m
BG_BLUE			= \033[44m
ENDCOLOR		= \033[0m
BOLD			= \033[1m

# Define arguments to use
ifneq ($(filter $(MAKECMDGOALS), $(INPUT_TARGETS)),)
ARGS				:= $(shell read -p "$(shell echo "$(YELLOW)$(BOLD)Please input your map path: $(ENDCOLOR)")" args; echo $$args)
endif

# Texts
START			= echo "$(BLUE)Compilation of $(NAME) started\n$(ENDCOLOR)"
END				= echo "$(GREEN)$(BOLD)✔ Compilation finished\n$(ENDCOLOR)"
CLEAN_MSG		= echo "$(RED)$(BOLD)✖ Deleting object files\n$(ENDCOLOR)"
FCLEAN_MSG		= echo "$(RED)$(BOLD)✖ Deleting program\n$(ENDCOLOR)"
ENTER_LDIR		= echo "$(BLUE)➜$(ENDCOLOR)$(BOLD)  Entering directory$(RESET) $(YELLOW)$(LIBFT_DIR)$(ENDCOLOR)"
LEAVE_LDIR		= echo "$(BLUE)➜$(ENDCOLOR)$(BOLD)  Leaving directory$(RESET) $(YELLOW)$(LIBFT_DIR)$(ENDCOLOR)"
ENTER_MDIR		= echo "$(BLUE)➜$(ENDCOLOR)$(BOLD)  Entering directory$(RESET) $(YELLOW)$(MLX_DIR)$(ENDCOLOR)"
LEAVE_MDIR		= echo "$(BLUE)➜$(ENDCOLOR)$(BOLD)  Leaving directory$(RESET) $(YELLOW)$(MLX_DIR)$(ENDCOLOR)"

# Define bar variables
BAR_LEN			= 70
BAR				= $(shell expr $(COMPILED_FILES) \* $(BAR_LEN) / $(TOT_FILES))

# Define includes
HEAD			= ./includes/cub3D.h

# Library creation command
AR				= ar rcs

# Cleaning command
RM				= rm -f

# Compiler / debugger
CC				= gcc
DEBUGGER		= valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --verbose --log-file=valgrind-out.txt


# Compiler / debugger flags
CFLAGS			= -Wall -Wextra -Werror -g
DFLAGS			= -ggdb3
MLXFLAGS		= -L ./lib/mlx-linux/ -lmlx -Ilmlx -lXext -lX11

# Define all
all:			start start2 $(NAME) end

# Define bonus
bonus:			all

# Define logo
logo:
				@tput setaf 5; tput bold; cat ./ascii_art/cub3D; echo "\n"; tput init;

# Define start visual
start:
				@tput setaf 4; cat ./ascii_art/Fenris;  echo "\n"; tput init;
start2:
				@tput setaf 4; cat ./ascii_art/CDRX;  echo "\n"; tput init;

# Define end visual
end:
				@tput setaf 2; tput bold; cat ./ascii_art/done; echo "\n"; tput init;

# Create object files
$(OBJ_DIR)%.o : %.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@
				$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES)+1))))
				@printf "$(BLUE)%s\r\n$(ENDCOLOR)" $(MESSAGE)
				@sleep 0.1
				@printf "$(BG_BLUE)%*s$(ENDCOLOR)\r" $(BAR) " "
				@printf "\033[F"

# Create libraries
libraries:
				@$(MAKELIBFT) all;
				@$(LEAVE_LDIR)
				@$(MAKEMLX) all;
				@$(LEAVE_MDIR)

# Create program file
$(NAME):		libraries logo $(OBJS)
				@printf "\n\n"
				@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -lm -o $(NAME)
				@$(END)

# Create program file for debugging
$(DEBUG):		libraries logo $(OBJS)
				@$(CC) $(DFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -lm -o $(DEBUG)

# Run program
run:			start start2 $(NAME) end
				./$(NAME) $(ARGS)

# Debug program
debug:			start start2 $(DEBUG) end
				@$(DEBUGGER) ./$(DEBUG) $(ARGS)


# Clean object files & if on linux rm valgrind-out.txt
clean:
				@$(CLEAN_MSG)
				@$(RM) -r $(OBJ_DIR)
				@if [ $(UNAME) = "Linux" ]; then $(RM) valgrind-out.txt; fi
				@tput setaf 1; tput bold; cat ./ascii_art/trash; tput init;
				@tput setaf 1; tput bold; cat ./ascii_art/gone; echo "\n"; tput init;
				@$(MAKELIBFT) clean;
				@$(MAKEMLX) clean;

# Clean object files and program file
fclean:			clean
				@$(FCLEAN_MSG)
				@$(RM) $(NAME)
				@$(RM) $(DEBUG)
				@tput setaf 1; tput bold; cat ./ascii_art/trash; tput init;
				@tput setaf 1; tput bold; cat ./ascii_art/all_gone; tput init;
				@$(MAKELIBFT) fclean;

# Redo everything
re:				fclean all

# Avoid collisions with files named the same as commands
.PHONY:			all clean fclean re run debug bonus
