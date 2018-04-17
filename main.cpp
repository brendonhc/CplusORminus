/*
 * Trabalho 1 da Disciplina: Algoritimo e Estrutura de Dados II
 * Curso: Bacharelado em Sistemas de Informação
 * ICMC - USP - 1/2018
 */

/*
 * File:   graph.hpp
 * Author: Brendon Hudson
 *
 * Created on 14 de Abril de 2018, 12:33
 */

#include <cstdlib>
#include <iostream>
#include "graph.hpp"


using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    int step, numberOfVertices, numberOfEdges, v, w;
    std::vector<int> topoSortLex;
    Graph *graph;

    cin >> step;
    cin >> numberOfVertices >> numberOfEdges;

    graph = new Graph(numberOfVertices);

    // Leitura das arestas
    for (int i = 0; i < numberOfEdges; i++) {
        cin >> v;
        cin >> w;
        graph->addArc(v-1, w-1);
    }

    topoSortLex = graph->topoSortLexBFS();

    // Impressão da saída da parte 1
    for (int i = 0; i < numberOfVertices-1; i++) {
        cout << topoSortLex[i]+1 << " ";
    }
    cout << topoSortLex[numberOfVertices-1]+1 << endl;

    return 0;
}
