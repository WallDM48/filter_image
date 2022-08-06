build:
	mkdir build
	gcc -c filter_image.c
	gcc -c main.c
	gcc filter_image.o main.o -o filter_image
	mv filter_image.o main.o filter_image ./build

clean:
	rm -r ./build