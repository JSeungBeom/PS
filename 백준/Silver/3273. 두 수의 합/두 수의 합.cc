#include <bits/stdc++.h>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[1000001] = {};
	int freq[2000001] = {};

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int x;
	cin >> x;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (freq[x - arr[i]]) {
			cnt++;
		}
		else
			freq[arr[i]] = 1;
	}

	cout << cnt;
}