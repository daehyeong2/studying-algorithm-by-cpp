#include <bits/stdc++.h>
using namespace std;

int n, x, y, w, h, adj[27][27];
vector<vector<int>> v;

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> w >> h;
        v.push_back({x, y, w, h});
    }
    for (int i = 0; i < n; i++) {
        int i_x = v[i][0];
        int i_y = v[i][1];
        int i_w = v[i][2];
        int i_h = v[i][3];
        for (int j = 0; j < n; j++) {
            if (adj[i][j] || adj[j][i]) continue;
            int j_x = v[j][0];
            int j_y = v[j][1];
            int j_w = v[j][2];
            int j_h = v[j][3];
            if ((i_x >= j_x && i_x <= j_x + j_w) || (i_x + i_w >= j_x && i_x + i_w <= j_x + j_w)) {
                if ((i_y >= j_y && i_y <= j_y + j_h) || (i_y + i_h >= j_y && i_y + i_h <= j_y + j_h)) {
                    adj[i][j] = 1;
                    adj[j][i] = 1;
                }
            }
        }
    }
    for (int i = 0; i < (1<<n); i++) {
        for (int j = 0; j < 25; j++) {
            if (i & (1<<j)) {

            }
        }
    }
    return 0;
}