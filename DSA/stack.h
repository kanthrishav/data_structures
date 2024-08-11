#include <iostream>
class Stack {
public:
	int topIndex;
	static int const MAX_SIZE = 20;
	int elements[MAX_SIZE];
	Stack() : topIndex(-1) {}
	~Stack() {}
	void push(int n) {
		elements[++topIndex] = n;
	}
	int pop() {
		return(elements[topIndex--]);
	}
	int top() {
		return(elements[topIndex]);
	}
	int size() {
		return(topIndex + 1);
	}

	void deleteMiddleElement() {}

	void checkParenthesis() {}
	void getLongestValidParanthesis() {}
	void reverseString() {}
	void reverseArray() {}
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
