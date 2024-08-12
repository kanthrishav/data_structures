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
	void reverseArray(int * arr, int size) {
		int i;
		for (i = 0; i < size; i++)
			this->push(arr[i]);
		for (i = 0; i < size; i++)
			arr[i] = this->pop();
	}
	void reverseString(char * arr, char * newArr, int size) {
		int i;
		for (i = 0; i < size; i++)
			this->push(arr[i]);
		for (i = 0; i < size; i++)
			newArr[i] = this->pop('t');
	}
	std::string reverseString(std::string str) {
		int i;
		std::string cc = "";
		for (char&c : str)
			this->push(c);
		for (char& c : str)
			cc += this->pop('t');
		return cc;
	}


	bool checkParenthesis(std::string str) {
		bool status = true;
		std::vector<char> openPar = { '(' , '{', '['};
		std::vector<char> closePar = { ')' , '}', ']'};
		std::map<char, char> par{{'{', '}'},
								 {'[', ']'},
								 {'(', ')'}};
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
		std::vector<char> openPar = { '(' , '{', '['};
		std::vector<char> closePar = { ')' , '}', ']'};
		Stack* open = new Stack;
		Stack* close = new Stack;
		std::map<char, char> par{{'{', '}'},
								 {'[', ']'},
								 {'(', ')'}};
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
	void reverseIndividualWords() {}
	void evaluatePostfixExpression() {}
	void getNextGreaterElement() {}
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
