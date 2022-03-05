/*
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;
	int cnt = 0;
	int* arr = new int[n]; // 크기 n의 동적 배열을 생성

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	} // 배열의 각 요소를 입력받고 초기화 한다

	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			cnt++;
			continue;
		} // 1은 소수가 아니다
		for (int j = 2; j < arr[i]; j++) {
			if (arr[i] % j == 0) {
				cnt++;
				break;
			}
		} // 소수는 1과 자신을 제외한 숫자로 나눠지지 않는 수이다
		// 따라서 2부터 자신 - 1까지 검사하여, 나누어 떨어진다면 그 수는 소수가 아닌 수이다
	} // 소수가 아닌 수를 판단하는 for문

	delete[]arr;

	cout << n - cnt << endl; // 입력받은 수의 개수 중 소수가 아닌 수를 제외한다

	return 0;

}