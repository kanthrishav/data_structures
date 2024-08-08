#include "pch.h"

namespace LINKEDLIST_linear {
	class LL : public testing::Test {
	public:
		LinearLL* list = new LinearLL;
		NodeLL* ptr = nullptr;
		void SetUp() {
			// pass
		}
		void TearDown() {
			delete list;
		}
	};

	class INSERTION : public LL {};
	TEST_F(INSERTION, nullptr_head) {
		ASSERT_EQ(list->head, nullptr);
	}
	TEST_F(INSERTION, Start_1Val) {
		int val = 0;
		list->insertAtStart(val);
		ASSERT_EQ(list->head->info, val);
	}
	TEST_F(INSERTION, Start_5Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtStart(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[4 - i]);
			ptr = ptr->next;
		}
	}
	TEST_F(INSERTION, End_1Val) {
		int val = 0;
		list->insertAtEnd(val);
		ASSERT_EQ(list->head->info, val);
	}
	TEST_F(INSERTION, End_5Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(INSERTION, Start5Val_End1Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtStart(val[i]);
		list->insertAtEnd(7);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[4 - i]);
			ptr = ptr->next;
		}
		ASSERT_EQ(ptr->info, 7);
	}
	TEST_F(INSERTION, End5Val_Start1Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		list->insertAtStart(7);
		ptr = list->head;
		ASSERT_EQ(ptr->info, 7);
		ptr = ptr->next;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(INSERTION, After_1Val_FOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		found = list->insertAfter(7, 2);
		ASSERT_EQ(found, true);
		ASSERT_EQ(list->head->next->next->next->info, 7);
	}
	TEST_F(INSERTION, After_1Val_NOTFOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		found = list->insertAfter(7, 11);
		ASSERT_EQ(found, false);
	}
	TEST_F(INSERTION, Before_1Val_FOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		found = list->insertBefore(7, 2);
		ASSERT_EQ(found, true);
		ASSERT_EQ(list->head->next->next->info, 7);
	}
	TEST_F(INSERTION, Before_1Val_NOTFOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		found = list->insertBefore(7, 11);
		ASSERT_EQ(found, false);
	}


	class DELETION : public LL {};
	TEST_F(DELETION, Start_1Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->deleteAtStart();
		ASSERT_EQ(list->head->info, 6);
	}
	TEST_F(DELETION, Start_4Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->deleteAtStart();
		list->deleteAtStart();
		list->deleteAtStart();
		list->deleteAtStart();
		ASSERT_EQ(list->head->info, 3);
	}
	TEST_F(DELETION, Start_all_nullptr_head) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->deleteAtStart();
		list->deleteAtStart();
		list->deleteAtStart();
		list->deleteAtStart();
		list->deleteAtStart();
		ASSERT_EQ(list->head, nullptr);
	}
	TEST_F(DELETION, End_1Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->deleteAtEnd();
		ASSERT_EQ(list->head->next->next->next->info, 0);
	}
	TEST_F(DELETION, End_4Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->deleteAtEnd();
		list->deleteAtEnd();
		list->deleteAtEnd();
		list->deleteAtEnd();
		ASSERT_EQ(list->head->info, 5);
	}
	TEST_F(DELETION, End_all_nullptr_head) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->deleteAtEnd();
		list->deleteAtEnd();
		list->deleteAtEnd();
		list->deleteAtEnd();
		list->deleteAtEnd();
		ASSERT_EQ(list->head, nullptr);
	}
	TEST_F(DELETION, After_1Val_FOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		found = list->deleteAfter(6);
		ASSERT_EQ(list->head->next->next->info, 0);
		ASSERT_EQ(found, true);
	}
	TEST_F(DELETION, After_1Val_NOTFOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		found = list->deleteAfter(7);
		ASSERT_EQ(found, false);
	}
	TEST_F(DELETION, Before_1Val_FOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		found = list->deleteBefore(2);
		ASSERT_EQ(list->head->next->info, 2);
		ASSERT_EQ(found, true);
	}
	TEST_F(DELETION, Before_1Val_NOTFOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		found = list->deleteBefore(7);
		ASSERT_EQ(found, false);
	}
	TEST_F(DELETION, All) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->deleteList();
		ASSERT_EQ(list->head, nullptr);
	}

	TEST_F(DELETION, 3NodesAfter6_3PRESENT) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 3, 1, 7 };
		int i;
		bool present;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		present = list->deleteMNodesAfterNNodes(3, 6);
		ASSERT_EQ(present, true);
		ASSERT_EQ(list->head->next->next->info, 1);
		ASSERT_EQ(list->head->next->next->next->info, 7);
	}

	TEST_F(DELETION, 3NodesAfter3_3ABSENT) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 3, 1, 7 };
		int i;
		bool present;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		present = list->deleteMNodesAfterNNodes(3, 3);
		ASSERT_EQ(present, false);
		ASSERT_EQ(list->head->next->next->next->next->next, nullptr);
	}

	TEST_F(DELETION, 3NodesBefore3_3PRESENT) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 3, 1, 7 };
		int i;
		bool present;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		present = list->deleteMNodesBeforeNNodes(3, 3);
		ASSERT_EQ(present, true);
		ASSERT_EQ(list->head->next->info, 3);
		ASSERT_EQ(list->head->next->next->info, 1);
		ASSERT_EQ(list->head->next->next->next->info, 7);
	}

	TEST_F(DELETION, 3NodesBefore3_3ABSENT) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 3, 1, 7 };
		int i;
		bool present;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		present = list->deleteMNodesBeforeNNodes(3, 6);
		ASSERT_EQ(present, false);
		ASSERT_EQ(list->head->info, 6);
	}
	TEST_F(DELETION, OddNodes) {
		int const size = 5;
		int val[size] = { 5, 2, 3, 0, 7 };
		int i;
		int frequency;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		frequency = list->deleteOddNodes();
		ASSERT_EQ(frequency, 3);
		ASSERT_EQ(list->head->info, 2);
		ASSERT_EQ(list->head->next->info, 0);
		ASSERT_EQ(list->head->next->next, nullptr);
	}
	TEST_F(DELETION, EvenNodes) {
		int const size = 5;
		int val[size] = { 2, 5, 4, 0, 7 };
		int i;
		int frequency;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		frequency = list->deleteEvenNodes();
		ASSERT_EQ(frequency, 3);
		ASSERT_EQ(list->head->info, 5);
		ASSERT_EQ(list->head->next->info, 7);
		ASSERT_EQ(list->head->next->next, nullptr);
	}
	TEST_F(DELETION, NodesWith6) {
		int const size = 5;
		int val[size] = { 5, 6, 6, 4, 6 };
		int i;
		int frequency;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		frequency = list->deleteSpecificNodes(6);
		ASSERT_EQ(frequency, 3);
		ASSERT_EQ(list->head->info, 5);
		ASSERT_EQ(list->head->next->info, 4);
		ASSERT_EQ(list->head->next->next, nullptr);
	}


	class ARRANGEMENT : public LL {};
	TEST_F(ARRANGEMENT, reverse) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->reverseList();
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[size - 1 - i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, swapNodes) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		NodeLL* p0;
		NodeLL* p1;
		NodeLL* p2;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			if (i == 1)
				p0 = ptr;
			if (i == 2)
				p1 = ptr;
			if (i == 3)
				p2 = ptr;
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->swapNodes(p0, p1, p2);
		ptr = list->head;
		ASSERT_EQ(ptr->info, val[0]);
		ptr = ptr->next;
		ASSERT_EQ(ptr->info, val[1]);
		ptr = ptr->next;
		ASSERT_EQ(ptr->info, val[3]);
		ptr = ptr->next;
		ASSERT_EQ(ptr->info, val[2]);
		ptr = ptr->next;
		for (i = 4; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, length) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		int len = list->length();
		ASSERT_EQ(len, size);
	}
	TEST_F(ARRANGEMENT, rotateFromStartToEndBy2) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->rotateFromStartToEndBy(2);
		ptr = list->head;
		int val2[size] = { 4, 3, 5, 6, 2, 0, 1 };
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, rotateFromStartToEndBy4) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->rotateFromStartToEndBy(4);
		ptr = list->head;
		int val2[size] = { 0, 1, 4, 3, 5, 6, 2 };
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, rotateFromStartToEndBy1) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->rotateFromStartToEndBy(1);
		ptr = list->head;
		int val2[size] = { 3, 5, 6, 2, 0, 1, 4 };
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, rotateFromEndToStartBy2) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->rotateFromEndToStartBy(2);
		ptr = list->head;
		int val2[size] = { 2, 0, 1, 4, 3, 5, 6 };
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, rotateFromEndToStartBy4) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->rotateFromEndToStartBy(4);
		ptr = list->head;
		int val2[size] = { 1, 4, 3, 5, 6, 2, 0 };
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, rotateFromEndToStartBy1) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->rotateFromEndToStartBy(1);
		ptr = list->head;
		int val2[size] = { 6, 2, 0, 1, 4, 3, 5 };
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, splitInTwoAt3) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		NodeLL* otherList = list->splitListInTwo(3);
		ptr = list->head;
		int val2[size - 3] = { 5, 6, 2, 0 };
		int val3[3] = { 1, 4, 3 };
		for (i = 0; i < (size - 3); i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		ptr = otherList;
		for (i = 0; i < 3; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, splitInTwoAt5) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		NodeLL* otherList = list->splitListInTwo(5);
		ptr = list->head;
		int val2[size - 1] = { 5, 6, 2, 0, 1, 4 };
		int val3[1] = { 3 };
		for (i = 0; i < (size - 1); i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		ptr = otherList;
		for (i = 0; i < 1; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, splitInTwoAt0) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		NodeLL* otherList = list->splitListInTwo(0);
		ptr = list->head;
		int val2[1] = { 5 };
		int val3[size - 1] = { 6, 2, 0, 1, 4, 3 };
		for (i = 0; i < 1; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		ptr = otherList;
		for (i = 0; i < (size - 1); i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, splitIntoEvenOdd) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		NodeLL* even = list->splitIntoOddEvenLists();
		ptr = list->head;
		int val2[3] = { 5, 1, 3 };
		int val3[4] = { 6, 2, 0, 4 };
		for (i = 0; i < 3; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		ptr = even;
		for (i = 0; i < 4; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, removeDuplicates) {
		int const size = 15;
		int val[size] = { 0, 5, 0, 6, 2, 0, 1, 6, 1, 1, 4, 3, 3, 3, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		list->removeDuplicates();
		ptr = list->head;
		int val2[7] = { 0, 5, 6, 2, 1, 4, 3 };
		for (i = 0; i < 7; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, removeDuplicatesInSortedList) {
		int const size = 12;
		int val[size] = { 0, 0, 0, 1, 1, 2, 3, 4, 4, 4, 4, 5 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		list->removeDuplicatesFromSortedList();
		ptr = list->head;
		int val2[7] = { 0, 1, 2, 3, 4, 5 };
		for (i = 0; i < 6; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, bubbleSort) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->sortListBubble('a');
		int val2[size] = { 0, 1, 2, 3, 4, 5, 6 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		list->sortListBubble('d');
		int val3[size] = { 6, 5, 4, 3, 2, 1, 0 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, selectionSort) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->sortListSelection('a');
		int val2[size] = { 0, 1, 2, 3, 4, 5, 6 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		list->sortListSelection('d');
		int val3[size] = { 6, 5, 4, 3, 2, 1, 0 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, insertionSort) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->sortListInsertion('a');
		int val2[size] = { 0, 1, 2, 3, 4, 5, 6 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		list->sortListInsertion('d');
		int val3[size] = { 6, 5, 4, 3, 2, 1, 0 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, mergeSort) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < (size - 1); i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}

		ptr = list->head;
		while (ptr->next != nullptr)
			ptr = ptr->next;

		list->sortListMerge(&list->head, 'a');

		int val2[size] = { 0, 1, 2, 3, 4, 5, 6 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}

		ptr = list->head;
		while (ptr->next != nullptr)
			ptr = ptr->next;
		list->sortListMerge(&list->head, 'd');
		int val3[size] = { 6, 5, 4, 3, 2, 1, 0 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT, quickSort) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < (size - 1); i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}

		ptr = list->head;
		while (ptr->next != nullptr)
			ptr = ptr->next;

		list->sortListQuick(&list->head, 'a');

		int val2[size] = { 0, 1, 2, 3, 4, 5, 6 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		
		ptr = list->head;
		while (ptr->next != nullptr)
			ptr = ptr->next;
		list->sortListQuick(&list->head, 'd');
		int val3[size] = { 6, 5, 4, 3, 2, 1, 0 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}


	class CUSTOM : public LL {};

	TEST_F(CUSTOM, findIntersection) {

		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}

		ptr = list->head;
		int intersectionValue = 2;
		NodeLL* intersectionPtr;
		while (ptr != nullptr) {
			if (ptr->info == intersectionValue) {
				intersectionPtr = ptr;
				break;
			}
			ptr = ptr->next;
		}

		int val2[size] = { 7, 8, intersectionValue, 0, 1, 4, 3 };
		LinearLL* list2 = new LinearLL;
		list2->insertAtEnd(val2[0]);
		list2->insertAtEnd(val2[1]);
		list2->head->next->next = ptr;
		ptr = list2->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}

		NodeLL* intersectionNode = list->findIntersection(list->head, list2->head);
		ASSERT_EQ(intersectionNode->info, intersectionValue);

		int val3[5] = { 9, 10, 11, 12, 13 };
		LinearLL* list3 = new LinearLL;
		for (i = 0; i < size; i++)
			list3->insertAtEnd(val3[i]);
		intersectionNode = list3->findIntersection(list3->head, list2->head);
		ASSERT_EQ(intersectionNode, nullptr);
		intersectionNode = list3->findIntersection(list3->head, list->head);
		ASSERT_EQ(intersectionNode, nullptr);

	}
	TEST_F(CUSTOM, findCycles) {

		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		NodeLL* ptr = list->head;
		NodeLL* ptr2;
		for (i = 0; i < (size - 1); i++) {
			if (ptr->info == 0)
				ptr2 = ptr;
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		bool found = list->findCycles();
		ASSERT_EQ(found, false);

		ptr->next = ptr2;

		found = list->findCycles();
		ASSERT_EQ(found, true);
	}
	TEST_F(CUSTOM, findCentre) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		NodeLL* ptr = list->head;
		for (i = 0; i < (size - 1); i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		NodeLL* centre = list->findCentre();
		ASSERT_EQ(centre->info, 0);
	}
	TEST_F(CUSTOM, findValueFrequency) {
		int val[15] = { 0, 5, 0, 6, 2, 0, 1, 6, 1, 1, 4, 3, 3, 3, 3 };
		int i;
		for (i = 0; i < 15; i++)
			list->insertAtEnd(val[i]);
		NodeLL* ptr = list->head;
		for (i = 0; i < 15; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		int* pFreq = list->findFrequencyOfNodes();
		ASSERT_EQ(pFreq[0], 3);
		ASSERT_EQ(pFreq[1], 3);
		ASSERT_EQ(pFreq[2], 1);
		ASSERT_EQ(pFreq[3], 4);
		ASSERT_EQ(pFreq[4], 1);
		ASSERT_EQ(pFreq[5], 1);
		ASSERT_EQ(pFreq[6], 2);
		ASSERT_EQ(pFreq[7], 0);
		ASSERT_EQ(pFreq[8], 0);
		ASSERT_EQ(pFreq[9], 0);
	}
	TEST_F(CUSTOM, checkPallindrome) {
		int val[8] = { 0, 5, 0, 6, 6, 0, 5, 0 };
		int i;
		for (i = 0; i < 8; i++)
			list->insertAtEnd(val[i]);
		NodeLL* ptr = list->head;
		for (i = 0; i < 8; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		bool found = list->checkPallindrome();
		ASSERT_EQ(found, true);

		val[5] = 1;
		found = list->checkPallindrome();
		ASSERT_EQ(found, false);
	}
	TEST_F(CUSTOM, addPolynomials) {
		int coeff1[4] = { 0, 5, 0, 6 };
		int pow1[4] = { 0, 1, 2, 3 };
		int coeff2[2] = { 4, -3 };
		int pow2[2] = { 1, 2 };

		LinearLL* head1 = new LinearLL;
		LinearLL* head2 = new LinearLL;

		head1->head2 = new NodeLL2;
		head2->head2 = new NodeLL2;
		NodeLL2* ptr1 = head1->head2;
		NodeLL2* ptr2 = head2->head2;

		for (int i = 0; i < 4; i++) {
			ptr1->info1 = coeff1[i];
			ptr1->info2 = pow1[i];
			ptr1->next = new NodeLL2;
			ptr1 = ptr1->next;
		}
		for (int i = 0; i < 2; i++) {
			ptr2->info1 = coeff2[i];
			ptr2->info2 = pow2[i];
			ptr2->next = new NodeLL2;
			ptr2 = ptr2->next;
		}
		NodeLL2* addedPtr = list->addPolynomials(head1->head2, head2->head2);
		ASSERT_EQ(addedPtr->info1, 0);
		addedPtr = addedPtr->next;
		ASSERT_EQ(addedPtr->info1, 9);
		addedPtr = addedPtr->next;
		ASSERT_EQ(addedPtr->info1, -3);
		addedPtr = addedPtr->next;
		ASSERT_EQ(addedPtr->info1, 6);
	}

}

namespace LINKEDLIST_double {
	class DL : public testing::Test {
	public:
		DoublyLL* list = new DoublyLL;
		NodeDL* ptr = nullptr;
		void SetUp() {
			// pass
		}
		void TearDown() {
			delete list;
		}
	};

	class INSERTION_DL : public DL {};
	TEST_F(INSERTION_DL, nullptr_head) {
		ASSERT_EQ(list->head, nullptr);
	}
	TEST_F(INSERTION_DL, Start_1Val) {
		int val = 0;
		list->insertAtStart(val);
		ASSERT_EQ(list->head->info, val);
	}
	TEST_F(INSERTION_DL, Start_5Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtStart(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[4 - i]);
			ptr = ptr->next;
		}
	}
	TEST_F(INSERTION_DL, End_1Val) {
		int val = 0;
		list->insertAtEnd(val);
		ASSERT_EQ(list->head->info, val);
	}
	TEST_F(INSERTION_DL, End_5Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(INSERTION_DL, Start5Val_End1Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtStart(val[i]);
		list->insertAtEnd(7);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[4 - i]);
			ptr = ptr->next;
		}
		ASSERT_EQ(ptr->info, 7);
	}
	TEST_F(INSERTION_DL, End5Val_Start1Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		list->insertAtStart(7);
		ptr = list->head;
		ASSERT_EQ(ptr->info, 7);
		ptr = ptr->next;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(INSERTION_DL, After_1Val_FOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		found = list->insertAfter(7, 2);
		ASSERT_EQ(found, true);
		ASSERT_EQ(list->head->next->next->next->info, 7);
	}
	TEST_F(INSERTION_DL, After_1Val_NOTFOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		found = list->insertAfter(7, 11);
		ASSERT_EQ(found, false);
	}
	TEST_F(INSERTION_DL, Before_1Val_FOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		found = list->insertBefore(7, 2);
		ASSERT_EQ(found, true);
		ASSERT_EQ(list->head->next->next->info, 7);
	}
	TEST_F(INSERTION_DL, Before_1Val_NOTFOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		found = list->insertBefore(7, 11);
		ASSERT_EQ(found, false);
	}


	class DELETION_DL : public DL {};
	TEST_F(DELETION_DL, Start_1Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->deleteAtStart();
		ASSERT_EQ(list->head->info, 6);
	}
	TEST_F(DELETION_DL, Start_4Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->deleteAtStart();
		list->deleteAtStart();
		list->deleteAtStart();
		list->deleteAtStart();
		ASSERT_EQ(list->head->info, 3);
	}
	TEST_F(DELETION_DL, Start_all_nullptr_head) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->deleteAtStart();
		list->deleteAtStart();
		list->deleteAtStart();
		list->deleteAtStart();
		list->deleteAtStart();
		ASSERT_EQ(list->head, nullptr);
	}
	TEST_F(DELETION_DL, End_1Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->deleteAtEnd();
		ASSERT_EQ(list->head->next->next->next->info, 0);
	}
	TEST_F(DELETION_DL, End_4Val) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->deleteAtEnd();
		list->deleteAtEnd();
		list->deleteAtEnd();
		list->deleteAtEnd();
		ASSERT_EQ(list->head->info, 5);
	}
	TEST_F(DELETION_DL, End_all_nullptr_head) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->deleteAtEnd();
		list->deleteAtEnd();
		list->deleteAtEnd();
		list->deleteAtEnd();
		list->deleteAtEnd();
		ASSERT_EQ(list->head, nullptr);
	}
	TEST_F(DELETION_DL, After_1Val_FOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		found = list->deleteAfter(6);
		ASSERT_EQ(list->head->next->next->info, 0);
		ASSERT_EQ(found, true);
	}
	TEST_F(DELETION_DL, After_1Val_NOTFOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		found = list->deleteAfter(7);
		ASSERT_EQ(found, false);
	}
	TEST_F(DELETION_DL, Before_1Val_FOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		found = list->deleteBefore(2);
		ASSERT_EQ(list->head->next->info, 2);
		ASSERT_EQ(found, true);
	}
	TEST_F(DELETION_DL, Before_1Val_NOTFOUND) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		bool found;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		found = list->deleteBefore(7);
		ASSERT_EQ(found, false);
	}
	TEST_F(DELETION_DL, All) {
		int val[5] = { 5, 6, 2, 0, 3 };
		int i;
		for (i = 0; i < 5; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->deleteList();
		ASSERT_EQ(list->head, nullptr);
	}

	TEST_F(DELETION_DL, 3NodesAfter6_3PRESENT) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 3, 1, 7 };
		int i;
		bool present;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		present = list->deleteMNodesAfterNNodes(3, 6);
		ASSERT_EQ(present, true);
		ASSERT_EQ(list->head->next->next->info, 1);
		ASSERT_EQ(list->head->next->next->next->info, 7);
	}

	TEST_F(DELETION_DL, 3NodesAfter3_3ABSENT) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 3, 1, 7 };
		int i;
		bool present;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		present = list->deleteMNodesAfterNNodes(3, 3);
		ASSERT_EQ(present, false);
		ASSERT_EQ(list->head->next->next->next->next->next, nullptr);
	}

	TEST_F(DELETION_DL, 3NodesBefore3_3PRESENT) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 3, 1, 7 };
		int i;
		bool present;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		present = list->deleteMNodesBeforeNNodes(3, 3);
		ASSERT_EQ(present, true);
		ASSERT_EQ(list->head->next->info, 3);
		ASSERT_EQ(list->head->next->next->info, 1);
		ASSERT_EQ(list->head->next->next->next->info, 7);
	}

	TEST_F(DELETION_DL, 3NodesBefore3_3ABSENT) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 3, 1, 7 };
		int i;
		bool present;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		present = list->deleteMNodesBeforeNNodes(3, 6);
		ASSERT_EQ(present, false);
		ASSERT_EQ(list->head->info, 6);
	}
	TEST_F(DELETION_DL, OddNodes) {
		int const size = 5;
		int val[size] = { 5, 2, 3, 0, 7 };
		int i;
		int frequency;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		frequency = list->deleteOddNodes();
		ASSERT_EQ(frequency, 3);
		ASSERT_EQ(list->head->info, 2);
		ASSERT_EQ(list->head->next->info, 0);
		ASSERT_EQ(list->head->next->next, nullptr);
	}
	TEST_F(DELETION_DL, EvenNodes) {
		int const size = 5;
		int val[size] = { 2, 5, 4, 0, 7 };
		int i;
		int frequency;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		frequency = list->deleteEvenNodes();
		ASSERT_EQ(frequency, 3);
		ASSERT_EQ(list->head->info, 5);
		ASSERT_EQ(list->head->next->info, 7);
		ASSERT_EQ(list->head->next->next, nullptr);
	}
	TEST_F(DELETION_DL, NodesWith6) {
		int const size = 5;
		int val[size] = { 5, 6, 6, 4, 6 };
		int i;
		int frequency;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		frequency = list->deleteSpecificNodes(6);
		ASSERT_EQ(frequency, 3);
		ASSERT_EQ(list->head->info, 5);
		ASSERT_EQ(list->head->next->info, 4);
		ASSERT_EQ(list->head->next->next, nullptr);
	}


	class ARRANGEMENT_DL : public DL {};
	TEST_F(ARRANGEMENT_DL, reverse) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->reverseList();
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[size - 1 - i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, swapNodes) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		NodeDL* p0;
		NodeDL* p1;
		NodeDL* p2;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			if (i == 1)
				p0 = ptr;
			if (i == 2)
				p1 = ptr;
			if (i == 3)
				p2 = ptr;
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->swapNodes(p0, p1, p2);
		ptr = list->head;
		ASSERT_EQ(ptr->info, val[0]);
		ptr = ptr->next;
		ASSERT_EQ(ptr->info, val[1]);
		ptr = ptr->next;
		ASSERT_EQ(ptr->info, val[3]);
		ptr = ptr->next;
		ASSERT_EQ(ptr->info, val[2]);
		ptr = ptr->next;
		for (i = 4; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, length) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		int len = list->length();
		ASSERT_EQ(len, size);
	}
	TEST_F(ARRANGEMENT_DL, rotateFromStartToEndBy2) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->rotateFromStartToEndBy(2);
		ptr = list->head;
		int val2[size] = { 4, 3, 5, 6, 2, 0, 1 };
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, rotateFromStartToEndBy4) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->rotateFromStartToEndBy(4);
		ptr = list->head;
		int val2[size] = { 0, 1, 4, 3, 5, 6, 2 };
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, rotateFromStartToEndBy1) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->rotateFromStartToEndBy(1);
		ptr = list->head;
		int val2[size] = { 3, 5, 6, 2, 0, 1, 4 };
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, rotateFromEndToStartBy2) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->rotateFromEndToStartBy(2);
		ptr = list->head;
		int val2[size] = { 2, 0, 1, 4, 3, 5, 6 };
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, rotateFromEndToStartBy4) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->rotateFromEndToStartBy(4);
		ptr = list->head;
		int val2[size] = { 1, 4, 3, 5, 6, 2, 0 };
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, rotateFromEndToStartBy1) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->rotateFromEndToStartBy(1);
		ptr = list->head;
		int val2[size] = { 6, 2, 0, 1, 4, 3, 5 };
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, splitInTwoAt3) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		NodeDL* otherList = list->splitListInTwo(3);
		ptr = list->head;
		int val2[size - 3] = { 5, 6, 2, 0 };
		int val3[3] = { 1, 4, 3 };
		for (i = 0; i < (size - 3); i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		ptr = otherList;
		for (i = 0; i < 3; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, splitInTwoAt5) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		NodeDL* otherList = list->splitListInTwo(5);
		ptr = list->head;
		int val2[size - 1] = { 5, 6, 2, 0, 1, 4 };
		int val3[1] = { 3 };
		for (i = 0; i < (size - 1); i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		ptr = otherList;
		for (i = 0; i < 1; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, splitInTwoAt0) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		NodeDL* otherList = list->splitListInTwo(0);
		ptr = list->head;
		int val2[1] = { 5 };
		int val3[size - 1] = { 6, 2, 0, 1, 4, 3 };
		for (i = 0; i < 1; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		ptr = otherList;
		for (i = 0; i < (size - 1); i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, splitIntoEvenOdd) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		NodeDL* even = list->splitIntoOddEvenLists();
		ptr = list->head;
		int val2[3] = { 5, 1, 3 };
		int val3[4] = { 6, 2, 0, 4 };
		for (i = 0; i < 3; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		ptr = even;
		for (i = 0; i < 4; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, removeDuplicates) {
		int const size = 15;
		int val[size] = { 0, 5, 0, 6, 2, 0, 1, 6, 1, 1, 4, 3, 3, 3, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		list->removeDuplicates();
		ptr = list->head;
		int val2[7] = { 0, 5, 6, 2, 1, 4, 3 };
		for (i = 0; i < 7; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, removeDuplicatesInSortedList) {
		int const size = 12;
		int val[size] = { 0, 0, 0, 1, 1, 2, 3, 4, 4, 4, 4, 5 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		list->removeDuplicatesFromSortedList();
		ptr = list->head;
		int val2[7] = { 0, 1, 2, 3, 4, 5 };
		for (i = 0; i < 6; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, bubbleSort) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->sortListBubble('a');
		int val2[size] = { 0, 1, 2, 3, 4, 5, 6 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		list->sortListBubble('d');
		int val3[size] = { 6, 5, 4, 3, 2, 1, 0 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, selectionSort) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->sortListSelection('a');
		int val2[size] = { 0, 1, 2, 3, 4, 5, 6 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		list->sortListSelection('d');
		int val3[size] = { 6, 5, 4, 3, 2, 1, 0 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, insertionSort) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->sortListInsertion('a');
		int val2[size] = { 0, 1, 2, 3, 4, 5, 6 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		list->sortListInsertion('d');
		int val3[size] = { 6, 5, 4, 3, 2, 1, 0 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}
	TEST_F(ARRANGEMENT_DL, mergeSort) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < (size - 1); i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}

		ptr = list->head;
		while (ptr->next != nullptr)
			ptr = ptr->next;

		list->sortListMerge(&list->head);

		int val2[size] = { 0, 1, 2, 3, 4, 5, 6 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}

		/*
		ptr = list->head;
		while (ptr->next != nullptr)
			ptr = ptr->next;
		list->sortListMerge(&list->head, 'd');
		int val3[size] = { 6, 5, 4, 3, 2, 1, 0 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
		*/

	}


	class CUSTOM_DL : public DL {};

	TEST_F(CUSTOM_DL, findIntersection) {

		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}

		ptr = list->head;
		int intersectionValue = 2;
		NodeDL* intersectionPtr;
		while (ptr != nullptr) {
			if (ptr->info == intersectionValue) {
				intersectionPtr = ptr;
				break;
			}
			ptr = ptr->next;
		}

		int val2[size] = { 7, 8, intersectionValue, 0, 1, 4, 3 };
		DoublyLL* list2 = new DoublyLL;
		list2->insertAtEnd(val2[0]);
		list2->insertAtEnd(val2[1]);
		list2->head->next->next = ptr;
		ptr = list2->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}

		NodeDL* intersectionNode = list->findIntersection(list->head, list2->head);
		ASSERT_EQ(intersectionNode->info, intersectionValue);

		int val3[5] = { 9, 10, 11, 12, 13 };
		DoublyLL* list3 = new DoublyLL;
		for (i = 0; i < size; i++)
			list3->insertAtEnd(val3[i]);
		intersectionNode = list3->findIntersection(list3->head, list2->head);
		ASSERT_EQ(intersectionNode, nullptr);
		intersectionNode = list3->findIntersection(list3->head, list->head);
		ASSERT_EQ(intersectionNode, nullptr);

	}
	TEST_F(CUSTOM_DL, findCycles) {

		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		NodeDL* ptr = list->head;
		NodeDL* ptr2;
		for (i = 0; i < (size - 1); i++) {
			if (ptr->info == 0)
				ptr2 = ptr;
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		bool found = list->findCycles();
		ASSERT_EQ(found, false);

		ptr->next = ptr2;

		found = list->findCycles();
		ASSERT_EQ(found, true);
	}
	TEST_F(CUSTOM_DL, findCentre) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertAtEnd(val[i]);
		NodeDL* ptr = list->head;
		for (i = 0; i < (size - 1); i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		NodeDL* centre = list->findCentre();
		ASSERT_EQ(centre->info, 0);
	}
	TEST_F(CUSTOM_DL, findValueFrequency) {
		int val[15] = { 0, 5, 0, 6, 2, 0, 1, 6, 1, 1, 4, 3, 3, 3, 3 };
		int i;
		for (i = 0; i < 15; i++)
			list->insertAtEnd(val[i]);
		NodeDL* ptr = list->head;
		for (i = 0; i < 15; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		int* pFreq = list->findFrequencyOfNodes();
		ASSERT_EQ(pFreq[0], 3);
		ASSERT_EQ(pFreq[1], 3);
		ASSERT_EQ(pFreq[2], 1);
		ASSERT_EQ(pFreq[3], 4);
		ASSERT_EQ(pFreq[4], 1);
		ASSERT_EQ(pFreq[5], 1);
		ASSERT_EQ(pFreq[6], 2);
		ASSERT_EQ(pFreq[7], 0);
		ASSERT_EQ(pFreq[8], 0);
		ASSERT_EQ(pFreq[9], 0);
	}
	TEST_F(CUSTOM_DL, checkPallindrome) {
		int val[8] = { 0, 5, 0, 6, 6, 0, 5, 0 };
		int i;
		for (i = 0; i < 8; i++)
			list->insertAtEnd(val[i]);
		NodeDL* ptr = list->head;
		for (i = 0; i < 8; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		bool found = list->checkPallindrome();
		ASSERT_EQ(found, true);

		val[5] = 1;
		found = list->checkPallindrome();
		ASSERT_EQ(found, false);
	}

}