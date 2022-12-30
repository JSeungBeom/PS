#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
int t[1500003];
int p[1500003];
int d[1500003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = n; i >= 1; i--) {
		if(i + t[i] <= n + 1)
		{
			d[i] = max(d[i + t[i]] + p[i], d[i + 1]);
		}
		else {
			d[i] = d[i + 1];
		}
	}

	cout << *max_element(d + 1, d + 1 + n);

}