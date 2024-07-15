#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
int A[500005];
int B[500005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	for (int i = 0; i < m; i++)
		cin >> B[i];

	sort(A, A + n);
	sort(B, B + m);

	vector<int> ans;

	for (int i = 0; i < n; i++) {
		if (!binary_search(B, B + m, A[i]))
			ans.push_back(A[i]);
	}

	cout << (int)ans.size() << '\n';
	for (auto e : ans)
		cout << e << ' ';
}