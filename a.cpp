#include <bits/stdc++.h>
using namespace std;

int c, s;
string num1, num2, ret;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> num1 >> num2;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    for (int i = 0; i < max(num1.size(), num2.size()); i++) {
        if (i >= num1.size()) {
            int num = num2[i] - '0' + c;
            c = num / 10;
            s = num % 10;
            ret = to_string(s) + ret;
            continue;
        } else if (i >= num2.size()) {
            int num = num1[i] - '0' + c;
            c = num / 10;
            s = num % 10;
            ret = to_string(s) + ret;
            continue;
        }
        int num = (num1[i] - '0') + (num2[i] - '0') + c;
        c = num / 10;
        s = num % 10;
        ret = to_string(s) + ret;
    }
    if (c) cout << to_string(c) + ret << "\n";
    else cout << ret << "\n";
    return 0;
}