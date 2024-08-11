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
		if (start >= end)
			return;

		int pivotIndex = end;
		int iter = 0, leftIter = 0;
		int temp;
		bool comparison;
		while (iter < pivotIndex) {
			comparison = (a_ == 'a') ? ((arr[iter] <= arr[pivotIndex]) ? true : false) : ((arr[iter] >= arr[pivotIndex]) ? true : false);
			if (comparison) {
				if (iter == leftIter) {
					leftIter++;
					iter++;
				}
				else {
					temp = arr[leftIter];
					arr[leftIter] = arr[iter];
					arr[iter] = temp;
					leftIter++;
					iter++;
				}
			}
			else {
				iter++;
			}
		}
		temp = arr[pivotIndex];
		arr[pivotIndex] = arr[leftIter];
		arr[leftIter] = temp;
		pivotIndex = leftIter;

		sortQuick(arr, start, pivotIndex - 1, a_);
		sortQuick(arr, pivotIndex + 1, end, a_);
	}
	void sortHeap(int* arr, char a_) {
		int l, r, i, temp;
		int lastLeafNode = (size / 2.0) - 1;
		int maxId = (2*lastLeafNode+2 > (size-1)) ? (2*lastLeafNode + 1) : (2*lastLeafNode + 2);
		int passCount = 10;
		bool leftChildComparison, rightChildComparison;
		int min = 10000;
		int max = -10000;
		if (a_ == 'a') {
			for (i = 0; i < size; i++) {
				if (arr[i] < min)
					min = arr[i];
			}
		}
		else if (a_ == 'd') {
			for (i = 0; i < size; i++) {
				if (arr[i] > max)
					max = arr[i];
			}
		}

		while (passCount > 0) {
			passCount = 0;
			for (i = lastLeafNode; i >= 0; i--) {
				l = 2 * i + 1;
				r = l + 1;
				if (a_ == 'a') {
					leftChildComparison = (arr[l] > arr[i] && arr[l] > arr[r] && (l <= maxId)) ? true : false;
					rightChildComparison = (arr[r] > arr[i] && arr[r] > arr[l] && (r <= maxId)) ? true : false;
				}
				else if (a_ == 'd') {
					leftChildComparison = (arr[l] < arr[i] && arr[l] < arr[r] && (l <= maxId)) ? true : false;
					rightChildComparison = (arr[r] < arr[i] && arr[r] < arr[l] && (r <= maxId)) ? true : false;
				}
				if (leftChildComparison) {
					temp = arr[l];
					arr[l] = arr[i];
					arr[i] = temp;
					passCount++;
				}
				else if (rightChildComparison) {
					temp = arr[r];
					arr[r] = arr[i];
					arr[i] = temp;
					passCount++;
				}
			}

			if (passCount > 0) {
				temp = arr[0];
				arr[0] = arr[maxId];
				arr[maxId] = temp;
				maxId--;
			}
			else {
				if (a_ == 'a' && arr[0] != min) {
					temp = arr[0];
					arr[0] = arr[maxId];
					arr[maxId] = temp;
					passCount = 1;
				}
				else if (a_ == 'd' && arr[0] != max) {
					temp = arr[0];
					arr[0] = arr[maxId];
					arr[maxId] = temp;
					passCount = 1;
				}
			}
		}
	}

	bool linearSearch(int* arr, int n) {}
	bool binarySearch(int * arr, int n) {}

	int findIntersection(int* arr1, int* arr2, int size1, int size2, int * result) {
		int i, j, k, l;
		int count = 0, foundSum = 0;
		for (i = 0; i < size1; i++) {
			for (j = 0; j < size2; j++) {
				if (arr1[i] == arr2[j]) {
					foundSum = 0;
					count = 0;
					for (k = i, l = j; k < size1 && l < size2; k++, l++) {
						if (arr1[k] == arr2[l]) {
							result[foundSum] = arr1[k];
							foundSum++;
						}
						count++;
					}
					if (count == foundSum && count > 1)
						return i;
				}
			}
		}

		return -1;
	}
	void findUnion(int* arr1, int* arr2, int size1, int size2, int* result) {
		int i = 0, j = 0, k = 0, c = 0;
		bool present;
		while (i < size1) {
			present = false;
			for (k = 0; k < c; k++) {
				if (arr1[i] == result[k])
					present = true;
			}
			if (!present) {
				result[c] = arr1[i];
				c++;
			}
			i++;
		}
		while (j < size2) {
			present = false;
			for (k = 0; k < c; k++) {
				if (arr2[j] == result[k])
					present = true;
			}
			if (!present) {
				result[c] = arr2[j];
				c++;
			}
			j++;
		}
	}
	bool checkPallindrome(int* arr) {
		int* rev = new int[size];
		for (int i = 0; i < size; i++)
			rev[i] = arr[i];
		reverse(rev);
		for (int i = 0; i < size; i++) {
			if (rev[i] != arr[i])
				return false;
		}
		return true;
	}
	int findKthLargestElement(int* arr, int k) {
		sortSelection(arr, 'd');
		return(arr[k - 1]);
	}
	int findKthSmallestElement(int* arr, int k) {
		sortBubble(arr, 'a');
		return(arr[k - 1]);
	}
	void getSubArrayWithSpecificSum(int* arr, int sum, int * result) {
		int sumIter = 0;
		int start = 0;
		int i, j, k, l;
		bool found = false;
		while (start < size) {
			sumIter = 0;
			for (i = start; i < size; i++) {
				sumIter += arr[i];
				if (sumIter == sum) {
					found = true;
					break;
				}
			}
			if (found)
				break;
			start++;
		}

		int count = 0;
		if (found) {
			for (j = start; j <= i; j++) {
				result[count] = arr[j];
				count++;
			}
		}
		else {
			result[count] = -10000;
		}
	}
	void getSubArrayWithSpecificProduct(int* arr, int product, int * result) {
		int sumIter = 1;
		int start = 0;
		int i, j, k, l;
		bool found = false;
		while (start < size) {
			sumIter = 1;
			for (i = start; i < size; i++) {
				sumIter *= arr[i];
				if (sumIter == product) {
					found = true;
					break;
				}
			}
			if (found)
				break;
			start++;
		}

		int count = 0;
		if (found) {
			for (j = start; j <= i; j++) {
				result[count] = arr[j];
				count++;
			}
		}
		else {
			result[count] = -10000;
		}

	}
	void segregateElementsBasedOnSign(int* arr) {
		int countPositive = 0, countNegative = 0;
		int i, j;
		for (i = 0; i < size; i++) {
			if (arr[i] < 0)
				countNegative++;
			else
				countPositive++;
		}
		int* pos = new int[countPositive];
		int* neg = new int[countNegative];
		int nc = 0, pc = 0;
		for (i = 0; i < size; i++) {
			if (arr[i] < 0)
				neg[nc++] = arr[i];
			else 
				pos[pc++] = arr[i];
		}

		for (i = 0; i < countNegative; i++)
			arr[i] = neg[i];
		
		for (j = 0; j < countPositive; j++)
			arr[i++] = pos[j];

		delete[] pos;
		delete[] neg;
	}
	void segregateElementsBasedOnEvenOdd(int* arr) {
		int countEven = 0, countOdd = 0;
		int i, j;
		for (i = 0; i < size; i++) {
			if (arr[i] % 2 != 0)
				countOdd++;
			else
				countEven++;
		}
		int* even = new int[countEven];
		int* odd = new int[countOdd];
		int nc = 0, pc = 0;
		for (i = 0; i < size; i++) {
			if (arr[i] % 2 != 0)
				odd[nc++] = arr[i];
			else
				even[pc++] = arr[i];
		}

		for (i = 0; i < countOdd; i++)
			arr[i] = odd[i];

		for (j = 0; j < countEven; j++)
			arr[i++] = even[j];

		delete[] even;
		delete[] odd;
	}
	void findCommonElementsInThreeSortedArrays(int* arr1, int* arr2, int* arr3, int size1, int size2, int size3, int * result) {
		
		int* common;
		int common12 = 0;
		int* common2;
		int common23 = 0;
		int count = 0;
		int i, j;
		for (i = 0; i < size1; i++) {
			for (j = 0; j < size2; j++) {
				if (arr1[i] == arr2[j])
					common12++;
			}
		}
		
		common = new int[common12];
		for (i = 0; i < size1; i++) {
			for (j = 0; j < size2; j++) {
				if (arr1[i] == arr2[j])
					common[count++] = arr1[i];
			}
		}

		for (i = 0; i < common12; i++) {
			for (j = 0; j < size3; j++) {
				if (common[i] == arr3[j])
					common23++;
			}
		}

		common2 = new int[common23];
		count = 0;
		for (i = 0; i < common12; i++) {
			for (j = 0; j < size3; j++) {
				if (common[i] == arr3[j])
					result[count++] = common[i];
			}
		}
		delete[] common;
		delete[] common2;
	}
	void rearrangeWithAlternatingSign(int* arr) {
		int countPositive = 0, countNegative = 0;
		int i, j;
		for (i = 0; i < size; i++) {
			if (arr[i] < 0)
				countNegative++;
			else
				countPositive++;
		}
		int* pos = new int[countPositive];
		int* neg = new int[countNegative];
		int nc = 0, pc = 0;
		for (i = 0; i < size; i++) {
			if (arr[i] < 0)
				neg[nc++] = arr[i];
			else
				pos[pc++] = arr[i];
		}
		pc = 0;
		nc = 0;
		for (i = 0; i < size && pc < countPositive && nc < countNegative; i++) {
			if (i % 2 == 0) {
				arr[i] = pos[pc++];
			}
			else {
				arr[i] = neg[nc++];
			}
		}

		if (i < size && pc == countPositive) {
			while(nc < countNegative)
				arr[i++] = neg[nc++];
		}
		else if (i < size && nc == countNegative) {
			while (pc < countPositive)
				arr[i++] = pos[pc++];
		}

		delete[] pos;
		delete[] neg;
	}
	void findLargestSumContiguousSubArray(int* arr, int * result) {
		int sumIter = 0;
		int start = 0;
		int count = 0;
		int i;
		int maxSum = -10000;
		int maxSumStart;
		int maxSumEnd;
		while (start < size) {
			sumIter = 0;
			for (i = start; i < size; i++) {
				sumIter += arr[i];
				if (sumIter > maxSum) {
					maxSum = sumIter;
					maxSumStart = start;
					maxSumEnd = i;
				}
			}
			start++;
		}

		for (i = maxSumStart; i <= maxSumEnd; i++)
			result[count++] = arr[i];
	}
	void findLargestProductContiguousSubArray(int* arr, int * result) {
		int sumIter = 1;
		int start = 0;
		int count = 0;
		int i;
		int maxSum = -10000;
		int maxProductStart;
		int maxProductEnd;
		while (start < size) {
			sumIter = 1;
			for (i = start; i < size; i++) {
				sumIter *= arr[i];
				if (sumIter > maxSum) {
					maxSum = sumIter;
					maxProductStart = start;
					maxProductEnd = i;
				}
			}
			start++;
		}

		for (i = maxProductStart; i <= maxProductEnd; i++)
			result[count++] = arr[i];
	}

};


