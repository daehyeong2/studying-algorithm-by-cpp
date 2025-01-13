#include <bits/stdc++.h>
using namespace std;

const int max_n = 500000;
int a, b, visited[2][max_n + 4], turn = 1;
bool ok;

int main() {
	cin >> a >> b;
	if (a == b) { cout << 0 << "\n"; return 0; }
	queue<int> q;
	visited[0][a] = 1;
	q.push(a);
	while (q.size()) {
		b += turn;
		if (b > max_n) break;
		if(visited[turn % 2][b]) {
			ok = 1; break;
		}
		int qSize = q.size();
		for (int _ = 0; _ < qSize; _++) {
			int n = q.front(); q.pop();
			for (int i : {n + 1, n - 1, n * 2}) {
				if (i < 0 || i > max_n || visited[turn % 2][i]) continue;
				visited[turn % 2][i] = visited[(turn + 1) % 2][n] + 1;
				if (i == b) {
					ok = 1;
					break;
				}
				q.push(i);
			}
			if (ok) break;
		}
		if (ok) break;
		turn++;
	}
	if (ok) cout << turn << "\n";
	else cout << -1 << "\n";
}