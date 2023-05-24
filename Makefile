CFLAGS=-Wall -Wextra -Werror
INCLUDE=-Iinclude -Ilibft
SRC_DIR=src
SRC_NAME=$(notdir $(wildcard $(SRC_DIR)/*.c))
BUILD_DIR=build
LIB_DIR=.
LIB_NAME=libftprintf.a
LIBFT_DIR=libft
LIBFT_NAME=libft.a
MAIN_SRC=main.c

$(shell mkdir -p build)
OBJ=$(addprefix $(BUILD_DIR)/,$(SRC_NAME:.c=.o))
LIBFT=$(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME))
LIB=$(addprefix $(LIB_DIR)/,$(LIB_NAME))
NAME=$(LIB)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(LIB)
	$(AR) rs $@ $(OBJ)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

main: $(MAIN_SRC) $(LIB) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) -L$(LIB_DIR) -lftprintf -o $@ $(MAIN_SRC)

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
