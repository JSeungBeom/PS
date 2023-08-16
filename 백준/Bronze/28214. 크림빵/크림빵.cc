#include <bits/stdc++.h>

using namespace std;

int n, k, p;
int arr[52][52];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> p;

	int cnt = n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < k; j++) {
			if (!arr[i][j]) count++;
		}
		if (count >= p) cnt--;
	}

	cout
		<< cnt;


}