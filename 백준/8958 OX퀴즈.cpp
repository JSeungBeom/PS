/*
"OOXXOXXOOO"와 같은 OX퀴즈의 결과가 있다. O는 문제를 맞은 것이고, X는 문제를 틀린 것이다.
문제를 맞은 경우 그 문제의 점수는 그 문제까지 연속된 O의 개수가 된다.
예를 들어, 10번 문제의 점수는 3이 된다.

"OOXXOXXOOO"의 점수는 1+2+0+0+1+0+0+1+2+3 = 10점이다.

OX퀴즈의 결과가 주어졌을 때, 점수를 구하는 프로그램을 작성하시오.
*/


#include <iostream>
#include <string.h> // 문자열을 다룰 수 있는 다양한 함수가 포함된 헤더 파일

using namespace std;

int main() {
	int testcase;
	int count = 0;
	int sum = 0;
	char ox[81];

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> ox; // 문자열을 입력받는다
		int len = strlen(ox); // 길이 81의 문자열에서 입력받는 문자 다음에는 어떤 문자가 올지 모르므로, strlen 함수를 이용한다
		for (int j = 0; j < len; j++) {
			if (ox[j] == 'O') {
				count++;
				sum += count;
			} // 문자 'O'일때는 count를 1 증가시키고 이를 sum에 더한다

			if (ox[j] == 'X') {
				count = 0;
			} // 문자 'X'일때는 count를 다시 0으로 초기화시킨다
		}

		cout << sum << endl;

		sum = 0; 
		count = 0; // 다른 testcase를 실행해야 하므로 sum, count를 다시 0으로 초기화한다
	}

	return 0;
}