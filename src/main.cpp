#include <iostream>

#include "Graph.h"

using namespace std;

int main() {
    int no_of_lines, power_iterations;
    string from, to;
    cin >> no_of_lines;
    cin >> power_iterations;
    Graph graph;

    for (int i = 0; i < no_of_lines; i++) {
        cin >> from;
        cin >> to;
        graph.InsertEdge(from, to);
    }
    graph.PageRank(power_iterations);
    graph.PrintRanks();
}
