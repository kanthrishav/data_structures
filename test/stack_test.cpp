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

}