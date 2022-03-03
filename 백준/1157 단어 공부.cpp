/*
알파벳 대소문자로 된 단어가 주어지면,
이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 
프로그램을 작성하시오.
단, 대문자와 소문자를 구분하지 않는다.
*/

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main() {
	char alpha[] = "abcdefghijklmnopqrstuvwxyz"; // 입력받은 문자열과 비교할 배열
	int checker[26] = { 0 }; // 문자가 몇 번 나왔는지를 확인할 배열

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	} // string s의 모든 인덱스의 요소들을 소문자로 만든다

	int max = -10;
	int index = 0;

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < s.length(); j++) {
			if (alpha[i] == s[j]) {
				checker[i]++;
			}
		}
	}  // 입력받은 문자열과, alpha 문자열을 비교해 같은 경우 checker의 해당 인덱스에 1을 더한다

	for (int i = 0; i < 26; i++) {
		if (checker[i] > max) {
			max = checker[i];
			index = i;
		}
	} // checker의 요소들 중 가장 큰 수를 찾아 인덱스를 저장한다

	for (int i = index + 1; i < 26; i++) {
		if (checker[index] == checker[i]) {
			cout << "?" << endl;
			return 0;
		}
	} // 중복 검사. 가장 큰 수를 가진 인덱스 다음 인덱스부터 검사하여 같은 값을 가지면 ?을 출력한다

	char word = toupper(alpha[index]); // 마지막으로, 해당 문자를 대문자로 변환한다

	cout << word << endl;

	return 0;
}

/*
toupper 함수
tolower 함수
string으로 입력받았을 경우에는 .length() 함수로 길이를 확인할 수 있다.
char으로 입력받았을 경우에는 strlen() 함수 사용
*/