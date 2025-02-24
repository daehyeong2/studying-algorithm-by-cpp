#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, dy[] = { -1, 0, 1, 0 }, dx[] = { 0, 1, 0, -1 };
pair<int, int> ju, cr;
int arr[304][304], visited[304][304];
vector<pair<int, int>> v;
char tmp;

int main() {
	cin >> n >> m;
	cin >> ju.first >> ju.second >> cr.first >> cr.second;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			if (tmp == '#' || tmp == '1') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}
	queue<pair<int, int>> q;
	q.push({ ju.first - 1, ju.second - 1 });
	visited[ju.first - 1][ju.second - 1] = 1;
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
			if (arr[ny][nx] == 1) {
				visited[ny][nx] = visited[y][x] + 1;
				arr[ny][nx] = 0;
				v.push_back({ ny, nx });
			}
			else {
				visited[ny][nx] = visited[y][x];
				q.push({ ny, nx });
			}
		}
		if (q.empty()) {
			for (pair<int, int> i : v) {
				q.push(i);
			}
			v = {};
		}
	}
	cout << visited[cr.first - 1][cr.second - 1] - 1 << "\n";
}