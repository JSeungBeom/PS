/*
"OOXXOXXOOO"�� ���� OX������ ����� �ִ�. O�� ������ ���� ���̰�, X�� ������ Ʋ�� ���̴�.
������ ���� ��� �� ������ ������ �� �������� ���ӵ� O�� ������ �ȴ�.
���� ���, 10�� ������ ������ 3�� �ȴ�.

"OOXXOXXOOO"�� ������ 1+2+0+0+1+0+0+1+2+3 = 10���̴�.

OX������ ����� �־����� ��, ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/


#include <iostream>
#include <string.h> // ���ڿ��� �ٷ� �� �ִ� �پ��� �Լ��� ���Ե� ��� ����

using namespace std;

int main() {
	int testcase;
	int count = 0;
	int sum = 0;
	char ox[81];

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> ox; // ���ڿ��� �Է¹޴´�
		int len = strlen(ox); // ���� 81�� ���ڿ����� �Է¹޴� ���� �������� � ���ڰ� ���� �𸣹Ƿ�, strlen �Լ��� �̿��Ѵ�
		for (int j = 0; j < len; j++) {
			if (ox[j] == 'O') {
				count++;
				sum += count;
			} // ���� 'O'�϶��� count�� 1 ������Ű�� �̸� sum�� ���Ѵ�

			if (ox[j] == 'X') {
				count = 0;
			} // ���� 'X'�϶��� count�� �ٽ� 0���� �ʱ�ȭ��Ų��
		}

		cout << sum << endl;

		sum = 0; 
		count = 0; // �ٸ� testcase�� �����ؾ� �ϹǷ� sum, count�� �ٽ� 0���� �ʱ�ȭ�Ѵ�
	}

	return 0;
}