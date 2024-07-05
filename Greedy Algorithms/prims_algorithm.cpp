#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int destination;
    int weight;
};

void primMST(const vector<vector<Edge>>& graph) {
    int numVertices = graph.size();
    vector<int> minEdgeWeight(numVertices, INT_MAX);
    vector<int> parent(numVertices, -1);
    vector<bool> inMST(numVertices, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, 0});
    minEdgeWeight[0] = 0;

    while (!minHeap.empty()) {
        int currentVertex = minHeap.top().second;
        minHeap.pop();

        inMST[currentVertex] = true;

        for (const auto& edge : graph[currentVertex]) {
            int neighbor = edge.destination;
            int edgeWeight = edge.weight;

            if (!inMST[neighbor] && minEdgeWeight[neighbor] > edgeWeight) {
                minEdgeWeight[neighbor] = edgeWeight;
                minHeap.push({minEdgeWeight[neighbor], neighbor});
                parent[neighbor] = currentVertex;
            }
        }
    }

    cout << "Edges in the MST:\n";
    for (int i = 1; i < numVertices; ++i) {
        cout << parent[i] << " - " << i << "\n";
    }
}

int main() {
    int numVertices = 6;
    vector<vector<Edge>> graph(numVertices);

    graph[0] = {{1, 7}, {2, 8}};
    graph[1] = {{0, 7}, {2, 3}, {3, 6}};
    graph[2] = {{0, 8}, {1, 3}, {3, 4}, {4, 3}};
    graph[3] = {{1, 6}, {2, 4}, {4, 2}, {5, 5}};
    graph[4] = {{2, 3}, {3, 2}, {5, 2}};
    graph[5] = {{3, 5}, {4, 2}};

    primMST(graph);

    return 0;
}