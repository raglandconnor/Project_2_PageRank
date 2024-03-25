//
// Created by Connor Ragland on 3/24/24.
//

#ifndef PROJECT_2_PAGERANK_GRAPH_H
#define PROJECT_2_PAGERANK_GRAPH_H


#include <string>
#include <map>
using namespace std;

class Graph {
private:
    map<string, int> keys;
    vector<pair<string, int>> adjacencyList;

    int vertexCount;  // Stores how many vertices are in the graph

    vector<string> getAdjacent(string vertex);

    int numVertices();  // Returns number of vertices
    int numEdges();  // Returns number of edges

public:
    Graph();
    Graph(int vertexCount);  // Creates graph with V vertices
    ~Graph();  // Destructor

    void insertEdge(string from, string to, int weight);
    void removeEdge(string from, string to);
    bool isEdge(string from, string to);
    int getWeight(string from, string to);
};


#endif //PROJECT_2_PAGERANK_GRAPH_H
