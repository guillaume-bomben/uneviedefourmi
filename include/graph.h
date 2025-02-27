#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>
#include <algorithm>

using namespace std;

class Graph {
    public:
        Graph();
        ~Graph();
        void addVertex(string v);
        void addEdge(string v1, string v2, int weight);
        void printGraph();
        void removeVertex(string v);
        void removeEdge(string v1, string v2);
        int getVertexIndex(string v);
        vector<string> shortestPath(string src, string dest);
        string getVertexName(int i) { return vertexList[i]; }
        int getEdgeWeight(string v1, string v2) { return edgeList[{v1, v2}]; }

    private:
        vector<string> vertexList;  // Liste des sommets (nom)
        map<pair<string, string>, int> edgeList;  // Liste des arêtes avec poids
};