#include <iostream>
#include <map>
class Stack {
public:
	int topIndex;
	static int const MAX_SIZE = 10;
	int elements[MAX_SIZE];
	char elements_c[MAX_SIZE];
	Stack() : topIndex(-1) {
		for (int i = 0; i < MAX_SIZE; i++)
			elements[i] = -10000;
	}
	~Stack() {}
	void push(int n) {
		elements[++topIndex] = n;
	}
	void push(char c) {
		elements_c[++topIndex] = c;
	}

	int pop() {
		return(elements[topIndex--]);
	}
	char pop(char c) {
		return(elements_c[topIndex--]);
	}
	int top() {
		return(elements[topIndex]);
	}
	int size() {
		return(topIndex + 1);
	}

	void deleteMiddleElement() {
		Stack* tempStack = new Stack;
		int midIndex = (topIndex + 1) / 2;
		int count = 0;
		while (count < midIndex) {
			tempStack->push(this->pop());
			count++;
		}
		this->pop();
		count = 0;
		while (count < midIndex) {
			this->push(tempStack->pop());
			count++;
		}
		delete tempStack;
	}
	void reverseArray(int* arr, int size) {
		int i;
		for (i = 0; i < size; i++)
			this->push(arr[i]);
		for (i = 0; i < size; i++)
			arr[i] = this->pop();
	}
	void reverseString(char* arr, char* newArr, int size) {
		int i;
		for (i = 0; i < size; i++)
			this->push(arr[i]);
		for (i = 0; i < size; i++)
			newArr[i] = this->pop('t');
	}
	std::string reverseString(std::string str) {
		int i;
		std::string cc = "";
		for (char& c : str)
			this->push(c);
		for (char& c : str)
			cc += this->pop('t');
		return cc;
	}

