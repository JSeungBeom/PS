#include <bits/stdc++.h>

using namespace std;

char arr[17];
char num[17];
int l, c;

void func(int cur, int st) {
	if (cur == l) {
		int cnt1 = 0;
		int cnt2 = 0;

		for (int i = 0; i < l; i++) {
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i'
				|| arr[i] == 'o' || arr[i] == 'u') {
				cnt1++;
			}
			else
				cnt2++;
		}

		if (cnt1 >= 1 && cnt2 >= 2) {
			for (int i = 0; i < l; i++) {
				cout << arr[i];
			}
			cout << "\n";

			return;
		}
		else
			return;
	}

	for (int i = st; i < c; i++) {
		arr[cur] = num[i];
		func(cur + 1, i + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> num[i];
	}

	sort(num, num + c);
	func(0, 0);
}