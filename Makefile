SRC_DIR=src
SRC_NAME=$(notdir $(wildcard $(SRC_DIR)/*.c))
OBJ_DIR=obj
INCLUDE_DIR=include
CFLAGS=-Wall -Wextra -Werror
LIB_NAME=libftprintf.a
LIBFT_NAME=libft.a
LIBFT_DIR=libft

OBJ=$(addprefix $(OBJ_DIR)/,$(SRC_NAME:.c=.o))
LIBFT=$(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME))

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDE_DIR)


main: main.c $(LIB_NAME) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ -c $< -L. -L$(LIBFT_DIR) -l$(LIBFT_NAME) -l$(LIB_NAME) -I$(INCLUDE_DIR)

.PHONY: clean
clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(LIB_NAME)
	make -C $(LIBFT_DIR)

.PHONY: re
re: fclean all
