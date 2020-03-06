all:
	g++ -o bin/wolfie src/*.cpp `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image
run:
	./bin/wolfie