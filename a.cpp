#include <bits/stdc++.h>
using namespace std;

int n, arr[54], che[2004], visited[104], b[104];
vector<vector<int>> node;
vector<int> ret;

bool bmatch(int here) {
    if (visited[here]) return false;
    visited[here] = 1;
    for (int there : node[here]) {
        if (!b[there] || bmatch(b[there])) {
            b[here] = there;
            b[there] = here;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n;
    for (int i = 0; i < n+4; i++) node.emplace_back();
    fill(begin(che), end(che), 1);
    che[0] = 0, che[1] = 0;
    for (int i = 2; i*i <= 2000; i++) {
        if (che[i]) {
            for (int j = i*i; j <= 2000; j+=i) {
                che[j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i==j) continue;
            if (find(node[i].begin(), node[i].end(), j) != node[i].end()) continue;
            int first = arr[i];
            int second = arr[j];
            if (che[first+second]) {
                node[i].push_back(j);
                node[j].push_back(i);
            }
        }
    }
    for (int root : node[1]) {
        memset(b, 0, sizeof(b));
        int cnt = 1;
        b[1] = root;
        b[root] = 1;
        for (int i = 2; i <= n; i++) {
            if (i == root) continue;
            memset(visited, 0, sizeof(visited));
            visited[1] = 1;
            visited[root] = 1;
            if (!b[i] && bmatch(i)) cnt++;
        }
        if (cnt == n/2) {
            ret.push_back(arr[root]);
        }
    }
    if (ret.empty()) {
        cout << -1 << "\n";
        exit(0);
    }
    sort(ret.begin(), ret.end());
    for (int v : ret) {
        cout << v << " ";
    }
    cout << "\n";
    return 0;
}
