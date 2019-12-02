.PHONY: all clean fclean re

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
PATH_OBJ = ./obj/
PATH_SRC = ./src/
PATH_INC = ./includes/

HEADER = $(PATH_INC)libft.h
HEADER2 = $(PATH_INC)ft_printf.h

#******************************************************************************#
#                              LIB FILES                                       #
#******************************************************************************#

FILES = ft_atoi \
		ft_bzero \
		ft_intcount \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_islower \
		ft_isprint \
		ft_isupper \
		ft_itoa \
		ft_long_atoi \
		ft_lstadd \
		ft_lstdel \
		ft_lstdelone \
		ft_lstiter \
		ft_lstmap \
		ft_lstnew \
		ft_memalloc \
		ft_memccpy \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memdel \
		ft_memmove \
		ft_memrev \
		ft_memset \
		ft_putchar \
		ft_putchar_fd \
		ft_putendl \
		ft_putendl_fd \
		ft_putnbr \
		ft_putnbr_fd \
		ft_putstr \
		ft_putstr_fd \
		ft_strcat \
		ft_strchr \
		ft_strclr \
		ft_strcmp \
		ft_strcpy \
		ft_strdel \
		ft_strdup \
		ft_strequ \
		ft_striter \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlen \
		ft_strmap \
		ft_strmapi \
		ft_strncat \
		ft_strncmp \
		ft_strncpy \
		ft_strnequ \
		ft_strnew \
		ft_strnstr \
		ft_strrchr \
		ft_strrev \
		ft_strsplit \
		ft_strstr \
		ft_strsub \
		ft_strtrim \
		ft_tolower \
		ft_toupper \
		ft_triabulles \
		get_next_line \
		multi_split \
		ft_printf/fd_printf \
		ft_printf/flag_parsing2 \
		ft_printf/ft_printf \
		ft_printf/itoa_base_s \
		ft_printf/itoa_base_u \
		ft_printf/make_flags \
		ft_printf/make_s_c \
		ft_printf/precision \
		ft_printf/processing \
		ft_printf/run_big_c \
		ft_printf/run_big_s \
		ft_printf/start_processing \
		ft_printf/struct_management \
		ft_printf/trees \
		ft_printf/width \
		ft_printf/width_for_chr

OBJ = $(addprefix $(PATH_OBJ), $(addsuffix .o , $(FILES)))
SRC = $(addprefix $(PATH_SRC), $(addsuffix .c , $(FILES)))


#******************************************************************************#
#                                    RULES                                     #
#******************************************************************************#

all: $(NAME)

$(NAME): $(PATH_OBJ) $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(NAME) has been created"

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(HEADER) $(HEADER2)
	@$(CC) $(CFLAGS) -I $(PATH_INC) -c $< -o $@

$(PATH_OBJ):
	@mkdir -p $(PATH_OBJ)
	@mkdir -p $(PATH_OBJ)ft_printf/

clean:
	@printf "\n\033[1m SUPPRESSION DES OBJETS\033[0m\n"
	@rm -rf $(PATH_OBJ)

fclean: clean
	@printf "\n\033[1mSUPPRESSION DE $(NAME)\033[0m\n"
	@rm -rf $(NAME)
	@rm -rf $(PATH_OBJ)

re: fclean all
	@echo "$(NAME) is fresh new"