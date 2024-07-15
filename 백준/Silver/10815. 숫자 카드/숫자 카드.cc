#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
int arr[500005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cin >> m;
	int num;

	for (int i = 0; i < m; i++) {
		cin >> num;
		cout << binary_search(arr, arr + n, num) << ' ';
	}

}