#include "src/ants.cpp"

int main() {
    Ants a;
    Graph g;
    int numberOfAnts = 0;
    //g.addVertex("Sv");
    //g.addVertex("S1");
    //g.addVertex("S2");
    //g.addVertex("S3");
    //g.addVertex("S4");
    //g.addVertex("S5");
    //g.addVertex("S6");
    //g.addVertex("Sd");
    g.addVertex("Sv");
    g.addVertex("S1");
    g.addVertex("S2");
    g.addVertex("S3");
    g.addVertex("S4");
    g.addVertex("S5");
    g.addVertex("S6");
    g.addVertex("S7");
    g.addVertex("S8");
    g.addVertex("S9");
    g.addVertex("S10");
    g.addVertex("S11");
    g.addVertex("S12");
    g.addVertex("S13");
    g.addVertex("S14");
    g.addVertex("Sd");




    std::string src = g.getVertexName(g.getVertexIndex("Sv"));
    for (int i = 0; i < 5; i++) {
        // Ajout de fourmis
        a.addAnt("Ant" + to_string(i+1), &src);
        numberOfAnts++;
    }


    g.addEdge("Sv", "S1", numberOfAnts, 2);
    g.addEdge("S1", "S2", 2, 1);
    g.addEdge("S2", "S3", 2, 1);
    g.addEdge("S3", "S4", 2, numberOfAnts);
    g.addEdge("S4", "S5", 2, 1);
    g.addEdge("S6", "S7", 2, 1);
    g.addEdge("S7", "S9", 2, 1);
    g.addEdge("S9", "S14", 2, 1);
    g.addEdge("S14", "Sd", 2, numberOfAnts);
    g.addEdge("S7", "S10", 2, 1);
    g.addEdge("S10", "S14", 2, 1);
    g.addEdge("S1", "S6", 2, numberOfAnts);
    g.addEdge("S6", "S8", 2, 1);
    g.addEdge("S8", "S11", 2, 1);
    g.addEdge("S11", "S13", 2, 1);
    g.addEdge("S8", "S12", 2, 1);
    g.addEdge("S12", "S13", 2, 1);
    g.addEdge("S2", "S6", 1, numberOfAnts);
    g.addEdge("S13", "Sd", 1, numberOfAnts);


    g.printGraphBinaryTree();

    a.simulateAnts("Sv", "Sd", g);


    return 0;
}