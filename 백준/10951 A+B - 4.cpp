/*
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	int a, b;
	
	while (cin >> a >> b) {
		cout << a + b << "\n";
	} // a와 b가 입력되는 동안, 즉 EOF가 될 때까지 입력을 받는 while문
	// 통상적으로 윈도우에서 EOF(End of File)은 Ctrl + Z이다

	return 0;
}