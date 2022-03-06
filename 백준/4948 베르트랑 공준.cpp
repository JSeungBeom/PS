/*
베르트랑 공준은 임의의 자연수 n에 대하여, n보다 크고,
2n보다 작거나 같은 소수는 적어도 하나 존재한다는 내용을 담고 있다.

이 명제는 조제프 베르트랑이 1845년에 추측했고, 파프누티 체비쇼프가 1850년에 증명했다.

예를 들어, 10보다 크고, 20보다 작거나 같은 소수는 4개가 있다.
(11, 13, 17, 19) 또, 14보다 크고, 28보다 작거나 같은 소수는 3개가 있다. (17,19, 23)

자연수 n이 주어졌을 때, n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	int n;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> n;
		if (n == 0)
			break; // n을 계속 입력받다가, 0이 입력되면 프로그램이 종료
		int n2 = n * 2; 
		bool* prime = new bool[n2 + 1]; // index와 요소를 맞추기 위해 n2 + 1 크기의 배열을 생성
		for (int i = 2; i <= n2; i++) {
			prime[i] = true;
		} // 2부터 n2까지 index의 요소들을 true로 초기화

		for (int i = 2; i <= n2; i++) {
			for (int j = 2; i * j <= n2; j++) {
				if (prime[i] == true) {
					prime[i * j] = false;
				}
			}
		} // 2부터 n2까지 인덱스의 요소 중, true인 index(소수)의 배수는 소수가 아니므로 false를 대입
		// 2 * 2, 2 * 3, 2 * 4 ... 는 소수가 아니다
		int cnt = 0;
		for (int i = n + 1; i <= n2; i++) {
			if (prime[i] == true)
				cnt++;
		} // n보다 크고, n2보다 작은 수 중, true(소수)라면 cnt를 1 더한다
		cout << cnt << "\n";

		delete[]prime; // 동적 배열의 메모리 해제

	}

	return 0;
}
/*
에라토스테네스의 체 : 소수를 구하는 방법
prime[i]를 검사하여 true (소수)라면 그 배수는 모두 소수가 아닌 수이다
따라서 2부터 n까지 검사하여 소수가 아닌 수를 모두 false로 bool 배열에 저장한다
*/