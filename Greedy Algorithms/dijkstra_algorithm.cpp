#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int destination;
    int weight;
};

void dijkstra(const vector<vector<Edge>>& graph, int source) {
    int numVertices = graph.size();
    vector<int> distances(numVertices, INT_MAX);
    distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, source});

    while (!minHeap.empty()) {
        int currentVertex = minHeap.top().second;
        minHeap.pop();

        for (const auto& edge : graph[currentVertex]) {
            int neighbor = edge.destination;
            int edgeWeight = edge.weight;

            if (distances[currentVertex] + edgeWeight < distances[neighbor]) {
                distances[neighbor] = distances[currentVertex] + edgeWeight;
                minHeap.push({distances[neighbor], neighbor});
            }
        }
    }

    cout << "Vertex distances from source " << source << ":\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": " << distances[i] << "\n";
    }
}

int main() {
    int numVertices = 9;
    vector<vector<Edge>> graph(numVertices);

    graph[0] = {{1, 4}, {4, 8}};
    graph[1] = {{0, 4}, {4, 11}, {2, 8}};
    graph[2] = {{1, 8}, {8, 2}, {6, 4}, {3, 7}};
    graph[3] = {{2, 7}, {6, 14}, {7, 9}};
    graph[4] = {{0, 8}, {1, 11}, {8, 7}, {5, 1}};
    graph[5] = {{4, 1}, {8, 6}, {6, 2}};
    graph[6] = {{2, 4}, {5, 2}, {3, 14}, {7, 10}};
    graph[7] = {{3, 9}, {6, 10}};
    graph[8] = {{4, 7}, {2, 2}, {5, 6}};

    int source = 0; // Assuming you want to use Dijkstra's algorithm
    dijkstra(graph, source);

    return 0;
}
