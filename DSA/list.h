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
		while (ptr!=nullptr) {
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

	void swapNodes(int a, int b){}
	void reverseList() {
		NodeLL* ptr = head;
		NodeLL * curr, * prev, * next;
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
	void reverseListInGroupsOf(int n) {}
	int length() {}
	void rotateFromStartToEndBy(int n) {}
	void rotateFromEndToStartBy(int n) {}
	NodeLL* splitListInParts(int parts) {}
	NodeLL* splitIntoOddEvenLists() {}
	void removeDuplicates() {}
	void removeDuplicatesFromSortedList() {}
	void sortList() {}
	NodeLL * mergeLists(NodeLL* l1, NodeLL* l2) {}

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

