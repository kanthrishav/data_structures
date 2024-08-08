#pragma once

#include <iostream>

class NodeDL {
public:
	int info;
	NodeDL* next;
	NodeDL* prev;
	NodeDL() {
		info = 0;
		next = nullptr;
		prev = nullptr;
	}
	NodeDL(int n) {
		info = n;
		next = nullptr;
		prev = nullptr;
	}
	NodeDL(int n, NodeDL* ptrNext, NodeDL* ptrPrev) {
		info = n;
		next = ptrNext;
		prev = ptrPrev;
	}
	~NodeDL() {
		delete next;
		delete prev;
	}
};

class DoublyLL {
public:
	NodeDL* head;
	DoublyLL() {
		head = nullptr;
	}
	void print() {
		NodeDL* ptr = head;
		while (ptr != nullptr) {
			std::cout << ptr->info << ", ";
			ptr = ptr->next;
		}
		std::cout << std::endl;
	}

	void insertAtStart(int n) {
		NodeDL* ptr = new NodeDL;
		ptr->info = n;
		ptr->next = head;
		ptr->prev = nullptr;
		head = ptr;
	}
	void insertAtEnd(int n) {
		NodeDL* ptr = new NodeDL;
		ptr->info = n;
		ptr->next = nullptr;
		ptr->prev = nullptr;
		if (head != nullptr) {
			NodeDL* ptr1 = head;
			while (ptr1->next != nullptr) {
				ptr1 = ptr1->next;
			}
			ptr1->next = ptr;
			ptr->prev = ptr1;
		}
		else
			head = ptr;
	}
	bool insertAfter(int n, int after) {
		NodeDL* ptr = head;
		bool found = false;
		while (ptr != nullptr) {
			if (ptr->info == after) {
				found = true;
				break;
			}
			ptr = ptr->next;
		}
		if (found) {
			NodeDL* rest = ptr->next;
			ptr->next->info = n;
			ptr->next->prev = ptr;
			ptr->next->next = rest;
			ptr->next->next->prev = ptr->next;
		}
		return found;
	}
	bool insertBefore(int n, int before) {
		NodeDL* ptr = head;
		bool found = true;
		while (ptr->next->info != before) {
			ptr = ptr->next;
			if (ptr->next == nullptr) {
				found = false;
				break;
			}
		}
		if (found) {
			NodeDL* rest = ptr->next;
			ptr->next->info = n;
			ptr->next->prev = ptr;
			ptr->next->next = rest;
			ptr->next->next->prev = ptr->next;
		}
		return found;
	}

