#pragma once

#include <iostream>

class NodeLL {
public:
	int info;
	NodeLL* next;
	NodeLL() {
		info = 0;
		next = NULL;
	}
	NodeLL(int n) {
		info = n;
		next = NULL;
	}
	NodeLL(int n, NodeLL * ptrNext) {
		info = n;
		next = ptrNext;
	}
	~NodeLL() {
		delete next;
	}
};

class LinearLL {
public:
	NodeLL* head;
	LinearLL() {
		head = NULL;
	}
	void print() {
		NodeLL* ptr = head;
		while (ptr != NULL) {
			std::cout << ptr->info << ", ";
			ptr = ptr->next;
		}
		std::cout << std::endl;
	}

	void insertAtStart(int n) {
		NodeLL* ptr = new NodeLL;
		ptr->info = n;
		ptr->next = head;
		head = ptr;
	}
	void insertAtEnd(int n) {
		NodeLL* ptr = new NodeLL;
		ptr->info = n;
		ptr->next = NULL;
		if (head != nullptr) {
			NodeLL* ptr1 = head;
			while (ptr1->next != NULL)
				ptr1 = ptr1->next;
			ptr1->next = ptr;
		}
		else
			head = ptr;
	}
	bool insertAfter(int n, int after) {
		NodeLL* ptr = head;
		bool found = false;
		while (ptr != nullptr) {
			if (ptr->info == after) {
				found = true;
				break;
			}
			ptr = ptr->next;
		}
		if (found) {
			NodeLL* rest = ptr->next;
			ptr->next->info = n;
			ptr->next->next = rest;
		}
		return found;
	}
	bool insertBefore(int n, int before) {
		NodeLL* ptr = head;
		bool found = true;
		while (ptr->next->info != before) {
			ptr = ptr->next;
			if (ptr->next == nullptr) {
				found = false;
				break;
			}
		}
		if (found) {
			NodeLL* rest = ptr->next;
			ptr->next->info = n;
			ptr->next->next = rest;
		}
		return found;
	}

