#include <bits/stdc++.h>

using namespace std;

int n;
int A[1000005];
int B, C;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cin >> B >> C;
	
	long long cnt = 0;

	for (int i = 0; i < n; i++) {
		if (A[i] - B <= 0)
			cnt++;
		else {
			A[i] -= B;
			cnt++;

			if (A[i] % C == 0) {
				cnt += (A[i] / C);
			}
			else {
				cnt += ((A[i] / C) + 1);
			}
		}
	}

	cout << cnt;
}