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

	bool* prime = new bool[n + 1]; // index와 요소의 값을 맞추기 위해 배열의 크기를 n + 1로 한다

	if (n <= 1) {
		return 0;
	} // n이 1보다 작거나 같다면 종료

	for (int i = 2; i <= n; i++) {
		prime[i] = true;
	} // 2부터 n까지 index의 요소들을 일단 모두 true로 초기화

	for (int i = 2; i <= n; i++) {
		if (prime[i] == true) {
			for (int j = 2; i * j <= n; j++) {
				prime[i * j] = false;
			}
		} // prime[i] (소수)의 배수들은 소수가 아닌 수이니, false를 대입한다
	}

	for (int i = m; i <= n; i++) {
		if (prime[i] == true) {
			cout << i << "\n"; // endl을 "\n"으로 변경하여, 실행 시간을 단축시킨다
		}
	} // 소수만 출력

	delete[]prime;
}

/*
에라토스테네스의 체 : 소수를 찾는 방법
2부터 시작하여 2의 배수는 모두 소수가 아니니 모두 false로 세팅
3의 배수 또한 모두 소수가 아니니 false로 세팅
이런 식으로 소수가 아닌 수를 false로 세팅한다
시간복잡도를 많이 줄일 수 있다
*/