#include <bits/stdc++.h>
using namespace std;

const int V = 4;
vector<int> adj[V]; bool visited[V];

void go(int from) {
	visited[from] = 1;
	cout << from << "\n";
	for (int i : adj[from]) {
		if (!visited[i]) {
			go(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[0].push_back(3);

	adj[1].push_back(0);
	adj[1].push_back(2);

	adj[2].push_back(0);
	adj[2].push_back(1);

	adj[3].push_back(0);

	for (int i = 0; i < V; i++) {
		if (adj[i].size() && !visited[i]) {
			go(i);
		}
	}

	return 0;
}