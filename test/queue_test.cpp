#include "pch.h"

namespace QUEUE_T {
	class QUE : public testing::Test {
	public:
		Queue* list = new Queue;
		void SetUp() {
			// pass
		}
		void TearDown() {
			delete list;
		}
	};
	TEST_F(QUE, enqueue_dequeue) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->enqueue(val[i]);
		for (i = 0; i < size; i++)
			ASSERT_EQ(list->dequeue(), val[i]);
	}
	TEST_F(QUE, reverseFirstKElements) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int val2[size] = { 0, 2, 6, 5, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->enqueue(val[i]);
		list->reverseFirstKElements(4);
		for (i = 0; i < size; i++)
			ASSERT_EQ(list->dequeue(), val2[i]);
	}
	TEST_F(QUE, findMaxIntegerInEveryKWindow) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->enqueue(val[i]);
		int* max = new int[5];
		list->findMaxIntegerInEveryKWindow(3, max);
		ASSERT_EQ(max[0], 6);
		ASSERT_EQ(max[1], 6);
		ASSERT_EQ(max[2], 2);
		ASSERT_EQ(max[3], 4);
		ASSERT_EQ(max[4], 4);
		delete[] max;
	}
}

namespace DEQUE_T {
	class DEQ : public testing::Test {
	public:
		Deque* list = new Deque;
		void SetUp() {
			// pass
		}
		void TearDown() {
			delete list;
		}
	};
	TEST_F(DEQ, enqueueRear_dequeueFront) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->enqueueRear(val[i]);
		for (i = 0; i < size; i++)
			ASSERT_EQ(list->dequeueFront(), val[i]);
	}
	TEST_F(DEQ, enqueueFront_dequeueRear) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->enqueueFront(val[i]);
		for (i = 0; i < size; i++)
			ASSERT_EQ(list->dequeueRear(), val[i]);
	}
	TEST_F(DEQ, reverseFirstKElements) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int val2[size] = { 0, 2, 6, 5, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->enqueueRear(val[i]);
		list->reverseFirstKElements(4);
		for (i = 0; i < size; i++)
			ASSERT_EQ(list->dequeueFront(), val2[i]);
	}
	TEST_F(DEQ, findMaxIntegerInEveryKWindow) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->enqueueRear(val[i]);
		int* max = new int[5];
		list->findMaxIntegerInEveryKWindow(3, max);
		ASSERT_EQ(max[0], 6);
		ASSERT_EQ(max[1], 6);
		ASSERT_EQ(max[2], 2);
		ASSERT_EQ(max[3], 4);
		ASSERT_EQ(max[4], 4);
		delete[] max;
	}
}

namespace PRIOQ_T {
	class PRIOQ : public testing::Test {
	public:
		PriorityQue* list = new PriorityQue;
		void SetUp() {
			// pass
		}
		void TearDown() {
			delete list;
		}
	};
	TEST_F(PRIOQ, enqueue_dequeue) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int priority[size] = { 1, 0, 5, 2, 4, 3, 6 };
		int val2[size] = { 3, 2, 1, 4, 0, 5, 6 };
		int i;
		for (i = 0; i < size; i++)
			list->enqueue(val[i], priority[i]);
		for (i = 0; i < size; i++)
			ASSERT_EQ(list->dequeue(), val2[i]);
	}
}