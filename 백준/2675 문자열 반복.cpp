/*
���ڿ� S�� �Է¹��� �Ŀ�, �� ���ڸ� R�� �ݺ��� �� ���ڿ� P�� ���� �� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
��, ù ��° ���ڸ� R�� �ݺ��ϰ�, �� ��° ���ڸ� R�� �ݺ��ϴ� ������ P�� ����� �ȴ�.
S���� QR Code "alphanumeric" ���ڸ� ����ִ�.

QR Code "alphanumeric" ���ڴ� 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: �̴�.
*/

#include <iostream>
#include <string.h>
using namespace std;
// s[0], s[1], s[2] = s[0] s[3], s[4], s[5] = s[3]
int main() {
	int testcase; // ���� Ƚ��
	int r; // �ݺ� ����� Ƚ��
	char s[21]; 

	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> r;
		cin >> s;
		for (int i = 0; i < strlen(s); i++) {
			for (int j = 0; j < r; j++) {
				cout << s[i];
			} 
		} // ���ڿ��� ù��° ���ں��� r�� �ݺ��Ͽ� ����ϴ� for��
		cout << endl;
	}

	return 0;
}