/*
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;
	int* arr = new int[n]; // n의 size를 갖는 동적 배열

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	} // 배열에 요소들을 입력 받는다

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	} // bubble sort, O(n^2)

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	} // 배열 출력

	return 0;
}