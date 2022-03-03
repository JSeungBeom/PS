/*
문자열 S를 입력받은 후에, 각 문자를 R번 반복해 새 문자열 P를 만든 후 출력하는 프로그램을 작성하시오.
즉, 첫 번째 문자를 R번 반복하고, 두 번째 문자를 R번 반복하는 식으로 P를 만들면 된다.
S에는 QR Code "alphanumeric" 문자만 들어있다.

QR Code "alphanumeric" 문자는 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: 이다.
*/

#include <iostream>
#include <string.h>
using namespace std;
// s[0], s[1], s[2] = s[0] s[3], s[4], s[5] = s[3]
int main() {
	int testcase; // 실행 횟수
	int r; // 반복 출력할 횟수
	char s[21]; 

	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> r;
		cin >> s;
		for (int i = 0; i < strlen(s); i++) {
			for (int j = 0; j < r; j++) {
				cout << s[i];
			} 
		} // 문자열의 첫번째 문자부터 r번 반복하여 출력하는 for문
		cout << endl;
	}

	return 0;
}