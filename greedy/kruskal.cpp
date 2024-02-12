#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph


// Function to add an edge to the graph
void addEdge(vector<vector<Edge>>& graph, int from, int to, int weight) {
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
}
struct Edge {
    int to;
    int weight;
};
// Function to perform Prim's algorithm and find the minimum spanning tree
void prim(vector<vector<Edge>>& graph, int startVertex) {
    int numVertices = graph.size();

    // Priority queue to store edges with their weights
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Vector to keep track of visited vertices
    vector<bool> visited(numVertices, false);

    // Start with the given vertex
    pq.push({0, startVertex});

    while (!pq.empty()) {
        // Extract the vertex with the minimum weight
        int currentVertex = pq.top().second;
        int currentWeight = pq.top().first;
        pq.pop();

        // Mark the current vertex as visited
        visited[currentVertex] = true;

        // Process all adjacent vertices of the current vertex
        for (const Edge& edge : graph[currentVertex]) {
            int neighbor = edge.to;
            int weight = edge.weight;

            // If the neighbor is not visited and the weight is less than the current known weight
            if (!visited[neighbor] && weight < currentWeight) {
                // Add the edge to the MST
                cout << "Edge: " << currentVertex << " - " << neighbor << "   Weight: " << weight << endl;

                // Mark the neighbor as visited
                visited[neighbor] = true;

                // Add the neighbor and its edges to the priority queue
                pq.push({weight, neighbor});
                for (const Edge& neighborEdge : graph[neighbor]) {
                    pq.push({neighborEdge.weight, neighborEdge.to});
                }
            }
        }
    }
}

int main() {
    // Number of vertices in the graph
    int numVertices = 5;

    // Adjacency list representation of the graph
    vector<vector<Edge>> graph(numVertices);

    // Add edges to the graph
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 3, 7);
    addEdge(graph, 2, 3, 3);

    // Start Prim's algorithm from vertex 0
    prim(graph, 0);

    return 0;
}