# ASIGNATURA: ALGORITMOS
# PRÁCTICA: Ordenacion por insercion y ordenacion shell
# FECHA DE ENTREGA: 21/09/23
# INTEGRANTES: ALEJANDRO COUTO NICOLAU (alejandro.couto.nicolau@udc.es)
#              DANIEL QUEIJO SEOANE (daniel.queijo.seoane@udc.es)
# 		     MIGUEL CANO MENÉNDEZ (miguel.cano@udc.es)


CC = gcc
TARGET = p1
SRCS = p1.c
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


