#include <bits/stdc++.h>
#define long long ll;

using namespace std;


int n;
int arr[22];
bool vis[2000002];

void func(int k, int ans) {
	if (n == k) {
		vis[ans] = 1;
		return;
	}

	func(k + 1, ans + arr[k]);
	func(k + 1, ans);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	func(0, 0);
	
	for (int i = 0; i < 2000002; i++) {
		if (!vis[i]) {
			cout << i; break;
		}
	}
}