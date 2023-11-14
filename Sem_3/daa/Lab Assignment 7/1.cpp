#include <bits/stdc++.h>

using namespace std;

void floydWarshel(vector<vector<int>>& m, int x, int y, int edges) {
    for (int i=0; i<edges; i++) {
        for (int j=0; j<edges; j++) {
            if (i == x || j == y) continue;
            if (m[x][j] == INT_MAX || m[i][y] == INT_MAX) continue;
            m[i][j] = min(m[i][j], m[x][j]+m[i][y]);
        }
    }
    if (x+1 != edges || y+1 != edges)
    floydWarshel(m, x+1, y+1, edges);
}

int main() {
    int len,t, edges;
    cout << "Enter number of edges: ";
    cin >> t;
    len = t;
    cout << "Enter number of nodes: ";
    cin >> edges;
    cout << "Enter source, destination, distance between nodes" << endl;
    vector<vector<int>> mat (edges, vector<int> (edges, INT_MAX));
    for (int i=0; i<mat.size(); i++) {
        mat[i][i] = 0;
    }
    pair<pair<int, int>, int> temp;
    while (t--) {
        cin >> temp.first.first >> temp.first.second >> temp.second;
        mat[temp.first.first - 1][temp.first.second - 1] = temp.second;
    }
    floydWarshel(mat, 0, 0, edges);
    cout << "Printing matrix: " << endl;
    for (int i=0; i<edges; i++) {
        for (int j=0; j<edges; j++) {
            if (mat[i][j] == INT_MAX) {
                cout << "inf" << " ";
            }
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}