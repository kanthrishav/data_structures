#include "pch.h"

namespace STACK_T {
	class STK : public testing::Test {
	public:
		Stack* list = new Stack;
		void SetUp() {
			// pass
		}
		void TearDown() {
			delete list;
		}
	};

	TEST_F(STK, pushpop) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->push(val[i]);
		for (i = size - 1; i >  -1; i--)
			ASSERT_EQ(list->pop(), val[i]);
	}
	TEST_F(STK, deleteMiddleElement) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->push(val[i]);
		list->deleteMiddleElement();
		int val2[size-1] = { 5, 6, 2, 1, 4, 3 };
		for (i = size - 2; i > -1; i--)
			ASSERT_EQ(list->pop(), val2[i]);
	}
	TEST_F(STK, reverseArray) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		list->reverseArray(val, size);
		int val2[size] = { 3, 4, 1, 0, 2, 6, 5 };
		for (i = 0; i < size; i++)
			ASSERT_EQ(val[i], val2[i]);
	}
	TEST_F(STK, reverseString) {
		int const size = 7;
		char* val = "asfdfee";
		int i;
		char* newArr = new char[size];
		list->reverseString(val, newArr, size);
		char* val2 = "eefdfsa";
		for (i = 0; i < size; i++)
			ASSERT_EQ(newArr[i], val2[i]);
		delete[] newArr;
	}
	TEST_F(STK, reverseStdString) {
		std::string valStr = "asfdfee";
		std::string valRet = list->reverseString(valStr);
		std::string val2Str = "eefdfsa";
		ASSERT_EQ(valRet, val2Str);
	}
	TEST_F(STK, checkParenthesis0) {
		std::string valStr = "(){}[]";
		bool valRet1 = list->checkParenthesis(valStr);
		ASSERT_EQ(valRet1, true);
	}
	TEST_F(STK, checkParenthesis1) {
		std::string valStr = "({[]})";
		bool valRet2 = list->checkParenthesis(valStr);
		ASSERT_EQ(valRet2, true);
	}
	TEST_F(STK, checkParenthesis2) {
		std::string valStr = "({}[])";
		bool valRet3 = list->checkParenthesis(valStr);
		ASSERT_EQ(valRet3, true);
	}
	TEST_F(STK, checkParenthesis3) {
		std::string valStr = "({[}])";
		bool valRet4 = list->checkParenthesis(valStr);
		ASSERT_EQ(valRet4, false);
	}
	TEST_F(STK, getLongestValidParanthesis) {
		std::string valStr = "(a*b*{a + [e+f*h - g]}*f]*h)";
		std::string valRet4 = list->getLongestValidParanthesis(valStr);
		ASSERT_EQ(valRet4, "{a + [e+f*h - g]}");
	}
	TEST_F(STK, reverseIndividualWords) {
		std::string valStr = "I am in a Belise.";
		std::string valRet4 = list->reverseIndividualWords(valStr);
		ASSERT_EQ(valRet4, "I ma ni a esileB.");
		valStr = "You might !see some C++ programs that use? the size():";
		valRet4 = list->reverseIndividualWords(valStr);
		ASSERT_EQ(valRet4, "uoY thgim !ees emos ++C smargorp taht ?esu eht ()ezis:");
	}
	TEST_F(STK, evaluatePostfixExpression) {
		std::string valStr = "231*+9-";
		int valRet4 = list->evaluatePostfixExpression(valStr);
		ASSERT_EQ(valRet4, -4);
	}
	TEST_F(STK, sortBubble) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valSortedAscend[size] = { 0, 1, 2, 3, 4, 5, 6 };
		int valSortedDescend[size] = { 6, 5, 4, 3, 2, 1, 0 };
		int i;
		for (i = 0; i < size; i++) {
			list->push(val[i]);
		}

		list->sortBubble('a');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedAscend[i], list->elements[i]);
		}
		list->sortBubble('d');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedDescend[i], list->elements[i]);
		}
	}
	TEST_F(STK, sortSelection) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valSortedAscend[size] = { 0, 1, 2, 3, 4, 5, 6 };
		int valSortedDescend[size] = { 6, 5, 4, 3, 2, 1, 0 };
		int i;
		for (i = 0; i < size; i++) {
			list->push(val[i]);
		}

		list->sortSelection('a');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedAscend[i], list->elements[i]);
		}
		list->sortBubble('d');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedDescend[i], list->elements[i]);
		}
	}
	TEST_F(STK, sortInsertion) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valSortedAscend[size] = { 0, 1, 2, 3, 4, 5, 6 };
		int valSortedDescend[size] = { 6, 5, 4, 3, 2, 1, 0 };
		int i;
		for (i = 0; i < size; i++) {
			list->push(val[i]);
		}

		list->sortInsertion('a');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedAscend[i], list->elements[i]);
		}
		list->sortBubble('d');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedDescend[i], list->elements[i]);
		}
	}
	TEST_F(STK, sortMerge) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valSortedAscend[size] = { 0, 1, 2, 3, 4, 5, 6 };
		int valSortedDescend[size] = { 6, 5, 4, 3, 2, 1, 0 };
		int i;
		for (i = 0; i < size; i++) {
			list->push(val[i]);
		}

		list->sortMerge(0, list->topIndex, 'a');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedAscend[i], list->elements[i]);
		}
		list->sortMerge(0, list->topIndex, 'd');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedDescend[i], list->elements[i]);
		}
	}
	TEST_F(STK, sortQuick) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valSortedAscend[size] = { 0, 1, 2, 3, 4, 5, 6 };
		int valSortedDescend[size] = { 6, 5, 4, 3, 2, 1, 0 };
		int i;
		for (i = 0; i < size; i++) {
			list->push(val[i]);
		}

		list->sortQuick(0, list->topIndex, 'a');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedAscend[i], list->elements[i]);
		}
		list->sortQuick(0, list->topIndex, 'd');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedDescend[i], list->elements[i]);
		}
	}
	TEST_F(STK, sortHeap) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int valSortedAscend[size] = { 0, 1, 2, 3, 4, 5, 6 };
		int valSortedDescend[size] = { 6, 5, 4, 3, 2, 1, 0 };
		int i;
		for (i = 0; i < size; i++) {
			list->push(val[i]);
		}

		list->sortHeap('a');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedAscend[i], list->elements[i]);
		}

		int temp = list->elements[3];
		list->elements[3] = list->elements[5];
		list->elements[5] = temp;

		list->sortHeap('d');
		for (int i = 0; i < size; i++) {
			ASSERT_EQ(valSortedDescend[i], list->elements[i]);
		}
	}
	TEST_F(STK, getNextGreaterElement) {
		int const size = 9;
		int val1[6] = { 4, 1, 0, 3, 6, 5 };
		int val2[size] = { 5, 6, 2, 4, 1, 0, 3, 7, 9};
		int i = list->getNextGreaterElement(val1, val2, 6, 9);
		ASSERT_EQ(i, 5);
	}
	TEST_F(STK, deleteConsecutiveSameWordsInSequence) {
		std::string str = "That guy works works as a postman in the day but also runs runs his shop at night.";
		std::string newStr = list->deleteConsecutiveSameWordsInSequence(str);
		std::string expectedStr = "That guy works as a postman in the day but also runs his shop at night.";
		ASSERT_EQ(newStr, expectedStr);
	}

}