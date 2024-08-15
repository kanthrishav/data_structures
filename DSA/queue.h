#include <iostream>

class Queue {
private:
	static int const MAX_SIZE = 100;
	int elements[MAX_SIZE];
	char elements_c[MAX_SIZE];
public:
	int front, rear;
	Queue() : front(-1), rear(-1) {}
	bool isEmpty() {
		return (front == -1);
	}
	bool isFull() {
		return(rear % MAX_SIZE == front);
	}
	void enqueue(int value) {
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
	}
	int dequeue() {
		int temp;
		temp = elements[front];
		if (front == rear)
			front = rear = -1;
		else
			front++;
		return temp;
	}

	void reverseFirstKElements(int k) {
		Stack s2;
		Stack* s1 = &s2;
		int count = 0;
		while (count < k) {
			s1->push(this->dequeue());
			count++;
		}
		count = 0;
		while (count < k) {
			this->enqueue(s1->pop());
			count++;
		}
		count = 0;
		while (count < (rear - front - k+1)) {
			this->enqueue(this->dequeue());
			count++;
		}
	}
	void findMaxIntegerInEveryKWindow(int k, int * max) {
		int windowMax, window, windowStack, current, iter = 0, onePop;
		Stack s1;
		bool firstPop;
		int size = rear - front + 1;
		int iterLimit = size - k +1;
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
				current = this->dequeue();
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