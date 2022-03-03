/*
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	int a = 1, b = 1;

	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) { // a와 b에 0이 입력되는 순간 while문을 break로 빠져나간다
			break;
		}
		cout << a + b << "\n";

	}

	return 0;
}