#include <bits/stdc++.h>

using namespace std;

int k;
int arr[52];
int ans[52];

void back_tracking(int st, int n) {
	if (n == 6) {
		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	for (int i = st; i < k; i++){
		ans[n] = arr[i];
		back_tracking(i + 1, n + 1);
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> k;
		if (k == 0) return 0;

		fill(arr, arr + k + 1, 0);

		fill(ans, ans + k + 1, 0);
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}

		back_tracking(0, 0);
		cout << '\n';
	}


}