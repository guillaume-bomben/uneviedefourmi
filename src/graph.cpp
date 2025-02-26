#include "../include/Graph.h"

Graph::Graph(){}
Graph::~Graph(){}

void Graph::addVertex(int v) {
    adjList[v] = {};
}

// Graph_Class::removeVertex(int v) {
//     adjList.erase(v);
// }

void Graph::addEdge(int v1, int v2) {
    adjList[v1].push_back(v2);
    adjList[v2].push_back(v1);
}

void Graph::printGraph() {
    for (auto const& [v, adj] : adjList) {
        std::cout << v << ": ";
        for (auto const& a : adj) {
            std::cout << a << " ";
        }
        std::cout << std::endl;
    }
}

