#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int arr[1000005];
int tmp[1000005];
vector<int> v;

int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		tmp[i] = arr[i];
	}

	sort(arr, arr + n);

	int val = 0x7f7f7f7f;

	for (int i = 0; i < n; i++) {
		if (arr[i] != val) {
			v.push_back(arr[i]);
			val = arr[i];
		}
	}

	for (int i = 0; i < n; i++) {
		cout << lower_bound(v.begin(), v.end(), tmp[i]) - v.begin() << ' ';
	}
}