#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[1003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
	reverse(a, a + n);

	cout << a[k - 1];
}
