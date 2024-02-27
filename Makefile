TARGET = bin/ShootTheTargets
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))
CFLAGS=-Iinclude
LDFLAGS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all: $(TARGET)

run: all
	bin/ShootTheTargets

clean:
	rm -f obj/*.o
	rm -f bin/*

$(TARGET): $(OBJ)
	mkdir -p bin
	cc -o $@ $? $(LDFLAGS)

obj/%.o: src/%.c
	mkdir -p obj
	cc -c $< -o $@ $(CFLAGS)
