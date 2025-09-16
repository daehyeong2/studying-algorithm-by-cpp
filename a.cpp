#include <bits/stdc++.h>
using namespace std;

int n, k, l, t, dir = 1, in_y, in_x, y=1, x=1, board[104][104], dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
char in_c, rotation[10004];
queue<pair<int, int>> q;

int main(){
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> in_y >> in_x;
        board[in_y][in_x] = 2;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> in_x >> in_c;
        rotation[in_x] = in_c;
    }
    q.emplace(1, 1);
    board[1][1] = 1;
    while (++t) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny > n || ny < 1 || nx > n || nx < 1 || board[ny][nx] == 1) break;
        if (board[ny][nx] == 0) {
            auto [fst, snd] = q.front(); q.pop();
            board[fst][snd] = 0;
        }
        board[ny][nx] = 1;
        q.emplace(ny, nx);
        y = ny; x = nx;

        if (rotation[t] == 'L') dir = (dir - 1) % 4;
        else if (rotation[t] == 'D') dir = (dir + 1) % 4;
        if (dir < 0) dir = 4+dir;
    };
    cout << t << "\n";
    return 0;
}