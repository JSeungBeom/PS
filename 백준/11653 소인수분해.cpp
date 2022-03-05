/*
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;

	if (n == 1) {
		return 0;
	} // n이 1이라면 아무것도 출력하지 않는다
	for (int i = 2; i <= n; i++) {
		while (n % i == 0) {
			n /= i;
			cout << i << endl;
		} // 만약 n이 i로 나누어 떨어진다면, n을 i로 나누고 이를 출력한다. 나누어 떨어지지 않을 때까지 반복한다
	}

	return 0;
}