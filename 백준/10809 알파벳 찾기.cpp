/*
알파벳 소문자로만 이루어진 단어 S가 주어진다.
각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를,
포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char s[101]; // 길이 100인 문자열을 받기 위해선, 널 문자를 포함하여 크기가 101이 되어야 한다
	char alphabet[26];

	cin >> s;

	for (int i = 0; i < 26; i++) {
		alphabet[i] = 'a' + i;
	} // alphabet 배열을 순서대로 a to z까지 초기화한다

	for (int i = 0; i < 26; i++) {

		int count = 0; // 문자열에 없는 알파벳을 계산하기 위한 변수

		for (int j = 0; j < strlen(s); j++) {
			if (alphabet[i] == s[j]) {
				cout << j << " ";
				break;
			} // 알파벳과 입력받은 문자열의 문자가 일치하는 경우 처음 위치를 출력한다 
			else
				count++; // 일치하는 문자가 없는 경우를 계산하기 위해 count를 1씩 더한다
		}
		if(count == strlen(s)) 
		cout << -1 << " "; // count가 문자열의 길이와 동일하면, 일치하는 문자가 없는 경우이므로 -1을 출력한다
	}
	return 0;
}