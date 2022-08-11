#include <bits/stdc++.h>

using namespace std;

int n;
int s[10];
int w[10];
bool broken[10];
int mx = 0;
int num = 0;

void func(int cur) {
	if (cur == n) {
		mx = max(mx, num);
		return;
	}

	if (s[cur] <= 0 || num == n - 1) {
		func(cur + 1);
		return;
	}

	

	for (int i = 0; i < n; i++) {
		if (i == cur || s[i] <= 0)
			continue;

		s[cur] -= w[i];
		s[i] -= w[cur];
		if (s[cur] <= 0) {
			num++;
		}
		if (s[i] <= 0) {
			num++;
		}
		func(cur + 1);
		if (s[cur] <= 0) {
			num--;
		}
		if (s[i] <= 0) {
			num--;
		}
		s[cur] += w[i];
		s[i] += w[cur];
	}


}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> w[i];
	}

	func(0);
	cout << mx;
}