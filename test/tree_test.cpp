#include "pch.h"

namespace BST_T {
	class BST : public testing::Test {
	public:
		BSTree* list = new BSTree;
		void SetUp() {
			// pass
		}
		void TearDown() {
			delete list;
		}
	};
	TEST_F(BST, insert) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insert(val[i]);
		BSTNode* ptr = list->root;
		ASSERT_EQ(ptr->info, val[0]);
		ASSERT_EQ(ptr->left->info, val[2]);
		ASSERT_EQ(ptr->right->info, val[1]);

		BSTNode * ptr1 = ptr->left;
		ASSERT_EQ(ptr1->left->info, val[3]);
		ASSERT_EQ(ptr1->right->info, val[5]);

		ASSERT_EQ(ptr1->left->right->info, val[4]);
		ASSERT_EQ(ptr1->right->left->info, val[6]);

	}
	TEST_F(BST, insertRecursive) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertRecursive(val[i]);
		BSTNode* ptr = list->root;
		ASSERT_EQ(ptr->info, val[0]);
		ASSERT_EQ(ptr->left->info, val[2]);
		ASSERT_EQ(ptr->right->info, val[1]);

		BSTNode* ptr1 = ptr->left;
		ASSERT_EQ(ptr1->left->info, val[3]);
		ASSERT_EQ(ptr1->right->info, val[5]);

		ASSERT_EQ(ptr1->left->right->info, val[4]);
		ASSERT_EQ(ptr1->right->left->info, val[6]);
	}
	TEST_F(BST, deleteRecursive) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };

		int i;
		for (i = 0; i < size; i++)
			list->insertRecursive(val[i]);

		BSTNode* ptr = list->root;
		BSTNode* ptr1 = ptr->left;

		list->deleteRecursive(val[6]);
		ASSERT_EQ(ptr1->right->left, nullptr);

		list->deleteRecursive(val[4]);
		ASSERT_EQ(ptr1->left->right, nullptr);

		list->deleteRecursive(val[5]);
		ASSERT_EQ(ptr1->right, nullptr);

		list->deleteRecursive(val[3]);
		ASSERT_EQ(ptr1->left, nullptr);

		list->deleteRecursive(val[1]);
		ASSERT_EQ(ptr->right, nullptr);

		list->deleteRecursive(val[2]);
		ASSERT_EQ(ptr->left, nullptr);

		list->deleteRecursive(val[0]);
		ASSERT_EQ(list->root, nullptr);
	}
	TEST_F(BST, addIncPreOrderTraversal) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insert(val[i]);
		list->addPreOrder(0);

		
		BSTNode* ptr = list->root;
		ASSERT_EQ(ptr->info, val[0]+0);
		ASSERT_EQ(ptr->left->info, val[2]+1);
		ASSERT_EQ(ptr->right->info, val[1]+6);

		BSTNode* ptr1 = ptr->left;
		ASSERT_EQ(ptr1->left->info, val[3]+2);
		ASSERT_EQ(ptr1->right->info, val[5]+4);

		ASSERT_EQ(ptr1->left->right->info, val[4]+3);
		ASSERT_EQ(ptr1->right->left->info, val[6]+5);

	}
	TEST_F(BST, addIncInOrderTraversal) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insert(val[i]);
		list->addInOrder(0);

		BSTNode* ptr = list->root;
		ASSERT_EQ(ptr->info, val[0] + 5);
		ASSERT_EQ(ptr->left->info, val[2] + 3);
		ASSERT_EQ(ptr->right->info, val[1] + 6);

		BSTNode* ptr1 = ptr->left;
		ASSERT_EQ(ptr1->left->info, val[3] + 2);
		ASSERT_EQ(ptr1->right->info, val[5] + 5);

		ASSERT_EQ(ptr1->left->right->info, val[4] + 3);
		ASSERT_EQ(ptr1->right->left->info, val[6] + 5);
	}
	TEST_F(BST, addIncPostOrderTraversal) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insert(val[i]);
		list->addPostOrder(0);

		BSTNode* ptr = list->root;
		ASSERT_EQ(ptr->info, val[0] + 6);
		ASSERT_EQ(ptr->left->info, val[2] + 5);
		ASSERT_EQ(ptr->right->info, val[1] + 6);

		BSTNode* ptr1 = ptr->left;
		ASSERT_EQ(ptr1->left->info, val[3] + 3);
		ASSERT_EQ(ptr1->right->info, val[5] + 5);

		ASSERT_EQ(ptr1->left->right->info, val[4] + 3);
		ASSERT_EQ(ptr1->right->left->info, val[6] + 5);
	}
	TEST_F(BST, findHeight) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insert(val[i]);
		int height = list->heightTree();
		ASSERT_EQ(height, 4);
	}
	TEST_F(BST, findNumberOfNodes) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insert(val[i]);
		int nodes = list->countTotalNodes();
		ASSERT_EQ(nodes, 7);
	}
	TEST_F(BST, findNumberOfNonLeafNodes) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insert(val[i]);
		int nodes = list->countInternalNodes();
		ASSERT_EQ(nodes, 2);
	}
	TEST_F(BST, findNumberOfLeafNodes) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insert(val[i]);
		int nodes = list->countExternalNodes();
		ASSERT_EQ(nodes, 3);
	}
	TEST_F(BST, mirorImage) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertRecursive(val[i]);
		BSTNode* ptr = list->root;
		BSTNode* ptr1 = ptr->left;
		ASSERT_EQ(ptr->info, val[0]);
		ASSERT_EQ(ptr->left->info, val[2]);
		ASSERT_EQ(ptr->right->info, val[1]);

		ASSERT_EQ(ptr1->left->info, val[3]);
		ASSERT_EQ(ptr1->right->info, val[5]);

		ASSERT_EQ(ptr1->left->right->info, val[4]);
		ASSERT_EQ(ptr1->right->left->info, val[6]);

		list->mirrorImage();
		ptr1 = ptr->right;

		ASSERT_EQ(ptr->info, val[0]);
		ASSERT_EQ(ptr->left->info, val[1]);
		ASSERT_EQ(ptr->right->info, val[2]);

		ASSERT_EQ(ptr1->left->info, val[5]);
		ASSERT_EQ(ptr1->right->info, val[3]);

		ASSERT_EQ(ptr1->left->right->info, val[6]);
		ASSERT_EQ(ptr1->right->left->info, val[4]);
	}
	TEST_F(BST, findMin) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertRecursive(val[i]);
		int smallest = list->findSmallest();
		ASSERT_EQ(smallest, 0);
	}
	TEST_F(BST, findMax) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int i;
		for (i = 0; i < size; i++)
			list->insertRecursive(val[i]);
		int largest = list->findLargest();
		ASSERT_EQ(largest, 6);
	}
}

namespace HEAP_T {
	class MaxHP : public testing::Test {
	public:
		MaxHeap* list = new MaxHeap(100);
		void SetUp() {
			// pass
		}
		void TearDown() {
			delete list;
		}
	};
	TEST_F(MaxHP, insert_remove) {
		int const size = 7;
		int val[size] = { 5, 6, 2, 0, 1, 4, 3 };
		int val2[size] = { 6, 5, 4, 3, 2, 1, 0 };
		int i;
		for (i = 0; i < size; i++)
			list->insert(val[i]);
		for (i = 0; i < size; i++)
			ASSERT_EQ(list->remove(), val2[i]);
	}
}