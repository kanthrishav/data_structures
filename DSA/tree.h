#include <iostream>
#include <queue>

class BSTNode {
public:
	BSTNode* left;
	int info;
	BSTNode* right;
};

class BSTree {
public:
	BSTNode* root;
	BSTree() : root(nullptr) {}
	~BSTree() {
		if(root != nullptr)
			delete root;
	}
	void insert(int value) {
		BSTNode* ptr, * parentPtr, * nodePtr;
		ptr = new BSTNode;
		ptr->info = value;
		ptr->left = ptr->right = nullptr;

		if (root == nullptr)
			root = ptr;
		else {
			parentPtr = nullptr;
			nodePtr = root;
			while (nodePtr != nullptr) {
				parentPtr = nodePtr;
				if (value < nodePtr->info)
					nodePtr = nodePtr->left;
				else
					nodePtr = nodePtr->right;
			}
			if (value < parentPtr->info)
				parentPtr->left = ptr;
			else
				parentPtr->right = ptr;
		}
	}
	void insertElement(BSTNode ** h, int value) {
		if (*h == nullptr) {
			*h = new BSTNode;
			(*h)->info = value;
			(*h)->left = (*h)->right = nullptr;
		}
		else if (value < (*h)->info) {
			insertElement(&((*h)->left), value);
		}
		else
			insertElement(&((*h)->right), value);
	}
	void insertRecursive(int value) {
		insertElement(&root, value);
	}
	void deleteElement(BSTNode** tree, int value) {
		BSTNode* temp;
		if (*tree == nullptr)
			return;
		else if (value < (*tree)->info)
			deleteElement(&((*tree)->left), value);
		else if (value > (*tree)->info)
			deleteElement(&((*tree)->right), value);
		else {
			temp = *tree;
			if ((*tree)->left == nullptr && (*tree)->right == nullptr)
				*tree = nullptr;
			else if ((*tree)->right == nullptr)
				*tree = (*tree)->left;
			else
				*tree = (*tree)->right;
			delete temp;
			temp = nullptr;
		}
	}
	void deleteRecursive(int value) {
		deleteElement(&root, value);
	}
	int traversePreOrder(BSTNode* h, int add) {
		if (h != nullptr) {
			h->info += add;
			add = traversePreOrder(h->left, add + 1);
			add = traversePreOrder(h->right, add + 1);
		}
		else
			add--;
		return add;
	}
	void addPreOrder(int add) {
		traversePreOrder(root, add);
	}
	int traverseInOrder(BSTNode* h, int add) {
		if (h != nullptr) {
			add = traverseInOrder(h->left, add + 1);
			h->info += add;
			add = traverseInOrder(h->right, add + 1);
		}
		else
			add--;
		return add;
	}
	void addInOrder(int add) {
		traverseInOrder(root, add);
	}
	int traversePostOrder(BSTNode* h, int add) {
		if (h != nullptr) {
			add = traversePostOrder(h->left, add + 1);
			add = traversePostOrder(h->right, add + 1);
			h->info += add;
		}
		else
			add--;
		return add;
	}
	void addPostOrder(int add) {
		traversePostOrder(root, add);
	}
	void findHeight(BSTNode* tree, int* h) {
		int hl, hr;
		if (tree == nullptr) {
			*h = 0;
		}
		else {
			findHeight(tree->left, &hl);
			findHeight(tree->right, &hr);
			if (hl > hr)
				*h = hl + 1;
			else
				*h = hr + 1;
		}
	}
	int heightTree() {
		int h;
		findHeight(root, &h);
		return h;
	}
	int totalNodes(BSTNode* tree) {
		if (tree == nullptr)
			return 0;
		else
			return(totalNodes(tree->left) + totalNodes(tree->right)+1);
	}
	int countTotalNodes() {
		return(totalNodes(root));
	}
	int internalNodes(BSTNode* tree) {
		if ((tree == nullptr) || (tree->left == nullptr || tree->right == nullptr))
			return 0;
		else
			return(internalNodes(tree->left) + internalNodes(tree->right) + 1);
	}
	int countInternalNodes() {
		return(internalNodes(root));
	}
	int externalNodes(BSTNode* tree) {
		if (tree == nullptr)
			return 0;
		else if ((tree->left == nullptr) && (tree->right == nullptr))
			return 1;
		else
			return(externalNodes(tree->left) + externalNodes(tree->right));
	}
	int countExternalNodes() {
		return(externalNodes(root));
	}
	void reflect(BSTNode* tree) {
		BSTNode* temp;
		if (tree != nullptr) {
			reflect(tree->left);
			reflect(tree->right);
			temp = tree->left;
			tree->left = tree->right;
			tree->right = temp;
		}
	}
	void mirrorImage() {
		reflect(root);
	}
};