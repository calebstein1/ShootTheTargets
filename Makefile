TARGET = bin/ShootTheTargets
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

default: $(TARGET)

clean:
	rm -f obj/*.o
	rm -f bin/*

$(TARGET): $(OBJ)
	cc -o $@ $? -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

obj/%.o: src/%.c
	cc -c $< -o $@ -Iinclude
