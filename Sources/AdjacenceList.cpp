#include "../Headers/AdjacenceList.hpp"
#include <iostream>

template <class Type>
AdjacenceList<Type>::AdjacenceList()
{
	AdjacenceList(0);
}

template <class Type>
AdjacenceList<Type>::AdjacenceList(int size)
{
	adjList.resize(size);
}

template <class Type>
int AdjacenceList<Type>::getSize()
{
	return adjList.size();
}

template <class Type>
void AdjacenceList<Type>::insertAdj(int source, Type element)
{
	if (source >= adjList.size()) {
		adjList.resize(source+1);
	}
	adjList[source].push_back(element);
}

template <class Type>
Type AdjacenceList<Type>::removeAdj(int source, Type element)
{
	int i;
	for (i = 0; i < adjList[source].size(); i++) {
		if (adjList[source][i] == element) {
			return adjList[source][i].push_back();
		}
	}
	return NULL;
}

template <class Type>
bool AdjacenceList<Type>::searchAdj(int source, Type element)
{
	int i;
	for (i = 0; i < adjList[source].size(); i++) {
		if (adjList[source][i] == element) {
			return true;
		}
	}
	return false;
}
