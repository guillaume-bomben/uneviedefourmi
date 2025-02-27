#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "../src/graph.cpp"


using namespace std;

class Ants {
    public:
        Ants();
        ~Ants();
        void addAnt(string name, string* roomName);
        void removeAnt(string name);
        void printAnts();
        void moveAnt(string name, string* roomName);

        void simulateAnts(string src, string dest, Graph g);
    private:
        map<string, string*> antsList;
};