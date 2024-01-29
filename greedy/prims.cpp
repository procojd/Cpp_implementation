#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a graph edge
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// Function to perform Prim's algorithm and find the minimum spanning tree
void prim(const vector<vector<Edge>>& graph, int startNode) {
    int n = graph.size(); // Number of vertices
    vector<int> key(n, INT_MAX); // Key values used to pick minimum weight edge
    vector<bool> inMST(n, false); // To keep track of vertices included in MST

    // Priority queue to store and extract minimum key value
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start with the first node
    key[startNode] = 0;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Include the extracted vertex in MST
        inMST[u] = true;

        // Iterate through all adjacent vertices of u
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // If v is not yet included in MST and the weight of the current edge is less than the key value of v
            if (!inMST[v] && weight < key[v]) {
                // Update key value of v
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    // Print the minimum spanning tree
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < n; ++i) {
        cout << "Edge: " << i << " - " << key[i] << endl;
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<Edge>> graph = {
        {{1, 2}, {2, 4}},      // Node 0
        {{0, 2}, {2, 1}, {3, 3}},  // Node 1
        {{0, 4}, {1, 1}, {3, 5}},  // Node 2
        {{1, 3}, {2, 5}}           // Node 3
    };

    // Start Prim's algorithm from the first node (you can choose any starting node)
    prim(graph, 0);

    return 0;
}
