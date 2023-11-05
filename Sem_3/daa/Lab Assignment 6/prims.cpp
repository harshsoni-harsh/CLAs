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

class Prims {
public:
    int cost = 0;
    int visits = 1, len;
    set<int> s;
    priority_queue<node, vector<node>, comparator> p;
    vector<int> visited;
    Prims(int num, vector<node>& a) {
        for (int i=0; i<a.size(); i++) {
            s.insert(a[i].i);
            s.insert(a[i].j);
        }
        len = s.size();
        visited = vector<int>(len, 0);
        visited[num] = 1;
        int top_num = num;
        while(visits != len) {
            int x;
            for (x = 0; x < a.size(); x++) {
                if (a[x].i == top_num && visited[a[x].j] == 0) {
                    p.push(node(top_num, a[x].j, a[x].w));
                }
                else if (a[x].j == top_num && visited[a[x].i] == 0) {
                    p.push(node (top_num, a[x].i, a[x].w));
                }
            }
            
            if (p.empty()) {
                for (int x = 0; x < len; x++) {
                    if(visited[a[x].i] == 0) {
                        top_num = a[x].i;
                        visited[top_num] = 1;
                        break;
                    }
                    else if(visited[a[x].j] == 0) {
                        top_num = a[x].j;
                        visited[top_num] = 1;
                        break;
                    }
                }
                for (int x = 0; x < len; x++) {
                    if (a[x].i == top_num) {
                        p.push(node(top_num, a[x].j, a[x].w));
                    }
                    else if (a[x].j == top_num) {
                        p.push(node (top_num, a[x].i, a[x].w));
                    }
                }
            }
            while (visited[p.top().j] == 1) {
                p.pop();
            }
            p.push(node(0,0,-1));
            p.pop();
            visited[p.top().j] = 1;
            cost += p.top().w;
            top_num = p.top().j;
            visits += 1;
            cout << p.top().i << " -> " << p.top().j << " - Cost: " << p.top().w << endl;
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
    cout << "Enter a node number to start: ";
    cin >> len;
    Prims k(len, a);
    cout << k.cost << endl;
    return 0;
}