#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll arr[100005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	ll mxval = (1ll << 62) - 1;
	ll mxcnt = 0;
	int cnt = 1;

	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[i - 1]) {
			if (cnt > mxcnt) {
				mxcnt = cnt;
				mxval = arr[i - 1];
			}

			cnt = 1;
		}
		else {
			cnt++;
		}
	}

	if (cnt > mxcnt) mxval = arr[n - 1];
	cout << mxval;
}