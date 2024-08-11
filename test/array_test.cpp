#include "pch.h"

namespace ARRAY_T {
	class ARR : public testing::Test {
	public:
		Array* list = new Array;
		void SetUp() {
			// pass
		}
		void TearDown() {
			delete list;
		}
	};

	TEST_F(ARR, swapValues) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		list->swapValues(val, 2, 4);
		ASSERT_EQ(1, val[2]);
		ASSERT_EQ(2, val[4]);
	}
	TEST_F(ARR, reverse) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valRev[size] = { 3, 4, 1, 0, 2, 6, 5 };
		int i;
		list->reverse(val);
		for (i = 0; i < size; i++) {
			ASSERT_EQ(valRev[i], val[i]);
		}
	}
	TEST_F(ARR, rotateFromStartToEndBy2) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valRot[size] = { 4, 3, 5, 6, 2, 0, 1 };
		int i;
		list->rotateFromStartToEndBy(val, 2);
		for (i = 0; i < size; i++) {
			ASSERT_EQ(valRot[i], val[i]);
		}
	}
	TEST_F(ARR, rotateFromStartToEndBy4) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valRot[size] = { 0, 1, 4, 3, 5, 6, 2 };
		int i;
		list->rotateFromStartToEndBy(val, 4);
		for (i = 0; i < size; i++) {
			ASSERT_EQ(valRot[i], val[i]);
		}
	}
	TEST_F(ARR, rotateFromStartToEndBy1) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valRot[size] = { 3, 5, 6, 2, 0, 1, 4 };
		int i;
		list->rotateFromStartToEndBy(val, 1);
		for (i = 0; i < size; i++) {
			ASSERT_EQ(valRot[i], val[i]);
		}
	}
	TEST_F(ARR, rotateFromEndToStartBy1) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valRot[size] = { 6, 2, 0, 1, 4, 3, 5 };
		int i;
		list->rotateFromEndToStartBy(val, 1);
		for (i = 0; i < size; i++) {
			ASSERT_EQ(valRot[i], val[i]);
		}
	}
	TEST_F(ARR, rotateFromEndToStartBy2) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valRot[size] = { 2, 0, 1, 4, 3, 5, 6 };
		int i;
		list->rotateFromEndToStartBy(val, 2);
		for (i = 0; i < size; i++) {
			ASSERT_EQ(valRot[i], val[i]);
		}
	}
	TEST_F(ARR, rotateFromEndToStartBy4) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valRot[size] = { 1, 4, 3, 5, 6, 2, 0 };
		int i;
		list->rotateFromEndToStartBy(val, 4);
		for (i = 0; i < size; i++) {
			ASSERT_EQ(valRot[i], val[i]);
		}
	}
	TEST_F(ARR, splitArrayInTwo) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int val1[4] = { 5, 6, 2, 0 };
		int val2[3] = { 1, 4, 3 };
		int i;
		int splitIndex = 3;
		int size1 = splitIndex + 1;
		int size2 = size - (splitIndex + 1);
		int* arr1 = new int[size1];
		int* arr2 = new int[size2];
		list->splitArrayInTwo(val, splitIndex, arr1, arr2);
		for (i = 0; i < size1; i++) {
			ASSERT_EQ(val1[i], arr1[i]);
		}
		for (i = 0; i < size2; i++) {
			ASSERT_EQ(val2[i], arr2[i]);
		}
		delete [] arr1;
		delete [] arr2;
	}
	TEST_F(ARR, removeDuplicates) {
		int const size = 9;
		list->size = size;
		int val[size] = { 5, 6, 6, 0, 1, 1, 1, 4, 3 };
		int val1[6] = { 5, 6, 0, 1, 4, 3 };
		int i;
		int sizeReduced = 2;
		int* arr = nullptr;
		list->removeDuplicates(val, &arr, &sizeReduced);
		for (i = 0; i < sizeReduced; i++) {
			ASSERT_EQ(val1[i], arr[i]);
		}
		delete[] arr;
	}
	TEST_F(ARR, sortBubble) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valSortedAscend[size] = { 0, 1, 2, 3, 4, 5, 6 };
		int valSortedDescend[size] = { 6, 5, 4, 3, 2, 1, 0 };

		list->sortBubble(val, 'a');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedAscend[i], val[i]);
		}
		list->sortBubble(val, 'd');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedDescend[i], val[i]);
		}
	}
	TEST_F(ARR, sortSelection) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valSortedAscend[size] = { 0, 1, 2, 3, 4, 5, 6 };
		int valSortedDescend[size] = { 6, 5, 4, 3, 2, 1, 0 };

		list->sortSelection(val, 'a');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedAscend[i], val[i]);
		}
		list->sortSelection(val, 'd');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedDescend[i], val[i]);
		}
	}
	TEST_F(ARR, sortInsertion) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valSortedAscend[size] = { 0, 1, 2, 3, 4, 5, 6 };
		int valSortedDescend[size] = { 6, 5, 4, 3, 2, 1, 0 };

		list->sortInsertion(val, 'a');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedAscend[i], val[i]);
		}
		list->sortInsertion(val, 'd');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedDescend[i], val[i]);
		}
	}
	TEST_F(ARR, sortMerge) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valSortedAscend[size] = { 0, 1, 2, 3, 4, 5, 6 };
		int valSortedDescend[size] = { 6, 5, 4, 3, 2, 1, 0 };

		list->sortMerge(val, 0, size - 1, 'a');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedAscend[i], val[i]);
		}
		list->sortMerge(val, 0, size - 1, 'd');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedDescend[i], val[i]);
		}
	}
	TEST_F(ARR, sortQuick) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valSortedAscend[size] = { 0, 1, 2, 3, 4, 5, 6 };
		int valSortedDescend[size] = { 6, 5, 4, 3, 2, 1, 0 };

		list->sortQuick(val, 0, size - 1, 'a');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedAscend[i], val[i]);
		}
		list->sortQuick(val, 0, size - 1, 'd');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedDescend[i], val[i]);
		}
	}
	TEST_F(ARR, sortHeap) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valSortedAscend[size] = { 0, 1, 2, 3, 4, 5, 6 };
		int valSortedDescend[size] = { 6, 5, 4, 3, 2, 1, 0 };

		list->sortHeap(val, 'a');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedAscend[i], val[i]);
		}

		int val2[size] = { 5, 6, 2, 0, 1, 4, 3 };

		list->sortHeap(val2, 'd');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedDescend[i], val2[i]);
		}
	}
	TEST_F(ARR, findIntersection) {
		int const size = 7;
		list->size = size;
		int val1[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int val2[size-1] = { 8, 9, 0, 1, 4, 3 };
		int val3[size] = { 8, 7, 2, 0, 3, 4, 1 };
		int* result = new int[4];
		int found = list->findIntersection(val1, val2, size, size-1, result);
		ASSERT_EQ(found, 3);
		ASSERT_EQ(result[0], 0);
		ASSERT_EQ(result[1], 1);
		ASSERT_EQ(result[2], 4);
		ASSERT_EQ(result[3], 3);
		delete[] result;
		result = new int[4];
		found = list->findIntersection(val2, val3, size-1, size, result);
		ASSERT_EQ(found, -1);
		delete[] result;
	}
	TEST_F(ARR, findUnion) {
		int const size = 7;
		list->size = size;
		int val1[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int val2[4] = { 5, 6, 2, 0 };
		int val3[4] = { 1, 4, 3, 4 };
		int* result = new int[7];
		list->findUnion(val2, val3, 4, 4, result);
		for (int j = 0; j < size; j++) {
			ASSERT_EQ(result[j], val1[j]);
		}
		delete[] result;
	}
	TEST_F(ARR, checkPallindrome) {
		int const size = 7;
		list->size = size;
		int val1[size] = { 5, 6, 2, 0, 2, 6, 5 };
		bool found = list->checkPallindrome(val1);
		ASSERT_EQ(found, true);
		int val2[size] = { 0, 2, 6, 1, 6, 1, 0};
		found = list->checkPallindrome(val2);
		ASSERT_EQ(found, false);
	}
	TEST_F(ARR, checkKthLargestElement) {
		int const size = 7;
		list->size = size;
		int val1[size] = { 5, 6, 2, 0, 1, 4, 3 };
		
		int k = 1;
		int expectedKthLargest = 6;
		int kLarge = list->findKthLargestElement(val1, k);
		ASSERT_EQ(kLarge, expectedKthLargest);

		k = 2;
		expectedKthLargest = 5;
		kLarge = list->findKthLargestElement(val1, k);
		ASSERT_EQ(kLarge, expectedKthLargest);

		k = 5;
		expectedKthLargest = 2;
		kLarge = list->findKthLargestElement(val1, k);
		ASSERT_EQ(kLarge, expectedKthLargest);
	}
	TEST_F(ARR, checkKthSmallestElement) {
		int const size = 7;
		list->size = size;
		int val1[size] = { 5, 6, 2, 0, 1, 4, 3 };

		int k = 1;
		int expectedKthLargest = 0;
		int kLarge = list->findKthSmallestElement(val1, k);
		ASSERT_EQ(kLarge, expectedKthLargest);

		k = 2;
		expectedKthLargest = 1;
		kLarge = list->findKthSmallestElement(val1, k);
		ASSERT_EQ(kLarge, expectedKthLargest);

		k = 5;
		expectedKthLargest = 4;
		kLarge = list->findKthSmallestElement(val1, k);
		ASSERT_EQ(kLarge, expectedKthLargest);
	}
	TEST_F(ARR, getSubArrayWithSpecificSum) {
		int const size = 7;
		list->size = size;
		int val1[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int* result;

		int sum = 1;
		int resultSize = 2;
		int * expectedResult = new int[resultSize]{ 0, 1 };
		result = new int[resultSize];
		list->getSubArrayWithSpecificSum(val1, sum, result);
		for (int i = 0; i < resultSize; i++) {
			ASSERT_EQ(result[i], expectedResult[i]);
		}
		delete[] result;
		delete[] expectedResult;

		sum = 9;
		resultSize = 4;
		expectedResult = new int[resultSize]{ 6, 2, 0, 1 };
		result = new int[resultSize];
		list->getSubArrayWithSpecificSum(val1, sum, result);
		for (int i = 0; i < resultSize; i++) {
			ASSERT_EQ(result[i], expectedResult[i]);
		}
		delete[] result;
		delete[] expectedResult;

		sum = 12;
		result = new int[resultSize];
		list->getSubArrayWithSpecificSum(val1, sum, result);
		ASSERT_EQ(result[0], -10000);
		delete[] result;

	}
	TEST_F(ARR, getSubArrayWithSpecificProduct) {
		int const size = 7;
		list->size = size;
		int val1[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int* result;

		int sum = 30;
		int resultSize = 2;
		int* expectedResult = new int[resultSize] { 5, 6 };
		result = new int[resultSize];
		list->getSubArrayWithSpecificProduct(val1, sum, result);
		for (int i = 0; i < resultSize; i++) {
			ASSERT_EQ(result[i], expectedResult[i]);
		}
		delete[] result;
		delete[] expectedResult;

		sum = 0;
		resultSize = 4;
		expectedResult = new int[resultSize] { 5, 6, 2, 0};
		result = new int[resultSize];
		list->getSubArrayWithSpecificProduct(val1, sum, result);
		for (int i = 0; i < resultSize; i++) {
			ASSERT_EQ(result[i], expectedResult[i]);
		}
		delete[] result;
		delete[] expectedResult;

		sum = -1;
		result = new int[resultSize];
		list->getSubArrayWithSpecificProduct(val1, sum, result);
		ASSERT_EQ(result[0], -10000);
		delete[] result;

	}
	TEST_F(ARR, segregateElementsBasedOnSign) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, -6, 2, 0, -1, 4, -3 };
		int val1[size] = { -6, -1, -3, 5, 2, 0, 4 };

		list->segregateElementsBasedOnSign(val);
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(val[i], val1[i]);
		}
	}
	TEST_F(ARR, segregateElementsBasedOnEvenOdd) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int val1[size] = { 5, 1, 3, 6, 2, 0, 4 };

		list->segregateElementsBasedOnEvenOdd(val);
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(val[i], val1[i]);
		}
	}
	TEST_F(ARR, findCommonElementsInThreeSortedArrays) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int val1[size-1] = { 1, 7, 10, 11, 5, 0};
		int val2[size] = { 1, 7, 9, -10, -1, 5, 0 };
		int* result = new int[3];
		int expected[3] = {5, 0, 1};
		list->findCommonElementsInThreeSortedArrays(val, val1, val2, size, size-1, size, result);
		for (int i = 0; i < 3; i++) {
			ASSERT_EQ(result[i], expected[i]);
		}
		delete[] result;
	}
	TEST_F(ARR, rearrangeWithAlternatingSign) {
		int const size = 7;
		list->size = size;
		int val[size] = { 5, -6, 2, 0, -1, 4, -3 };
		int val1[size] = { 5, -6, 2, -1, 0, -3, 4 };

		list->rearrangeWithAlternatingSign(val);
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(val[i], val1[i]);
		}
	}
	TEST_F(ARR, findLargestSumContiguousSubArray) {
		int const size = 7;
		list->size = size;
		int val1[size] = { 5, -6, 2, 0, 1, 4, -3 };
		int* result;

		int resultSize = 4;
		int expectedResult[4] = {2, 0, 1, 4};
		result = new int[resultSize];
		list->findLargestSumContiguousSubArray(val1, result);
		for (int i = 0; i < resultSize; i++) {
			ASSERT_EQ(result[i], expectedResult[i]);
		}
		delete[] result;
	}
	TEST_F(ARR, findLargestProductContiguousSubArray) {
		int const size = 7;
		list->size = size;
		int val1[size] = { 5, -6, 2, 0, 1, 4, -3 };
		int* result;

		int resultSize = 1;
		int expectedResult[1] = { 5 };
		result = new int[resultSize];
		list->findLargestProductContiguousSubArray(val1, result);
		for (int i = 0; i < resultSize; i++) {
			ASSERT_EQ(result[i], expectedResult[i]);
		}
		delete[] result;
	}
}