	void deleteAtStart() {
		NodeLL* ptr = head;
		NodeLL* ptr1 = head->next;
		head->next = nullptr;
		head = ptr1;
		delete ptr;
	}
	void deleteAtEnd() {
		NodeLL* ptr = head;

		if (ptr->next != nullptr) {
			while (ptr->next->next != nullptr) {
				ptr = ptr->next;
			}
			NodeLL* ptr1 = ptr->next;
			ptr->next = NULL;
			delete ptr1;
		}
		else {
			delete ptr;
			head = nullptr;
		}

	}
	bool deleteAfter(int after) {
		NodeLL* ptr = head;
		bool found = false;
		while (ptr != nullptr) {
			if (ptr->info == after) {
				found = true;
				break;
			}
			ptr = ptr->next;
		}
		if (found) {
			NodeLL* ptr1 = ptr->next;
			ptr->next = ptr->next->next;
			ptr1->next = nullptr;
			delete ptr1;
		}
		return found;
	}
	bool deleteMNodesAfterNNodes(int m, int n) {
		bool present = false;
		NodeLL* ptr = head;
		int countDeleted = 0;
		while (ptr != nullptr) {
			if (ptr->info == n) {
				while (countDeleted < m) {
					if (ptr->next == nullptr)
						break;
					NodeLL* ptr1 = ptr->next;
					ptr->next = ptr->next->next;
					ptr1->next = nullptr;
					delete ptr1;
					countDeleted++;
				}
			}
			ptr = ptr->next;
		}
		if (countDeleted == m)
			present = true;
		return present;
	}
	bool deleteBefore(int before) {
		NodeLL* ptr = head;
		bool found = false;
		while (ptr->next->next != nullptr) {
			if (ptr->next->next->info == before) {
				found = true;
				break;
			}
			ptr = ptr->next;
		}
		if (found) {
			NodeLL* rest = ptr->next;
			ptr->next = ptr->next->next;
			rest->next = nullptr;
			delete rest;
		}
		return found;
	}
	bool deleteMNodesBeforeNNodes(int m, int n) {
		reverseList();
		bool present = deleteMNodesAfterNNodes(m, n);
		reverseList();
		return present;
	}
	int deleteOddNodes() {
		int count = 0;
		if (head->info % 2 != 0) {
			NodeLL* ptr1 = head;
			head = head->next;
			ptr1->next = nullptr;
			delete ptr1;
			count++;
		}

		NodeLL* ptr = head;
		while (ptr->next != nullptr) {
			if (ptr->next->info % 2 != 0) {
				NodeLL* ptr1 = ptr->next;
				ptr->next = ptr->next->next;
				count++;
				ptr1->next = nullptr;
				delete ptr1;
			}
			else
				ptr = ptr->next;
		}
		return count;
	}
	int deleteEvenNodes() {
		int count = 0;
		if (head->info % 2 == 0) {
			NodeLL* ptr1 = head;
			head = head->next;
			ptr1->next = nullptr;
			delete ptr1;
			count++;
		}
		NodeLL* ptr = head;
		while (ptr->next != nullptr) {
			if (ptr->next->info % 2 == 0) {
				NodeLL* ptr1 = ptr->next;
				ptr->next = ptr->next->next;
				count++;
				ptr1->next = nullptr;
				delete ptr1;
			}
			else
				ptr = ptr->next;
		}
		return count;
	}
	int deleteSpecificNodes(int n) {
		int count = 0;
		if (head->info == n) {
			NodeLL* ptr1 = head;
			head = head->next;
			ptr1->next = nullptr;
			delete ptr1;
			count++;
		}
		NodeLL* ptr = head;
		while (ptr->next != nullptr) {
			if (ptr->next->info == n) {
				NodeLL* ptr1 = ptr->next;
				ptr->next = ptr->next->next;
				count++;
				ptr1->next = nullptr;
				delete ptr1;
			}
			else
				ptr = ptr->next;
		}
		return count;
	}
	void deleteList() {
		while (head != nullptr) {
			NodeLL* ptr1 = head;
			head = head->next;
			ptr1->next = nullptr;
			delete ptr1;
		}
	}

