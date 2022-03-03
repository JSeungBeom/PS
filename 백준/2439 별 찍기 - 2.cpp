/*
첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제

하지만, 오른쪽을 기준으로 정렬한 별을 출력하시오.
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) { // 줄바꿈을 위한 외부의 for문
		for (int j = n - 1 ; j >= i; j--) {
			cout << " ";
		} // 오른쪽 정렬하기 위한 공백을 만드는 for문

		for (int k = 1; k <= i; k++) {
			cout << "*";
		} // 별 찍기 for문

		cout << "\n";
	}

	return 0;

}