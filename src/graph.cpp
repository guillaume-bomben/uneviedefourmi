#include "../include/graph.h"

Graph::Graph(){}
Graph::~Graph(){}

// Ajouter un sommet
void Graph::addVertex(string v) {
    vertexList.push_back(v);
}

// Ajouter une arête avec poids
void Graph::addEdge(string v1, string v2, int weight1 , int weight2) {
    edgeList[{v1, v2}] = weight2;
    edgeList[{v2, v1}] = weight1;  // Graphe non orienté
}

// Afficher le graphe
void Graph::printGraph() {
    for (auto const& [v, adj] : edgeList) {
        cout << v.first << " - " << v.second << " : " << adj << endl;
    }
}

// Supprimer un sommet
void Graph::removeVertex(string v) {
    vertexList.erase(remove(vertexList.begin(), vertexList.end(), v), vertexList.end());

    // Supprimer toutes les arêtes connectées au sommet
    for (auto it = edgeList.begin(); it != edgeList.end();) {
        if (it->first.first == v || it->first.second == v) {
            it = edgeList.erase(it);
        } else {
            ++it;
        }
    }
}

// Supprimer une arête
void Graph::removeEdge(string v1, string v2) {
    edgeList.erase({v1, v2});
    edgeList.erase({v2, v1});
}

// Obtenir l’index d’un sommet dans la liste
int Graph::getVertexIndex(string v) {
    auto it = find(vertexList.begin(), vertexList.end(), v);
    if (it != vertexList.end()) {
        return distance(vertexList.begin(), it);
    }
    return -1;  // Retourne -1 si le sommet n'existe pas
}

// Algorithme de Dijkstra
vector<string> Graph::shortestPath(string src, string dest) {

    // Initialisation
    map<string, int> dist;
    map<string, string> prev;
    for (string v : vertexList) {
        dist[v] = numeric_limits<int>::max();
        prev[v] = "";
    }
    dist[src] = 0;

    // File de priorité
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push({0, src});

    // Boucle principale
    while (!pq.empty()) {
        string u = pq.top().second;
        pq.pop();

        for (auto const& [edge, weight] : edgeList) {
            string v = edge.second;
            if (edge.first == u) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    // Affichage du chemin le plus court
    string u = dest;
    vector<string> path;
    while (u != "") {
        path.push_back(u);
        u = prev[u];
    }
    reverse(path.begin(), path.end());
    cout << "Chemin le plus court de " << src << " a " << dest << " : ";
    for (string v : path) {
        cout << v << " ";
    }
    cout << endl;
    cout << "Distance : " << dist[dest] << endl;

    return path;
}

