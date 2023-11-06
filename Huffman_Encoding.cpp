#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Huffman tree node
struct Node {
    char data;
    int frequency;
    Node* left;
    Node* right;

    Node(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// Custom comparator for priority queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

// Function to build the Huffman tree and return the root node
Node* buildHuffmanTree(string text) {
    // Count the frequency of each character in the text
    unordered_map<char, int> freqMap;
    for (char c : text) {
        freqMap[c]++;
    }

    // Create a priority queue to store the nodes based on their frequencies
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build the Huffman tree by merging nodes from the priority queue
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        // Create a new internal node with sum of frequencies as its frequency
        // and set its left and right child pointers
        Node* newNode = new Node('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        // Add the new internal node back to the priority queue
        pq.push(newNode);
    }

    // The last remaining node in the priority queue is the root of the Huffman tree
    return pq.top();
}

// Function to perform Huffman encoding on a given text
string encode(string text) {
    // Build the Huffman tree
    Node* root = buildHuffmanTree(text);

    // Generate Huffman codes for each character in the text using a greedy approach
    unordered_map<char, string> huffmanCodes;
    string code = "";
    
    // Traverse the Huffman tree and assign codes to each leaf node
    auto assignCodes = [&](Node* node, auto&& self) {
        if (node == nullptr) {
            return;
        }
        
        if (node->left == nullptr && node->right == nullptr) {
            huffmanCodes[node->data] = code;
            return;
        }
        
        code.push_back('0');
        self(node->left, self);
        
        code.pop_back();
        code.push_back('1');
        self(node->right, self);
        
        code.pop_back();
    };
    
    assignCodes(root, assignCodes);

    // Encode the text using the generated Huffman codes
    string encodedText = "";
    for (char c : text) {
        encodedText += huffmanCodes[c];
    }

    return encodedText;
}

int main() {
    string text;
    cout << "Enter the text to encode: ";
    getline(cin, text);

    // Perform Huffman encoding using a greedy approach
    string encodedText = encode(text);
    
   cout << "Encoded text: " << encodedText << endl;

   return 0;
}
