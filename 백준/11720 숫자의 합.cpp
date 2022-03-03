/*
N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {

	int n;
	int sum = 0;

	cin >> n;

	char* num = new char[n]; // 길이 n의 char 타입 동적 배열을 생성
	cin >> num;
	for (int i = 0; i < n; i++) {
		sum += num[i] - '0';
	} // ASCII 코드에 따라 숫자 0~9는 48번부터 할당이 되므로, 48번에 해당하는 '0'을 빼 순수 숫자를 얻을 수 있다.
	// num[i] - '0' 대신 num[i] - 48을 해도 결과는 동일하다.

	cout << sum << endl;

	return 0;
}