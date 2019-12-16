.PHONY: all clean fclean re

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = ft_ssl
PATH_OBJ = ./obj/
PATH_SRC = ./src/
PATH_INC = ./includes/

HEADER = $(PATH_INC)$(NAME).h

#******************************************************************************#
#                              FT_SSL                                          #
#******************************************************************************#

FILES = ft_ssl \
		freeing \
		init_md5_worker \
		init_sh256_worker \
		md5 \
		parsing_hash \
		print_digest \
		process_argument \
		sha256 \
		usages \
		utils

OBJ = $(addprefix $(PATH_OBJ), $(addsuffix .o , $(FILES)))
SRC = $(addprefix $(PATH_SRC), $(addsuffix .c , $(FILES)))

#******************************************************************************#
#                                  LIBFT                                       #
#******************************************************************************#

PATH_LIB = ./libft/
PATH_INC_LIB = ./libft/
NAME_LIB = ft
INC_LIB = -L $(PATH_LIB) -l $(NAME_LIB)

#******************************************************************************#
#                                    RULES                                     #
#******************************************************************************#

all: lib $(NAME)

clean:
	@printf "\n\033[1m SUPPRESSION DES OBJETS\033[0m\n"
	@rm -rf $(PATH_OBJ)
	@make clean -C $(PATH_LIB)

fclean: clean
	@printf "\n\033[1mSUPPRESSION DE $(NAME)\033[0m\n"
	@rm -rf $(NAME)
	@rm -rf $(PATH_OBJ)
	@make fclean -C $(PATH_LIB)

re: fclean all

#******************************************************************************#
#                                  Compilation                                 #
#******************************************************************************#

lib:
	@make -C $(PATH_LIB)

$(NAME): $(PATH_OBJ) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I $(PATH_INC) $(INC_LIB) -o $(NAME)
	echo "$(NAME) has been compiled"

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(HEADER)
	$(CC) $(CFLAGS) -I $(PATH_INC) -I $(PATH_INC_LIB) -c $< -o $@

$(PATH_OBJ):
	@mkdir -p $(PATH_OBJ)