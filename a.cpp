#include <bits/stdc++.h>
using namespace std;

int n, k, m, v, c, ret;
string s;
vector<pair<int, int>> v1;
vector<int> v2;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        v1.push_back({m, v});
    }
    for (int i = 0; i < k; i++) {
        cin >> c;
        v2.push_back(c);
    }
    priority_queue<int> pq;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int j = 0;
    for (int i = 0; i < k; i++) {
        while (j < n && v1[j].first <= v2[i]) pq.push(v1[j++].second);
        if (pq.size()) {
            ret += pq.top(); pq.pop();
        }
    }
    cout << ret << "\n";
    return 0;
}