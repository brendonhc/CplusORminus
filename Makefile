all: main.cpp Sources/AdjacenceList.cpp
	g++ main.cpp Sources/AdjacenceList.cpp -o exe -g

run:
	./exe

clean:
	rm -rf exe *.o
