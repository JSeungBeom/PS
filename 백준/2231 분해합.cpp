/*
어떤 자연수 N이 있을 때, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미한다.
어떤 자연수 M의 분해합이 N인 경우, M을 N의 생성자라 한다.
예를 들어, 245의 분해합은 256(=245+2+4+5)이 된다. 따라서 245는 256의 생성자가 된다.
물론, 어떤 자연수의 경우에는 생성자가 없을 수도 있다.
반대로, 생성자가 여러 개인 자연수도 있을 수 있다.

자연수 N이 주어졌을 때, N의 가장 작은 생성자를 구해내는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int partsum = i; // 분해합을 구할 변수
		int createnum = i; // 생성자를 저장할 변수
		int temp = i; // 계산을 위해 생성한 임시 변수
		while (temp != 0) {
			partsum += temp % 10;
			temp /= 10;
		} // 분해합은 n과 n을 이루는 각 자리수의 합
		if (partsum == n) {
			cout << createnum << "\n";
			return 0;
		} // 분해합과 n이 같다면 i는 n의 생성자이므로, 생성자를 출력하고 프로그램 종료
	}

	cout << 0 << "\n"; // n보다 작은 수를 검사하여, 생성자가 없다면 0을 출력

	return 0;
}