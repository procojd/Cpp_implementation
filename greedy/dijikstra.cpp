#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a weighted edge in the graph
struct Edge {
    int destination;
    int weight;
};

// Structure to represent a vertex in the graph
struct Vertex {
    vector<Edge> edges;
};

// Dijkstra's algorithm function
void dijkstra(vector<Vertex>& graph, int start) {
    int numVertices = graph.size();
    vector<int> distance(numVertices, INT_MAX); // Initialize distances to infinity
    vector<bool> visited(numVertices, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (const Edge& edge : graph[u].edges) {
            int v = edge.destination;
            int weight = edge.weight;

            if (!visited[v] && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    // Print the shortest distances from the start vertex to all other vertices
    cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "To vertex " << i << ": " << (distance[i] == INT_MAX ? "INF" : to_string(distance[i])) << endl;
    }
}

int main() {
    // Example graph representation
    int numVertices = 6;
    vector<Vertex> graph(numVertices);

    // Adding edges and weights
    graph[0].edges.push_back({1, 2});
    graph[0].edges.push_back({2, 4});
    graph[1].edges.push_back({2, 1});
    graph[1].edges.push_back({3, 7});
    graph[2].edges.push_back({4, 3});
    graph[3].edges.push_back({4, 1});
    graph[4].edges.push_back({5, 5});

    // Start Dijkstra's algorithm from vertex 0
    dijkstra(graph, 0);

    return 0;
}
