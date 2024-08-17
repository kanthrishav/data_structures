#include <iostream>

class PriorityQueLL {};

class PriorityQue {
private:
	static int const MAX_SIZE = 100;
	int elements[MAX_SIZE];
	int priority[MAX_SIZE];
	char elements_c[MAX_SIZE];
public:
	int front, rear;
	PriorityQue() : front(-1), rear(-1) {}
	bool isEmpty() {
		return (front == -1);
	}
	bool isFull() {
		return(rear % MAX_SIZE == front);
	}
	void enqueue(int value, int prio) {
		int index;
		if (isEmpty()) {
			front = rear = index = 0;
		}
		else {
			if (prio > priority[rear]) {
				rear++;
				index = rear;
			}
			else {
				if (prio <= priority[front])
					index = front;
				else {
					for (int i = front; i < rear; i++) {
						if (prio > priority[i] && prio <= priority[i + 1]) {
							index = i + 1;
							break;
						}
					}
				}
				++rear;
				for (int i = rear; i > index; i--) {
					elements[i] = elements[i - 1];
					priority[i] = priority[i - 1];
				}
			}
		}
		elements[index] = value;
		priority[index] = prio;
	}
	int dequeue() {
		int temp;
		temp = elements[rear];
		if (front == rear)
			front = rear = -1;
		else
			rear--;
		return temp;
	}
};