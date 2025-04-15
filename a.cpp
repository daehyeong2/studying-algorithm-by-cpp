#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, a, mx;
ll ret;
stack<pair<int, ll>> stk;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (i==0) {
            stk.push({a, 1});
            continue;
        }
        if (stk.top().first > a) {
            ret++;
            // cout << "Added " << 1 << "(" << stk.top().first << ")" << " : " << i << "\n";
        }
        else {
            ret+=stk.top().second;
            // cout << "Added " << stk.top().second << "(" << stk.top().first << ")" << " : " << i << "\n";
        }
        int cnt = 1;
        while (stk.size() && a >= stk.top().first) {
            if (a == stk.top().first) {
                cnt+=stk.top().second;
            }
            mx = stk.top().first;
            if (mx > a) continue;
            stk.pop();
            if (stk.size() && stk.top().first >= mx) {
                if (stk.top().first > a) {
                    ret++;
                    // cout << "Added " << 1 << "(" << stk.top().first << ")" <<  " :: " << i << " " << mx << "\n";
                } else {
                    ret+=stk.top().second;
                    // cout << "Added " << stk.top().second << "(" << stk.top().first << ")" <<  " :: " << i << " " << mx << "\n";
                }
            } else if (stk.size()) stk.pop();
        }
        stk.push({a, cnt});
    }
    cout << ret << "\n";
    return 0;
}