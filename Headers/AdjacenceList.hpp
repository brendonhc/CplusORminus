#ifndef _ADJLIST_HPP_
#define _ADJLIST_HPP_

#include <vector>

/*
 * Header que descreve a Classe Template AdjacenceList, referente ao TAD Lista
 * de adjacências, muito utilizado para representar Grafos.
 * A implementação proposta visa criar uma Lista de "Vectors" da STL usando
 * template, assim como a classe vector também utiliza.
 *
 */
template <class Type>
class AdjacenceList {
private:
	std::vector<Type> adjList;

public:
	// Constructors
	AdjacenceList();
	AdjacenceList(int);

	// Métodos Getters e Setters
	int getSize();
	void insertAdj(int source, Type element);
	Type removeAdj(int source, Type element);
	bool searchAdj(int source, Type element);
};


#endif
