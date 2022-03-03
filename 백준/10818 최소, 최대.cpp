/*
N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	
	int n, num;
	cin >> n;
	int *arr = new int[n]; // 길이 n의 동적 배열을 생성한다

	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[i] = num;
	} // 입력받은 숫자들로 배열을 초기화한다

	int max = -1000000; 
	int min = 1000000;

	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		} // 최댓값을 찾기 위한 if문

		if (arr[i] < min) {
			min = arr[i];
		} // 최솟값을 찾기 위한 if문
	} // 각 index들의 값을 검사하는 for문

	delete arr; // 동적 배열의 메모리를 반납한다

	cout << min << " " << max << endl;

	return 0;
}