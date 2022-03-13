/*
�� ���� ��밡 �ְ� ù ��° ��뿡�� �ݰ��� ���� �ٸ� n���� ������ �׿� �ִ�. 
�� ������ �ݰ��� ū ������� �׿��ִ�. 
���� �����µ��� ���� ��Ģ�� ���� ù ��° ��뿡�� �� ��° ���� �ű�� �Ѵ�.

�� ���� �� ���� ���Ǹ��� �ٸ� ž���� �ű� �� �ִ�.
�׾� ���� ������ �׻� ���� ���� �Ʒ��� �ͺ��� �۾ƾ� �Ѵ�.
�� �۾��� �����ϴµ� �ʿ��� �̵� ������ ����ϴ� ���α׷��� �ۼ��϶�. 
��, �̵� Ƚ���� �ּҰ� �Ǿ�� �Ѵ�.

�Ʒ� �׸��� ������ 5���� ����� �����̴�.
*/

#include <iostream>
#include <cmath>
using namespace std;

int cnt = 0;

void hanoi(int n, int from, int by, int to) {
	if (n == 1)
		cout << from << " " << to << endl;

	else {
		hanoi(n - 1, from, to, by);
		cout << from << " " << to << endl;
		hanoi(n - 1, by, from, to);
	}
}

int main() {
	int n;

	cin >> n;

	int k = pow(2, n) - 1;
	cout << k << endl;

	hanoi(n, 1, 2, 3);

	return 0;
}