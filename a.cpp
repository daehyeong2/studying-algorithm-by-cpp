#include <bits/stdc++.h>
using namespace std;

int r, c, t, ret, a[54][54], dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

void dfs(int y, int x, int v, bool isTop, int dir) {
    int nextV = a[y][x];
    a[y][x] = v;
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if (ny < 0 || nx < 0 || ny >= r || nx >= c || a[ny][nx] == -1) return;
    if (nx == c-1) {
        if (isTop) dir = 0;
        else dir = 2;
    }
    if (ny == r-1 || ny == 0) dir = 3;
    if (nx == 0) {
        if (isTop) dir = 2;
        else dir = 0;
    }
    dfs(ny, nx, nextV, isTop, dir);
}

int main(){
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    while (t--) {
        int newA[54][54];
        memcpy(newA, a, sizeof(a));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (a[i][j] > 0) {
                    int amount = a[i][j] / 5;
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == -1) continue;
                        newA[ny][nx] += amount;
                        cnt++;
                    }
                    newA[i][j] -= amount * cnt;
                }
            }
        }
        memcpy(a, newA, sizeof(newA));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (a[i][j] == -1) {
                    dfs(i, j+1, 0, a[i-1][j] != -1, 1);
                }
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] != -1) ret += a[i][j];
        }
    }
    cout << ret << "\n";
    return 0;
}