/*
N�� �Է¹��� ��, ������ N���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ��� ���Ŀ� ���缭 ����ϸ� �ȴ�.
*/

#include <iostream>

using namespace std;

int main() {
	int num;

	cin >> num;

	for (int i = 1; i <= 9; i++) {
		cout << num << " * " << i << " = " << num * i << endl;
	} // num * 1 = num , num * 2 = 2num ������ ��µǴ� for��

	return 0;
}