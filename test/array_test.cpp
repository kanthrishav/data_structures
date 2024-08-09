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
}

