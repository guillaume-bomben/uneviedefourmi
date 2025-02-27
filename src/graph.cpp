#include "../include/Graph.h"

Graph::Graph(){}
Graph::~Graph(){}

void Graph::addVertex(std::string v) {
    adjList[v] = {};
}

void Graph::removeVertex(std::string v) {
    if (adjList.find(v) == adjList.end()) {
        return;
    }
    else {
        adjList.erase(v);
    }

    for (auto const& [vertex, adj] : adjList) {
        adjList[vertex].erase(std::remove(adjList[vertex].begin(), adjList[vertex].end(), v), adjList[vertex].end());
    }
}

void Graph::addEdge(std::string v1, std::string v2) {
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


void Graph::removeEdge(std::string v1, std::string v2) {
    adjList[v1].erase(std::remove(adjList[v1].begin(), adjList[v1].end(), v2), adjList[v1].end());
    adjList[v2].erase(std::remove(adjList[v2].begin(), adjList[v2].end(), v1), adjList[v2].end());
}

std::string Graph::getVertex(std::string i) {
    return adjList[i].front();
}

std::string Graph::getEdge(std::string i, std::string j) {
    return adjList[i].front();
}