cmake_minimum_required(VERSION 3.9)
project(libft VERSION 0.0.1 LANGUAGES C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Werror -Wall")

add_library(libft
        ft_memset.c 
        ft_bzero.c
        ft_memcpy.c
        ft_memccpy.c
        ft_memmove.c
        ft_memchr.c
        ft_memcmp.c
        ft_strlen.c
        ft_strdup.c
        ft_strcpy.c
        ft_strncpy.c
        ft_strcat.c
        ft_strncat.c
        ft_strlcat.c
        ft_strchr.c
        ft_strrchr.c
        ft_strstr.c
        ft_strnstr.c
        ft_strcmp.c
        ft_strncmp.c
        ft_atoi.c
        ft_isalpha.c
        ft_isdigit.c
        ft_isalnum.c
        ft_isascii.c
        ft_isprint.c
        ft_toupper.c
        ft_tolower.c
        ft_memalloc.c
        ft_memdel.c
        ft_strnew.c
        ft_strdel.c
        ft_strclr.c
        ft_striter.c
        ft_striteri.c
        ft_strmap.c
        ft_strmapi.c
        ft_strequ.c
        ft_strnequ.c
        ft_strsub.c
        ft_strjoin.c
        ft_strtrim.c
        ft_strsplit.c
        ft_itoa.c
        ft_putchar.c
        ft_putstr.c
        ft_putendl.c
        ft_putnbr.c
        ft_putchar_fd.c
        ft_putstr_fd.c
        ft_putendl_fd.c
        ft_putnbr_fd.c
        ft_lstnew.c
        ft_lstdelone.c
        ft_lstdel.c
        ft_lstadd.c
        ft_lstiter.c
        ft_lstmap.c
        ft_islower.c
        ft_isupper.c
        ft_strrev.c
        ft_intcount.c
        ft_triabulles.c
        get_next_line.c
        multi_split.c
        ft_long_atoi.c
        ft_printf/fd_printf.c
        ft_printf/flag_parsing2.c
        ft_printf/ft_printf.c
        ft_printf/itoa_base_s.c
        ft_printf/itoa_base_u.c
        ft_printf/make_flags.c
        ft_printf/make_s_c.c
        ft_printf/precision.c
        ft_printf/run_big_c.c
        ft_printf/run_big_s.c
        ft_printf/start_processing.c
        ft_printf/processing.c
        ft_printf/struct_management.c
        ft_printf/trees.c
        ft_printf/width_for_chr.c
        ft_printf/width.c)

set_target_properties(libft PROPERTIES
        C_STANDARD 99
        OUTPUT_NAME "ft"
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

target_include_directories(libft PRIVATE ${CMAKE_CURRENT_LIST_DIR} PUBLIC ${CMAKE_CURRENT_LIST_DIR})