	bool checkParenthesis(std::string str) {
		bool status = true;
		std::vector<char> openPar = { '(' , '{', '[' };
		std::vector<char> closePar = { ')' , '}', ']' };
		std::map<char, char> par{ {'{', '}'},
								 {'[', ']'},
								 {'(', ')'} };
		for (char& c : str) {
			if (std::find(openPar.begin(), openPar.end(), c) != openPar.end()) {
				this->push(par[c]);
			}
			else if (std::find(closePar.begin(), closePar.end(), c) != closePar.end()) {
				if (this->pop('a') != c) {
					status = false;
					break;
				}
			}
		}
		return status;
	}
	std::string getLongestValidParanthesis(std::string str) {
		bool status = true;
		std::vector<char> openPar = { '(' , '{', '[' };
		std::vector<char> closePar = { ')' , '}', ']' };
		Stack* open = new Stack;
		Stack* close = new Stack;
		std::map<char, char> par{ {'{', '}'},
								 {'[', ']'},
								 {'(', ')'} };
		int index = 0;
		int lastIndex = 0;
		int firstIndex = 0;
		for (char& c : str) {
			if (std::find(openPar.begin(), openPar.end(), c) != openPar.end()) {
				this->push(par[c]);
				open->push(index);
			}
			else if (std::find(closePar.begin(), closePar.end(), c) != closePar.end()) {
				if (this->pop('a') != c) {
					status = false;
					break;
				}
				else {
					close->push(index);
					lastIndex = index;
				}
			}
			index++;
		}
		while (close->topIndex != -1) {
			firstIndex = open->pop();
			close->pop();
		}

		std::string newStr = "";
		int count = 0;
		for (char& c : str) {
			if (count >= firstIndex && count <= lastIndex)
				newStr += c;
			count++;
		}
		return newStr;
	}
	std::string reverseIndividualWords(std::string str) {
		std::string newStr = "";
		std::string word = "";
		char lastChar;
		int count = 0;
		int len = str.length();
		for (char& c : str) {
			if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == ' ') {
				if (c == ' ') {
					word = "";
					while (this->topIndex != -1)
						word += this->pop('a');
					newStr += word + c;
				}
				else
					this->push(c);
			}
			else if (count < len - 1)
				newStr += c;
			else
				lastChar = c;
			count++;
		}
		word = "";
		while (this->topIndex != -1)
			word += this->pop('a');
		newStr += word + lastChar;
		return newStr;
	}
	int evaluatePostfixExpression(std::string str) {
		int op1, op2, result;
		for (char& c : str) {
			if (c >= 48 && c <= 57) {
				this->push(c - '0');
			}
			else {
				op2 = this->pop();
				op1 = this->pop();
				switch (c) {
				case '+': {
					result = op1 + op2;
					break;
				}
				case '-': {
					result = op1 - op2;
					break;
				}
				case '*': {
					result = op1 * op2;
					break;
				}
				case '/': {
					result = op1 / op2;
					break;
				}
				case '%': {
					result = op1 % op2;
					break;
				}
				}
				this->push(result);
			}
		}
		return(result);
	}

	void sortBubble(char a_) {
		int i, temp;
		int passCount = 10;
		int end = topIndex;
		bool comparison;
		while (passCount > 0) {
			passCount = 0;
			for (i = 0; i < end; i++) {
				comparison = (a_ == 'a') ? ((elements[i] > elements[i + 1]) ? true : false) : ((elements[i] < elements[i + 1]) ? true : false);
				if (comparison) {
					temp = elements[i];
					elements[i] = elements[i + 1];
					elements[i + 1] = temp;
					passCount++;
				}
			}
			end--;
		}
	}
	void sortSelection(char a_) {
		int temp;
		int i;
		int min = 10000;
		int max = -10000;
		int minIndex;
		int maxIndex;
		int start = 0;
		while (start < topIndex) {
			min = 10000;
			max = -10000;
			for (i = start; i < topIndex + 1; i++) {
				if (a_ == 'a') {
					if (elements[i] < min) {
						min = elements[i];
						minIndex = i;
					}
				}
				else if (a_ == 'd') {
					if (elements[i] > max) {
						max = elements[i];
						maxIndex = i;
					}
				}
			}
			temp = elements[start];
			if (a_ == 'a') {
				elements[start] = elements[minIndex];
				elements[minIndex] = temp;
			}
			else if (a_ == 'd') {
				elements[start] = elements[maxIndex];
				elements[maxIndex] = temp;
			}
			start++;
		}
	}
	void sortInsertion(char a_) {
		int temp, i, j, newValue;
		int start = 0, end = 1;
		while (end < topIndex) {
			for (i = start; i < end; i++) {
				if (a_ == 'a') {
					if (elements[end+1] > elements[i] && elements[end+1] <= elements[i+1]) {
						temp = elements[end+1];
						for (j = end+1; j > i; j--) {
							elements[j] = elements[j - 1];
						}
						elements[i + 1] = temp;
					}
					else if (elements[end+1] <= elements[i]) {
						temp = elements[end+1];
						for (j = end+1; j >= i; j--) {
							elements[j] = elements[j - 1];
						}
						elements[i] = temp;
					}
				}
				else if (a_ == 'a') {
					if (elements[end + 1] < elements[i] && elements[end + 1] >= elements[i + 1]) {
						temp = elements[end + 1];
						for (j = end + 1; j > i; j--) {
							elements[j] = elements[j - 1];
						}
						elements[i + 1] = temp;
					}
					else if (elements[end + 1] >= elements[i]) {
						temp = elements[end + 1];
						for (j = end + 1; j >= i; j--) {
							elements[j] = elements[j - 1];
						}
						elements[i] = temp;
					}
				}
			}
			end++;
		}
	}
	void SortedMerge(int start1, int end1, int start2, int end2, char a_) {
		if (start1 > end1 || start2 > end2) {
			return;
		}

		int size1 = end1 - start1 + 1;
		int size2 = end2 - start2 + 1;
		int* left = new int[size1] {};
		int* right = new int[size2] {};

		int count, i;
		for (i = 0, count = start1; i < size1 && count <= end1; i++, count++)
			left[i] = elements[count];
		for (i = 0, count = start2; i < size2 && count <= end2; i++, count++)
			right[i] = elements[count];
		bool comparison;
		int c1 = 0, c2 = 0;
		i = start1;
		while ((c1 < size1) && (c2 < size2)) {
			comparison = (a_ == 'a') ? ((left[c1] < right[c2]) ? true : false) : ((left[c1] > right[c2]) ? true : false);
			elements[i++] = comparison ? left[c1++] : right[c2++];
		}

		if (c1 == size1) {
			while (i <= end2)
				elements[i++] = right[c2++];
		}
		else if (c2 == size2) {
			while (i <= end2)
				elements[i++] = left[c1++];
		}

		delete[] left;
		delete[] right;
	}
	void sortMerge(int start, int end, char a_) {
		if (start >= end) {
			return;
		}

		int mid = start + ((int)((end - start) / 2.0));
		sortMerge(start, mid, a_);
		sortMerge(mid+1, end, a_);

		SortedMerge(start, mid, mid + 1, end, a_);
	}
	void sortQuick(int start, int end, char a_) {
		
		if (start >= end) {
			return;
		}

		int pivotIndex = end;
		int i = start, j = start, temp;
		bool comparison;
		while (i < pivotIndex) {
			comparison = (a_ == 'a') ? (elements[i] < elements[pivotIndex] ? true : false) : (elements[i] > elements[pivotIndex] ? true : false);
			if (comparison) {
				if (i != j) {
					temp = elements[i];
					elements[i] = elements[j];
					elements[j] = temp;
				}
				j++;
			}
			i++;
		}

		if (i != j) {
			temp = elements[pivotIndex];
			elements[pivotIndex] = elements[j];
			elements[j] = temp;
		}
		
		sortQuick(start, j - 1, a_);
		sortQuick(j+1, end, a_);


	}
	void sortHeap(char a_) {
		bool leftComparison, rightComparison;
		int len = topIndex + 1;
		int lastLeafNode = (len / 2) - 1;
		int sortedNode = (2 * lastLeafNode + 2 > (len - 1)) ? (2 * lastLeafNode + 1) : (2 * lastLeafNode + 2);
		int i, l, r, temp, passCount = 10;
		int min = 10000;
		int max = -10000;
		if (a_ == 'a') {
			for (i = 0; i < len; i++) {
				if (elements[i] < min)
					min = elements[i];
			}
		}
		else if (a_ == 'd') {
			for (i = 0; i < len; i++) {
				if (elements[i] > max)
					max = elements[i];
			}
		}


		while (passCount > 0) {
			passCount = 0;
			for (i = lastLeafNode; i >= 0; i--) {
				l = 2 * i + 1;
				r = 2 * i + 2;
				if (a_ == 'a') {
					leftComparison = (elements[l] > elements[i] && elements[l] > elements[r] && l <= sortedNode) ? true : false;
					rightComparison = (elements[r] > elements[i] && elements[r] > elements[l] && r <= sortedNode) ? true : false;
				}
				else if (a_ == 'd') {
					leftComparison = (elements[l] < elements[i] && elements[l] < elements[r] && l <= sortedNode) ? true : false;
					rightComparison = (elements[r] < elements[i] && elements[r] < elements[l] && r <= sortedNode) ? true : false;
				}
				if (leftComparison) {
					temp = elements[i];
					elements[i] = elements[l];
					elements[l] = temp;
					passCount++;
				}
				else if (rightComparison) {
					temp = elements[i];
					elements[i] = elements[r];
					elements[r] = temp;
					passCount++;
				}
			}
			if (passCount > 0) {
				temp = elements[0];
				elements[0] = elements[sortedNode];
				elements[sortedNode] = temp;
				sortedNode--;
			}
			else {
				if ((a_ == 'a' && elements[0] != min) || (a_ == 'd' && elements[0] != max)) {
					temp = elements[0];
					elements[0] = elements[sortedNode];
					elements[sortedNode] = temp;
					passCount = 1;
				}
			}

		}
	}

	void getNextGreaterElement() {
		// Given 
	}
	void getNearestSmallerElement() {}
	void getNextSmallerOfNextGreaterElement() {}
	void deleteConsecutiveSameWordsInSequence() {}
	void getCountOfSubArraysWhoseFirstElementIsMinimum() {}
	void getLengthOfLongestValidSubstring() {};
	void getNextFrequencyElement() {}
	void getMaxDiffBetweenNearestLeftAndRightSmallerElements() {}
	void getMaxProductOfIndicesOfNextGreaterOnLeftAnfRight() {}
	void checkWhetherGivenPermutationIsValidStackPermutation() {}
	void checkWhetherTwoExpInBracketsAreSame() {}
	void findLargestRectanglularAreaPossibleInAGivenHistogram() {}
	void celebrityProblem() {}
	void designCustomBrowserHistoryBasedOnGivenOperations() {}
	void getMaxPeopleOneCanSeeWhileStandinInLineInBothDirections() {}
	void getCountOfDistinctDifferencesBetweenTwoMaxElementsOfEverySubArray() {}
	void getMaxOfMinForEveryWindowInArray() {}
	void trappingRainWater() {}
	void simplifyPath() {}
	void buildBasicCalculator() {}
	void buildMinStack() {}
	void removeDuplicateLetters() {}
	void createMaxNumber() {}
	void miniParser() {}
	void longestAbsoluteFilePath() {}
	void decodeString() {}
	void removeKStrings() {}
	void ternaryExpressionParser() {}
	void _132Pattern() {}
	void findPermutation() {}
	void zumaGame() {}
	void shortestUnsoortedContinuousSubArray() {}
	void tagValidator() {}
	void baseballGame() {}
	void createMaxStack() {}
	void numberOfAtoms() {}
	void asteroidCollision() {}
	void parseLispExpression() {}
	void dailyTemperatures() {}
	void carFleet() {}
	void scoreOfParanthesis() {}
	void createMaxFrequencyStack() {}
	void onlineStockPlan() {}
	void sumOfSubArrayMinimums() {}
	void miniimumAddToMakeParanthesisValid() {}
	void stampingTheSequence() {}
	void validateStackSequences() {}
	void maxWidthRamp() {}
	void removeOuterMostParanthesis() {}
	void smallestSubSequenceOfDistinctCharacters() {}
	void parsingABooleanExpression() {}
	void dinnerPlateStacks() {}
	void longestWellPerformingInterval() {}
	void reverseSubstringsBetweenEachPairOfParantheses() {}
	void minimumDeletionsToMakeArrayBeautiful() {}
	void minimumRemoveToMakeValidParenthesis() {}
	void finalPricesWithSpecialDiscountInAShop() {}
	void countSubMatricesWithAllOnes() {}
	void minNumberOfIncrementsOnSubArraysToFormmATargetArray() {}
	void makeTheStringGreat() {}
	void shortestSubArrayToBeRemovedToMakeArraySorted() {}
	void crawlerLogFile() {}
	void getNestingdepthOfParenthesis() {}
	void findMostCompetetiveSubsequence() {}
	void numberOfStudentsUnableToEatLunch() {}
	void uildingWithAnOceanView() {}
	void jumpGame() {}
	void numberrOfWeakCharactersInTheGame() {}
	void scoreOfStudentsSolvingMathExpression() {}
	void replaceNonCoprimeNumbersInArray() {}
	void countCollisionsOnTheRoad() {}
	void sumOfTotalNumberOfWizards() {}
	void designATextEditor() {}
	void designVideoSharingPlatform() {}
};
