NAME = ./libft.a
INCLUDES = includes
SRC_DIR = src/
OBJ_DIR = obj/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I
RM = rm -f
AR = ar rcs

IS_DIR = is_fns/
IS_FNS = ft_isalnum ft_isalpha ft_isascii \
		ft_isdigit ft_isprint

STR_DIR = str_fns/
STR_FNS = ft_count_words ft_split ft_strchr \
		ft_strdup ft_striteri ft_strjoin \
		ft_strlcat ft_strlcpy ft_strlen \
		ft_strmapi ft_strncmp ft_strnstr \
		ft_strrchr ft_strtrim ft_substr

CONV_DIR = convert_fns/
CONV_FNS = ft_atoi ft_itoa ft_tolower \
		ft_toupper ft_max ft_abs ft_atoi_base

PUT_FD_DIR = put_fd_fns/
PUT_FD_FNS = ft_putchar_fd ft_putendl_fd ft_putnbr_fd \
		ft_putstr_fd

MEM_DIR = mem_fns/
MEM_FNS = ft_bzero ft_calloc ft_memchr \
		ft_memcmp ft_memcpy ft_memmove \
		ft_memset

LST_DIR = lst_fns/
LST_FNS = ft_lstadd_back ft_lstadd_front ft_lstclear \
		ft_lstdelone ft_lstiter ft_lstlast \
		ft_lstmap ft_lstnew ft_lstsize

PRINTF_DIR = ft_printf/
PRINTF_FNS = ft_printf ft_print_types

GNL_DIR = ft_gnl/
GNL_FNS = get_next_line get_next_line_utils

SRC_FILES+=$(addprefix $(IS_DIR),$(IS_FNS))
SRC_FILES+=$(addprefix $(STR_DIR),$(STR_FNS))
SRC_FILES+=$(addprefix $(CONV_DIR),$(CONV_FNS))
SRC_FILES+=$(addprefix $(PUT_FD_DIR),$(PUT_FD_FNS))
SRC_FILES+=$(addprefix $(MEM_DIR),$(MEM_FNS))
SRC_FILES+=$(addprefix $(LST_DIR),$(LST_FNS))
SRC_FILES+=$(addprefix $(PRINTF_DIR),$(PRINTF_FNS))
SRC_FILES+=$(addprefix $(GNL_DIR),$(GNL_FNS))

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJSF = .cache_exists

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJSF)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSF):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(IS_DIR)
	@mkdir -p $(OBJ_DIR)$(STR_DIR)
	@mkdir -p $(OBJ_DIR)$(CONV_DIR)
	@mkdir -p $(OBJ_DIR)$(PUT_FD_DIR)
	@mkdir -p $(OBJ_DIR)$(MEM_DIR)
	@mkdir -p $(OBJ_DIR)$(LST_DIR)
	@mkdir -p $(OBJ_DIR)$(PRINTF_DIR)
	@mkdir -p $(OBJ_DIR)$(GNL_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) -f $(OBJSF)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norm:
	@norminette $(SRCS) $(INCLUDES) | grep -v Norme -B1 || true

