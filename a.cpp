#include <bits/stdc++.h>
using namespace std;

int t, h, l, cnt, d[51][51], elv[51];
map<int, pair<int, int>> mp;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++) {
        memset(elv, 0, sizeof(elv));
        memset(d, 0, sizeof(d));
        mp = {}; cnt = 0;
        cin >> h >> l;
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < l; k++) {
                cin >> d[j][k];
                if (d[j][k] != -1) {
                    mp[d[j][k]] = {j, k};
                }
                cnt = max(cnt, d[j][k]);
            }
        }
        int ret = 0;
        for (int j = 1; j <= cnt; j++) {
            int time = mp[j].first * 20 + min(abs(elv[mp[j].first] - mp[j].second), min(l-mp[j].second + elv[mp[j].first], l-elv[mp[j].first] + mp[j].second)) * 5;
            elv[mp[j].first] = mp[j].second;
            ret += time;
        }
        cout << ret << "\n";
    }
    return 0;
}