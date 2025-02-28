#include "src/ants.cpp"

int main() {
    Ants a;
    Graph g;
    int numberOfAnts = 0;
    g.addVertex("Sv");
    g.addVertex("S1");
    g.addVertex("S2");
    g.addVertex("Sd");




    std::string src = g.getVertexName(g.getVertexIndex("Sv"));
    for (int i = 0; i < 5; i++) {
        // Ajout de fourmis
        a.addAnt("Ant" + to_string(i+1), &src);
        numberOfAnts++;
    }

    g.addEdge("Sv", "S1", numberOfAnts, 2);
    g.addEdge("S1", "S2", 2, 1);
    g.addEdge("S2", "Sd", 1 ,numberOfAnts);

    a.simulateAnts("Sv", "Sd", g);

    return 0;
}