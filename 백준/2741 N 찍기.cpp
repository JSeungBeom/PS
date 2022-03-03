/*
 자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 문제를 풀 때, 시간 제한에 유의하여야 한다
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cout << i << "\n";
	}

	return 0;
}