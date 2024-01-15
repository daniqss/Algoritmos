CC = gcc
TARGET = p4
SRCS =  leerTiempo.c p4.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -Wall -o $(TARGET) $(OBJS) -lm

%.o: %.c
	$(CC) -Wall -c $< -lm

clean:
	rm -rf $(OBJS) $(TARGET)

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(TARGET)


