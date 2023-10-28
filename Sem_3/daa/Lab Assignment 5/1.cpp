#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
class node {
public:
    char character = 'a';
    int frequency = 0;
    node* left = NULL;
    node* right = NULL;
};

class comparator{
public:
    bool operator() (const node* lhs, const node* rhs){
        return lhs->frequency > rhs->frequency;
    }
};

class huff_encode {
public:
    node* head;
    map<char, string> encoding;
    string message;
    string encoded;
    int freq[256] = {0};
    priority_queue<node*, vector<node*>, comparator> pq;
    huff_encode(string st) {
        message = st;
        calculate_freq();
        create_priority_queue();
        head = huffman(pq);
        encoder(head, "");
        get_encoded();
    }
    node* huffman (priority_queue<node*, vector<node*>, comparator> pq) {
        while (pq.size() > 1) {
            node* n1 = pq.top();
            pq.pop();
            node* n2 = pq.top();
            pq.pop();
            node* n = new node();
            n->frequency = n1->frequency + n2->frequency;
            n->left = n1;
            n->right = n2;
            pq.push(n);
        }
        return pq.top();
    }
    void calculate_freq() {    
        for (char i : message) {
            freq[i]++;
        }
    }
    void create_priority_queue() {
        for (int i=0; i<256; i++) {
            if(freq[i]!=0) {
                node* node1 = new node();
                node1->frequency = freq[i];
                node1->character = i;
                pq.push(node1);
            }
        }
    }
    void encoder(node *head, string s) {
        if(head->left) {
            encoder(head->left, s+"0");
        }
        if(head->right) {
            encoder(head->right, s+"1");
        }
        if(head->left == NULL && head->right == NULL) {
            encoding.insert({head->character, s});
        }
    }
    void print_code() {
        for (auto itr = encoding.begin(); itr!=encoding.end(); itr++) {
            cout << itr->first << " - " << itr->second << endl;
        }
    }
    void get_encoded() {
        encoded = "";
        for (char i : message) {
            encoded += encoding[i];
        }
    }
};
class huff_decode {
public:
    string message = "";
    map<string, char> decoder;
    huff_decode(map<char, string> code, string encoded) {
        rev_map(code);
        decode(encoded);
    }
    void decode(string encoded) {
        string buff = "";
        for (char i : encoded) {
            buff += i;
            if(decoder.count(buff) == 1) {
                message += decoder[buff];
                buff = "";
            }
        }
    }
    void rev_map(map<char, string> code) {
        for (auto i : code) {
            decoder.insert({i.second, i.first});
        }
    }
};
void print_binary(string st) {
    cout << "Binary form of ascii string: " << "\n";
    for (char c : st) {
        for (int i=7; i>=0; i--) {
            cout << (c & (1<<i)) ? '1' : '0';
        }
    }
    cout << endl;
}
int main() {    
    int choice, len;
    string message = "";
    string encoded = "";
    char ch;
    string st = "";
    map<char, string> decoding;
    while (1) {
        cout << "1. Encode a message" << endl;
        cout << "2. Decode a message" << endl;
        cout << "3. Print message in binary" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter a number from choices: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter message: ";
                cin >> message;
                huff_encode* code = new huff_encode(message);
                cout << "Encoded message: " << code->encoded << endl;
                cout << "Number of encoded characters: " << code->encoding.size() << endl;
                cout << "Encoding: " << endl;
                for (auto itr = code->encoding.begin(); itr != code->encoding.end();  itr++) {
                    cout << itr->first << " " << itr->second << endl;
                }
            } break;
            case 2: {
                cout << "Enter encoded binary message: ";
                cin >> encoded;
                cout << "Number of encoded characters: ";
                cin >> len;
                cout << "Enter encoding in the format {C 011} separated on new line" << endl;
                for (int i=0; i<len; i++) {
                    cin >> ch >> st;
                    decoding.insert({ch,st});
                }
                huff_decode* decode = new huff_decode(decoding, encoded);
                cout << "Decoded message: " << decode->message << endl;
            } break;
            case 3: {
                print_binary(message);
            } break;
            case 4: {
                return 0;
            } break;
            default: {
                cout << "Invalid choice" << endl;
            } break;            
        } cout << endl;
    }
    return 0;
}