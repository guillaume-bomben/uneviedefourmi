#include "include/graph.h"

Graph::Graph(){}
Graph::~Graph(){}

Graph::addVertex(int v) {
    adjList[v] = {};
}

// Graph::removeVertex(int v) {
//     adjList.erase(v);
// }

Graph::addEdge(int v1, int v2) {
    adjList[v1].push_back(v2);
    adjList[v2].push_back(v1);
}

Graph::printGraph() {
    for (auto const& [v, adj] : adjList) {
        std::cout << v << ": ";
        for (auto const& a : adj) {
            std::cout << a << " ";
        }
        std::cout << std::endl;
    }
}

