#include <bits/stdc++.h>
using namespace std;

int n, m, mx, d[4][4], visited[4][4];
char ch;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch;
            d[i][j] = ch-'0';
        }
    }
    for (int i = 0; i < (1<<n*m); i++) {
        memset(visited, 0, sizeof(visited));
        int ret = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (visited[j][k]) continue;
                int idx = j * m + k;
                if (i & (1<<idx)) {
                    int cnt = 0;
                    for (int l = j; l < n; l++) {
                        if (i & (1<<(l * m + k))) {
                            cnt = (cnt*10) + d[l][k];
                            visited[l][k] = 1;
                        } else break;
                    }
                    ret += cnt;
                } else {
                    int cnt = 0;
                    for (int l = k; l < m; l++) {
                        if (~i & (1<<(j * m + l))) {
                            cnt = (cnt*10) + d[j][l];
                            visited[j][l] = 1;
                        } else break;
                    }
                    ret += cnt;
                }
            }
        }
        mx = max(mx, ret);
    }
    cout << mx << "\n";
    return 0;
}