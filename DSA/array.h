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
	void rotateFromEndToStartBy(int* arr, int n) {
		int end = size - 1;
		int count = 0;
		int beginValue;
		while (count < n) {
			beginValue = arr[0];
			for (int i = 1; i < size; i++) {
				arr[i-1] = arr[i];
			}
			arr[end] = beginValue;
			count++;
		}
		return;
	}
	void splitArrayInTwo(int * arr, int splitIndex, int * arr1, int * arr2) {
		int size1 = splitIndex + 1;
		int size2 = size - (splitIndex + 1);
		int i;
		for (i = 0; i <= splitIndex; i++) {
			arr1[i] = arr[i];
		}
		for (i = splitIndex+1; i < size; i++) {
			arr2[i - splitIndex - 1] = arr[i];
		}
	}
	void removeDuplicates(int* arr, int** newArray, int* currentSize) {
		int countUnique = 0;
		int newSize;
		int* frequency = new int[100] {};
		for (int i = 0; i < size; i++) {
			frequency[arr[i]] += 1;
		}
		for (int i = 0; i < 100; i++) {
			if (frequency[i] != 0) {
				countUnique += 1;
			}
		}
		newSize = countUnique;
		int* againNewArray = new int[newSize];
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (frequency[arr[i]] >= 1) {
				againNewArray[count] = arr[i];
				frequency[arr[i]] = 0;
				count++;
			}
		}
		*newArray = againNewArray;
		*currentSize = newSize;
		delete[] frequency;
		return;
	}

	void sortBubble(int* arr, char a_) {
		int temp;
		int i;
		int passCount = 10;
		int end = size;
		bool comparison;
		while (passCount > 0) {
			passCount = 0;
			for (i = 1; i < end; i++) {
				comparison = (a_ == 'a') ? ((arr[i - 1] >= arr[i]) ? true : false) : ((arr[i - 1] <= arr[i]) ? true : false);
				if (comparison) {
					temp = arr[i - 1];
					arr[i - 1] = arr[i];
					arr[i] = temp;
					passCount += 1;
				}
			}
			if(passCount > 0)
				end--;
		}
	}
	void sortSelection(int* arr, char a_) {
		int temp;
		int i;
		int min = 10000;
		int max = -10000;
		int minIndex;
		int maxIndex;
		int begin = 0;
		while (begin < size) {
			min = 10000;
			max = -10000;
			for (i = begin; i < size; i++) {
				if (a_ == 'a') {
					if (arr[i] < min) {
						min = arr[i];
						minIndex = i;
					}
				}
				else if (a_ == 'd') {
					if (arr[i] > max) {
						max = arr[i];
						maxIndex = i;
					}
				}
			}
			if (a_ == 'a') {
				if (minIndex != begin) {
					temp = arr[minIndex];
					arr[minIndex] = arr[begin];
					arr[begin] = temp;
				}
			}	
			else if (a_ == 'd') {
				if (maxIndex != begin) {
					temp = arr[maxIndex];
					arr[maxIndex] = arr[begin];
					arr[begin] = temp;
				}
			}
			begin++;
		}
	}
	void sortInsertion(int* arr, char a_) {
		int temp; 
		int temp2;
		int i;
		int subArraySize = 1;
		bool comparison1, comparison2;
		while (subArraySize != size) {		
			for (i = 0; i < subArraySize; i++) {

				if (a_ == 'a') {
					comparison1 = (arr[subArraySize] > arr[i] && arr[subArraySize] <= arr[i + 1] && subArraySize > 1) ? true : false;
					comparison2 = (arr[subArraySize] <= arr[0]) ? true : false;
				}
				else if (a_ == 'd') {
					comparison1 = (arr[subArraySize] < arr[i] && arr[subArraySize] >= arr[i + 1] && subArraySize > 1) ? true : false;
					comparison2 = (arr[subArraySize] >= arr[0]) ? true : false;
				}
				if (comparison1) {
					temp = arr[subArraySize];
					for (int j = subArraySize; j > i + 1; j--)
						arr[j] = arr[j - 1];
					arr[i + 1] = temp;
					break;
				}
				else if (comparison2) {
					temp = arr[subArraySize];
					for (int j = subArraySize; j > 0; j--)
						arr[j] = arr[j - 1];
					arr[0] = temp;
					break;
				}
			}
			subArraySize++;
		}

	}
	void SortedMerge(int* arr, int start1, int end1, int start2, int end2, char a_) {
		int leftSize = end1 - start1 + 1;
		int rightSize = end2 - start2 + 1;
		int* left = new int[leftSize] {};
		int* right = new int[rightSize] {};
		bool comparison;

		int count;

		for (int i = start1, count = 0; i <= end1 && count < leftSize; i++, count++)
			left[count] = arr[i];
		for (int i = start2, count = 0; i <= end2 && count < rightSize; i++, count++)
			right[count] = arr[i];

		int c1 = 0, c2 = 0, i = start1;
		while ((c1 < leftSize) && (c2 < rightSize)) {
			comparison = (a_ == 'a') ? ((left[c1] < right[c2]) ? true : false) : ((left[c1] > right[c2]) ? true : false);
			arr[i++] = comparison ? left[c1++] : right[c2++];
		}

		if (c1 == leftSize) {
			while (i <= end2)
				arr[i++] = right[c2++];
		}
		else if (c2 == rightSize) {
			while (i <= end2)
				arr[i++] = left[c1++];
		}

		delete[] left;
		delete[] right;
	}
	void sortMerge(int* arr, int start, int end, char a_) {
		if (start >= end) {
			return;
		}

		int mid = start + ((int)((end - start)/ 2.0));
		
		sortMerge(arr, start, mid, a_);
		sortMerge(arr, mid+1, end, a_);

		SortedMerge(arr, start, mid, mid + 1, end, a_);

	}
	void sortQuick(int* arr, int start, int end, char a_) {
	}
	void sortHeap(int* arr, char a_) {}

	bool linearSearch(int* arr, int n) {}
	bool binarySearch(int * arr, int n) {}

	int * findIntersection(int* arr1, int* arr2) {}
	int* findUnion(int* arr1, int* arr2) {}
	bool checkPallindrome(int* arr) {}
	int findKthLargestElement(int* arr, int k) {}
	int findKthSmallestElement(int* arr, int k) {}
	int* getSubArrayWithSpecificSum(int* arr, int sum) {}
	int* getSubArrayWithSpecificProduct(int* arr, int product) {}
	void segregateElementsBasedOnSign(int* arr) {}
	void segregateElementsBasedOnEvenOdd(int* arr) {}
	int countPairsWithSpecificSum(int* arr, int sum) {}
	int * findCommonElementsInThreeSortedArrays(int* arr1, int* arr2, int* arr3) {}
	void rearrangeWithAlternatingSign(int* arr) {}
	int* findLargestSumContiguousSubArray(int* arr) {}
	int* findLargestProductContiguousSubArray(int* arr) {}

};


