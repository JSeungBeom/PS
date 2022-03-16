/*
���ɽð��� �Ǹ� �� �л� ��ΰ� �� �ٷ� ���� ���� �޽��� ź��. 
�׷��� ���� ���� ���ڸ��� ���� �л����� �տ� ���� �� ���� ������ �԰�, 
���ڸ��� ���� �л����� �ڿ� ���� �� �ʰ� ������ �԰� �ȴ�.
��� �ϸ� �̷��� ��Ȳ�� �ٲپ� �� �� ������ ����ϴ� �� �������� �� ���� ����� �� ���Ҵ�. 
�� ����� ������ ����.

�л����� �� �ٷ� ���� �� ��, ù ��° �л����� ���ʷ� ��ȣ�� �̴´�. 
ù ��°�� ���� �� �л��� ������ 0�� ��ȣ�� �޾� ���� �տ� ���� ����.
�� ��°�� ���� �� �л��� 0�� �Ǵ� 1�� �� �� �ϳ��� ��ȣ�� �̴´�.
0���� ������ �� �ڸ��� �״�� �ְ�, 1���� ������ �ٷ� ���� �л� ������ ���� ���� ����. 
�� ��°�� ���� �� �л��� 0, 1 �Ǵ� 2 �� �ϳ��� ��ȣ�� �̴´�.
�׸��� ���� ��ȣ��ŭ ���ڸ��� ���� ���� ����.
�������� ���� �� �л����� �̿� ���� ������� ���� ��ȣ��ŭ ������ ���� ���� ���� �ȴ�.
���� ���� ��ȣ�� �ڽ��� ó���� �� �������ٴ� ���� ���̴�.

���� ��� 5���� �л��� ���� ����,
ù ��°�� ���� �� �л����� �ټ� ��°�� ���� �� �л����� ���ʷ� 0, 1, 1, 3, 2���� ��ȣ�� �̾Ҵٰ� ����,
ù ��° �л����� �ټ� ��° �л����� 1���� 5�� ǥ���ϸ� �л����� ���� �� ������ ������ ���� �ȴ�.

ù ��° �л��� ��ȣ�� ���� �� : 1
�� ��° �л��� ��ȣ�� ���� �� : 2 1
�� ��° �л��� ��ȣ�� ���� �� : 2 3 1
�� ��° �л��� ��ȣ�� ���� �� : 4 2 3 1
�ټ� ��° �л��� ��ȣ�� ���� �� : 4 2 5 3 1
���� ���������� �л����� ���� �� ������ 4, 2, 5, 3, 1�� �ȴ�.

���� �� �л����� ���ʷ� ���� ��ȣ�� �־��� ��
�л����� ���������� ���� �� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

struct node {
	int data; // ���� �����͸� ������ ����
	node* next; // ���� ��带 ����ų ������
	node* prev; // ���� ��带 ����ų ������
};

class linkedlist {
private:
	node* header; // �� ó�� ��带 ����ų ������
	node* trailer; // �� ������ ��带 ����ų ������
	int listsize; // ����Ʈ�� ������

public:
	linkedlist() {
		header = NULL;
		trailer = NULL;
		listsize = 0;
	} // ��� ������ �ʱ�ȭ

	void insertion(int idx, int data) {
		node* newNode = new node;
		newNode->data = data;
		if (idx == 0) {
			if (listsize == 0) {
				newNode->prev = NULL;
				newNode->next = NULL;
				header = trailer = newNode;
			} // ����Ʈ�� ó�� ��带 �����ϴ� ����, header�� trailer ��� newNode�� �ȴ�
			else {
				header->prev = newNode;
				newNode->prev = NULL;
				newNode->next = header;
				header = newNode;
			} // header�� �����ϹǷ�, newNode�� ���� ���� NULL�̵ǰ� header�� newNode�� �ȴ�
		}
		else if(idx == listsize) {
			trailer->next = newNode;
			newNode->next = NULL;
			newNode->prev = trailer;
			trailer = newNode;
		} // trailer�� �ڿ� ��带 �����ϴ� ���)
		else{
			node* curNode = header;
			for (int i = 1; i < idx; i++) {
				curNode = curNode->next;
			} // �����ϰ��� �ϴ� ��ġ�� ���� ��带 Ž��

			newNode->next = curNode->next;
			newNode->prev = curNode;
			curNode->next->prev = newNode;
			curNode->next = newNode;
		} // ���� ��� | ���ο� ��� | ���� ����� ���� ����� next�� prev ��尡 ����Ǿ�� �Ѵ� 
		listsize++;
	}

	void print_reverse() {
		node* curNode = trailer;
		while (curNode != NULL) {
			cout << curNode->data << " ";
			curNode = curNode->prev;
		}
		cout << endl;
	} // trailer���� ���� ��带 Ž���ϸ� �����͸� �ݴ�� ���
	
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