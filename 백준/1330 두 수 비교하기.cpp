/*
�� ���� A�� B�� �־����� ��, A�� B�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

int main() {
	int a, b;

	cin >> a >> b;

	if (a > b) {
		cout << ">" << endl;
	}

	else if (a < b) {
		cout << "<" << endl;
	}

	else {
		cout << "==" << endl;
	} // �� ������ ��� �񱳿���, ũ�ų� ���� �ʴٸ� ���� ���̱⿡ else ���� ��� �����ϴ�.

	return 0;
}