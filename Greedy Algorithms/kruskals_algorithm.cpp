#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int numVertices) {
        parent.resize(numVertices);
        rank.resize(numVertices, 0);
        for (int i = 0; i < numVertices; ++i)
            parent[i] = i;
    }

    int find(int vertex) {
        if (vertex != parent[vertex])
            parent[vertex] = find(parent[vertex]);
        return parent[vertex];
    }

    void unionSets(int vertex1, int vertex2) {
        int root1 = find(vertex1);
        int root2 = find(vertex2);

        if (root1 != root2) {
            if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }
};

void kruskalMST(vector<Edge>& edges, int numVertices) {
    sort(edges.begin(), edges.end(), compare);

    DisjointSet ds(numVertices);

    vector<Edge> mst;

    for (const auto& edge : edges) {
        int vertex1 = edge.source;
        int vertex2 = edge.destination;

        if (ds.find(vertex1) != ds.find(vertex2)) {
            mst.push_back(edge);
            ds.unionSets(vertex1, vertex2);
        }
    }

    cout << "Edges in the MST:\n";
    for (const auto& edge : mst) {
        cout << edge.source << " - " << edge.destination << " (Weight: " << edge.weight << ")\n";
    }
}

int main() {
    int numVertices = 6;
    vector<Edge> edges = {
    {0, 1, 7}, {1, 0, 7}, 
    {0, 2, 8}, {2, 0, 8}, 
    {1, 2, 3}, {2, 1, 3}, 
    {1, 3, 6}, {3, 1, 6}, 
    {2, 3, 4}, {3, 2, 4}, 
    {2, 4, 3}, {4, 2, 3}, 
    {3, 4, 2}, {4, 3, 2}, 
    {3, 5, 5}, {5, 3, 5}, 
    {4, 5, 2}, {5, 4, 2}
};

    kruskalMST(edges, numVertices);

    return 0;
}