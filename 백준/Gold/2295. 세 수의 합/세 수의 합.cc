#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll arr[1005];
vector<ll> two;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			two.push_back(arr[i] + arr[j]);
		}
	}
	
	sort(two.begin(), two.end());

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(two.begin(), two.end(), arr[i] - arr[j])) {
				cout << arr[i];
				return 0;
			}
		}
	}
}