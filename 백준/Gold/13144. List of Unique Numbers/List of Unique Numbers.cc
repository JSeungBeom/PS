#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr(100003);
vector<bool> chk(100003);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int en = 0;
	long long ans = 0;

	chk[arr[0]] = 1;

	for (int st = 0; st < n; st++) {
		while (en < n - 1 && !chk[arr[en + 1]]) {
			en++;
			chk[arr[en]] = 1;
		}

		chk[arr[en]] = 1;
		ans += en - st + 1;
		chk[arr[st]] = 0;
	}

	cout << ans;
}

// 1 1 2 1 1
