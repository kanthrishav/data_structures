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

class NodeLL2 {
public:
	int info1;
	int info2;
	NodeLL2* next;
	NodeLL2() {
		info1 = 0;
		info2 = 0;
		next = NULL;
	}
	NodeLL2(int n1, int n2) {
		info1 = n1;
		info2 = n2;
		next = NULL;
	}
	NodeLL2(int n1, int n2, NodeLL2* ptrNext) {
		info1 = n1;
		info2 = n2;
		next = ptrNext;
	}
	~NodeLL2() {
		delete next;
	}
};


class LinearLL {
public:
	NodeLL* head;
	NodeLL2* head2;
	LinearLL() {
		head = nullptr;
		head2 = nullptr;
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
	void splitList(NodeLL* source, NodeLL** firstRef, NodeLL** secondRef)
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
	void sortListMerge(NodeLL** headRef, char a_ = 'a')
	{
		NodeLL* head = *headRef;
		NodeLL* first;
		NodeLL* second;

		if ((head == NULL) || (head->next == NULL)) {
			return;
		}

		splitList(head, &first, &second);

		sortListMerge(&first);
		sortListMerge(&second);

		*headRef = SortedMerge(first, second, a_);
	}
	void sortListQuick() {}
	void sortListHeap() {}

	NodeLL* findIntersection(NodeLL* head1, NodeLL* head2) {
		NodeLL* ptr1 = head1;
		NodeLL* ptr2;
		bool sameValue;
		NodeLL* intersectionPtr;
		bool firstEntry = false;
		int count = 0;
		int countCommon = 0;
		int entryCount = 0;
		while (ptr1 != nullptr) {
			ptr2 = head2;
			while (ptr2 != nullptr) {
				sameValue = (ptr1->info == ptr2->info) ? true : false;
				if (!firstEntry && sameValue) {
					intersectionPtr = ptr2;
					entryCount++;
				}
				else if (sameValue) {
					entryCount++;
					countCommon++;
				}
				count++;
				ptr2 = ptr2->next;
			}
			if (countCommon == (entryCount - 1)) {
				return intersectionPtr;
				break;
			}
			ptr1 = ptr1->next;
		}
		return nullptr;
	}
	bool findCycles() {
		
		NodeLL* slow = head;
		NodeLL* fast = head;
		while ((fast->next != nullptr) && (fast != nullptr)) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				return true;
			}
		}

		return false;
	}
	NodeLL* findCentre() {
		NodeLL* slow = head;
		NodeLL* fast = head->next;
		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL) {
				slow = slow->next;
				fast = fast->next;
			}
		}
		return slow;
	}
	int* findFrequencyOfNodes() {
		int* arr = new int[10]();
		NodeLL* ptr = head;
		while (ptr != nullptr) {
			arr[ptr->info]++;
			ptr = ptr->next;
		}

		return arr;
	}
	bool checkPallindrome() {
		NodeLL* centrePtr = findCentre();
		NodeLL* mainHead = head;
		head = centrePtr;
		reverseList();
		NodeLL* ptr1 = head;
		NodeLL* ptr2 = mainHead;
		bool continuousChain = true;
		while ((ptr1 != nullptr) && (ptr2 != centrePtr)) {
			continuousChain &= (ptr1->info == ptr2->info);
			if (!continuousChain) {
				return false;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		return true;
	}

	NodeLL2* addPolynomials(NodeLL2* l1, NodeLL2* l2) {
		NodeLL2* addedPtr = new NodeLL2;
		NodeLL2* addedPtrHead = addedPtr;
		int power;
		int coeff1;
		int coeff2;
		for (power = 0; power < 10; power++) {
			NodeLL2* ptr1 = l1;
			NodeLL2* ptr2 = l2;
			coeff1 = -100;
			coeff2 = -100;
			while (ptr1 != nullptr) {
				if (power == ptr1->info2) {
					coeff1 = ptr1->info1;
					break;
				}
				ptr1 = ptr1->next;
			}
			while (ptr2 != nullptr) {
				if (power == ptr2->info2) {
					coeff2 = ptr2->info1;
					break;
				}
				ptr2 = ptr2->next;
			}
			if ((coeff1 != -100) && (coeff2 != -100)) {
				addedPtr->info1 = coeff1 + coeff2;
				addedPtr->info2 = power;
				addedPtr->next = new NodeLL2;
				addedPtr = addedPtr->next;
			}
			else if (coeff1 != -100) {
				addedPtr->info1 = coeff1;
				addedPtr->info2 = power;
				addedPtr->next = new NodeLL2;
				addedPtr = addedPtr->next;
			}
			else if (coeff2 != -100) {
				addedPtr->info1 = coeff2;
				addedPtr->info2 = power;
				addedPtr->next = new NodeLL2;
				addedPtr = addedPtr->next;
			}
		}
		return addedPtrHead;
	}
};

