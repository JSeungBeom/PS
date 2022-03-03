/*
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
각 테스트 케이스마다 A+B를 출력한다.
*/

#include <iostream>

using namespace std;

int main() {
	int testcase; // 몇 번의 연산을 할지를 정하는 Testcase의 수
	int a, b; //  실제 연산에 사용되는 수 a, b 

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> a >> b;
		cout << a + b << endl;
	} // 주어진 testcase만큼 a + b를 진행한다.

	return 0;
}