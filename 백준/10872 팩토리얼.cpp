/*
0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int factorial(int n) {
	if (n <= 1)
		return 1;
	return n * factorial(n - 1);
} // 재귀함수를 통한 factorial 계산 

int main() {
	int n;
	
	cin >> n;
	cout << factorial(n) << "\n";

	return 0;
}