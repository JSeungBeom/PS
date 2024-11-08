#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int k;
string s;
int arr[10];
bool vis[10];

long long mn = 10000000000;
long long mx = 0;

void solve(int n) {
	if (n == k + 1) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '<') {
				if (arr[i] >= arr[i + 1])
					return;
			}
			else {
				if (arr[i] <= arr[i + 1])
					return;
			}
		}

		string tmp = "";

		for (int i = 0; i < n; i++) {
			tmp += (char)(arr[i] + '0');
		}

		long long num = stoll(tmp);

		mx = max(num, mx);
		mn = min(num, mn);

		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		arr[n] = i;
		solve(n + 1);
		vis[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;

	char c;
	
	for (int i = 0; i < k; i++) {
		cin >> c;

		s += c;
	}

	solve(0);

	string ans1 = to_string(mx);
	string ans2 = to_string(mn);
	if (ans1.length() < k + 1) {
		ans1.insert(ans1.begin(), '0');
	}

	if (ans2.length() < k + 1) {
		ans2.insert(ans2.begin(), '0');
	}

	cout << ans1 << '\n' << ans2;
}

