#pragma once

#include <iostream>

class Array {
public:
	int size;
	Array() : size(10) {}
	Array(int n) : size(n) {}
	~Array() {}
	void swapValues(int * arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		return;
	}
	void reverse(int * arr) {
		int end = this->size - 1;
		int begin = 0;
		while (begin < end) {
			arr[begin] = arr[begin] + arr[end];
			arr[end] = arr[begin] - arr[end];
			arr[begin++] = arr[begin] - arr[end--];
		}
	}
	void rotateFromStartToEndBy(int* arr, int n) {
		int end = size - 1;
		int count = 0;
		int endValue;
		while (count < n) {
			endValue = arr[end];
			for (int i = end; i >  0; i--) {
				arr[i] = arr[i-1];
			}
			arr[0] = endValue;
			count++;
		}
		return;
	}
};


