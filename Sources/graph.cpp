/*
 * Trabalho 1 da Disciplina: Algoritimo e Estrutura de Dados II
 * Curso: Bacharelado em Sistemas de Informação
 * ICMC - USP - 1/2018
 */

/*
 * File:   graph.cpp
 * Author: Brendon Hudson
 *
 * Created on 14 de Abril de 2018, 12:33
 */

#include "graph.hpp"
#include <iostream>
#include <vector>
#include <stack>


Graph::Graph(int numberOfVertices)
{
    this -> numberOfVertices = numberOfVertices;
    adjacence = new weight_t*[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++) {
        adjacence[i] = new weight_t[numberOfVertices]();
    }
}


void Graph::addArc(int v, int w)
{
    Graph::addArc(v, w, 1);
}


/**
 * Lines of Adjacence Matrix is v vertices (source), and your Rows is w
 * vertices, target.
 * @param v: source vertex index
 * @param w: target vertex index
 * @param weight: weight of path v->w
 */
void Graph::addArc(int v, int w, weight_t weight)
{
    adjacence[v][w] = weight;
    numberOfEdges++;
}


void Graph::removeArc(int v, int w)
{
    adjacence[v][w] = 0;
}


int Graph::getNumberOfEdges()
{
    return numberOfEdges;
}

int Graph::getNumberOfVertex()
{
    return numberOfVertices;
}


/**
 * DFS Algorithm.
 * @param vertex: vertex that init way
 */
void Graph::dfs(int vertex)
{
    int i;
    visited_list[vertex] = true;

    for (i = 0; i < numberOfVertices; i++) {
        if (adjacence[vertex][i] && not visited_list[i]) {
            Graph::dfs(i);
        }
    }
}

/**
 * Get number of Conexal Components in the Graph using DFS to way in the graph.
 * @return: number of components
 */
int Graph::getNumberOfComponents()
{
    int i, n_components = 0;
    //Vertex curr_vertex;
    visited_list = new bool[numberOfVertices]();

    // Call DFS until visit all vertex
    for (i = 0; i < numberOfVertices; i++) {
        if (not visited_list[i]) {
            dfs(i);
            n_components++;
        }
    }

    delete[] visited_list;
    visited_list = __null;

    return n_components;
}



/**
 * Lexical Topological Sort using BFS to percurse.
 * @return: path (vector with Topological Sort of graph)
 */
std::vector<int> Graph::topoSortLexBFS()
{
    int i, j, curr_v, *predecessor_count = new int[numberOfVertices]();
    std::stack<int> stack;
    std::vector<int> path;
    path.reserve(numberOfVertices);

    // First step, search all roots
    for (i = numberOfVertices-1; i >= 0; i--) {
        for (j = 0; j < numberOfVertices; j++) {
            if (adjacence[j][i]) {
                predecessor_count[i]++;
            }
        }
        // If no have predecessor, push, is a root vertex
        if (not predecessor_count[i]) {
            stack.push(i);
        }
    }

    // Second step, bfs
    while (not stack.empty()) {
        curr_v = stack.top();
        path.push_back(curr_v);
        stack.pop();

        // Push to stack yours adjacences
        for (i = numberOfVertices; i >= 0; i--) {
            if (adjacence[curr_v][i]) {
                predecessor_count[i]--;
                if (not predecessor_count[i]) {
                    stack.push(i);
                }
            }
        }

    }

    delete[] predecessor_count;

    // Final step, return path
    return path;
}



int * Graph::dijkstra()
{
    return __null;
}


Graph::~Graph() {
}
