#include <iostream>
#include <vector>

using namespace std;

const int N = 5; // Size of the maze, you can change it according to your maze size

// Function to print the answer matrix
void print(const vector<vector<int>>& answer) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the current cell is a valid move
bool isSafe(int x, int y, const vector<vector<int>>& maze) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Recursive function to solve the rat in a maze problem
bool solveMazeUtil(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& answer) {
    // If the rat reaches the destination
    if (x == N - 1 && y == N - 1) {
        answer[x][y] = 1;
        return true;
    }

    // Check if the current cell is a valid move
    if (isSafe(x, y, maze)) {
        // Mark the current cell as part of the answer path
        answer[x][y] = 1;

        // Move right
        if (solveMazeUtil(x, y + 1, maze, answer))
            return true;

        // Move down
        if (solveMazeUtil(x + 1, y, maze, answer))
            return true;

        // If no valid move is possible, backtrack
        answer[x][y] = 0;
        return false;
    }

    return false;
}

// Function to solve the rat in a maze problem
void solveMaze( vector<vector<int>>& maze) {
    vector<vector<int>> answer(N, vector<int>(N, 0));

    if (solveMazeUtil(0, 0, maze, answer)) {
        cout << "answer exists. The path is:\n";
        print(answer);
    } else {
        cout << "No answer exists.\n";
    }
}

int main() {
    // Example maze represented as a 2D array
    vector<vector<int>> maze = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1}
    };

    solveMaze(maze);

    return 0;
}
