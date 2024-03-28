//
// Created by Connor Ragland on 3/24/24.
//

#ifndef PROJECT_2_PAGERANK_GRAPH_H
#define PROJECT_2_PAGERANK_GRAPH_H


#include <string>
#include <map>
#include <set>
using namespace std;



class Graph {
private:
    struct Webpage {
        string url;
        set<string> outPages;
        set<string> inPages;

        double getRank() {
            if (inPages.empty()) {
                return 0.0;
            } else {
                return 1.0f / (double)inPages.size();
            }
        }
    };

    map<string, int> mapper;
    map<string, double> rankMapper;
    vector<Webpage> adjacencyList;

    int vertexCount = 0;  // Stores how many unique vertices are in the graph

    vector<string> getAdjacent(string vertex);

    int numVertices();  // Returns number of vertices
    int numEdges();  // Returns number of edges


public:
    Graph();
    Graph(int vertexCount);  // Creates graph with V vertices
    ~Graph();  // Destructor

    void insertEdge(string from, string to);
    void removeEdge(string from, string to);
    bool isEdge(string from, string to);
//    double getRank(string url);
    void performPowerIterations(int p);
};


#endif //PROJECT_2_PAGERANK_GRAPH_H
