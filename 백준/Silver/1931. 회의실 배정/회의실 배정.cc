#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
pair<int ,int> arr[100003];
int ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].Y >> arr[i].X;
	}

	sort(arr, arr + n);

	int tmp = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i].Y >= tmp) {
			tmp = arr[i].X;
			ans++;
		}
	}

	cout << ans;
}


