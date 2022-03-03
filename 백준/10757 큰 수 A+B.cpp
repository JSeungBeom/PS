/*
�� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main() {
	char a[1000000];
	char b[1000000];
	int c[1000001] = { 0, };

	cin >> a >> b; // ū ���ڸ� �Է¹ޱ� ����, char �迭�� �Է¹޴´�

	int a_len = strlen(a);
	int b_len = strlen(b); 

	int s = a_len > b_len ? a_len : b_len; // a�� b��, �� ū �ڸ����� �����Ѵ�

	for (int i = 0; i < a_len; i++) {
		c[i] += a[a_len - i - 1] - '0';
	} 

	for (int i = 0; i < b_len; i++) {
		c[i] += b[b_len - i - 1] - '0';
	} // c�� a�� b�� ��ҵ��� ���� ���ؼ� �����Ѵ�

	for (int i = 0; i <= s; i++) {
		if (c[i] >= 10) {
			c[i] = c[i] - 10;
			c[i + 1]++;
		}
	} // �迭 c�� 10�� �Ѵ� ���� �ִٸ�, 10�� ���ְ� �� ���� �ڸ����� 1�� �߰��Ѵ� (������ ����) 
	if (c[s] == 0) {
		for (int i = s - 1; i >= 0; i--) {
			cout << c[i];
		}
	} // ó�� ���� 0�̶�� �� �������� ����Ѵ�
	else {
		for (int i = s; i >= 0; i--) {
			cout << c[i];
		}
	}

	return 0;
}