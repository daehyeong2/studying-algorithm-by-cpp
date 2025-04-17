#include <bits/stdc++.h>
using namespace std;

int n;
double a;
priority_queue<double> pq;
vector<double> ret;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
        if (pq.size() > 5) pq.pop();
    }
    for (int i = 0; i < 5; i++) {
        ret.push_back(pq.top()); pq.pop();
    }
    for (int i = 4; i >= 0; i--) cout << ret[i] << "\n";
    return 0;
}