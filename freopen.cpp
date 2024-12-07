#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Function to generate the graph
void generateGraph(int N, double waferDiameter, double angleIncrement) {
    double radius = waferDiameter / 2.0;
    vector<pair<double, double>> nodes;  // Store the nodes (points)
    vector<pair<int, int>> edges;       // Store the edges

    // Generate points on the wafer edge
    for (int i = 0; i < N; ++i) 
    {
        double theta = i * angleIncrement * M_PI / 180.0; // Angle in radians
        double x = radius * cos(theta);
        double y = radius * sin(theta);
        nodes.emplace_back(x, y);

        // Connect to the previous node (to form a cycle)
        if (i > 0) {
            edges.emplace_back(i - 1, i);
        }
    }
    // Connect the last node to the first to complete the cycle
    edges.emplace_back(N - 1, 0);

    // Print the graph
    cout << "Nodes:" << endl;
    for (int i = 0; i < nodes.size(); ++i) {
        cout << "Node " << i << ": (" << fixed << setprecision(4) << nodes[i].first << ", " << nodes[i].second << ")" << endl;
    }

    cout << "\nEdges:" << endl;
    for (const auto& edge : edges) {
        cout << "Edge: " << edge.first << " -> " << edge.second << endl;
    }
}

int main() {
    double waferDiameter;
    int N;
    double angleIncrement;

    cout << "Enter wafer diameter (mm): ";
    cin >> waferDiameter;
    cout << "Enter number of points (N): ";
    cin >> N;
    cout << "Enter angle increment (degrees): ";
    cin >> angleIncrement;

    generateGraph(N, waferDiameter, angleIncrement);

    return 0;

    //code in c++ to generate the graph 

}
