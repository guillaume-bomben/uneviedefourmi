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
    cout << "*****************************************************" << endl;
    cout << "Name of ant : " << name << endl;
    cout << "Name of current room : " << *currentRoom << endl;
    cout << "Name of next room : " << nextRoom << endl;
    cout << "Ants on Next room : " << roomCapacity[nextRoom] << endl;
    cout << "Next room capacity : " << g.getEdgeWeight(*currentRoom, nextRoom) << endl;
    cout << name << " moved from " << *currentRoom << " to " << nextRoom << endl;
    cout << "*****************************************************" << endl;
    roomCapacity[*currentRoom]--;
    roomCapacity[nextRoom]++;
    antsList[name].first = roomName;
}


void Ants::simulateAnts(string src, string dest, Graph g) {
    vector<string> path = g.shortestPath(src, dest);
    int AntsArrived = 0;

    while (AntsArrived != antsList.size()) {
        vector<string> toMove;
        for (auto& [name, data] : antsList) {
            string* &roomName = data.first;
            bool &arrived = data.second;
            if (arrived) continue;
            else {
                toMove.push_back(name);
            }
        }
        for (string& name : toMove) {
            string* currentRoom = antsList[name].first;
            auto nextRoomIndex = find(path.begin(), path.end(), *currentRoom);
            moveAnt(name, &path[nextRoomIndex - path.begin() + 1], g);
            //printAnts();
            if (path[nextRoomIndex - path.begin() + 1] == dest) {
                antsList[name].second = true;
                AntsArrived++;
            }
        }
    }
}



