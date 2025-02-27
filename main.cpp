#include "src/Graph.cpp"

int main() {
    Graph g;
    g.addVertex("1");
    g.addVertex("2");
    g.addVertex("3");
    g.addVertex("4");
    g.addVertex("5");
    g.addVertex("6");
    g.addVertex("7");
    g.addVertex("8");
    g.addVertex("9");
    g.addVertex("15");
    g.addEdge("1", "2",1);
    g.addEdge("1", "3",1);
    g.addEdge("2", "4",1);
    g.addEdge("4", "5",1);
    g.addEdge("3", "6",1);
    g.addEdge("6", "7",1);
    g.addEdge("7", "8",1);
    g.addEdge("8", "9",1);
    g.addEdge("9", "15",1);
    g.addEdge("15", "5",1);
    g.addEdge("1", "5",1);
    g.addEdge("2", "5",1);
    g.addEdge("3", "5",1);
    g.addEdge("1", "2",1000);
    g.addEdge("1", "3",1500);
    g.addEdge("2", "4",160);
    g.addEdge("4", "5",10000);
    g.addEdge("3", "6",2000);
    g.addEdge("6", "7",10);
    g.addEdge("3", "5",1200);
    g.printGraph();
    g.shortestPath("1", "5");
    return 0;
}