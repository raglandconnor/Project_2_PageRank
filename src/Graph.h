//
// Created by Connor Ragland on 3/24/24.
//

#ifndef PROJECT_2_PAGERANK_GRAPH_H
#define PROJECT_2_PAGERANK_GRAPH_H


#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <iomanip>

using namespace std;


class Graph {
private:
    struct Webpage {
        string url;
        vector<string> outPages;
        vector<string> inPages;
    };

    map<string, int> mapper;
    map<string, double> rankMapper;
    vector<Webpage> adjacencyList;
    int vertexCount;  // Stores how many unique vertices are in the graph

public:
    Graph();
    void InsertEdge(string from, string to);
    void PageRank(int p);
    void PrintRanks();
};


#endif //PROJECT_2_PAGERANK_GRAPH_H
