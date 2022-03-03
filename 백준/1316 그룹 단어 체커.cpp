/*
그룹 단어란 단어에 존재하는 모든 문자에 대해서,
각 문자가 연속해서 나타나는 경우만을 말한다.
예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고,
kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만,
aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.

단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int count = 0; // 그룹 단어의 개수를 셀 변수



	for (int i = 0; i < n; i++) {
		bool visited[500] = { false, }; // 문자가 나왔던 문자인지 확인할 bool 배열
		string word; 
		cin >> word;
		bool check = false; // 그룹 단어이면 false를, 아니면 true를 저장한다
		char prev = word[0]; // 직전의 문자를 저장할 변수
		visited[word[0]] = true; 
		for (int j = 1; j < word.length(); j++) {
			if (word[j] != prev) {
				if (visited[word[j]]) {
					check = true;
					break;
				} // 문자가 직전의 문자와 다를 때, 이미 나왔던 문자이면 그룹 단어가 아니다
				else {
					prev = word[j];
					visited[word[j]] = true;
				} // 단어를 검사하며 직전의 문자를 prev에 저장하고, 나왔던 문자임을 bool 배열에 저장한다
			}
		}
		if (!check) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}