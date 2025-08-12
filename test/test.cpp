#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, x, y, w, h, ret_cnt, adj[27];
ll ret_s;
vector<vector<ll>> v;

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
            if ((adj[i] & (1<<j)) || (adj[j] & (1<<i))) continue;
            int j_x = v[j][0];
            int j_y = v[j][1];
            int j_w = v[j][2];
            int j_h = v[j][3];
            if ((i_x >= j_x && i_x <= j_x + j_w - 1) || (i_x + i_w - 1 >= j_x && i_x + i_w - 1 <= j_x + j_w - 1)) {
                if ((i_y >= j_y && i_y <= j_y + j_h - 1) || (i_y + i_h - 1 >= j_y && i_y + i_h - 1 <= j_y + j_h - 1)) {
                    adj[i] |= (1<<j);
                    adj[j] |= (1<<i);
                }
            }
        }
    }
    for (int i = 0; i < (1<<n); i++) {
        int visited = 0;
        ll hap = 0;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if ((i & (1<<j)) && !(visited & adj[j])) {
                visited |= (1<<j);
                hap += v[j][2] * v[j][3];
                cnt++;
            }
        }
        if (cnt > ret_cnt) {
            ret_cnt = cnt;
            ret_s = hap;
        } else if (cnt == ret_cnt && hap > ret_s) {
            ret_s = hap;
        }
    }
    cout << ret_cnt << " " << ret_s << "\n";
    return 0;
}