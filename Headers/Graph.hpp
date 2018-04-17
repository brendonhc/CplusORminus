#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include "Vertex.hpp"
#include "AdjList.hpp"

/*
 * Classe que implementa uma estrutura de Grafos em C++ como um objeto.
 * Contém 0 ou mais Listas de Adjacencias (Class AdjList)
 *
 */
class Graph {
private:
	int numberOfVertex;
	int numberOfEdges;
	int width;


public:
	void setVertex();
	int getVertex();
}

class Vertex {
	private:
		AdjList adjacences;

	public:

}

#endif
