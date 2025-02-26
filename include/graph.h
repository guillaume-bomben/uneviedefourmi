#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


class Graph {
    public:
        Graph();
        ~Graph();
        void addEdge(int v1, int v2);
        void removeEdge(int v1, int v2);
        void addVertex(int v);
        void removeVertex(int v);
        void printGraph();
    private:
        std::map<int, std::vector<int>> adjList;
};