#include <bits/stdc++.h>
using namespace std;

int n, argument, mask;
string command;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "add") {
            cin >> argument;
            mask |= (1 << (argument-1));
        } else if (command == "remove") {
            cin >> argument;
            mask &= ~(1<<(argument-1));
        } else if (command == "check") {
            cin >> argument;
            if (mask & (1<<(argument-1))) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (command == "toggle") {
            cin >> argument;
            if (mask & (1<<(argument-1))) mask &= ~(1<<(argument-1));
            else mask |= (1<<(argument-1));
        } else if (command == "all") {
            mask |= ((1<<20)-1);
        } else if (command == "empty") {
            mask = 0;
        }
    }
    return 0;
}