#include <bits/stdc++.h>

using namespace std;

int A, B;
vector<int> v;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B;
	A--; B--;
	for (int i = 1; v.size() <= 1000; i++) {
		for (int j = 1; j <= i; j++) {
			v.push_back(i);
		}
	}

	int ans = 0;

	for (int i = A; i <= B; i++) {
		ans += v[i];
	}

	cout << ans;
}

