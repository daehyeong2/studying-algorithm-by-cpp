#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d, unf[11];

int Find(int v){
    if(v == unf[v]) return v;
    else return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
    int fa = Find(a);
    int fb = Find(b);
    if(fa != fb) unf[fa] = fb;
}

int main(){
    cin >> n;
    for(int i = 1; i < 11; i++) unf[i] = i;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        Union(a, b);
    }
    cin >> c >> d;
    if(Find(c) == Find(d)) cout << "YES\n";
    else cout << "NO\n";
}