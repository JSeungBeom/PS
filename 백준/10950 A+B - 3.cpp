/*
�� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�� �׽�Ʈ ���̽����� A+B�� ����Ѵ�.
*/

#include <iostream>

using namespace std;

int main() {
	int testcase; // �� ���� ������ ������ ���ϴ� Testcase�� ��
	int a, b; //  ���� ���꿡 ���Ǵ� �� a, b 

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> a >> b;
		cout << a + b << endl;
	} // �־��� testcase��ŭ a + b�� �����Ѵ�.

	return 0;
}