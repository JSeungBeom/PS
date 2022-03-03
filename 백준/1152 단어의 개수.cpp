/*
영어 대소문자와 공백으로 이루어진 문자열이 주어진다.
이 문자열에는 몇 개의 단어가 있을까? 
이를 구하는 프로그램을 작성하시오.
단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.
*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
	char str[1000001];

	cin.getline(str, 1000001);
	// cin을 할 때 띄어쓰기는 출력이 되지 않는데, cin.getline() 함수를 이용해 띄어쓰기 까지 포함이 가능하다

	int count = 1; 

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
			count++;
		}
	} // 문자열을 검사하여, 공백이 나오는 경우 count를 1 더한다
	// 이때, 공백의 숫자가 아니라 단어의 수를 구하는 경우이므로 count를 1로 초기화한다

	if (str[0] == ' ') {
		count--;
	} // 문자열의 0번째 인덱스에 공백이 포함되었을 경우, count를 1 빼준다.

	if (str[strlen(str) - 1] == ' ') {
		count--;
	} // 문자열의 마지막 인덱스에 공백이 포함되었을 경우, count를 1 빼준다.

	cout << count << endl;

	return 0;
}