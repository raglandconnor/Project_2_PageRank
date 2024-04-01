//
// Created by Connor Ragland on 3/24/24.
//

#include "Graph.h"


Graph::Graph() {
    this->vertexCount = 0;
    this->numPowerIterations = 0;
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
    adjacencyList[mapper[from]].outPages.push_back(to);
    adjacencyList[mapper[to]].inPages.push_back(from);
}


void Graph::PageRank(int p) {  // Computes 'p' number of power iterations
    for (int i = 1; i <= p; i++) {
        numPowerIterations++;
        if (numPowerIterations == 1) {  // First power iteration
            for (const auto& webpage : adjacencyList) {
                rankMapper[webpage.url] = 1.0f / (double)vertexCount;
            }
        }
        else {  // power iteration >= 2
            map<string, double> tempRankMapper = rankMapper;

            for (const auto& webpage: adjacencyList) {
                // Initialize new rank mapper
                tempRankMapper[webpage.url] = 0;

                for (const auto& inPage : webpage.inPages) {
                    tempRankMapper[webpage.url] += rankMapper[inPage] / (double)adjacencyList[mapper[inPage]].outPages.size();
                }
            }

            rankMapper = tempRankMapper;
        }
    }
}


void Graph::PrintRanks() {  // Prints ranks in alphabetical order
    for (const auto& webpage : rankMapper) {
        cout << webpage.first << " " << fixed << setprecision(2) << webpage.second << endl;
    }
}


// Catch2 Testing Function: Returns a string that contains the text output of all the page ranks
string Graph::getStringRepresentation() {
    string listRanks;

    for (const auto& webpage : rankMapper) {
        stringstream ss;
        ss << fixed << setprecision(2) << webpage.second;
        string rankString = ss.str();

        listRanks += webpage.first + " " + rankString + "\n";
    }

    return listRanks;
}


// Catch2 Testing Function: Parses a string input then computes the 'p' number of power iterations
void Graph::parseInput(Graph &graph, const std::string& input) {
    string firstLine;
    int numLines, powerIterations;

    stringstream ss(input);
    getline(ss, firstLine);

    stringstream firstLineStream(firstLine);
    for (int i = 0; i < 2; i++) {
        firstLineStream >> numLines;
        firstLineStream >> powerIterations;
    }

    for (int i = 0; i < numLines; i++) {
        string line, webpage_1, webpage_2;
        getline(ss, line);

        stringstream lineStream(line);
        lineStream >> webpage_1;
        lineStream >> webpage_2;

        graph.InsertEdge(webpage_1, webpage_2);
    }

    graph.PageRank(powerIterations);
}