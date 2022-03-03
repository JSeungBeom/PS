/*
두 자연수 A와 B가 있을 때, A%B는 A를 B로 나눈 나머지 이다.
예를 들어, 7, 14, 27, 38을 3으로 나눈 나머지는 1, 2, 0, 2이다. 

수 10개를 입력받은 뒤, 이를 42로 나눈 나머지를 구한다.
그 다음 서로 다른 값이 몇 개 있는지 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	int arr[10];
	int count = 0;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		arr[i] %= 42; 
	} // 배열에 값들을 입력받고 이를 42로 나눈 나머지로 초기화한다


	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (arr[i] == arr[j]) {
				count++;
				break;
			}
		}
	} // 각 요소들끼리 모두 비교해서 같은 값일 경우 count를 1 더해주고 내부의 for문을 빠져나온다

	cout << 10 - count << endl; 

	return 0;
}