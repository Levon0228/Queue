#include <iostream>

class Queue
{
public:
	Queue(): m_size(0), m_back(nullptr), m_front(nullptr) {};
	struct Node {
		int val;
		Node* next;
	};
	void push(int val);
	void pop();
	void print();
private:
	Node* m_back;
	Node* m_front;
	int m_size;
};

int main() {
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.print();
	std::cout<<"-----------------" << std::endl;
	q.pop();
	q.print();
	
}

void Queue::push(int val) {
	if (m_size == 0) {
		Node* tmp = new Node();
		tmp->val = val;
		tmp->next = nullptr;
		m_back = tmp;
		m_front = tmp;
		
		++m_size;
	} else {
		Node* tmp = new Node();
		tmp->val = val;
		tmp->next = nullptr;
		m_back->next = tmp;
		m_back = tmp;
		++m_size;
		
	}
}

void Queue::pop() {
	if(m_size == 1) {
		m_front = nullptr;
		m_back = nullptr;
		--m_size;
	} else {
		Node* tmp = m_front;
		m_front = m_front->next;

		tmp->next = nullptr;
		delete tmp;
		--m_size;
	}
}

void Queue::print() {
	Node* curr = m_front;
	while (curr!= nullptr){
		std::cout<< curr->val<<std::endl;
		curr = curr->next;
	}
}


