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

}

