/*
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main() {
	char a[1000000];
	char b[1000000];
	int c[1000001] = { 0, };

	cin >> a >> b; // 큰 숫자를 입력받기 위해, char 배열로 입력받는다

	int a_len = strlen(a);
	int b_len = strlen(b); 

	int s = a_len > b_len ? a_len : b_len; // a와 b중, 더 큰 자릿수를 저장한다

	for (int i = 0; i < a_len; i++) {
		c[i] += a[a_len - i - 1] - '0';
	} 

	for (int i = 0; i < b_len; i++) {
		c[i] += b[b_len - i - 1] - '0';
	} // c에 a와 b의 요소들을 각각 더해서 저장한다

	for (int i = 0; i <= s; i++) {
		if (c[i] >= 10) {
			c[i] = c[i] - 10;
			c[i + 1]++;
		}
	} // 배열 c에 10이 넘는 수가 있다면, 10을 빼주고 그 다음 자릿수에 1을 추가한다 (덧셈과 같다) 
	if (c[s] == 0) {
		for (int i = s - 1; i >= 0; i--) {
			cout << c[i];
		}
	} // 처음 수가 0이라면 그 다음부터 출력한다
	else {
		for (int i = s; i >= 0; i--) {
			cout << c[i];
		}
	}

	return 0;
}