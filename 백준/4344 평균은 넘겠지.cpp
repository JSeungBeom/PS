/*
���л� ��������� 90%�� �ڽ��� �ݿ��� ����� �Ѵ´ٰ� �����Ѵ�.
����� �׵鿡�� ���� ������ �˷���� �Ѵ�.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int c, n;


	cin >> c; // �׽�Ʈ���̽� �Է�

	for (int i = 0; i < c; i++) {
		cin >> n; // �л��� �� �Է�

		double* score = new double[n]; // �л��� �� ��ŭ ���� �迭�� �����Ѵ�
		double sum = 0, avg = 0;
		double stdnum = 0;

		for (int j = 0; j < n; j++) {
			cin >> score[j];
			sum += score[j];
		} // �� �л��� ������ �Է¹ް� �� ���� ���Ѵ�

		avg = sum / n; // ����� ���Ѵ�

		for (int j = 0; j < n; j++) {
			if (score[j] > avg) {
				stdnum++;
			}
		} // ����� �Ѵ� �л��� ���� ���Ѵ�

		delete []score; // ���� �迭�� �Ҵ�Ǿ��� �޸𸮸� �����Ѵ�

		cout << fixed << setprecision(3) << (stdnum / n) * 100 << "%\n";
		// ����� �Ѵ� �л��� ������ �Ҽ��� 3�ڸ��� ���� �ݿø��Ͽ� ����Ѵ�. 
	}

	return 0;
}