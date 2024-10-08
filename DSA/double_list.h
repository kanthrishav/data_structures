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

class NodeDL2 {
public:
	int info1;
	int info2;
	NodeDL2* next;
	NodeDL2() {
		info1 = 0;
		info2 = 0;
		next = NULL;
	}
	NodeDL2(int n1, int n2) {
		info1 = n1;
		info2 = n2;
		next = NULL;
	}
	NodeDL2(int n1, int n2, NodeDL2* ptrNext) {
		info1 = n1;
		info2 = n2;
		next = ptrNext;
	}
	~NodeDL2() {
		delete next;
	}
};

class DoublyLL {
public:
	NodeDL* head;
	NodeDL2* head2;
	DoublyLL() {
		head = nullptr;
		head2 = nullptr;
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
		NodeDL* temp;
		prev = nullptr;

		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		NodeDL * head2 = ptr;
		ptr->next = ptr->prev;
		ptr->prev = nullptr;
		ptr = ptr->next;
		while (ptr != head) {
			temp = ptr->next;
			ptr->next = ptr->prev;
			ptr->prev = temp;
			ptr = ptr->next;
		}
		ptr->next = nullptr;
		head = head2;
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

		if (a_ == 'a') {
			if (first->info <= second->info) {
				result = first;
				result->next = SortedMerge(first->next, second, a_);
			}
			else {
				result = second;
				result->next = SortedMerge(first, second->next, a_);
			}
		}
		else if (a_ == 'd') {
			if (first->info >= second->info) {
				result = first;
				result->next = SortedMerge(first->next, second, a_);
			}
			else {
				result = second;
				result->next = SortedMerge(first, second->next, a_);
			}
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
	void sortListMerge(NodeDL** headRef, char a_)
	{
		NodeDL* head = *headRef;
		NodeDL* first;
		NodeDL* second;

		if ((head == NULL) || (head->next == NULL)) {
			return;
		}

		splitList(head, &first, &second);

		sortListMerge(&first, a_);
		sortListMerge(&second, a_);

		*headRef = SortedMerge(first, second, a_);
	}
	void sortListQuick(NodeDL** headRef, char a_) {
		NodeDL* head = *headRef;
		if ((head == NULL) || (head->next == NULL)) {
			return;
		}
		NodeDL* ptr1 = head;
		NodeDL* ptr2 = head;
		NodeDL* pivot = head;
		NodeDL* ptr;
		int temp;
		while (pivot->next != nullptr) {
			pivot = pivot->next;
		}
		while (ptr1->next != nullptr) {
			if (ptr1->info <= pivot->info && a_ == 'a') {
				if (ptr1 != ptr2) {
					temp = ptr1->info;
					ptr1->info = ptr2->info;
					ptr2->info = temp;
				}
				ptr2 = ptr2->next;
			}
			else if (ptr1->info >= pivot->info && a_ == 'd') {
				if (ptr1 != ptr2) {
					temp = ptr1->info;
					ptr1->info = ptr2->info;
					ptr2->info = temp;
				}
				ptr2 = ptr2->next;
			}

			ptr1 = ptr1->next;
		}
		temp = ptr2->info;
		ptr2->info = pivot->info;
		pivot->info = temp;
		pivot = ptr2;

		NodeDL* left;
		NodeDL* right;

		if (pivot != head)
			left = head;
		else
			left = nullptr;
		right = pivot->next;
		NodeDL* leftEnd = left;
		if (leftEnd != nullptr && leftEnd != pivot) {
			while (leftEnd->next != pivot)
				leftEnd = leftEnd->next;
		}
		pivot->next = nullptr;
		if (leftEnd != nullptr)
			leftEnd->next = nullptr;

		sortListQuick(&left, a_);
		sortListQuick(&right, a_);

		if (left != nullptr) {
			leftEnd = left;
			while (leftEnd->next != nullptr)
				leftEnd = leftEnd->next;
			leftEnd->next = pivot;
			pivot->next = right;
			*headRef = left;
		}
		else {
			pivot->next = right;
			*headRef = pivot;
		}
	}
	void heapify(int arr[], int size, int root) {
		int temp;
		int largest = root;
		int l = 2 * root + 1;
		int r = 2 * root + 2;

		if (l < size && arr[l] > arr[largest]) {
			largest = l;
		}

		if (r < size && arr[r] > arr[largest]) {
			largest = r;
		}

		if (largest != root) {
			temp = arr[root];
			arr[root] = arr[largest];
			arr[largest] = temp;

			heapify(arr, size, largest);
		}
	}
	void sortListHeap(NodeDL** headRef, char a_) {
		const int size = this->length();
		int* arr = new int[size];
		NodeDL* head = *headRef;
		NodeDL* ptr = head;
		int i = 0;
		int temp;
		while (ptr != nullptr) {
			arr[i] = ptr->info;
			i++;
			ptr = ptr->next;
		}

		// Build heap
		for (int i = size / 2 - 1; i >= 0; i--) {
			heapify(arr, size, i);
			ptr = head;
			for (int ii = 0; ii < size; ii++) {
				ptr->info = arr[ii];
				ptr = ptr->next;
			}
		}

		// Moving current root to end
		for (int i = size - 1; i > 0; i--) {
			temp = arr[0];
			arr[0] = arr[i];
			arr[i] = temp;
			heapify(arr, i, 0);
			ptr = head;
			for (int ii = 0; ii < size; ii++) {
				ptr->info = arr[ii];
				ptr = ptr->next;
			}
		}

		ptr = head;
		for (i = 0; i < size; i++) {
			ptr->info = arr[i];
			ptr = ptr->next;
		}

		delete arr;

	}

	bool linearSearch(int n) {}
	bool binarySearch(int n) {}

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
		head = mainHead;
		return true;
	}

	NodeDL2* addPolynomials(NodeDL2* l1, NodeDL2* l2) {
		NodeDL2* addedPtr = new NodeDL2;
		NodeDL2* addedPtrHead = addedPtr;
		int power;
		int coeff1;
		int coeff2;
		for (power = 0; power < 10; power++) {
			NodeDL2* ptr1 = l1;
			NodeDL2* ptr2 = l2;
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
				addedPtr->next = new NodeDL2;
				addedPtr = addedPtr->next;
			}
			else if (coeff1 != -100) {
				addedPtr->info1 = coeff1;
				addedPtr->info2 = power;
				addedPtr->next = new NodeDL2;
				addedPtr = addedPtr->next;
			}
			else if (coeff2 != -100) {
				addedPtr->info1 = coeff2;
				addedPtr->info2 = power;
				addedPtr->next = new NodeDL2;
				addedPtr = addedPtr->next;
			}
		}
		return addedPtrHead;
	}

};