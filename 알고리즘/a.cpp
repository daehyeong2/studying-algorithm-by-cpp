#include <bits/stdc++.h>
using namespace std;

int N, M, A, B, a, psum[100004], sum;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		sum += a;
		psum[i] = sum;
	}
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		cout << psum[B] - psum[A - 1] << "\n";
	}
	return 0;
}