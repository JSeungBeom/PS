#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;

int roads[100005];
int price[100005];
int tmp[100005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int junk;

	for (int i = 0; i < n - 1; i++) {
		cin >> roads[i];
	}

	for (int i = 0; i < n - 1; i++) {
		cin >> price[i];
	}

	cin >> junk;

	int mn = 0x7fffffff;
	long long ans = 0;

	for (int i = 0; i < n - 1; i++) {
		if (price[i] < mn) {
			mn = price[i];
		}
		ans += (roads[i] * mn);
	}

	cout << ans;



}