	void swapNodes(NodeLL* n0, NodeLL* n1, NodeLL* n2) {
		NodeLL* next = n2->next;
		n2->next = n1;
		n1->next = next;
		n0->next = n2;
		return;
	}
	void reverseList() {
		NodeLL* ptr = head;
		NodeLL* curr, * prev, * next;
		prev = nullptr;

		while (ptr != nullptr) {
			curr = ptr;
			next = ptr->next;
			curr->next = prev;
			ptr = next;
			prev = curr;
		}
		head = prev;
	}
	int length() {
		NodeLL* ptr = head;
		int count = 0;
		while (ptr != nullptr) {
			count += 1;
			ptr = ptr->next;
		}
		return count;
	}
	void rotateFromStartToEndBy(int n) {
		NodeLL* ptr = head;
		int count = 0;
		int len = this->length();
		while (count < (len - n - 1)) {
			ptr = ptr->next;
			count++;
		}
		NodeLL* splitEnd = ptr;
		ptr = ptr->next;
		NodeLL* ptr2 = ptr;
		while (ptr2->next != nullptr) {
			ptr2 = ptr2->next;
		}
		ptr2->next = head;
		splitEnd->next = nullptr;
		head = ptr;
		return;
	}
	void rotateFromEndToStartBy(int n) {
		NodeLL* ptr = head;
		int count = 0;
		int len = this->length();
		while (count < (n - 1)) {
			ptr = ptr->next;
			count++;
		}
		NodeLL* splitEnd = ptr;
		ptr = ptr->next;
		NodeLL* ptr2 = ptr;
		while (ptr2->next != nullptr) {
			ptr2 = ptr2->next;
		}
		ptr2->next = head;
		splitEnd->next = nullptr;
		head = ptr;
		return;
	}
	NodeLL* splitListInTwo(int index) {
		NodeLL* ptr = head;
		int count = 0;
		while (count < index) {
			ptr = ptr->next;
			count++;
		}
		NodeLL* otherList = ptr->next;
		ptr->next = nullptr;
		return otherList;
	}
	NodeLL* splitIntoOddEvenLists() {
		NodeLL* ptr = head;
		NodeLL* even;
		NodeLL* odd;
		NodeLL* firstEven;
		bool firstEvenBool = false;
		NodeLL* firstOdd;
		bool firstOddBool = false;
		while (ptr != nullptr) {
			if (ptr->info % 2 == 0) {
				if (!firstEvenBool) {
					firstEven = ptr;
					even = firstEven;
					ptr = ptr->next;
					even->next = nullptr;
					firstEvenBool = true;
				}
				else {
					even->next = ptr;
					ptr = ptr->next;
					even = even->next;
					even->next = nullptr;
				}
			}
			else {
				if (!firstOddBool) {
					firstOdd = ptr;
					odd = firstOdd;
					ptr = ptr->next;
					odd->next = nullptr;
					firstOddBool = true;
				}
				else {
					odd->next = ptr;
					ptr = ptr->next;
					odd = odd->next;
					odd->next = nullptr;
				}
			}
		}
		head = firstOdd;
		return firstEven;
	}
	void removeDuplicates() {
		NodeLL* ptr = head;
		NodeLL* ptr2;
		NodeLL* temp;
		int count;

		while (ptr != nullptr) {
			count = 0;
			ptr2 = ptr;
			while (ptr2->next != nullptr) {
				if (ptr2->info == ptr->info) {
					count++;
				}
				ptr2 = ptr2->next;
			}

			if (count > 1) {
				ptr2 = ptr;
				while (ptr2->next != nullptr) {
					if (ptr2->next->info == ptr->info) {
						temp = ptr2->next;
						ptr2->next = ptr2->next->next;
						temp->next = nullptr;
						delete temp;
					}
					else {
						ptr2 = ptr2->next;
					}
				}
			}
			ptr = ptr->next;
		}
	}
	void removeDuplicatesFromSortedList() {
		NodeLL* ptr = head;
		NodeLL* ptr2;
		NodeLL* temp;
		int count;
		while (ptr != nullptr) {
			count = 0;
			ptr2 = ptr;
			while (ptr2->next != nullptr) {
				if (ptr2->info == ptr->info) {
					count++;
				}
				ptr2 = ptr2->next;
			}

			if (count > 1) {
				ptr2 = ptr;
				while (ptr2->next->info == ptr->info) {
					temp = ptr2->next;
					ptr2->next = ptr2->next->next;
					temp->next = nullptr;
					delete temp;
				}
			}
			ptr = ptr->next;
		}
	}
	void sortListBubble(char a_) {
		NodeLL* ptr = head;
		NodeLL* startPtr = head;
		int temp;
		bool pass = true;
		int swapCount = 0;
		while (pass) {
			swapCount = 0;
			ptr = startPtr;

			while (ptr->next != nullptr) {
				if (a_ == 'a') {
					if (ptr->info > ptr->next->info) {
						temp = ptr->info;
						ptr->info = ptr->next->info;
						ptr->next->info = temp;
						swapCount += 1;
					}
				}
				else {
					if (ptr->info < ptr->next->info) {
						temp = ptr->info;
						ptr->info = ptr->next->info;
						ptr->next->info = temp;
						swapCount += 1;
					}
				}
				ptr = ptr->next;
			}
			pass = (swapCount > 0) ? true : false;
		}
	}
	void sortListSelection(char a_) {
		NodeLL* ptr = head;
		NodeLL* startPtr = head;
		int temp;
		bool pass = true;
		int swapCount = 0;
		int min, max;
		NodeLL* minPtr, * maxPtr;
		minPtr = head;
		maxPtr = head;
		NodeLL* lastPtr = head;
		while (lastPtr->next != nullptr) {
			lastPtr = lastPtr->next;
		}
		while (startPtr != lastPtr) {
			ptr = startPtr;
			min = 100000;
			max = -100000;
			while (ptr != nullptr) {
				if (a_ == 'a') {
					if (min > ptr->info) {
						min = ptr->info;
						minPtr = ptr;
					}
				}
				else {
					if (max < ptr->info) {
						max = ptr->info;
						maxPtr = ptr;
					}
				}
				ptr = ptr->next;
			}

			if (a_ == 'a') {
				temp = minPtr->info;
				minPtr->info = startPtr->info;
			}
			else {
				temp = maxPtr->info;
				maxPtr->info = startPtr->info;
			}
			startPtr->info = temp;
			startPtr = startPtr->next;
		}
	}
	void sortListInsertion(char a_) {
		NodeLL* ptr = head;
		NodeLL* subArrayEndPtr = head->next;
		int temp;
		while (subArrayEndPtr != nullptr) {
			ptr = head;
			while (ptr != subArrayEndPtr) {
				if (a_ == 'a') {
					if ((ptr->info < subArrayEndPtr->info)
						&& (ptr->next->info > subArrayEndPtr->info)) {

						temp = ptr->next->info;
						ptr->next->info = subArrayEndPtr->info;
						subArrayEndPtr->info = temp;
					}
					else if (ptr->info > subArrayEndPtr->info) {
						temp = ptr->info;
						ptr->info = subArrayEndPtr->info;
						subArrayEndPtr->info = temp;
					}
				}
				else {
					if ((ptr->info > subArrayEndPtr->info)
						&& (ptr->next->info < subArrayEndPtr->info)) {

						temp = ptr->next->info;
						ptr->next->info = subArrayEndPtr->info;
						subArrayEndPtr->info = temp;
					}
					else if (ptr->info < subArrayEndPtr->info) {
						temp = ptr->info;
						ptr->info = subArrayEndPtr->info;
						subArrayEndPtr->info = temp;
					}
				}
				ptr = ptr->next;
			}
			subArrayEndPtr = subArrayEndPtr->next;
		}

	}
	NodeLL* SortedMerge(NodeLL* first, NodeLL* second, char a_)
	{
		NodeLL* result = NULL;

		if (first == NULL)
			return (second);
		else if (second == NULL)
			return (first);

		if (first->info <= second->info) {
			result = first;
			result->next = SortedMerge(first->next, second, a_);
		}
		else {
			result = second;
			result->next = SortedMerge(first, second->next, a_);
		}
		return (result);
	}

	void splitList(NodeLL* source, NodeLL** firstRef,
		NodeLL** secondRef)
	{
		NodeLL* slow = source;
		NodeLL* fast = source->next;

		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL) {
				slow = slow->next;
				fast = fast->next;
			}
		}

		*firstRef = source;
		*secondRef = slow->next;
		slow->next = NULL;
	}

	void MergeSort(NodeLL** headRef, char a_ = 'a')
	{
		NodeLL* head = *headRef;
		NodeLL* first;
		NodeLL* second;

		if ((head == NULL) || (head->next == NULL)) {
			return;
		}

		splitList(head, &first, &second);

		MergeSort(&first);
		MergeSort(&second);

		*headRef = SortedMerge(first, second, a_);
	}


	NodeLL* findIntersection(NodeLL& l1, NodeLL* l2) {}
	bool findCycles() {}
	NodeLL* findCentre() {}
	int findMin() {}
	int findMax() {}
	int* findFrequencyOfNodes() {}

	bool checkPallindrome() {}
	bool checkDuplicates() {}

	int addPolynomials(NodeLL* l1, NodeLL* l2) {}
};

