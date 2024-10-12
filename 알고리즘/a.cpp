#include <bits/stdc++.h>
using namespace std;

int n, a, sum;
int main() {
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> a;
		v[i] = a;
		sum += a;
	};
	sort(v.begin(), v.end());
	for (int i : v) {
		cout << i << " ";
	}
	cout << "\n";
	cout << fixed << setprecision(2) << sum / (double)n << "\n";
	return 0;
}