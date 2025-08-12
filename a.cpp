#include <bits/stdc++.h>
using namespace std;

int n, ret = 1e9, S[24][24];

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> S[i][j];
        }
    }
    for (int num = 0; num < (1<<n); num++) {
        int cnt = 0;
        vector<int> players;
        vector<int> players2;
        for (int i = 0; i < n; i++) {
            if (num & (1<<i)) {
                cnt++;
                players.push_back(i);
            } else {
                players2.push_back(i);
            }
        }
        if (n / 2 != cnt) continue;
        int score = 0;
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                score += S[players[i]][players[j]];
            }
        }
        int score2 = 0;
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                score2 += S[players2[i]][players2[j]];
            }
        }
        ret = min(ret, abs(score - score2));
        if (ret == 0) break;
    }
    cout << ret << "\n";
    return 0;
}