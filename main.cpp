#include "src/Graph.cpp"

int main() {
    Graph g;
    g.addVertex("1");
    g.addVertex("2");
    g.addVertex("3");
    g.addVertex("4");
    g.addVertex("5");
    g.addEdge("1", "2");
    g.addEdge("1", "3");
    g.addEdge("2", "4");
    g.addEdge("3", "5");
    g.removeVertex("3");
    g.printGraph();
    return 0;
}