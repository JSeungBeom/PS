#include <bits/stdc++.h>

using namespace std;

bool broken[10];
int ans;
int cnt;

int can_move(int num) {
	if (num == 0) {
		if (broken[num]) return -1;
		return 1;
	}

	int btn = 0;
	while (num > 0) {
		if (broken[num % 10]) return -1;
		num /= 10;
		btn++;
	}

	return btn;
}
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	int m;

	cin >> n >> m;

	int num;
	while (m--) {
		cin >> num;
		broken[num] = 1;
	}

	if (n == 100) {
		cout << 0;
		return 0;
	}

	ans = abs(100 - n);
	for (int i = 0; i <= 1000000; i++) {
		int numbtn = can_move(i);
		if (numbtn > 0) {
			numbtn += abs(i - n);
			ans = min(ans, numbtn);
		}
	}

	cout << ans;


}