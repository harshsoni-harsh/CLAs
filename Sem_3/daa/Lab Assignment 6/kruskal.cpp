#include <bits/stdc++.h>

using namespace std;

class node {
public:
    int i, j, w;
    node() {}
    node(int source, int destination, int weight) {
        i = source;
        j = destination;
        w = weight;
    }
};

class comparator {
public:
    bool operator()(node a, node b) {
        return a.w > b.w;
    }
};

class Kruskal {
public:
    int cost = 0;
    int visits = 1, len, temp = 2;
    set<int> s;
    priority_queue<node, vector<node>, comparator> p;
    node t;
    vector<int> visited;
    Kruskal(vector<node>& a) {
        for (int i=0; i<a.size(); i++) {
            s.insert(a[i].i);
            s.insert(a[i].j);
            p.push(a[i]);
        }
        p.push(node(0,0,-1));
        p.pop();
        len = s.size();
        for (int i=0; i<len; i++) {
            visited.push_back(i);
        }
        while(p.size()) {
            t = p.top();
            p.pop();
            if(visited[t.i] != visited[t.j]) {
                int temp = visited[t.i];
                for (int i = 0; i < len; i++) {
                    if (visited[i] == temp)
                        visited[i] = visited[t.j];
                }
                cost += t.w;
                cout << t.i+1 << " -> " << t.j+1 << " - Cost: " << t.w << endl;
            }
        }
    }
};

int main() {
    int len;
    cout << "Enter number of edges: ";
    cin >> len;
    cout << "Enter i,j,w" << endl;
    vector<node> a;
    while(len--) {
        node n;
        cin >> n.i >> n.j >> n.w;
        a.push_back(n);
    }
    Kruskal k(a);
    cout << "Total Cost :- " << k.cost << endl;
    return 0;
}