#include <iostream>
#include <queue>
using namespace std;

// Structure for Huffman tree nodes
struct HuffmanNode {
    char data;              // Data stored in the node (for leaf nodes, this is the character)
    int frequency;          // Frequency of the character
    HuffmanNode *left, *right;  // Left and right child pointers

    HuffmanNode(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// Comparator for priority queue (min-heap based on frequency)
struct CompareNodes {
    bool operator()(HuffmanNode* const& lhs, HuffmanNode* const& rhs) {
        return lhs->frequency > rhs->frequency;
    }
};

// Class representing Huffman Tree
class HuffmanTree {
private:
    HuffmanNode* root;

public:
    HuffmanTree() : root(nullptr) {}

    // Function to build Huffman Tree from given character frequencies
    void buildTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes>& minHeap) {
        while (minHeap.size() > 1) {
            // Extract the two nodes with the minimum frequency
            HuffmanNode* left = minHeap.top();
            minHeap.pop();

            HuffmanNode* right = minHeap.top();
            minHeap.pop();

            // Create a new internal node with these two nodes as children
            // and with a frequency equal to the sum of the children's frequencies.
            HuffmanNode* newNode = new HuffmanNode('$', left->frequency + right->frequency);
            newNode->left = left;
            newNode->right = right;

            // Add the new node to the min-heap
            minHeap.push(newNode);
        }
        // The remaining node in the heap is the root node of the Huffman tree
        root = minHeap.top();
    }

    // Function to print level order traversal of the Huffman Tree
    void printLevelOrder() {
        if (root == nullptr)
            return;

        queue<HuffmanNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                HuffmanNode* node = q.front();
                q.pop();

                cout << "(" << node->data << ", " << node->frequency << ") ";

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            cout << endl;
        }
    }
};

int main() {
    // Example usage to create a Huffman Tree for characters 'a', 'b', 'c', 'd'
    // and their respective frequencies
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;

    minHeap.push(new HuffmanNode('a', 5));
    minHeap.push(new HuffmanNode('b', 9));
    minHeap.push(new HuffmanNode('c', 12));
    minHeap.push(new HuffmanNode('d', 13));

    HuffmanTree tree;
    tree.buildTree(minHeap);

    cout << "Level Order Traversal of Huffman Tree:\n";
    tree.printLevelOrder();

    return 0;
}