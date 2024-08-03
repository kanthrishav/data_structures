#include "pch.h"

namespace LINKEDLIST {
	class LL : public testing::Test {
	public:
		LinearLL * list = new LinearLL;
		NodeLL* ptr = NULL;
		void SetUp() {
			// pass
		}
		void TearDown() {
			delete list;
		}
	};
	
	class INSERTION : public LL {};
	TEST_F(INSERTION, NULL_head) {
		ASSERT_EQ(list->head, nullptr);
	}
	TEST_F(INSERTION, Start_1Val) {
		int val = 0;
		list->insertAtStart(val);
		ASSERT_EQ(list->head->info, val);
	}
	TEST_F(INSERTION, Start_5Val) {
		int val[5] = {5, 6, 2, 0, 3 };
		int i;
		for(i = 0; i < 5; i++)
			list->insertAtStart(val[i]);
		ptr = list->head;
		for (i = 0; i < 5; i++) {
			ASSERT_EQ(ptr->info, val[4-i]);
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
			ASSERT_EQ(ptr->info, val[4-i]);
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
	TEST_F(DELETION, Start_all_NULL_head) {
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
	TEST_F(DELETION, End_all_NULL_head) {
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
		int val[size] = { 5, 6, 2, 0, 3, 1, 7};
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
		int val[size] = { 5, 6, 2, 0, 1, 4, 3};
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
			ASSERT_EQ(ptr->info, val[size-1-i]);
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
		int val2[size] = { 3, 5, 6, 2, 0, 1, 4};
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
		int val2[size] = { 2, 0, 1, 4, 3, 5, 6};
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
		NodeLL * otherList = list->splitListInTwo(3);
		ptr = list->head;
		int val2[size-3] = { 5, 6, 2, 0 };
		int val3[3] = { 1, 4, 3 };
		for (i = 0; i < (size-3); i++) {
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
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val[i]);
			ptr = ptr->next;
		}
		list->sortListMerge('a');
		int val2[size] = { 0, 1, 2, 3, 4, 5, 6 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val2[i]);
			ptr = ptr->next;
		}
		list->sortListMerge('d');
		int val3[size] = { 6, 5, 4, 3, 2, 1, 0 };
		ptr = list->head;
		for (i = 0; i < size; i++) {
			ASSERT_EQ(ptr->info, val3[i]);
			ptr = ptr->next;
		}
	}

}