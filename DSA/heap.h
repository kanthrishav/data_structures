#include <iostream>

class MaxHeap {
public:
	int* heap;
	int n;
	int size;
	MaxHeap(int m) {
		heap = new int[m + 1];
		n = 0;
		size = m;
	}
	~MaxHeap() {
		if (heap != nullptr)
			delete heap;
	}
	void insert(int value) {
		n++;
		heap[n] = value;
		reheapifyUpward(n);
	}
	void reheapifyUpward(int start) {
		int temp, parent;
		if (start > 1) {
			parent = start / 2;
			if (heap[parent] < heap[start]) {
				temp = heap[start];
				heap[start] = heap[parent];
				heap[parent] = temp;
				reheapifyUpward(parent);
			}
		}
	}
	int remove () {
		int temp;
		temp = heap[1];
		heap[1] = heap[n];
		n--;
		reheapifyDownward(1, n);
		return temp;
	}
	void reheapifyDownward(int start, int finish) {
		int index, lchild, rchild;
		int max, temp;
		lchild = 2 * start;
		rchild = lchild + 1;

		if (lchild <= finish) {
			max = heap[lchild];
			index = lchild;
			if (rchild <= finish) {
				if (heap[rchild] > max) {
					max = heap[rchild];
					index = rchild;
				}
			}
			if (heap[start] < heap[index]) {
				temp = heap[start];
				heap[start] = heap[index];
				heap[index] = temp;
				reheapifyDownward(index, finish);
			}
		}
	}
};

