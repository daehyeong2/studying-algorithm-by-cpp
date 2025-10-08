#include <bits/stdc++.h>
using namespace std;

char ch;
int n, m, ret, board[54][54], visited[54][54], cnt[54][54];

int go(int y, int x, int k) {
    if (cnt[y][x] && cnt[y][x] >= k) return cnt[y][x];
    int mx = k;
    for (int dir = 0; dir < 4; dir++) {
        int ny = -1, nx = -1;
        if (dir == 0) {
            ny = y - board[y][x], nx = x;
        } else if (dir == 1) {
            ny = y + board[y][x], nx = x;
        } else if (dir == 2) {
            ny = y, nx = x - board[y][x];
        } else if (dir == 3) {
            ny = y, nx = x + board[y][x];
        }
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || board[ny][nx] == 0) continue;
        if (visited[ny][nx]) {
            cout << -1 << "\n";
            exit(0);
        }
        visited[ny][nx] = 1;
        int output = go(ny, nx, k+1);
        mx = max(mx, output);
        visited[ny][nx] = 0;
    }
    if (cnt[y][x] < k) cnt[y][x] = k;
    return mx;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch;
            if (ch == 'H') board[i][j] = 0;
            else board[i][j] = ch-'0';
        }
    }
    visited[0][0] = 1;
    cout << go(0, 0, 1) << "\n";
    return 0;
}