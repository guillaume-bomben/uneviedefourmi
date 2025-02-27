#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

class Graph {
    public:
        Graph();
        ~Graph();
        void addEdge(std::string v1, std::string v2);
        void removeEdge(std::string v1, std::string v2);
        void addVertex(std::string v);
        void removeVertex(std::string v);
        void printGraph();
        std::string getVertex(std::string i);
        std::string getEdge(std::string i, std::string j);
    private:
        std::map<std::string, std::vector<std::string>> adjList;
};