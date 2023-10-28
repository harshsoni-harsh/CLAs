#include <iostream>
#include <fstream>
#include <map>
#include <sstream> // Include this header for istringstream

using namespace std;

// Define the structure for a Huffman tree node
struct HuffmanNode {
    char data;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to build the Huffman tree from the provided Huffman codes
HuffmanNode* buildHuffmanTree(map<string, char>& huffmanCodes) {
    HuffmanNode* root = new HuffmanNode('\0');
    for (const auto& pair : huffmanCodes) {
        HuffmanNode* current = root;
        const string& code = pair.first;
        char symbol = pair.second;

        for (char bit : code) {
            if (bit == '0') {
                if (current->left == nullptr) {
                    current->left = new HuffmanNode('\0');
                }
                current = current->left;
            } else if (bit == '1') {
                if (current->right == nullptr) {
                    current->right = new HuffmanNode('\0');
                }
                current = current->right;
            }
        }
        current->data = symbol;
    }
    return root;
}

// Function to decompress the data and write it to the output file
void decompressData(HuffmanNode* root, const string& compressedData, ofstream& output) {
    HuffmanNode* current = root;
    for (char bit : compressedData) {
        if (bit == '0') {
            current = current->left;
        } else if (bit == '1') {
            current = current->right;
        }

        if (current->data != '\0') {
            output << current->data;
            current = root;
        }
    }
}

// Function to decompress a file using Huffman coding
void decompressFile(const string& inputFile, const string& outputFile) {
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input.is_open() || !output.is_open()) {
        cerr << "Error opening input or output file." << endl;
        return;
    }

    map<string, char> huffmanCodes;
    string line;
    
    // Read Huffman codes from the input file
    while (getline(input, line)) {
        if (line == "#####") {
            break; // Separator
        }

        char symbol;
        string code;
        istringstream lineStream(line);
        lineStream >> symbol >> code;
        huffmanCodes[code] = symbol;
    }

    // Build the Huffman tree from the Huffman codes
    HuffmanNode* root = buildHuffmanTree(huffmanCodes);

    // Read and decompress the data
    string compressedData;
    input >> compressedData;
    decompressData(root, compressedData, output);

    input.close();
    output.close();

    cout << "File decompressed successfully." << endl;
}

int main() {
    string inputFile = "ori.txt";
    string outputFile = "dup.zip";

    decompressFile(inputFile, outputFile);

    return 0;
}
