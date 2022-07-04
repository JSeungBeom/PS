/*
���� ī��� ���� �ϳ��� ������ �ִ� ī���̴�. 
����̴� ���� ī�� N���� ������ �ִ�. ���� M���� �־����� ��, 
�� ���� �����ִ� ���� ī�带 ����̰� ������ �ִ��� �ƴ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_set<int> s;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		s.insert(x);
	}

	int m;
	cin >> m;
	while (m--) {
		int y;
		cin >> y;
		unordered_set<int>::const_iterator got = s.find(y);
		if (got == s.end()) {
			cout << 0 << " ";
		}
		else {
			cout << 1 << " ";
		}
	}
}
