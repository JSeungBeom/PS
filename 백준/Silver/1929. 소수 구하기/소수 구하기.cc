/*
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n;

	cin >> m >> n;

	bool* prime = new bool[n + 1];
	if (n <= 1) {
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		prime[i] = true;
	}

	for (int i = 2; i <= n; i++) {
		if (prime[i] == true) {
			for (int j = 2; i * j <= n; j++) {
				prime[i * j] = false;
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (prime[i] == true) {
			cout << i << "\n";
		}
	}

	delete[]prime;
}