#include <bits/stdc++.h>
using namespace std;

unsigned char a, b;
int fst, snd, n, c, here, ret, S=0, E=25, C[256][256], F[256][256], pre[256];
vector<vector<int>> D;

int main(){
    cin >> n;
    for (int i = 0; i < 256; i++) D.emplace_back();
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        fst = a - 'A'; snd = b - 'A';
        D[snd].push_back(fst);
        D[fst].push_back(snd);
        C[fst][snd] += c;
        C[snd][fst] += c;
    }
    while (true) {
        queue<int> q;
        q.push(S);
        memset(pre, -1, sizeof(pre));
        while (!q.empty()) {
            here = q.front(); q.pop();
            for (int there : D[here]) {
                if (F[here][there] < C[here][there] && pre[there] == -1) {
                    pre[there] = here;
                    q.push(there);
                    if (there == E) break;
                }
            }
        }
        if (pre[E] == -1) break;
        int flow = 1e9;
        for (int i = E; i != S; i = pre[i]) flow = min(flow, C[pre[i]][i]-F[pre[i]][i]);
        for (int i = E; i != S; i = pre[i]) {
            F[pre[i]][i] += flow;
            F[i][pre[i]] -= flow;
        }
        ret += flow;
    }
    cout << ret << "\n";
    return 0;
}
