#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Read first num of lines n from input
    int n;
    cin >> n;

    // Read num of power iterations p from input
    int p;
    cin >> p;

    // For the next n lines, read in the vertices from and to
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        istringstream in(line);

        // Read source vertex
        string from;
        in >> from;

        // Read destination vertex
        string to;
        in >> to;

        // Add vertices/edge(from->to) to your adjacency list here:

    }

    // Do power iterations here:


    return 0;
}
