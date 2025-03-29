#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, standard[4], d[15][5], price = INF;
map<int, vector<vector<int> > > ret;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int & i : standard) cin >> i;
    for (int i = 0; i < n; i++) for (int & j : d[i]) cin >> j;
    for (int i = 0; i < (1<<n); i++) {
        int total[5] = {};
        for (int j = 0; j < n; j++) {
            if (i & (1<<j)) {
                for (int k = 0; k < 5; k++) {
                    total[k] += d[j][k];
                }
             }
        }
        bool flag = 0;
        for (int j = 0; j < 4; j++) {
            if (total[j] < standard[j]) {
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        if (total[4] <= price) {
            price = total[4];
            vector<int> v;
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) {
                    v.push_back(j);
                }
            }
            ret[total[4]].push_back(v);
        }
    }
    if (price == INF) {
        cout << -1 << "\n";
        return 0;
    }
    sort(ret[price].begin(), ret[price].end());
    cout << price << "\n";
    for (const int & i : ret[price][0]) cout << i+1 << " ";
    cout << "\n";
    return 0;
}