#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, k, cnt, a[104], visited[104];
vector<int> v;

int main(){
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i < k; i++) {
        if (!visited[a[i]]) {
            if (v.size() == n) {
                int last_pos = 0, pos;
                for (const int a_ : v) {
                    int here_pos = INF;
                    for (int j = i+1; j < k; j++) {
                        if (a_ == a[j]) {
                            here_pos = j;
                            break;
                        }
                    }
                    if (last_pos < here_pos) {
                        last_pos = here_pos;
                        pos = a_;
                    }
                }
                visited[pos] = 0;
                cnt++;
                v.erase(find(v.begin(), v.end(), pos));
            }
            v.push_back(a[i]); visited[a[i]] = 1;
        }
    }
    cout << cnt << "\n";
    return 0;
}