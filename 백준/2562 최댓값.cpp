/*
9개의 서로 다른 자연수가 주어질 때, 
이들 중 최댓값을 찾고 그 최댓값이 몇 번째 수인지를 구하는 프로그램을 작성하시오.

예를 들어, 서로 다른 9개의 자연수

3, 29, 38, 12, 57, 74, 40, 85, 61

이 주어지면, 이들 중 최댓값은 85이고, 이 값은 8번째 수이다.
*/

#include <iostream>

using namespace std;

int main() {
	int arr[9]; // 길이 9의 int 배열을 생성한다
	int num;

	for (int i = 0; i < 9; i++) {
		cin >> num;
		arr[i] = num; 
	} // 입력받은 숫자로 배열을 초기화한다

	int max = 0; 
	int index = 0; 

	for (int i = 0; i < 9; i++) {
		if (arr[i] > max) {
			max = arr[i];
			index = i + 1; //  배열에서 index는 0부터 시작하므로, 1을 더해준다
		}
	} // 최댓값이 어떤 수인지, 어느 위치에 있는지 판단한다

	cout << max << endl << index << endl;

	return 0;
}