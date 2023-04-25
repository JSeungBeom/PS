#include <bits/stdc++.h>

using namespace std;

int t, n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;

		int ans[5] = { 0, };
		ans[0] += n / 60; // 전처리, ADDH 횟수 추가
		n %= 60; // 0 ~ 59분 

		// 35분 넘어가면, 60분에서 빼는게 최소 횟수
		if (n > 35) {
			ans[0]++; // ADDH 
			// 일의 자리가 5 이상이면, 10분 단위에서 빼는 게 최소 횟수
			if (n % 10 >= 5) {
				ans[2] += 6 - (n / 10 + 1); // MINT
				ans[4] += 10 - (n % 10); // MIN0
			}
			else {
				ans[2] += 6 - (n / 10); // ADDT
				ans[3] += n % 10; // ADD0
			}
		}
		else { // 35분 이하라면, ADDT하는게 최소 횟수
			if (n % 10 > 5) { // 일의 자리가 5 넘어가면, 10분 단위에서 빼는 게 최소 횟수
				ans[1] += n / 10 + 1;
				ans[4] += 10 - ( n % 10);
			}
			else {
				ans[1] += n / 10;
				ans[3] += n % 10;
			}
		}

		for (int i = 0; i < 5; i++) {
			cout << ans[i] << " ";
		}

		cout << "\n";
	}
}