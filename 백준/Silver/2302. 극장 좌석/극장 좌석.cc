#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;
int d[50];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int num;

	arr.push_back(0);

	while (m--) {
		cin >> num;
		arr.push_back(num);
	}
	arr.push_back(n + 1);

	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	int ans = 1;
	for (int i = 1; i < arr.size(); i++) {
		ans *= d[arr[i] - arr[i - 1] - 1];
	}

	cout << ans;
}

