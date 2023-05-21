CFLAGS=-Wall -Wextra -Werror
INCLUDE_DIR=include
SRC_DIR=src
SRC_NAME=$(notdir $(wildcard $(SRC_DIR)/*.c))
OBJ_DIR=obj
LIB_DIR=.
LIB_NAME=libftprintf.a
LIBFT_DIR=libft
LIBFT_NAME=libft.a
MAIN_SRC=main.c

OBJ=$(addprefix $(OBJ_DIR)/,$(SRC_NAME:.c=.o))
LIBFT=$(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME))
LIB=$(addprefix $(LIB_DIR)/,$(LIB_NAME))

all: $(LIB_NAME)

$(LIB): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(LIB)
	$(AR) rs $@ $(OBJ)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

main: $(MAIN_SRC) $(LIB) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -L$(LIB_DIR) -l$(LIB) -o $@ $^

.PHONY: clean
clean:
	$(RM) $(OBJ)
	make -C $(LIBFT_DIR) clean

.PHONY: fclean
fclean: clean
	$(RM) $(LIB)
	make -C $(LIBFT_DIR) fclean

.PHONY: re
re: fclean all
