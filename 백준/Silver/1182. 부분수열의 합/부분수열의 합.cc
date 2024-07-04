#include <bits/stdc++.h>

using namespace std;

int n, s;
int arr[25];
bool vis[25];
int cnt;

void solve(int cur, int tot) {
	if (cur == n) {
		if (tot == s) cnt++;
		return;
	}

	solve(cur + 1, tot);
	solve(cur + 1, tot + arr[cur]);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	solve(0, 0);

	if (s == 0) cnt--;

	cout << cnt;
}