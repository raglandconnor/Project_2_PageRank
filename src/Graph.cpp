//
// Created by Connor Ragland on 3/24/24.
//

#include "Graph.h"


Graph::Graph() {
    this->vertexCount = 0;
}


void Graph::InsertEdge(std::string from, std::string to) {
    if (mapper.find(from) == mapper.end()) {  // Add 'from' to graph if necessary
        mapper[from] = vertexCount++;
        rankMapper[from] = 0;

        Webpage webpageObject;
        webpageObject.url = from;
        adjacencyList.push_back(webpageObject);
    }
    if (mapper.find(to) == mapper.end()) {// Add 'to' to graph if necessary
        mapper[to] = vertexCount++;
        rankMapper[to] = 0;

        Webpage webpageObject;
        webpageObject.url = to;
        adjacencyList.push_back(webpageObject);
    }

    // Update inPages & outPages for both urls
    adjacencyList[mapper[from]].outPages.insert(to);
    adjacencyList[mapper[to]].inPages.insert(from);
}


void Graph::PageRank(int p) {  // Computes 'p' number of power iterations
    for (int i = 1; i <= p; i++) {
        if (i == 1) {  // First power iteration
            for (const auto& webpage : adjacencyList) {
                rankMapper[webpage.url] = 1.0f / (double)vertexCount;
            }
        }
        else {  // power iteration >= 2
            map<string, double> tempRankMapper = rankMapper;

            for (const auto& webpage: adjacencyList) {
                tempRankMapper[webpage.url] = 0;

                for (const auto& inPage : webpage.inPages) {
                    tempRankMapper[webpage.url] += rankMapper[inPage] / (double)adjacencyList[mapper[inPage]].outPages.size();
                }
            }

            rankMapper = tempRankMapper;
        }
    }
}


void Graph::PrintRanks() {
    for (const auto& webpage : rankMapper) {
        cout << webpage.first << " " << fixed << setprecision(2) << webpage.second << endl;
    }
}