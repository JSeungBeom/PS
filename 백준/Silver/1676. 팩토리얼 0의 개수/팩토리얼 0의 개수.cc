#include <bits/stdc++.h>

using namespace std;

int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	int ans = 0;
	while (n) {
		ans += n / 5;
		n /= 5;
	}
	cout << ans;
}