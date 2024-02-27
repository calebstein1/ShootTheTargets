TARGET = bin/ShootTheTargets
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

default: $(TARGET)

run: default
	bin/ShootTheTargets

clean:
	rm -f obj/*.o
	rm -f bin/*

$(TARGET): $(OBJ)
	mkdir -p bin
	cc -o $@ $? -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

obj/%.o: src/%.c
	mkdir -p obj
	cc -c $< -o $@ -Iinclude
