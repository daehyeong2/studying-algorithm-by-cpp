#include <bits/stdc++.h>
using namespace std;

int n, ret;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < 7; i++) {
        if (n & (1<<i)) ret++;
    }
    cout << ret << "\n";
    return 0;
}