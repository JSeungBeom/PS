/*
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 
상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 
이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을 작성하시오.
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
