#include <bits/stdc++.h>
using namespace std;

typedef struct Node {
    int p, d, j;
    Node(){}
    Node(int profit, int deadline, int jobId) {
        p = profit;
        d = deadline;
        j = jobId;
    }
}node;

bool comparator(node a, node b) {
    if (a.p == b.p) {
        return a.d < b.d;
    }
    return a.p > b.p;
}

int main() {
    int num;
    cout << "Enter number of jobs: ";
    cin >> num;
    vector<node> jobs;
    node temp;
    int maxd;
    for (int i=0; i<num; i++) {
        temp.j = i+1;
        cout << "Enter job id, deadline, profit for job " << i+1 << ": ";
        cin >> temp.j >> temp.d >> temp.p;
        jobs.push_back(temp);
        maxd = max(maxd, temp.d);
    }
    sort(jobs.begin(), jobs.end(), comparator);

    vector<pair<int, node>> slots;

    for (int i=maxd; i>=0 && jobs.isempty(); i--) {
        for (auto j = jobs.begin(); j != jobs.end(); j++) {
            if (j->d >= i) {
                slots.push_back({i, *j});
                jobs.erase(j);
                break;
            }
        }
    }

    cout << endl;
    int j=0, profit = 0;
    for (int i=0; i<slots.size(); i++) {
        if (slots[i].first) {
            cout << "Slot - " << slots[i].first << " - Job - " << slots[i].second.j << " - Profit - " << slots[i].second.p << endl;
            profit += slots[i].second.p;
        }
    }
    cout << "Total Profit: "<< profit << endl;
    return 0;
}