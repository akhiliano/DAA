#include <bits/stdc++.h>
using namespace std;

// A Huffman tree node
struct Node {
    char data;
    int freq;
    Node *left, *right;
    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue (min-heap)
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;  // Min-heap based on frequency
    }
};

// Print Huffman codes from the root
void printCodes(Node* root, string str) {
    if (!root) return;
    
    if (root->data != '#')  // Print only for leaf nodes (non-internal nodes)
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Main function to build Huffman tree and generate codes
void HuffmanCodes(vector<char>& data, vector<int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Create a leaf node for each character and push it to the heap
    for (size_t i = 0; i < data.size(); ++i) {
        minHeap.push(new Node(data[i], freq[i]));
    }

    // Build the Huffman tree
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();
        
        Node* parent = new Node('#', left->freq + right->freq);  // '#' marks internal nodes
        parent->left = left;
        parent->right = right;
        minHeap.push(parent);
    }

    // Print Huffman codes starting from the root node
    printCodes(minHeap.top(), "");
}

int main() {
    vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    HuffmanCodes(data, freq);
    return 0;
}
