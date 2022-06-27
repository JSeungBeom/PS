/*
널리 잘 알려진 자료구조 중 최대 힙이 있다. 
최대 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.

배열에 자연수 x를 넣는다.
배열에서 가장 큰 값을 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.
*/

#include <iostream>
#include <vector>

using namespace std;

class heap {
private:
	vector <int> arr;

	void swap(int idx1, int idx2) {
		arr[0] = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = arr[0];
	}

	void upHeap(int idx) {
		if (idx == 1) {
			return;
		}

		int parent = idx / 2;
		if (arr[parent] < arr[idx]) {
			swap(parent, idx);
			upHeap(parent);
		}
	}

	void downHeap(int idx) {
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int child;

		if (left > size()) {
			return;
		}
		else if (left == size()) {
			child = left;
		}
		else {
			if (arr[left] >= arr[right]) {
				child = left;
			}
			else {
				child = right;
			}
		}

		if (arr[child] > arr[idx]) {
			swap(child, idx);
			downHeap(child);
		}
	}

public:
	heap() {
		arr.push_back(0);
	}

	int size() {
		return arr.size() - 1;
	}

	bool empty() {
		return (size() == 0);
	}

	void insert(int e) {
		arr.push_back(e);
		upHeap(size());
	}

	int max() {
		if (empty()) {
			return 0;
		}

		return arr[1];
	}

	void removeMax() {
		if (empty()) {
			return;
		}

		swap(1, size());
		arr.pop_back();
		downHeap(1);
	}
};

int main() {
	int n;
	cin >> n;

	heap h;

	int x;
	while (n--) {
		cin >> x;
		if (x == 0) {
			cout << h.max() << "\n";
			h.removeMax();
		}
		else {
			h.insert(x);
		}
	}
}