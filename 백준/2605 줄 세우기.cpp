/*
점심시간이 되면 반 학생 모두가 한 줄로 줄을 서서 급식을 탄다. 
그런데 매일 같이 앞자리에 앉은 학생들이 앞에 줄을 서 먼저 점심을 먹고, 
뒷자리에 앉은 학생들은 뒤에 줄을 서 늦게 점심을 먹게 된다.
어떻게 하면 이러한 상황을 바꾸어 볼 수 있을까 고민하던 중 선생님이 한 가지 방법을 내 놓았다. 
그 방법은 다음과 같다.

학생들이 한 줄로 줄을 선 후, 첫 번째 학생부터 차례로 번호를 뽑는다. 
첫 번째로 줄을 선 학생은 무조건 0번 번호를 받아 제일 앞에 줄을 선다.
두 번째로 줄을 선 학생은 0번 또는 1번 둘 중 하나의 번호를 뽑는다.
0번을 뽑으면 그 자리에 그대로 있고, 1번을 뽑으면 바로 앞의 학생 앞으로 가서 줄을 선다. 
세 번째로 줄을 선 학생은 0, 1 또는 2 중 하나의 번호를 뽑는다.
그리고 뽑은 번호만큼 앞자리로 가서 줄을 선다.
마지막에 줄을 선 학생까지 이와 같은 방식으로 뽑은 번호만큼 앞으로 가서 줄을 서게 된다.
각자 뽑은 번호는 자신이 처음에 선 순서보다는 작은 수이다.

예를 들어 5명의 학생이 줄을 서고,
첫 번째로 줄을 선 학생부터 다섯 번째로 줄을 선 학생까지 차례로 0, 1, 1, 3, 2번의 번호를 뽑았다고 하자,
첫 번째 학생부터 다섯 번째 학생까지 1부터 5로 표시하면 학생들이 줄을 선 순서는 다음과 같이 된다.

첫 번째 학생이 번호를 뽑은 후 : 1
두 번째 학생이 번호를 뽑은 후 : 2 1
세 번째 학생이 번호를 뽑은 후 : 2 3 1
네 번째 학생이 번호를 뽑은 후 : 4 2 3 1
다섯 번째 학생이 번호를 뽑은 후 : 4 2 5 3 1
따라서 최종적으로 학생들이 줄을 선 순서는 4, 2, 5, 3, 1이 된다.

줄을 선 학생들이 차례로 뽑은 번호가 주어질 때
학생들이 최종적으로 줄을 선 순서를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

using namespace std;

struct node {
	int data; // 실제 데이터를 저장할 변수
	node* next; // 다음 노드를 가리킬 포인터
	node* prev; // 이전 노드를 가리킬 포인터
};

class linkedlist {
private:
	node* header; // 맨 처음 노드를 가리킬 포인터
	node* trailer; // 맨 마지막 노드를 가리킬 포인터
	int listsize; // 리스트의 사이즈

public:
	linkedlist() {
		header = NULL;
		trailer = NULL;
		listsize = 0;
	} // 멤버 변수의 초기화

	void insertion(int idx, int data) {
		node* newNode = new node;
		newNode->data = data;
		if (idx == 0) {
			if (listsize == 0) {
				newNode->prev = NULL;
				newNode->next = NULL;
				header = trailer = newNode;
			} // 리스트에 처음 노드를 삽입하는 경우로, header와 trailer 모두 newNode가 된다
			else {
				header->prev = newNode;
				newNode->prev = NULL;
				newNode->next = header;
				header = newNode;
			} // header에 삽입하므로, newNode의 이전 노드는 NULL이되고 header는 newNode가 된다
		}
		else if(idx == listsize) {
			trailer->next = newNode;
			newNode->next = NULL;
			newNode->prev = trailer;
			trailer = newNode;
		} // trailer의 뒤에 노드를 삽입하는 경우)
		else{
			node* curNode = header;
			for (int i = 1; i < idx; i++) {
				curNode = curNode->next;
			} // 삽입하고자 하는 위치의 현재 노드를 탐색

			newNode->next = curNode->next;
			newNode->prev = curNode;
			curNode->next->prev = newNode;
			curNode->next = newNode;
		} // 현재 노드 | 새로운 노드 | 현재 노드의 다음 노드의 next와 prev 노드가 연결되어야 한다 
		listsize++;
	}

	void print_reverse() {
		node* curNode = trailer;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->prev;
		}
		cout << endl;
	} // trailer부터 이전 노드를 탐색하며 데이터를 반대로 출력
	
};

int main() {
	linkedlist li;

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int idx;
		cin >> idx;
		li.insertion(idx, i);
	}
	li.print_reverse();
}