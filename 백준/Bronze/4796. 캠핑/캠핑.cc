#include <bits/stdc++.h>

using namespace std;

int L, P, V;
int t = 1;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			return 0;

		int ans = 0;
	
		ans += V / P * L;

		if (V % P <= L) {
			ans += V % P;
		}
		else {
			ans += L;
		}

		cout << "Case " << t++ << ": " << ans << "\n";
	}
}