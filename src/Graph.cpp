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
    }
    if (mapper.find(to) == mapper.end()) {
        mapper[to] = vertexCount++;
    }

    while (adjacencyList.size() < vertexCount) {  // Newly mapped objects are being added
        Webpage webpageObject;
        webpageObject.rank = (double) 0;
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

int Graph::getRank(std::string url) {
    adjacencyList[mapper[url]]
}

