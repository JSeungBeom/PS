/*
세 개의 자연수 A, B, C가 주어질 때 A × B × C를 계산한 결과에
0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지를 구하는 프로그램을 작성하시오.

예를 들어 A = 150, B = 266, C = 427 이라면 A × B × C = 150 × 266 × 427 = 17037300 이 되고,
계산한 결과 17037300 에는 0이 3번, 1이 1번, 3이 2번, 7이 2번 쓰였다.
*/

#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	int result;
	int arr[10] = { 0 }; // 길이 10의 배열을 모두 0으로 초기화한다
	cin >> a >> b >> c;


	result = a * b * c;
	
	while (result != 0) {
		arr[result % 10]++;
		result /= 10;
	} // result가 0이 될때까지 1의 자리를 구하고, result를 10으로 나누기를 반복한다

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	} // 각 index의 값들을 출력한다

	return 0;
}

