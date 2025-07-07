#include <bits/stdc++.h>
using namespace std;

int n, k, ret[5], a[1004][1004], visited[1004][1004];
int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(int y, int x) {
    int hap[5] = {0, 0, 0, 0, 0};
    vector<pair<int, int>> v;
    bool flag = false;
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
        if (a[ny][nx] == 0) continue;
        if (a[ny][nx] == k) {
            flag = true;
            continue;
        }
        if ((i-1) % 2 == 0) {
            v.emplace_back(ny, nx);
            visited[ny][nx] = 1;
            hap[a[ny][nx]-1]++;
        }
    }
    if (flag) {
        for (int i = 0; i < 5; i++) {
            ret[i] += hap[i];
        }
    } else {
        for (int i = 0; i < v.size(); i++) {
            visited[v[i].first][v[i].second] = 0;
        }
    }
    for (int i = 1; i < 8; i+=2) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || a[ny][nx] != 0) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
}

int main(){
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    visited[n-1][0] = 1;
    dfs(n-1, 0);
    for (int i = 0; i < 5; i++) {
        cout << ret[i] << "\n";
    }
    return 0;
}