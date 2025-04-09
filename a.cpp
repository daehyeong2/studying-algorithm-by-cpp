#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, mx, big, d[54][54], visited[54][54], compSize[2504], dy[] = {0, -1, 0, 1}, dx[] = {-1, 0, 1, 0};

int dfs(int y, int x, int cnt) {
    if (visited[y][x]) return 0;
    visited[y][x] = cnt;
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        if (!(d[y][x] & (1<<i))) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            ret += dfs(ny, nx, cnt);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                cnt++;
                compSize[cnt] = dfs(i, j, cnt);
                mx = max(mx, compSize[cnt]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n) {
                int a = visited[i][j];
                int b = visited[i + 1][j];
                if (a != b) {
                    big = max(big, compSize[a] + compSize[b]);
                }
            }
            if (j + 1 < m) {
                int a = visited[i][j];
                int b = visited[i][j + 1];
                if (a != b) {
                    big = max(big, compSize[a] + compSize[b]);
                }
            }
        }
    }
    cout << cnt << "\n" << mx << "\n" << big << "\n";
    return 0;
}