/*
�׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�,
�� ���ڰ� �����ؼ� ��Ÿ���� ��츸�� ���Ѵ�.
���� ���, ccazzzzbb�� c, a, z, b�� ��� �����ؼ� ��Ÿ����,
kin�� k, i, n�� �����ؼ� ��Ÿ���� ������ �׷� �ܾ�������,
aabbbccb�� b�� �������� ��Ÿ���� ������ �׷� �ܾ �ƴϴ�.

�ܾ� N���� �Է����� �޾� �׷� �ܾ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int count = 0; // �׷� �ܾ��� ������ �� ����



	for (int i = 0; i < n; i++) {
		bool visited[500] = { false, }; // ���ڰ� ���Դ� �������� Ȯ���� bool �迭
		string word; 
		cin >> word;
		bool check = false; // �׷� �ܾ��̸� false��, �ƴϸ� true�� �����Ѵ�
		char prev = word[0]; // ������ ���ڸ� ������ ����
		visited[word[0]] = true; 
		for (int j = 1; j < word.length(); j++) {
			if (word[j] != prev) {
				if (visited[word[j]]) {
					check = true;
					break;
				} // ���ڰ� ������ ���ڿ� �ٸ� ��, �̹� ���Դ� �����̸� �׷� �ܾ �ƴϴ�
				else {
					prev = word[j];
					visited[word[j]] = true;
				} // �ܾ �˻��ϸ� ������ ���ڸ� prev�� �����ϰ�, ���Դ� �������� bool �迭�� �����Ѵ�
			}
		}
		if (!check) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}