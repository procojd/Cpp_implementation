#include <iostream>
#include <vector>
using namespace std;
const int MAX_VERTICES = 100;

class Graph {
private:
    int vertices;
    int matrix[MAX_VERTICES][MAX_VERTICES];

public:
    Graph(int vertices) : vertices(vertices) {
        // Initialize the matrix with zeros
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int from, int to) {
        matrix[from][to] = 1;
        matrix[to][from] = 1;  // For undirected graph
    }

    void printMatrix() {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << matrix[i][j] << " ";
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

    // Print the adjacency matrix
    graph.printMatrix();

    return 0;
}
