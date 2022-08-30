#include <bits/stdc++.h>

using namespace std;

int n;
int mn = 0x7f7f7f7f;
int mx = -0x7f7f7f7f;
int num[12];
int oper[12];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	int op;

	int idx = 1;

	for (int i = 0; i < 4; i++) {
		cin >> op;
		while (op--) {
			oper[idx++] = i;
		}
	}

	do {
		int ans = num[0];

		for (int i = 1; i < n; i++) {
			switch (oper[i]) {
			case 0:
				ans += num[i]; break;
			case 1:
				ans -= num[i]; break;
			case 2:
				ans *= num[i]; break;
			case 3:
				ans /= num[i]; break;
			default:
				break;
			}
		}
		mn = min(mn, ans);
		mx = max(mx, ans);
	} while (next_permutation(oper + 1, oper + n));
	 
	cout << mx << "\n" << mn;
}