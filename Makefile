all:
	cc src/Game.c src/TargetsList.c src/InputHandler/InputHandler.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run:
	cc src/Game.c src/InputHandler/InputHandler.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	./a.out

clean:
	rm -f a.out
