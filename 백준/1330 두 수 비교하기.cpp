/*
두 정수 A와 B가 주어졌을 때, A와 B를 비교하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	int a, b;

	cin >> a >> b;

	if (a > b) {
		cout << ">" << endl;
	}

	else if (a < b) {
		cout << "<" << endl;
	}

	else {
		cout << "==" << endl;
	} // 두 정수의 대소 비교에서, 크거나 작지 않다면 같은 수이기에 else 문을 사용 가능하다.

	return 0;
}