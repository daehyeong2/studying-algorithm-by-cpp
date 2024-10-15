#include <bits/stdc++.h>
using namespace std;

int n, m, t, max_ = -1;
char c;
vector<vector<char>> v;
map<int, int> mp = {};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        v.push_back({});
        for (int j = 0; j < m; j++) {
            cin >> c;
            v[i].push_back(c);
        }
    }
    while (true) {
        if (t * t > 999999999) break;
        mp[t * t] = 1;
        t++;
    }
    if (n == 1 && m == 1) {
        if (mp[v[0][0] - 48]) cout << v[0][0] << "\n";
        else cout << -1 << "\n";
        return 0;
    }
    for (int i = -n + 1; i < n; i++) {
        for (int j = -m + 1; j < m; j++) {
            if (i == 0 && j == 0) continue;
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                    string str = "";
                    int i_ = k;
                    int j_ = l;
                    while (true) {
                        str += v[i_][j_];
                        int ret = stoi(str);
                        if (mp[ret]) max_ = max(max_, ret);
                        i_ += i;
                        if (i_ >= n || i_ < 0) break;
                        j_ += j;
                        if (j_ >= m || j_ < 0) break;
                    }
                }
            }
        }
    }
    cout << max_ << "\n";
}