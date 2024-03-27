#include <bits/stdc++.h>

using namespace std;

int p, t;
int arr[20];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> p;

	while (p--) {
		cin >> t;

		int cnt = 0;

		for (int i = 0; i < 20; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < 20; i++) {
			for (int j = i; j < 20; j++) {
				if (arr[i] > arr[j]) cnt++;
			}
		}

		cout << t << ' ' << cnt << '\n';
	}
}