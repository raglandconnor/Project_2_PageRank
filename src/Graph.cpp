//
// Created by Connor Ragland on 3/24/24.
//

#include "Graph.h"

//int Graph::numVertices() {
//
//}
//
//int Graph::numEdges() {
//
//}
//
//Graph::Graph() {
//
//}
//
//Graph::Graph(int vertexCount) {
//
//}
//
//Graph::~Graph() {
//
//}

void Graph::insertEdge(std::string from, std::string to) {
    if (mapper.find(from) == mapper.end()) {
        mapper[from] = vertexCount++;
        rankMapper[from] = 0;
        Webpage webpageObject;
        webpageObject.url = from;
        adjacencyList.push_back(webpageObject);
    }
    if (mapper.find(to) == mapper.end()) {
        mapper[to] = vertexCount++;
        rankMapper[to] = 0;
        Webpage webpageObject;
        webpageObject.url = to;
        adjacencyList.push_back(webpageObject);
    }

    adjacencyList[mapper[from]].outPages.insert(to);
    adjacencyList[mapper[to]].inPages.insert(from);
}


//void Graph::removeEdge(std::string from, std::string to) {
//
//}
//
//bool Graph::isEdge(std::string from, std::string to) {
//
//}

//double Graph::getRank(std::string url) {
//    return adjacencyList[mapper[url]].rank;
//}

void Graph::performPowerIterations(int p) {
    for (int i = 1; i <= p; i++) {
        if (i == 1) {  // First power iteration
            for (auto webpage : adjacencyList) {
                if (webpage.inPages.empty() == 1) {
                    rankMapper[webpage.url] = 0.0f;
                }
                else {
                    rankMapper[webpage.url] = 1.0f / (double)vertexCount;
                }
            }
        }
        else {  // p >= 2
            map<string, double> tempRankMapper = rankMapper;
            for (auto webpage: adjacencyList) {
                tempRankMapper[webpage.url] = 0;
                for (auto inPage : webpage.inPages) {
                    tempRankMapper[webpage.url] += rankMapper[inPage] / (double)adjacencyList[mapper[inPage]].outPages.size();
                }
            }

            rankMapper = tempRankMapper;
        }
    }
}