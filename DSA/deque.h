#include <iostream>

class DequeLL {};

class Deque {
private:
	static int const MAX_SIZE = 100;
	int elements[MAX_SIZE];
	char elements_c[MAX_SIZE];
public:
	int front, rear, size;
	Deque() : front(-1), rear(-1), size(0) {}
	bool isEmpty() {
		return (front == -1);
	}
	bool isFull() {
		return(size > MAX_SIZE);
	}
	void enqueueRear(int value) {
		if (isEmpty())
			front = rear = 0;
		else if (rear == MAX_SIZE - 1) {
			for (int i = front; i <= rear; i++) {
				elements[i - front] = elements[i];
			}
			rear = rear - front + 1;
			front = 0;
		}
		else
			rear++;
		elements[rear] = value;
		++size;
	}
	void enqueueFront(int value) {
		if (isEmpty())
			front = rear = 0;
		else if (front > 0){
			++size;
			front--;
		}
		else {
			if (!isFull()) {
				++size;
				++rear;
				if (size > 1) {
					for (int i = rear; i > 0; i--)
						elements[i] = elements[i - 1];
				}
				else {
					elements[front + 1] = elements[front];
				}
			}
		}
		elements[front] = value;
	}
	int dequeueFront() {
		int temp;
		temp = elements[front];
		if (front == rear)
			front = rear = -1;
		else
			front++;
		--size;
		return temp;
	}
	int dequeueRear() {
		int temp;
		temp = elements[rear];
		if (front == rear)
			front = rear = -1;
		else
			rear--;
		--size;
		return temp;
	}

	void reverseFirstKElements(int k) {
		Stack s2;
		Stack* s1 = &s2;
		int count = 0;
		while (count < k) {
			s1->push(this->dequeueFront());
			count++;
		}
		count = 0;
		while (count < k) {
			this->enqueueRear(s1->pop());
			count++;
		}
		count = 0;
		while (count < (rear - front - k + 1)) {
			this->enqueueRear(this->dequeueFront());
			count++;
		}
	}
	void findMaxIntegerInEveryKWindow(int k, int* max) {
		int windowMax, window, windowStack, current, iter = 0, onePop;
		Stack s1;
		bool firstPop;
		int size = rear - front + 1;
		int iterLimit = size - k + 1;
		while (iter < iterLimit) {
			windowStack = 0;
			windowMax = -10000;
			firstPop = false;
			if (s1.topIndex != -1) {
				while (windowStack < k - 1) {
					if (!firstPop) {
						onePop = s1.pop();
						current = onePop;
						firstPop = true;
					}
					else
						current = s1.pop();
					if (current > windowMax)
						windowMax = current;
					windowStack++;
				}
				s1.push(onePop);
			}
			window = 0;
			while ((window + windowStack) < k) {
				current = this->dequeueFront();
				if (current > windowMax) {
					windowMax = current;
				}
				s1.push(current);
				window++;
			}
			max[iter++] = windowMax;
		}
	}

};