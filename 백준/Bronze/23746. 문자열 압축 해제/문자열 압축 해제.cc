#include <bits/stdc++.h>

using namespace std;

int n, s, e;
char idx;
string st;
string a[300];
string ans;
string ans1 = "";

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--) {
		cin >> st >> idx;
		a[idx] = st;
	}

	cin >> ans;
	for (int i = 0; i < ans.length(); i++) {
		ans1 += a[ans[i]];
	}

	cin >> s >> e;

	for (int i = s - 1; i < e; i++)	{
		cout << ans1[i];
	}
}