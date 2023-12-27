#include <iostream>
#include <list>
#include <vector>
using namespace std;
class Graph {
private:
    int vertices;
    vector<list<int>> adjacencyList;

public:
    Graph(int vertices) : vertices(vertices), adjacencyList(vertices) {}

    void addEdge(int from, int to) {
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from);  // For undirected graph
    }

    void printList() {
        for (int i = 0; i < vertices; ++i) {
            cout << "Vertex " << i << ": ";
            for (int neighbor : adjacencyList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create an undirected graph with 4 vertices
    Graph graph(4);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    // Print the adjacency list
    graph.printList();

    return 0;
}
