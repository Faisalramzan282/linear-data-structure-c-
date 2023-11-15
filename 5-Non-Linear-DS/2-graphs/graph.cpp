// #include <iostream>
// #include <vector>

// class Graph {
// private:
//     int numVertices;              // Number of vertices in the graph
//     std::vector<std::vector<bool>> adjacencyMatrix;  // Adjacency matrix

// public:
//     Graph(int vertices);           // Constructor to initialize the graph
//     void addEdge(int src, int dest);  // Function to add an edge to the graph
//     void printGraph();             // Function to print the graph
// };

// // Constructor to initialize the graph with a given number of vertices
// Graph::Graph(int vertices) {
//     numVertices = vertices;  
//     // Initialize the adjacency matrix with all elements set to false (no edges initially)
//     adjacencyMatrix.resize(vertices, std::vector<bool>(vertices, false));
// }
// // Function to add an edge to the graph
// void Graph::addEdge(int src, int dest) {
//     // For an undirected graph, set both matrix[src][dest] and matrix[dest][src] to true
//     adjacencyMatrix[src][dest] = true;
//     adjacencyMatrix[dest][src] = true;
// }
// // Function to print the graph
// void Graph::printGraph() {
//     for (int i = 0; i < numVertices; ++i) {
//         std::cout << "Vertex " << i << " connected to: ";
//         for (int j = 0; j < numVertices; ++j) {
//             if (adjacencyMatrix[i][j]) {
//                 std::cout << j << " ";
//             }
//         }
//         std::cout << std::endl;
//     }
// }
// int main() {
//     // Create a graph with 5 vertices
//     Graph graph(5);
//     // Add edges to the graph
//     graph.addEdge(0, 1);
//     graph.addEdge(0, 4);
//     graph.addEdge(1, 2);
//     graph.addEdge(1, 3);
//     graph.addEdge(1, 4);
//     graph.addEdge(2, 3);
//     graph.addEdge(3, 4);
//     // Print the graph
//     graph.printGraph();
//     return 0;
// }
//---------------------------------------using adjacency lists ------------
// Adjascency List representation in C++

#include <bits/stdc++.h>
using namespace std;

// Add edge
void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

// Print the graph
void printGraph(vector<int> adj[], int V) {
  for (int d = 0; d < V; ++d) {
    cout << "\n Vertex "
       << d << ":";
    for (auto x : adj[d])
      cout << "-> " << x;
    printf("\n");
  }
}
int main() {
  int V = 5;
  vector<int> adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  printGraph(adj, V);
}