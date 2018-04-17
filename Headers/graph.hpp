/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Graph.hpp
 * Author: brendon
 *
 * Created on 14 de Abril de 2018, 12:33
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

typedef std::pair<int, int> Vertex;
typedef std::vector<Vertex> AdjacentVertices;
typedef std::vector<AdjacentVertices> AdjacencyList;


typedef int weight_t; // Redefine if you need
typedef weight_t ** AdjacenceMatrix;

class Graph {
public:
    Graph(int numberOfVertices);
    virtual ~Graph();

    // Getters
    int getNumberOfEdges();
    int getNumberOfVertex();
    int getNumberOfComponents();

    // Algorithms that will return Graph paths
    std::vector<int> topoSortLexBFS();
    int * dijkstra();
    void addArc(int w, int v);
    void addArc(int w, int v, weight_t weight);

    void removeArc(int w, int v);


private:
    AdjacenceMatrix adjacence;

    int numberOfVertices;
    int numberOfEdges;
    bool *visited_list;

    void dfs(int source);
    bool isRoot(int vertex);
};

#endif /* GRAPH_HPP */
