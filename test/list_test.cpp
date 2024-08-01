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
}