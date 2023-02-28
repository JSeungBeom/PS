#include <bits/stdc++.h>

using namespace std;

int m, n; 

int a[103][10003];

void compress(int arr[]) {
	vector<int> v(arr, arr + n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++) {
		arr[i] = upper_bound(v.begin(), v.end(), arr[i]) - v.begin();
	}
}

bool solve(int a[], int b[]) {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) return 0;
	}

	return 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		compress(a[i]);
	}

	int cnt = 0;

	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			if (solve(a[i], a[j]))
				cnt++;
		}
	}

	cout << cnt;

	
}