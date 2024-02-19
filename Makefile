all:
	cc raylib.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run:
	cc Game.c TargetsList.c InputHandler/InputHandler.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	./a.out

clean:
	rm -f a.out
