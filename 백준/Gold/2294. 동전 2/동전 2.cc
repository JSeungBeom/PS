#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
using namespace std;

int n, k;
int a[105], d[100005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	fill(d + 1, d + 100005, INF);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d[a[i]] = 1;
	}



	for (int i = 0; i < n; i++) {
		for (int j = a[i]; j <= k; j++) {
			d[j] = min(d[j], d[j - a[i]] + 1);
		}
	}

	if (d[k] != INF) cout << d[k];
	else cout << -1;
}