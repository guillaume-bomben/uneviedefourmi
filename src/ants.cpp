#include "../include/ants.h"

Ants::Ants(){}
Ants::~Ants(){}

// void Ants::addAnt(string name, string* roomName) {
//     antsList[name] = roomName;
// }

void Ants::addAnt(string name, string* roomName) {
    antsList[name] = roomName;
}

void Ants::removeAnt(string name) {
    antsList.erase(name);
}

void Ants::printAnts() {
    for (auto const& [name, roomName] : antsList) {
        cout << name << " : " << *roomName << endl;
    }
    cout << "########################################" << endl;
}

void Ants::moveAnt(string name, string* roomName) {
    antsList[name] = roomName;
}




void Ants::simulateAnts(string src, string dest, Graph g) {
    vector<string> path =  g.shortestPath(src, dest);
    int AntsArrived = 0;
    int currentRoomCapacity = 0;
    
    while (AntsArrived != antsList.size()) {
        for (int i = 1; i < path.size(); i++) {
            currentRoomCapacity = antsList.count(path[i]);
            for (auto const& [name, roomName] : antsList) {
                if (g.getEdgeWeight(path[0], path[1]) == currentRoomCapacity){
                    cout << "Room is full" << endl;
                    break;
                }
                moveAnt(name, &path[i]);
                currentRoomCapacity++;
                printAnts();
                if (path[i] == dest) {
                    AntsArrived++;
                }
                
            }
        }
    }

}