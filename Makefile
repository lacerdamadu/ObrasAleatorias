CC = gcc
CFLAGS = -Wall -Wextra
TARGET = Obra
SRC = main.c Menu.c Obra.c
OBJ = $(SRC:.c=.o)
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(TARGET)
.PHONY: clean
