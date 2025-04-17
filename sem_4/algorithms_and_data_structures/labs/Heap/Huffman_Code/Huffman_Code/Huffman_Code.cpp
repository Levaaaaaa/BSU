// Huffman_Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <queue>

using namespace std;

class Node {
public:
	Node(Node* n, Node* p, long long v) : next(n), prev(p), value(v) {

	}

	Node* next;
	Node* prev;
	long long value;
};
class MyQueue {
public:
	Node* head;
	Node* tail;
	int length;

	MyQueue(Node* h, Node* t) : head(h), tail(t), length(0) {

	}

	void push(long long v) {
		Node n(nullptr, nullptr, v);
		if (length == 0) {
			head = &n;
		}
		else {
			tail->prev = &n;
			n.next = tail;
		}
		tail = &n;
		length++;
	}

	long long pop() {
		if (length != 0) {
			long long result = head->value;
			head = head->prev;
			head->next = nullptr;
			length--;
			return result;
		}
	}

	int size() {
		return length;
	}

	int empty() {
		return length == 0;
	}

	long long front() {
		if (head != nullptr) {
			return head->value;
		}
	}

	long long back() {
		if (tail != nullptr) {
			return tail->value;
		}
	}
};

int main() {

	int n;
	ifstream in("huffman.in");
	std::ios_base::sync_with_stdio(false);
	in.tie(nullptr);

	in >> n;
//	queue<long long> q1;
	MyQueue q1(nullptr, nullptr);
	long long tmp;
	for (int i = 0; i < n; i++) {
		in >> tmp;
		q1.push(tmp);
	}
	in.close();

	long long sum = 0;
	MyQueue q2(nullptr, nullptr);
	long long first_min, second_min;
	while (q1.size() + q2.size() > 1) {
		if (q1.empty() || (!q2.empty() && q2.front() < q1.front())) {
			first_min = q2.pop();
			/*
			first_min = q2.front();
			q2.pop();
			*/
		}
		else {
			first_min = q1.pop();
			/*
			first_min = q1.front();
			q1.pop();
			*/
		}

		if (q1.empty() || (!q2.empty() && q2.front() < q1.front())) {
			second_min = q2.pop();
			/*
			second_min = q2.front();
			q2.pop();
			*/
		}
		else {
			second_min = q1.pop();
			/*
			second_min = q1.front();
			q1.pop();
			*/
		}

		sum += first_min + second_min;
		q2.push(first_min + second_min);
	}

	ofstream out("huffman.out");
	out << sum;
	out.close();

	return 0;
}