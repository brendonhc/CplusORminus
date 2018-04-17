#include "Headers/AdjacenceList.hpp"
#include <iostream>


// using namespace Headers\/AdjacenceList;

int main(int argc, char const *argv[]) {
	AdjacenceList<float>::AdjacenceList()<float> adj;
	
	adj.insertAdj(5, 2.999);
	adj.insertAdj(2, 3.1415);

	std::cout << adj.removeAdj(5, 2.999);

	return 0;
}
