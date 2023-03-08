#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
int n, cnt;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	if (n == 1) {
		cout << 0; return 0;
	}
	vector<bool> state(n + 1, 1); // 모두 소수로 생각

	// 에라토스테네스의 체, 시간복잡도는 O(nlog(logn)) 이란다.
	for (int i = 2; i * i <= n; i++) {
		if (state[i]) {
			for (int j = i * i; j <= n; j += i) {
				state[j] = 0;
			}
		}
	}

	// 소수들 다 넣어버리기
	for (int i = 2; i <= n; i++) {
		if(state[i]) primes.push_back(i);
	}

	// 연속된 소수의 합이므로, 투 포인터 풀이 
	int en = 1;
	int sum = primes[0];
 
	for (int st = 0; st < primes.size(); st++) {
		// sum이 n보다 작을 때까지, en을 움직이면서 누적합을 계산
		while (en < primes.size() && sum < n) {
			sum += primes[en];
			en++;
		}

		// 누적합이 n이 아닐 수 있으므로, n일때만 cnt 증가
		if (sum == n) {
			cnt++;
		}

		sum -= primes[st]; // st를 움직여야 되므로, 누적합에서 st에서 값을 빼준다
	}

	cout << cnt;


}

// 3 -> 2, 3
