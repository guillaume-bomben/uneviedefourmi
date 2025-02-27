#include "../include/ants.h"

Ants::Ants(){}
Ants::~Ants(){}

// void Ants::addAnt(string name, string* roomName) {
//     antsList[name] = roomName;
// }

void Ants::addAnt(string name, string* roomName) {
    antsList[name] = {roomName, false};
    roomCapacity[*roomName]++;
}

void Ants::removeAnt(string name) {
    antsList.erase(name);
}

void Ants::printAnts() {
    for (auto const& [name, data] : antsList) {
        cout << name << " : " << *(data.first) << endl;
    }
    cout << "########################################" << endl;
}


void Ants::moveAnt(string name, string* roomName, Graph& g) {
    if (antsList[name].second) return;
    string* currentRoom = antsList[name].first;
    string nextRoom = *roomName;
    if (roomCapacity[nextRoom] >= g.getEdgeWeight(*currentRoom, nextRoom)) {
        cout << "Room " << nextRoom << " is full, " << name << " cannot move.\n";
        return;
    }
    roomCapacity[*currentRoom]--;
    roomCapacity[nextRoom]++;
    antsList[name].first = roomName;
}



void Ants::simulateAnts(string src, string dest, Graph g) {
    vector<string> path = g.shortestPath(src, dest);
    int AntsArrived = 0;

    while (AntsArrived != antsList.size()) {
        for (int i = 1; i < path.size(); i++) {
            vector<string> toMove;
            for (auto& [name, data] : antsList) {
                string* &roomName = data.first;
                bool &arrived = data.second;
                if (arrived) continue;
                if (*roomName == path[i - 1]) {
                    toMove.push_back(name);
                }
            }
            int maxCapacity = g.getEdgeWeight(path[i - 1], path[i]);
            int moved = 0;
            for (string& name : toMove) {
                if (moved >= maxCapacity) break;
                moveAnt(name, &path[i], g);
                printAnts();
                moved++;

                if (path[i] == dest) {
                    antsList[name].second = true;
                    AntsArrived++;
                }
            }
        }
    }
}