	void deleteAtStart() {
		NodeDL* ptr = head;
		NodeDL* ptr1 = head->next;
		head->next = nullptr;
		head = ptr1;
		if(head!=nullptr)
			head->prev = nullptr;
		delete ptr;
	}
	void deleteAtEnd() {
		NodeDL* ptr = head;

		if (ptr->next != nullptr) {
			while (ptr->next->next != nullptr) {
				ptr = ptr->next;
			}
			NodeDL* ptr1 = ptr->next;
			ptr->next = nullptr;
			ptr1->prev = nullptr;
			delete ptr1;
		}
		else {
			delete ptr;
			head = nullptr;
		}

	}
	bool deleteAfter(int after) {
		NodeDL* ptr = head;
		bool found = false;
		while (ptr != nullptr) {
			if (ptr->info == after) {
				found = true;
				break;
			}
			ptr = ptr->next;
		}
		if (found) {
			NodeDL* ptr1 = ptr->next;
			ptr->next = ptr->next->next;
			ptr->next->prev = ptr->next;
			ptr1->next = nullptr;
			ptr1->prev = nullptr;
			delete ptr1;
		}
		return found;
	}
	bool deleteMNodesAfterNNodes(int m, int n) {
		bool present = false;
		NodeDL* ptr = head;
		int countDeleted = 0;
		while (ptr != nullptr) {
			if (ptr->info == n) {
				while (countDeleted < m) {
					if (ptr->next == nullptr)
						break;
					NodeDL* ptr1 = ptr->next;
					ptr->next = ptr->next->next;
					if(ptr->next!=nullptr)
						ptr->next->prev = ptr;
					ptr1->next = nullptr;
					ptr1->prev = nullptr;
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
		NodeDL* ptr = head;
		bool found = false;
		while (ptr->next->next != nullptr) {
			if (ptr->next->next->info == before) {
				found = true;
				break;
			}
			ptr = ptr->next;
		}
		if (found) {
			NodeDL* rest = ptr->next;
			ptr->next = ptr->next->next;
			ptr->next->prev = ptr;
			rest->next = nullptr;
			rest->prev = nullptr;
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
			NodeDL* ptr1 = head;
			head = head->next;
			ptr1->next = nullptr;
			delete ptr1;
			count++;
		}

		NodeDL* ptr = head;
		while (ptr->next != nullptr) {
			if (ptr->next->info % 2 != 0) {
				NodeDL* ptr1 = ptr->next;
				ptr->next = ptr->next->next;
				if(ptr->next!=nullptr)
					ptr->next->prev = ptr;
				count++;
				ptr1->next = nullptr;
				ptr1->prev = nullptr;
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
			NodeDL* ptr1 = head;
			head = head->next;
			ptr1->next = nullptr;
			delete ptr1;
			count++;
		}
		NodeDL* ptr = head;
		while (ptr->next != nullptr) {
			if (ptr->next->info % 2 == 0) {
				NodeDL* ptr1 = ptr->next;
				ptr->next = ptr->next->next;
				if(ptr->next!=nullptr)
					ptr->next->prev = ptr;
				count++;
				ptr1->next = nullptr;
				ptr1->prev = nullptr;
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
			NodeDL* ptr1 = head;
			head = head->next;
			ptr1->next = nullptr;
			delete ptr1;
			count++;
		}
		NodeDL* ptr = head;
		while (ptr->next != nullptr) {
			if (ptr->next->info == n) {
				NodeDL* ptr1 = ptr->next;
				ptr->next = ptr->next->next;
				if (ptr->next != nullptr)
					ptr->next->prev = ptr;
				count++;
				ptr1->next = nullptr;
				ptr1->prev = nullptr;
				delete ptr1;
			}
			else
				ptr = ptr->next;
		}
		return count;
	}
	void deleteList() {
		while (head != nullptr) {
			NodeDL* ptr1 = head;
			head = head->next;
			if(head!=nullptr)
				head->prev = nullptr;
			ptr1->next = nullptr;
			delete ptr1;
		}
	}

	void swapNodes(NodeDL* n0, NodeDL* n1, NodeDL* n2) {
		NodeDL* next = n2->next;
		n2->next = n1;
		n1->prev = n2;
		n1->next = next;
		n0->next = n2;
		n2->prev = n0;

		return;
	}
	void reverseList() {
		NodeDL* ptr = head;
		NodeDL* curr, * prev, * next;
		prev = nullptr;

		while (ptr != nullptr) {
			ptr = ptr->next;
		}
		NodeDL * head2 = ptr;
		while (ptr != head->next) {
			ptr->next = ptr->prev;
			ptr = ptr->next;
		}
		ptr->next = head;
		head->next = ptr;
	}
	int length() {
		NodeDL* ptr = head;
		int count = 0;
		while (ptr != nullptr) {
			count += 1;
			ptr = ptr->next;
		}
		return count;
	}
	void rotateFromStartToEndBy(int n) {
		NodeDL* ptr = head;
		int count = 0;
		int len = this->length();
		while (count < (len - n - 1)) {
			ptr = ptr->next;
			count++;
		}
		NodeDL* splitEnd = ptr;
		ptr = ptr->next;
		NodeDL* ptr2 = ptr;
		while (ptr2->next != nullptr) {
			ptr2 = ptr2->next;
		}
		ptr2->next = head;
		splitEnd->next = nullptr;
		head = ptr;
		return;
	}
	void rotateFromEndToStartBy(int n) {
		NodeDL* ptr = head;
		int count = 0;
		int len = this->length();
		while (count < (n - 1)) {
			ptr = ptr->next;
			count++;
		}
		NodeDL* splitEnd = ptr;
		ptr = ptr->next;
		NodeDL* ptr2 = ptr;
		while (ptr2->next != nullptr) {
			ptr2 = ptr2->next;
		}
		ptr2->next = head;
		splitEnd->next = nullptr;
		head = ptr;
		return;
	}
	NodeDL* splitListInTwo(int index) {
		NodeDL* ptr = head;
		int count = 0;
		while (count < index) {
			ptr = ptr->next;
			count++;
		}
		NodeDL* otherList = ptr->next;
		ptr->next = nullptr;
		return otherList;
	}
	NodeDL* splitIntoOddEvenLists() {
		NodeDL* ptr = head;
		NodeDL* even;
		NodeDL* odd;
		NodeDL* firstEven;
		bool firstEvenBool = false;
		NodeDL* firstOdd;
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
		NodeDL* ptr = head;
		NodeDL* ptr2;
		NodeDL* temp;
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
						if (ptr2->next != nullptr)
							ptr2->next->prev = ptr2;
						temp->next = nullptr;
						temp->prev = nullptr;
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
		NodeDL* ptr = head;
		NodeDL* ptr2;
		NodeDL* temp;
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
					if (ptr2->next != nullptr)
						ptr2->next->prev = ptr2;
					temp->next = nullptr;
					temp->prev = nullptr;
					delete temp;
				}
			}
			ptr = ptr->next;
		}
	}

	void sortListBubble(char a_) {
		NodeDL* ptr = head;
		NodeDL* startPtr = head;
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
		NodeDL* ptr = head;
		NodeDL* startPtr = head;
		int temp;
		bool pass = true;
		int swapCount = 0;
		int min, max;
		NodeDL* minPtr, * maxPtr;
		minPtr = head;
		maxPtr = head;
		NodeDL* lastPtr = head;
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
		NodeDL* ptr = head;
		NodeDL* subArrayEndPtr = head->next;
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
	NodeDL* SortedMerge(NodeDL* first, NodeDL* second, char a_)
	{
		NodeDL* result = NULL;

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
	void splitList(NodeDL* source, NodeDL** firstRef, NodeDL** secondRef)
	{
		NodeDL* slow = source;
		NodeDL* fast = source->next;

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
	void sortListMerge(NodeDL** headRef, char a_ = 'a')
	{
		NodeDL* head = *headRef;
		NodeDL* first;
		NodeDL* second;

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

	NodeDL* findIntersection(NodeDL* head1, NodeDL* head2) {
		NodeDL* ptr1 = head1;
		NodeDL* ptr2;
		bool sameValue;
		NodeDL* intersectionPtr;
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

		NodeDL* slow = head;
		NodeDL* fast = head;
		while ((fast->next != nullptr) && (fast != nullptr)) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				return true;
			}
		}

		return false;
	}
	NodeDL* findCentre() {
		NodeDL* slow = head;
		NodeDL* fast = head->next;
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
		NodeDL* ptr = head;
		while (ptr != nullptr) {
			arr[ptr->info]++;
			ptr = ptr->next;
		}

		return arr;
	}
	bool checkPallindrome() {
		NodeDL* centrePtr = findCentre();
		NodeDL* mainHead = head;
		head = centrePtr;
		reverseList();
		NodeDL* ptr1 = head;
		NodeDL* ptr2 = mainHead;
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

};