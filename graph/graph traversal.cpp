#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjacencyList;

    Graph(int v) : vertices(v), adjacencyList(v) {}

    void addEdge(int from, int to) {
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from);  // For undirected graph
    }

    void printGraph() {
        for (int i = 0; i < vertices; ++i) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adjacencyList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

void dfsRecursive(Graph& graph, int currentVertex, vector<bool>& visited) {
    visited[currentVertex] = true;
    cout << currentVertex << " ";

    for (int neighbor : graph.adjacencyList[currentVertex]) {
        if (!visited[neighbor]) {
            dfsRecursive(graph, neighbor, visited);
        }
    }
}

void dfs(Graph& graph, int startVertex) {
    vector<bool> visited(graph.vertices, false);
    dfsRecursive(graph, startVertex, visited);
    cout << endl;
}

void bfs(Graph& graph, int startVertex) {
    vector<bool> visited(graph.vertices, false);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        cout << currentVertex << " ";

        for (int neighbor : graph.adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}
