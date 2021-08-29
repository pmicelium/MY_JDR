NAME = libft.lib
DIR_NAME = Libft


## Sources ##
SRCS_DIR = C:\Users\Admin\Desktop\jdr\lib\libft/srcs/
SRCS_NAME = exit_cause.c\
			ft_abs.c\
			ft_atof.c\
			ft_atoi.c\
			ft_atoi_base.c\
			ft_atoi_tab.c\
			ft_bzero.c\
			ft_display_file.c\
			ft_free_tab.c\
			ft_free_tab_int.c\
			ft_free_tab_size.c\
			ft_intlen.c\
			ft_intlen_base.c\
			ft_is_base.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_dbtoa.c\
			ft_itoa_base.c\
			ft_lstadd.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_lstsrch.c\
			ft_memalloc.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_nbrmax.c\
			ft_nbrmin.c\
			ft_printlst_char.c\
			ft_printtab_char.c\
			ft_printtab_int.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_background.c\
			ft_putendl_color.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_endl.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_background.c\
			ft_putstr_color.c\
			ft_putstr_fd.c\
			ft_rm_path.c\
			ft_round.c\
			ft_str_contains_num.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strchr_rev.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strjoin_free.c\
			ft_strjoin_free_2.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_strupper.c\
			ft_strlower.c\
			ft_swap.c\
			ft_tolower.c\
			ft_toupper.c\
			get_next_line.c\
			gnl.c \
			exit_char.c 
			 
SRCS = $(addprefix $(SRCDIR), $(SRCS_NAME))

## Includes ##
INC = C:\Users\Admin\Desktop\jdr\lib\libft/includes/
INCS = C:\Users\Admin\Desktop\jdr\lib\libft/includes/get_next_line.h ./includes/libft.h

## Objects ##
OBJS_DIR = C:\Users\Admin\Desktop\jdr\lib\libft\objets\\

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

## Flags ##
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
	@echo "Creating $(DIR_NAME)'s objects with flag : $(CFLAGS)"

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c $(INCS)
	@echo "Creating	$@"
	@$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<

$(NAME) : $(OBJS)
	@echo "$(DIR_NAME)'s objects created"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@powershell write-host -ForegroundColor green "$(NAME) created"

clean :
	@powershell Remove-Item -r -fo //?/$(OBJS_DIR)
	@echo "$(DIR_NAME)'s objets removed"

fclean : clean
	@powershell Remove-Item -r -fo //?/C:\Users\Admin\Desktop\jdr\lib\libft\$(NAME)
	@echo "$(NAME) removed"

re : fclean all

.PHONY : all clean fclean re