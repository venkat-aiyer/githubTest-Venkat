// SmallPrograms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <functional>
#include <concurrent_priority_queue.h>
#include <concurrent_priority_queue.h>
#include <set>
#include <stack>
#include <regex>
#include <type_traits>

using namespace std;


//Below function helps us identify the triplet thats in increasing order
// this function  will check the increasing elements in any index, Not necessarily continous
bool increasingTriplet(vector<int>& nums) 
{
	int nFirst_Smallest = INT_MAX;
	int nSec_Smallest = INT_MAX;
	for (int nCurr : nums) {
		if (nCurr <= nFirst_Smallest) {
			nFirst_Smallest = nCurr;		// here the most least elem so far will be stored, as long as array vals are decreasing this var gets update for ever loop.
			// Unless the value start becoming increasing in the array, this variable keeps updating for every loop.
		}
		else if (nCurr <= nSec_Smallest) {
			nSec_Smallest = nCurr;		// This var will be updated when a val higher than nPrvFirst_num is found
		}
		else {
			return true;				// Control comes here when a var higher than nPrvSec_num is found. the array idx need not be continuous.
		}
	}
	return false;
}

double myPow(double x, int n) 
{
	int ans;

	if (n == 0) return 1;

	if (n < 0) n = abs(n), x = 1 / x;

	if (n % 2 == 0) return myPow(x * x, n / 2);

	else return x * myPow(x * x, n / 2);
}

double findPower(double nInput, int nPow)
{
	if (nPow < 0)
		return -1;
	if (nPow == 0)
		return 1;
	if (nPow == 1)
		return nInput;
	double nResult = nInput;
	for (int i = nPow; i > 1; --i)
	{
		nResult = nResult * nInput;
	}
	return nResult;
}

// Given an array with equal number of odds and even numbers
// Below function arranges odd number in odd indexes
// and even number in even indexes
void arrangeOddAndEvenValInOddAndEvenIndexes(vector<int> &nInputVectorArray)
{
	int nEvenIndex = 0;
	int nOddIndex = 1;

	while (nEvenIndex < nInputVectorArray.size() && nOddIndex < nInputVectorArray.size())
	{
		if (nInputVectorArray[nEvenIndex] % 2 != 0)
		{
			swap(nInputVectorArray[nEvenIndex], nInputVectorArray[nOddIndex]);	// as we now know that the current nOddIndex is having an odd val we are jumping +2.
			// To recheck the same index after the swap the nEvenIndex is still not incremented.
			nOddIndex += 2;
		}
		else
		{
			nEvenIndex += 2;
		}
	}
}

/*
	The below program tries to arrange odd numbers in odd indexes and even number in even indexes.
	To achieve this first initialize one variable named nEvenIdx = 0; Because 0 is even index and from here we can do +2 to jump to next even Idx.
	Then initialize another var nOddIdx = 1; as 1 is an odd Idx and from here we can make +2 to jump to next odd Idx.
	Now we need to loop through the whole input array. we need to start moving both odd and even Idx.
	We need to check the evenIdx first as it starts from 0 and check if contains even or odd val. If it contains odd val then swap it with oddIdx. Now increment the Odd Idx by 2;
	if the evenIdx contains evenVal then increment EvenVal + 2;
*/
void ArrangeOddAndEvenValsInRepectiveIdx(vector<int>& vArray)
{
	int nEvenIdx = 0;
	int nOddIdx = 1;

	while (nEvenIdx < vArray.size() && nOddIdx < vArray.size())
	{
		if (vArray[nEvenIdx] % 2 != 0)
		{
			swap(vArray[nEvenIdx], vArray[nOddIdx]);
			nOddIdx += 2;
		}
		else
		{
			nEvenIdx += 2;
		}
	}
}

// Below Program checks if the given integer is palindrome or not
// To check the palindromic integer we may check only half of the integer
// The remaing half should be same as reversed val. 

bool IsPalindromicInteger(int nX)
{
	if (nX < 0 || (nX != 0 && nX % 10 == 0))
		return false;

	int nReverse = 0;
	while (nReverse < nX)
	{
		nReverse = nReverse * 10 + nX % 10;
		nX = nX / 10;
	}
	return (nX == nReverse || nX == nReverse / 10);

}

double average(int a, int b)
{
	return ((a + b) / 2);
}

void stringToIntHash(std::string myString)
{
	
	long randomizer = 100;

	std::cout << "Enter a string: ";
	// std::getline(std::cin, myString);

	// Converts each character of string into an integer
	// and adds them together
	for (int i = 0; i < myString.size(); i++)
	{
		randomizer += myString[i];
	}

	// Make our number a little bit more unique
	randomizer *= 3.1415;
	randomizer += myString.size() * (int)myString[0];
	randomizer *= (int)myString[myString.size() - 1];

	std::cout << "Your strings unique number is: " << randomizer << std::endl;
}

// Find missing element in an continous numbered array (un sorted)
// Array contains value from 0 to N
// This problem can be solved by applying gaussian function.
int FindMissingNumberInContinousUnsortedArray(vector<int> arrayNumVector)
{
	int nSize = arrayNumVector.size();
	int nExpectedFinalResultOFFormula = nSize * (nSize + 1) / 2;
	int nActualCurrSum = 0;
	for (auto elem : arrayNumVector)
	{
		nActualCurrSum += elem;
	}

	return nExpectedFinalResultOFFormula - nActualCurrSum;
}


// Find the two Sum
// Given and array of numbers and a target value
// Write an algorithm to find the 2 elements which used for bringing the sum.

vector<int> findTwoSum(const vector<int>& vectorArray, int nTarget)
{
	map<int, int> mapOfSumVals;
	vector<int> resultVals;
	// Imagine a + b = result
	// In this loop We find the result - a = b is already in vector if not found insert the current val in
	// vector and its index.
	for (int i = 0; i<  vectorArray.size(); i++)
	{
		// We have used one of the element in the sum equation 
		// We are trying to find the second element used in the equation.
		// First it will not find the second element in the equation as it is not reached
		// Once the second element is reached in the array 
		// it will manage to find the first element as it is already pushed
		int nComplement = nTarget - vectorArray[i];
		if (mapOfSumVals.find(nComplement) != mapOfSumVals.end())
		{
			// map contains the index of the sum element used.
			resultVals.push_back(nComplement);
			// The second element is in the current index;
			resultVals.push_back(vectorArray[i]);
		}
		else
		{
			// push every element in the map and its index
			mapOfSumVals[vectorArray[i]] = i;
		}
	}
	return resultVals;
}

/*
* https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
167. Two Sum II - Input Array Is Sorted
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. 
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
*/
vector<int> findTwoSumInSorted(vector<int> nInputArr, int nTarget)
{
	int nLow = 0;
	int nHigh = nInputArr.size() - 1;

	while (nLow < nHigh)
	{
		int nSum = nInputArr[nLow] + nInputArr[nHigh];
		if (nSum == nTarget)
		{
			return { nLow + 1, nHigh + 1 };
		}
		else if (nSum < nTarget)
			++nLow;
		else
			--nHigh;
	}
	return { -1, -1 };
}


/*
* 532. K-diff Pairs in an Array
* https://leetcode.com/problems/k-diff-pairs-in-an-array/
* Asked in: KinAxis
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
nums[i] - nums[j] == k
Notice that |val| denotes the absolute value of val.

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
*/
// This problem is almost like 2 sum problem, However there are couple of new cases.
// 1. When k == 0 then we got to have atleast 2 similar element in the array. (remember the elements need to be in different idx's of arr). ++count.
// 2. When we can find any of the diff of  arrElem - k in the map that we already store all the arr elements to its count. Then we need to ++count.


int findUniqPairsWithKDiff(vector<int>& nums, int k) 
{
	unordered_map<int, int> mpOfValsToCount;
	int nCounOfKDiffPairs = 0;
	int nSize = nums.size();
	// First register the frequencies of each element int the arr.
	for (int eachElem : nums)
	{
		mpOfValsToCount[eachElem]++;
	}

	if (k == 0)
	{
		for (auto eachItmMap : mpOfValsToCount)
		{
			if (eachItmMap.second > 1)
				nCounOfKDiffPairs++;
		}
		return nCounOfKDiffPairs;
	}
	for (auto eachItmMap : mpOfValsToCount)
	{
		if (mpOfValsToCount.find(eachItmMap.first - k) != mpOfValsToCount.end() )
		{
			nCounOfKDiffPairs++;
		}
	}
	return nCounOfKDiffPairs;
}
/*
* 1099. Two Sum Less Than K
* https://leetcode.com/problems/two-sum-less-than-k/
Given an array nums of integers and integer k, 
return the maximum sum such that there exists i < j with nums[i] + nums[j] = sum and sum < k. 
If no i, j exist satisfying this equation, return -1.
*/

int findTwoSumLessThanK(vector<int> nInputArr, int nK)
{
	sort(nInputArr.begin(), nInputArr.end());
	int nLow = 0;
	int nHigh = nInputArr.size() - 1;
	int nMax = INT_MIN;
	while (nLow < nHigh)
	{
		int nSum = nInputArr[nLow] + nInputArr[nHigh];
		if(nSum < nK)
		{
			nMax = max(nMax, nSum);
			nLow++;
		}
		else
		{
			nHigh--;
		}
	}
	return nMax != INT_MIN ? nMax : -1;
}

// Sort an array with 0's 1's and 2's
// The below program takes care of sorting or arranging an array with 0's 1's and 2's
void sortColors(vector<int> nInputArr)
{
	int nLeft = 0;
	int nRight = nInputArr.size() - 1;
	int nMid = 0;
	while (nMid <= nRight)
	{
		if (nInputArr[nMid] == 0)
		{
			swap(nInputArr[nLeft], nInputArr[nMid]);
			nMid++;
			nLeft++;
		}
		else if (nInputArr[nMid] == 1)
		{
			nMid++;
		}
		else if (nInputArr[nMid] == 2)
		{
			swap(nInputArr[nMid], nInputArr[nRight]);
			nRight--;
		}
	}
}

/*
* 525. Contiguous Array
* https://leetcode.com/problems/contiguous-array/
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
*/

// The below algorithm is useful in finding the largest continous subarray with equal number of 0's and 1's.
// This problem can be solved by using hash map. The approach for this problem is bit similar to 2 sum in array.
// this proble works like a wave sign. When we ascend during continous similar elements we register the idx points.
// Now when we descend after seeing the opposite elem we touch the same points for second time. when we store max values
// when touching all these points and try to find max among these max points we'll find the result.

int findMaxSubArrayLengthOf0sAnd1s(vector<int> arrayNumbers)
{
	unordered_map<int, int> mapOfIndexes;
	int nSum = 0;
	int nMax = 0;
	mapOfIndexes[0] = -1;
	for (int i = 0; i < arrayNumbers.size(); i++)
	{
		// Here sum suggests the continuity of the digit.
		(arrayNumbers[i] == 0) ? --nSum : ++nSum;
		// Remember when starting from a nSum value and after some time if we reach same value after oscilating
		// between + and - then it means we reached balanced point. That means it has equal frequency of elems in opposite dir.
		if (mapOfIndexes.find(nSum) == mapOfIndexes.end())
		{
			// Store the index inside the map
			mapOfIndexes[nSum] = i;
		}
		else
		{
			// If the sum is already found then we are using the current index and fetch and substract the stored index in the map for the curr sum.
			nMax = max(nMax, i - mapOfIndexes[nSum]);
		}
	}
	return nMax;

}

// Given an integer array nums, find the contiguous subarray (containing at least one number) which
// has the largest sum and return its sum.
// This algorithm finds the maximum continuous sum value of the sub array elements in the given array.
int maxContinousSubArraySum(vector<int> inputVector)
{
	// initialize the vars with first element.
	int nCurrentSubArrSum = inputVector[0];
	int nMaximumSumSubArr = inputVector[0];

	// Loop starts from second element as the first is already used.
	for (int i = 1; i < inputVector.size(); i++)
	{
		int nCurrentNum = inputVector[i];
		// Check if the current index value is greater than sum so far.
		nCurrentSubArrSum = max(nCurrentNum, nCurrentSubArrSum + nCurrentNum);
		nMaximumSumSubArr = max(nCurrentSubArrSum, nMaximumSumSubArr);
	}
	return nMaximumSumSubArr;
}


/*
* 523. Continuous Subarray Sum
// https://www.youtube.com/watch?v=G_N0H7tFLTY
Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false
*/

bool checkIfSubarraySumIsMultiplesOfK(vector<int>& nums, int nK)
{
	// Base condition
	if (nums.size() < 2)
		return false;
	int nSize = nums.size();
	map<int, int> mapOfSumsToIndex;
	mapOfSumsToIndex[0] = -1;
	int nCurrsum = 0;
	for (int i = 0; i < nSize; i++)
	{
		nCurrsum += nums[i];
		// Problem statement is to find the subarray sums that is multiples of k hence we're using mod.
		// This below logic is required as we are trying to sub arrays with sum divisible by nK
		int nMod = (nK == 0) ? 0 : nCurrsum % nK;		// this is to avoid dividing by 0.
		// We now need to find the nMod in the stored nMods in map, this gives us idea of how many sub arrays are having nK sum or multiples of nK.
		// Searching nMod in the map is the key thing here. By using the condition (i - mapOfSumsToIndex[nMod] > 1) hinting us that we need more than 2 elements needed for the sub-arr.
		// The reason why we search the nMod is because when we get the same nMod which previously occured and then it is findable in map suggests that there is sub arr that amounts to k multiples.
		if (mapOfSumsToIndex.find(nMod) != mapOfSumsToIndex.end())
		{
			// As per problem statement This below check condition is to verify if at least 2 elements is amounting for this subarray sum.
			if (i - mapOfSumsToIndex[nMod] > 1)
			{
				// As per problem statement atleast 2 elements of subarray is need to amount to sum or multiples of sum of nK.
				return true;
			}
			// if there is only 1 elemt causing this then check further for other elements.
			// If there is only 1 element amounting to subarray then continue search dont store this sub array in map.
			continue;
		}
		mapOfSumsToIndex[nMod] = i;
	}
	return false;
}

/*
* 325. Maximum Size Subarray Sum Equals k
* https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
Given an integer array nums and an integer k, return the maximum length of a subarray that sums to k. If there is not one, return 0 instead.

Example 1:

Input: nums = [1,-1,5,-2,3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2,-1,2,1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
*/

// In this problem we use prefix sum, using prefix sum we can find if there was any sub array amounted to given sum. This same method used in two sum.

int maxWindSizeOfSubArrSumOfK(vector<int> nInputArr, int nK)
{
	int nPrefixSum = 0;
	int nSize = nInputArr.size();
	map<int, int> mpPrefixSumToIndex;
	int nMaxWindSizeOfSubArrSum = INT_MIN;
	for (int i = 0; i < nSize; i++)
	{
		nPrefixSum += nInputArr[i];
		if (nPrefixSum == nK)
		{
			nMaxWindSizeOfSubArrSum = i + 1;
		}
		if (mpPrefixSumToIndex.find(nPrefixSum - nK) != mpPrefixSumToIndex.end())
		{
			nMaxWindSizeOfSubArrSum = max(nMaxWindSizeOfSubArrSum, i - mpPrefixSumToIndex[nPrefixSum - nK] + 1);
		}
		// if (mpPrefixSumToIndex.find(nPrefixSum - nK) == mpPrefixSumToIndex.end())
		else
		{
			mpPrefixSumToIndex[nPrefixSum] = i;
		}
	}
	return nMaxWindSizeOfSubArrSum;
}

/*
* Subarray Sums Divisible by K
* https://leetcode.com/problems/subarray-sums-divisible-by-k/
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0
*/

int subarraysDivByK(vector<int>& nums, int k) {
	int nCountOfSubArrDivByK = 0;;
	vector<int> arrOfReminders(k, 0);
	int nReminder = 0;
	for (int elem : nums)
	{
		// This will make the -ve values to +ve.
		nReminder += (elem % k + k) % k;
		// This vector acts as a map tracker of reminders.
		arrOfReminders[nReminder % k]++;
		// in the above line % operator is added to reduce the search spectrum within 5.
	}
	// Remember that if there are a more number of same reminders chances are that the difference value or sum value between j + j - 1 will have k divisible.
	nCountOfSubArrDivByK = arrOfReminders[0];
	for (int sumOfElem : arrOfReminders)
	{
		nCountOfSubArrDivByK += (sumOfElem * (sumOfElem - 1) / 2);
	}
	return nCountOfSubArrDivByK;
}


// FindSubArraySumOf Given Sum	// Not working correctly
int FindSubArrSum(vector<int> inputArray, int K)
{
	int nCount = 0;
	int nCurrSum = 0;
	unordered_map<int, int> hashMap;
	hashMap[0]++;
	for (int i = 0; i < inputArray.size(); i++)
	{
		nCurrSum += inputArray[i];
		if (nCurrSum == K)
		{
			nCount++;
		}
		// Checking if nSum - K present or not.
		if (hashMap.count(nCurrSum - K))
		{
			nCount += hashMap[nCurrSum - K];
		}
		hashMap[nCurrSum]++;
	}
	return nCount;
}

int FindSubArraySum(vector<int> inputArr, int nSum)
{
	int nCount = 0;
	int nCurrSum = 0;
	unordered_map<int, int> mpOfSumToOccurence;
	int nIdx = 0;
	while (nIdx < inputArr.size())
	{
		nCurrSum += inputArr[nIdx];
		if (nCurrSum == nSum)
		{
			nCount++;
		}
		// This check is to validate if there is single elem sub arr
		// Or if there is new range of values in middle of arr is forming the sum.
		if (mpOfSumToOccurence.find(nCurrSum - nSum) != mpOfSumToOccurence.end())
		{
			nCount += mpOfSumToOccurence[nCurrSum - nSum];
		}
		// Even if the value is already found increment the counter still to make it useful. To identify following sub arrays with nSum.
		mpOfSumToOccurence[nCurrSum]++;
		nIdx++;
	}
	return nCount;
}

// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
int findMaxLengthofEqual0sAnd1s(vector<int>& nums) {
	unordered_map<int, int> mapOfIndexes;
	int nSum = 0; int nMaxCount = 0;
	mapOfIndexes[0] = -1;
	for (int i = 0; i < nums.size(); i++)
	{
		nums[i] == 0 ? --nSum : ++nSum;
		if (mapOfIndexes.find(nSum) == mapOfIndexes.end())
			mapOfIndexes[nSum] = i;
		else
			nMaxCount = max(nMaxCount, i - mapOfIndexes[nSum]);
	}
	return nMaxCount;
}

// find and return number of sub arrays whose product is less than k
int findSubArrayProductLessThanK(vector<int>& inputArr, int nKResult)
{
	int nProd = 1;
	int nStart = 0;
	int nEnd = 0;
	int nCount = 0;
	int nSize = inputArr.size();
	while (nEnd < nSize)
	{
		nProd *= inputArr[nEnd];
		while (nStart < nSize && nProd >= nKResult)
		{
			// I want to understand why by moving this cursor we are able to get the result correctly.
			// If it is sum we had to move and remove the exact index of val which is causing the spill over,
			// As this is product we are interested only in the difference of length.
			nProd /= inputArr[nStart];
			// also note that as per problem statement we need to find any prod val less than given prod.
			// So it doesnt matter that we are leaving bigger num or smaller num
			nStart++;
		}
		if (nProd < nKResult)
		{
			// In this computation we get all combination of possible subarrays that solves given condition.
			nCount += nEnd - nStart + 1;
		}
		nEnd++;
	}
	return nCount;
}

/*
* 209. Minimum Size Subarray Sum
* https://leetcode.com/problems/minimum-size-subarray-sum/
* https://www.youtube.com/watch?v=S6Xg-0uaODc
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr]
of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/
// this 2 pointer technique can be used only for monotonic array. (always increasing). 
// If the array contains -ve numbers then this 2 ptr technique may not be useful.
// 209. Minimum Size Subarray Sum
// The important point to note here in this algo is the usage of 2 pointers to adjust the length of the array to make it less length and to satisfy nCurrSum >= nTargetSum;
int findMinSubArrLenWithSumGreaterThanOrEqToTarget(vector<int>& inputArr, int nTargetSum)
{
	int nLeft = 0;
	int nRight = 0;
	int nMinLenOfSum = INT_MAX;
	int nCurrSum = 0;
	int nSize = inputArr.size();

	while (nRight < nSize)
	{
		nCurrSum += inputArr[nRight];
		if (nCurrSum >= nTargetSum)
		{
			while (nCurrSum >= nTargetSum)
			{
				nCurrSum -= inputArr[nLeft];
				nLeft++;
			}
			// We just removed the left most char and that caused the nCurrSum to reduce further less than target.
			// Hence we need to add the previous elem.
			// The array is zero index based so addig 1 for that. So in total + 2;
			nMinLenOfSum = min(nMinLenOfSum, nRight - nLeft + 2);
		}
		nRight++;
	}
	return nMinLenOfSum == INT_MAX ? 0 : nMinLenOfSum;
}


/*
* 862. Shortest Subarray with Sum at Least K (Hard)
* Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
https://www.youtube.com/watch?v=K0NgGYEAkA4

Input: nums = [2,-1,2], k = 3
Output: 3

Input: nums = [1,2], k = 4
Output: -1

Input: nums = [1], k = 1
Output: 1

Input: nums = { 2, 7, 3, -8, 4, 10 }, k = 12;
output = 2;
*/
// This algo uses sliding window technique.
// Find Shortest Sub array Sum With Sum atleast K
int shortestSubarrayWithSumGreaterOrEqToK(vector<int>& inputArr, int nK)
{
	int nSize = inputArr.size();
	deque<pair<int, int>> dq;
	long long nCumulativeSum = 0;
	long long nShortest = INT_MAX;

	for (long long i = 0; i < nSize; i++)
	{
		nCumulativeSum += inputArr[i];
		if (nCumulativeSum >= nK)
		{
			// sum from start to ith index.
			nShortest = min(nShortest, i + 1);
		}
		// Reduce window size to find min window with sum >= nK.
		pair<long long, long long> nCurr = { INT_MIN, INT_MIN };
		while (!dq.empty() && (nCumulativeSum - dq.front().second >= nK))
		{
			nCurr = dq.front();
			dq.pop_front();
		}
		// calculate new shortest if possible
		if (nCurr.second != INT_MIN)
		{
			nShortest = min(nShortest, (i - nCurr.first));
		}
		// maintian monotonically non decreasing order of deque
		// If the current cumulative sum is less than previous means there is a negative val.
		// We are making the deque monotnic so that it is easy to use sliging window technique to find shortest sub array for the sum
		while (!dq.empty() && nCumulativeSum <= dq.back().second)
			dq.pop_back();
		dq.push_back({ i, nCumulativeSum });
	}
	return nShortest == INT_MAX ? -1 : nShortest;
}

/*
* https://leetcode.com/problems/maximum-product-subarray/
* https://www.youtube.com/watch?v=hJ_Uy2DzE08
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

*/

int maxProductSubArr(vector<int>& inputArr)
{
	int nMax_ending_here = inputArr[0];
	int nMin_ending_here = inputArr[0];
	int nMax_Overall = inputArr[0];
	for (int i = 1; i < inputArr.size(); i++)
	{
		int nPrevMaxEndingHere = nMax_ending_here;
		nMax_ending_here = max({ inputArr[i], inputArr[i] * nMax_ending_here, inputArr[i] * nMin_ending_here });
		// As this is product we need to consider that -ve into -ve will result to +ve which can be higher value too
		// So we are using the mins computation also.
		nMin_ending_here = min({ inputArr[i], inputArr[i] * nPrevMaxEndingHere, inputArr[i] * nMin_ending_here });
		nMax_Overall = max(nMax_Overall, nMax_ending_here);
	}
	return nMax_Overall;
}


/*
*  Maximum Subarray --> Easy problem
* Solved using kadane's algorithm
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.


Input: nums = [5,4,-1,7,8]
Output: 23
*/

int maxSubArray(vector<int>& nums) {
	int nCurrsum = nums[0];
	int nMaxSum = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		int nCurrVal = nums[i];
		nCurrsum = max(nCurrVal, nCurrVal + nCurrsum);
		nMaxSum = max(nCurrsum, nMaxSum);
	}

	return nMaxSum;
}

int maxSubArrayNew(vector<int>& nums)
{
	int nPrefixSum = 0;
	int nMaxSubArrSum = INT_MIN;
	int nMaxSubArrWind = INT_MIN;
	int nLeftwindCorner = 0;
	int nRightWindCorner = 0;
	int nSize = nums.size();
	map<int, int> mpSumToIndex;
	for (int i = 0; i < nSize; i++)
	{
		nPrefixSum += nums[i];
		nMaxSubArrSum = max(nMaxSubArrSum, nPrefixSum);
	}
	return nMaxSubArrSum;
}

/*
* Subarray Sum Equals K
* https://leetcode.com/problems/subarray-sum-equals-k/
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
*/
// This problem is solved similar to 2 sum problem where we store the difference in the map which is treated as compliment
// to find the actual value contributing to sum. this approach can be borrowed here however it is used like currSum - k here
// this is because we need to find the total number of other ways that the k can be formed in the sub array.

// This logic is useful only when the sum to be found is countinous. Its find subarr not subsequence.
int findCounOfSubArraysToMakeK(vector<int> inputArr, int nK)
{
	int nCurrsum = 0;
	int nTotalSubArrCount = 0;
	unordered_map<int, int> mapOfSumOccurence;
	int nIdx = 0;
	while (nIdx < inputArr.size())
	{
		nCurrsum += inputArr[nIdx];
		if (nCurrsum == nK)
		{
			// Yes the current count to be incremented when we find a subaray with sum.
			nTotalSubArrCount++;
		}
		// unable to understand the meaning of this line. needs debugging.
		// this logic is to find the 1 element subArray which can amount to the given K.
		// This map find of difference value between currSum - nK will help us find the count of all the sub arrays that gives nK as sum val.
		if (mapOfSumOccurence.find(nCurrsum - nK) != mapOfSumOccurence.end())
		{
			nTotalSubArrCount += mapOfSumOccurence[nCurrsum - nK];
		}
		mapOfSumOccurence[nCurrsum]++;
		nIdx++;
	}
	return nTotalSubArrCount;
}

/*
* https://leetcode.com/problems/merge-sorted-array/
* 88. Merge Sorted Array
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n,
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n,
where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

*/
// Input: 2 arrays are given.
// 1 of the array is bigger one that can accomodate both the array elements put together.

// This problem makes use of 3 pointers technique.
// ptr1 = this is pointing to the last valid element of 1st array.
// ptr2 = this is pointing to the last valid element of 2nd array.
// ptrEnd = this is pointing to the last array index of the bigger array.

void mergeSortedArraysInto1st(vector<int>& arrayMOne, int mSize, vector<int>& arrayNTwo, int nSize)
{
	int nPtr1 = mSize - 1;
	int nPtr2 = nSize - 1;
	for (int nPtrEnd = mSize + nSize - 1; nPtrEnd >= 0; nPtrEnd--)
	{
		if (nPtr2 < 0)
			break;
		if (nPtr1 >= 0 && arrayMOne[nPtr1] > arrayNTwo[nPtr2])
		{
			arrayMOne[nPtrEnd] = arrayMOne[nPtr1];
			nPtr1--;
		}
		else
		{
			arrayNTwo[nPtrEnd] = arrayNTwo[nPtr2];
			nPtr2--;
		}
	}
}

/*
* Meeting Rooms
* https://leetcode.com/problems/meeting-rooms/
In an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.
Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true
*/
bool canAttendMeetings(vector<vector<int>>& intervals) {
	if (intervals.empty()) {
		return true;
	}

	// Note: C++ sort function automatically sorts a vector first
	// by the 1st element, then by the 2nd element and so on.
	sort(intervals.begin(), intervals.end());
	for (size_t i = 0; i < intervals.size() - 1; i++) {
		if (intervals[i][1] > intervals[i + 1][0]) {
			return false;
		}
	}
	return true;
}

/*
* Merge Intervals
* https://leetcode.com/problems/merge-intervals/
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/
// Algorithm approach to remember
// Step 1. Loop through 0 to n - 1 only
// For every ith element check if i + 1 interval is more (this is doen by interval[i][1] < interval[i + 1][0])
// If the above succeds then it means interval is not overlapping then this sub array can be directly added to result merged arr.
// If the interval is overlapping means it reaches else then mark the interval[i + 1][0] = interval [i][0] and interval[i+1][1] = max(interval[i+1][1], interval[i][1]);
// Now the last index needs to be merged as we havent used the ast index for merging scenario inside loop.
vector<vector<int>> mergeIntervals(vector<vector<int>>& nIntervalArr)
{
	int nSize = nIntervalArr.size();
	if (nSize == 1)
		return nIntervalArr;
	sort(nIntervalArr.begin(), nIntervalArr.end());
	vector<vector<int>> mergedArr;
	// the reason why this loop is only between 0 to n-1 is because 
	// When checking the last element we cannot go array out of bounds.
	// also if in case the last array also need to merged then its already taken care in the else part using i + 1
	int i;
	for (i = 0; i < nSize - 1; i++)
	{
		// For every ith element check check if i + 1 interval is more(this is doen by interval[i][1] < interval[i + 1][0])
		if (nIntervalArr[i][1] < nIntervalArr[i + 1][0])
		{
			mergedArr.push_back(nIntervalArr[i]);
		}
		else
		{
			nIntervalArr[i + 1][0] = nIntervalArr[i][0];
			nIntervalArr[i + 1][1] = max(nIntervalArr[i][1], nIntervalArr[i + 1][1]);
		}
	}
	mergedArr.push_back(nIntervalArr[i]);
	return mergedArr;
}

/*
Problem statement: Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of
conference rooms required.
*/


// How many meeting rooms required to conduct meetings based on given intervals
// to find which meeting starts first we can just sort the array and get that details by comparing the start time.
// To determine if we can reuse a meeting room we need to sort by end time for this purpose priority queue is used.
int minMeetingRooms(vector<vector<int>>& intervals) {
	int rooms = 0;
	sort(intervals.begin(), intervals.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	for (auto x : intervals) {
		int start = x[0], end = x[1];
		while (!pq.empty() && pq.top() <= start) {
			pq.pop();
		}
		pq.push(end);
		rooms = max(rooms, (int)pq.size());
	}
	return rooms;
}


/*
* https://leetcode.com/problems/insert-interval/
* Insert intervals
// https://www.youtube.com/watch?v=FuLfL_WhUHI
// (1, 3) (6,9)   --> (2, 5)
// ===   ===
//   ===
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted
in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals
(merge overlapping intervals if necessary).

Return intervals after the insertion.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInerval)
{
	int i = 0;
	int nSize = intervals.size();
	vector<vector<int>> resultInsertedMerged;
	// WE need to push all intervals that has clear gap before the start of new interval. That can be identified by the condition intervals[i][1] < newInterval[0]
	// First case where we need to check if the old interval ending is less than new interval starting. When this happens it means there is a gap between
	// new and old interval. So push all the intervals until this condition succeeds.
	while (i < nSize && intervals[i][1] < newInerval[0])
	{
		resultInsertedMerged.push_back(intervals[i]);
		i++;
	}
	vector<int> mergedInterval = newInerval;

	// When the control reach here means the program logic have already taken care of moving all the initial nodes to the result arr.
	// This is the main condition where all the overlapping of intervals happens which needs to be merged.
	// here intervals[i][0] <= newInerval[1] is an exit condition. Until this condition true means overlapping region.
	// when the node that comes in the old intervals after the overlapping region then the nodes starting will be more than new intervals merging end point.
	while (i < nSize && intervals[i][0] <= newInerval[1])		// && intervals[i][1] > newInerval[0]
	{
		// This loop makes sure to include all the overlapping region. This is done via comapring the min and max of new interval with the following intervals in given main interval.
		mergedInterval[0] = min(mergedInterval[0], intervals[i][0]);
		mergedInterval[1] = max(mergedInterval[1], intervals[i][1]);
		i++;
	}
	// mergedInterval will only have the max longest interval part after including all the overlapping parts with the given intervals.
	resultInsertedMerged.push_back(mergedInterval);
	// When control reach here means overlapping region is taken care.
	while (i < nSize)
	{
		resultInsertedMerged.push_back(intervals[i]);
		i++;
	}
	return resultInsertedMerged;
}

/*
Non-overlapping Intervals
https://leetcode.com/problems/non-overlapping-intervals/
https://www.youtube.com/watch?v=evA9Z5p16bI
Given an array of intervals intervals where intervals[i] = [starti, endi],
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/
// this problem is one of the trickiest one if we dont get the basics right.
// This problem requires us to makes the right choice by looking into all the possible overlaps available with us.
// We need to keep ourselves ready for future as well by making correct choices at the moment(Current time)
// The important cases to consider is as below
// Case 1 -> a:
// [1, 6] [3, 9] [7, 10] ==> in this case it advantageous to delete [3, 9]. This will give us edge even when overlapping line comes in future.
// In case1->b this can also come [1, 6] [3, 9] [4, 10]. ==> When this case come we can handle it in the loop.
// However when case 1 -> a comes we should consider deleting the [3, 9]. So that in future if there is some different type of overlap will not make us to delete one more time.
// Another case Case 2: [1, 9] [3, 6] [7, 9]. In this case we need to delete the second interval [3, 6].
// 


int eraseOverlappingIntervals(vector<vector<int>>& intervals)
{
	int nPrevious = 0;
	int nSize = intervals.size();
	int nCountOfDeletion = 0;
	for (int nCurrent = 1; nCurrent < nSize; nCurrent++)
	{
		if (intervals[nCurrent][0] < intervals[nPrevious][1])		// [1, 5][3, 6]         // Overlapping  // Case 1.a
		{
			nCountOfDeletion++;
			// [1, 5][3, 6]         // Overlapping  // Case 1.a
			// [1, 5][8, 10]        // Non-Overlapping
			// [1, 5][2, 3]         // Overlapping Case 1.b
			if (intervals[nCurrent][1] <= intervals[nPrevious][1])	 // [1, 5][2, 3]         // Overlapping Case 1.b
			{
				nPrevious = nCurrent;
			}
		}
		else
		{
			nPrevious = nCurrent;
		}
	}
	return nCountOfDeletion;
}

/*
*  Intersection of Two Arrays
* https://leetcode.com/problems/intersection-of-two-arrays/
Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any order.
*/

vector<int> intersectionOf2Arrays(vector<int>& nums1, vector<int>& nums2)
{
	set<int> uniqElems;
	for (int elem : nums1)
	{
		uniqElems.insert(elem);
	}

	set<int> trackerSet;
	for (int elem : nums2)
	{
		if (uniqElems.find(elem) != uniqElems.end())
		{
			trackerSet.insert(elem);
		}
	}

	vector<int> retArray;
	for (int elem : trackerSet)
	{
		retArray.push_back(elem);
	}

	return retArray;
}

/*
* 350. Intersection of Two Arrays II
* https://leetcode.com/problems/intersection-of-two-arrays-ii/
* // This problem is second variation of the array intersection problem.
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear
as many times as it shows in both arrays and you may return the result in any order.
Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
*/

vector<int> intersectionOf2ArraysII(vector<int>& inputArr1, vector<int>& inputArr2) {
	sort(inputArr1.begin(), inputArr1.end());
	sort(inputArr2.begin(), inputArr2.end());
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < inputArr1.size() && j < inputArr2.size())
	{
		if (inputArr1[i] < inputArr2[j])
		{
			++i;
		}
		else if (inputArr1[i] > inputArr2[j])
		{
			++j;
		}
		else
		{
			inputArr1[k++] = inputArr1[i++];
			++j;
		}
	}

	return vector<int>(begin(inputArr1), begin(inputArr1) + k);

}

/*
* 657. Robot Return to Origin
* https://leetcode.com/problems/robot-return-to-origin/
* Easy problem
There is a robot starting at the position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.

You are given a string moves that represents the move sequence of the robot where moves[i] represents its ith move. Valid moves are 'R' (right), 'L' (left), 'U' (up), and 'D' (down).

Return true if the robot returns to the origin after it finishes all of its moves, or false otherwise.

Note: The way that the robot is "facing" is irrelevant. 'R' will always make the robot move to the right once, 'L' will always make it move left, etc. Also, assume that the magnitude of the robot's movement is the same for each move.



Example 1:

Input: moves = "UD"
Output: true
Explanation: The robot moves up once, and then down once. All moves have the same magnitude, so it ended up at the origin where it started. Therefore, we return true.
Example 2:

Input: moves = "LL"
Output: false
Explanation: The robot moves left twice. It ends up two "moves" to the left of the origin. We return false because it is not at the origin at the end of its moves.
*/
// Robot returning to home
// Below algorithm is useful to find if the robot returned to the place where it started.
// Consider that robot can move Up->'U', Down->'D', Right->'R', Left->'L'.
// Given a character array or string, Check if robot returned to its home.

bool judgeCircle(string moves) {
	int nVertical = 0;
	int nHorizontal = 0;
	// Declare 2 variable to hold directions in which robot is moving every move.
	// Loop thorugh each character and for every move in +ve direction increment and 
	// For every move in -ve direction decrement.

	for (char ch : moves)
	{
		switch (ch)
		{
		case 'U': nVertical++;
			break;
		case 'D': nVertical--;
			break;
		case 'R': nHorizontal++;
			break;
		case 'L': nHorizontal--;
			break;
		}
	}
	return (nVertical == 0 && nHorizontal == 0);

}

// Increment the array number with one
// Given an array which contains non-negative numbers.
// These numbers are representation of a number where 

vector<int> incrementDigitInArray(vector<int> arrayRepresentationOfNum)
{
	int nSize = arrayRepresentationOfNum.size();

	for (int i = nSize - 1; i >= 0; i--)
	{
		if (arrayRepresentationOfNum[i] < 9)
		{
			arrayRepresentationOfNum[i]++;
			return arrayRepresentationOfNum;
		}
		else
		{
			arrayRepresentationOfNum[i] = 0;
		}
	}
	int *nNewArray = new int[nSize + 1, 0];
	memset(nNewArray, 0, (nSize + 1) * sizeof(int));
	nNewArray[0] = 1;
	vector<int> newarrayRepresentationOfNum(nSize+1);
	newarrayRepresentationOfNum[0] = 1;
	for (int i = 1; i < nSize + 1; i++)
	{
		newarrayRepresentationOfNum.push_back(nNewArray[i]);
	}
	return arrayRepresentationOfNum;
	// arrayRepresentationOfNum = nNewArray;
}

/*
41. First Missing Positive
https://leetcode.com/problems/first-missing-positive/
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.



Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1

*/
int firstMissingPositive(vector<int>& nums) {
	// We will partition the array into two sides, with one copy of each number
	// on the left, in order, as far as possible.
	// [1, 2, 3, 4, 5, ..., n][...(everything else, but not n+1)...].
	int i = 0, end = nums.size();
	// Call LeftPartition the interval [1, ..., i - 1]
	// Call RightPartition the interval [nums[end], nums[nums.size() - 1]].
	// Initially, both are empty.
	// At the end, when "i" and "end" meet, call the results FinalLeftPartition and FinalRightPartition.
	// Then the answer to the problem is 1 + size(FinalLeftPartition).
	//
	// We build those intervals in-place, by swapping elements when necessary, and updating i and end.
	while (i != end) {
		int val = nums[i];
		if (val == 1 + i) // Number is in the right place. We may consider it part of LeftPartition, and advance i.
			++i;
		else if (
			val > end // If this should go in FinalLeftPartition, then that would overlap with FinalRightPartition.
			|| val <= 0 // The number is negative, it cannot possibly belong in FinalLeftPartition.
			|| nums[val - 1] == val // This is a duplicate. It doesn't belong in FinalLeftPartition.
									// How can we get away with checking just this one spot for a duplicate?
									// See the next "else" branch -- we always put values into this exact spot.
			) {
			// If any of the above statements is true, this value doesn't need to be in FinalLeftPartition.
			// So we may put it in the right partition,
			// and advance "end".
			swap(nums[i], nums[--end]);
			// Now nums[i] has some new value that we haven't considered before, so
			// leave "i" as is and go back to the top of the loop.
		}
		else {
			// We don't yet know whether val should be in
			// FinalLeftPartition or FinalRightPartition, so put it in neither.
			// In order to consider another value, place val so that it matches its own index;
			// that is, place it where it will be if indeed it ends up in FinalLeftPartition,
			// and next consider the element there.
			swap(nums[i], nums[val - 1]);
			// We learned nothing new about what elements will be in FinalLeftPartition or FinalRightPartition,
			// and nums[i] has the previous value of nums[val - i], which we haven't dealt with yet,
			// so continue the loop without advancing either pointer.
			// But we did make useful progress in this branch: now in the future, if we see the same "val"
			// again, we will know it's a duplicate, because of the "nums[val - 1] == val" check above!
		}
	}
	return i + 1;
}

/*
34. Find First and Last Position of Element in Sorted Array
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/

int findLeftIdxPos(vector<int>& nums, int nTarget)
{
	int nLow = 0;
	int nHigh = nums.size() - 1;
	int nAns = 0;
	while (nLow <= nHigh)
	{
		int nMid = ((nHigh - nLow) / 2 + nLow ) ;
		// Here, I am trying to find the start idx/ left corner of the sub arr.
		if (nums[nMid] >= nTarget)
		{
			if (nums[nMid] == nTarget)
			{
				// As we stored the matching idx we can now explore on the left side to find the beginning of the sub arr.
				nAns = nMid;
			}
			// Exploring towards left side to find beginning of the subarr.
			nHigh = nMid - 1;
		}
		else
		{
			nLow = nMid + 1;
		}
	}
	return nAns;
}

int findRightIdxPos(vector<int>& nums, int nTarget)
{
	int nLow = 0;
	int nHigh = nums.size() - 1;
	int nAns = 0;

	while (nLow <= nHigh)
	{
		int nMid = ((nHigh - nLow) / 2 + nLow);
		// Here I am looking for the right corner of the sub arr.
		if (nums[nMid] <= nTarget)
		{
			if (nums[nMid] == nTarget)
			{
				// As we stored the matching idx we can now explore the right side of the wind.
				nAns = nMid;
			}
			// We need to keep exploring in the right side.
			nLow = nMid + 1;
		}
		else
			nHigh = nMid - 1;
	}
	return nAns;
}

vector<int> searchRangeOfIdxOfGivenVal(vector<int>& nums, int target) {
	int nLeftPos = findLeftIdxPos(nums, target);
	int nRightPos = findRightIdxPos(nums, target);
	vector<int> nStartAndEndIdx;
	nStartAndEndIdx.push_back(nLeftPos);
	nStartAndEndIdx.push_back(nRightPos);

	return nStartAndEndIdx;
}


// This below algorithm helps us in finding kth largest element in an array
/*
* 215. Kth Largest Element in an Array
* https://leetcode.com/problems/kth-largest-element-in-an-array/
 heap data structure is used here,
so Whenever u guys see question which have combination of k and largest or smallest just go with heap first..
and whenever u guys see largest use minheap and when u see smallest use maxheap,

here i saw largest, so i used minheap , i just pushed all elements of array in minheap and since 
i want k largest element means kth element in minheap from back so i popout every element 
until my heap have size k and then just return top of heap.
*/
int findKthLargest(vector<int>& nums, int k)
{
	priority_queue <int, vector<int>, greater<int>> minHeap;

	for (auto i : nums)
		minHeap.push(i);

	int i = minHeap.size() - k;

	while (i)
	{
		minHeap.pop();
		i--;
	}
	
	return minHeap.top();

}
int findKthLargestII(vector<int>& nums, int k)
{
	priority_queue <int, vector<int>, less<int>> maxHeap;

	for (auto i : nums)
		maxHeap.push(i);

	int i = k;

	while (i)
	{
		maxHeap.pop();
		i--;
	}

	return maxHeap.top();

}

string findKthLargestIII(vector<string>& nums, int k)
{
	priority_queue <int, vector<int>, less<int>> maxHeap;

	for (string i : nums)
	{
		int nNum = (i[0]) - '0';
		maxHeap.push(nNum);
	}

	int i = k - 1;

	while (i)
	{
		maxHeap.pop();
		i--;
	}
	string strRet = to_string(maxHeap.top());
	return (strRet);

}


// Find Triplets sums to 0
// Find Three sum to zero
vector<vector<int>> FindTripletsSummingToZero(vector<int> arrayOfMixedNum, int nSum)
{
	vector<vector<int>> tripletRetVector;
	int nSize = arrayOfMixedNum.size();
	std::sort(arrayOfMixedNum.begin(), arrayOfMixedNum.end());
	for (int i = 0; i < nSize && arrayOfMixedNum[i] <= 0; i++)
	{
		// The inner loop will enter for oth index or it should not have repeated values when compared to previous loop.
		if (i == 0 || arrayOfMixedNum[i - 1] != arrayOfMixedNum[i])
		{
			int nLeft = i + 1;
			int nRight = nSize - 1;
			while (nLeft < nRight)
			{
				int nTargetSum = arrayOfMixedNum[i] + arrayOfMixedNum[nLeft] + arrayOfMixedNum[nRight];
				if (nTargetSum < nSum)
				{
					nLeft++;
				}
				else if (nTargetSum > nSum)
				{
					nRight--;
				}
				else
				{
					tripletRetVector.push_back({ arrayOfMixedNum[i] , arrayOfMixedNum[nLeft] , arrayOfMixedNum[nRight] });
					nLeft++; nRight--;
					// The inner loop will enter for oth index or it should not have repeated values when compared to previous loop.
					while (nLeft < nRight && arrayOfMixedNum[i - 1] == arrayOfMixedNum[i])
						++nLeft;
				}
			}
		}
	}
	return tripletRetVector;
}

int threeSumClosest(vector<int>& inputArr, int nTarget)
{
	int nClosestSum = 0;
	sort(inputArr.begin(), inputArr.end());
	int nDiffBetTarget = INT_MAX;
	int nSize = inputArr.size();
	for (int i = 0; i < nSize; i++)
	{
		int nLeft = i + 1;
		int nRight = nSize - 1;
		while (nLeft < nRight)
		{
			// Get teh current sum
			int nSum = inputArr[i] + inputArr[nLeft] + inputArr[nRight];
			// This is best case. when we get exact target then return it.
			if (nSum == nTarget)
				return nTarget;
			else if (nSum < nTarget)		// Move towards right to increase the sum closer to target.
				nLeft++;
			else
				nRight--;					// Moving left to decrease the diff between target and current sum.
			// Make sure to beat the previous best of min diff between target.
			if (abs(nSum - nTarget) < nDiffBetTarget)
			{
				// When the current diff is less than prev diff.
				nDiffBetTarget = abs(nSum - nTarget);
				// as the control reached here this is the latest Closest sum
				nClosestSum = nSum;
			}
		}
	}
	return nClosestSum;
}

vector<vector<int>> findFourSum(vector<int> nInputArr, int nTargetSum)
{
	int nSize = nInputArr.size();
	vector<vector<int>> outputArr;
	for (int i = 0; i < nSize; i++)
	{
		for (int j = i + 1; j < nSize; j++)
		{
			int nLeft = j + 1;
			int nRight = nSize - 1;
			while (nLeft < nRight)
			{
				int nSum = nInputArr[i] + nInputArr[j] + nInputArr[nLeft] + nInputArr[nRight];
				if (nSum == nTargetSum)
				{
					outputArr.push_back({ nInputArr[i], nInputArr[j], nInputArr[nLeft], nInputArr[nRight] });
					nLeft++;
					nRight--;
				}
				else if (nSum < nTargetSum)
				{
					nLeft++;
				}
				else
					nRight--;
			}
			while (j + 1 < nSize && nInputArr[j] == nInputArr[j + 1])
				j++;
		}
		while (i + 1 < nSize && nInputArr[i] == nInputArr[i + 1])
			i++;
	}

	return outputArr;
}

// Approach to solve: Maintain 2 pointers nLEft and nRight start the loop  from 0 to size of array.
// Move the right pointer from ledt on every element found to be 0.
// However Move both nLeft and nRight pointers in all other scenarios where elem != 0. Before incrementing the ptr swap the values from ptr locations.
// 
// Move Zero'es to end of array
// the below function takes care of moving the zero elements towards the end of array.
// All the positive integers will be maintained in the beginning of the array.

void moveZeroesToEnd(vector<int>& inputArray)
{
	for (int nLastNonZeroFoundAt = 0, nCurr = 0; nCurr < inputArray.size(); nCurr++)
	{
		if (inputArray[nCurr] != 0)
		{
			swap(inputArray[nLastNonZeroFoundAt++], inputArray[nCurr]);
		}
	}
}
void moveZeroesToEndNew(vector<int>& inputArray)
{
	int nLeft = 0;
	int nRight = 0;
	int nSize = inputArray.size();
	if (nSize == 0 || nSize == 1)
		return;
	while (nRight < nSize)
	{
		// Move the right pointer from ledt on every element found to be 0.
		if (inputArray[nRight] == 0)
		{
			nRight++;
		}
		else
		{
			// However Move both nLeft and nRight pointers in all other scenarios where elem != 0. 
			// Before incrementing the ptr swap the values from ptr locations.
			int nTemp = inputArray[nLeft];
			inputArray[nLeft] = inputArray[nRight];
			inputArray[nRight] = nTemp;
			nLeft++;
			nRight--;
		}
	}
}




void f(int i) 
{
	for (int j = 2; j < i; j++)
	{
		for (int k = 1, x = j; (x *= j + k) < i; k++)
		{
			if (x == i)
			{
				for (i = j; i < j + k; i++)
					cout << i;
			}
		}
	}
}

/**
Arr = 12 -1 -7 2 15 -9 49 -10

Window size = 3

-1 -7  -7 -9 -9 -9

**/

// Arr = 12 -1 -7 2 15 -9 49 -10
vector<int> findFirstOccuringNeg(vector<int>& nInputArr, int nWindSize)
{
	queue<int> qArr;

	vector<int> nFirstOccuringNegInEachWind;
	if (nInputArr.empty())
		return {};
	if (nInputArr.size() < nWindSize)
		return {};
	int nWindCounter = 0;
	bool bFalgForEachWind = false;
	for (int i = 0; i < nInputArr.size(); i++)
	{
		qArr.push(nInputArr[i]);
		if (qArr.back() < 0 && nInputArr.size() - nWindSize - 1 > i)
		{
			// if(nInputArr.size() - nWindSize <= i && bFalgForEachWind == false)
			nFirstOccuringNegInEachWind.push_back(nInputArr[i]);
		}
		else if (qArr.back() < 0 && bFalgForEachWind == false) {

			nFirstOccuringNegInEachWind.push_back(nInputArr[i]);

		}
		if (i > nWindSize - 1)
		{
			qArr.pop();
		}
		if (nInputArr.size() - nWindSize <= i && nInputArr[i] < 0)
		{
			bFalgForEachWind = true;
		}
		nWindCounter++;
	}
	return nFirstOccuringNegInEachWind;
}

/*
239. Sliding Window Maximum
https://leetcode.com/problems/sliding-window-maximum/
// This question was asked in VMWare/ Facebook/ Citrix
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

vector<int> findSlidingWindMax(vector<int>& nInputArr, int nWindSize)
{
	queue<int> qArr;

	vector<int> nMaxInEachWind;
	if (nInputArr.empty())
		return {};
	if (nInputArr.size() < nWindSize)
		return {};
	int nWindCounter = 0;
	bool bFalgForEachWind = false;
	int nMaxOfEachWind = INT_MIN;
	for (int i = 0; i < nInputArr.size(); i++)
	{
		qArr.push(nInputArr[i]);
		if (nWindCounter < nWindSize)
		{
			nMaxOfEachWind = max(nMaxOfEachWind, qArr.back());
		}
		else if (nWindCounter == nWindSize)
		{
			nMaxInEachWind.push_back(nMaxOfEachWind);
			qArr.pop();
		}
		else
		{
			nMaxOfEachWind = max(nMaxOfEachWind, qArr.back());
			nMaxInEachWind.push_back(nMaxOfEachWind);
			qArr.pop();
		}

		nWindCounter++;
	}
	return nMaxInEachWind;
}

bool pronic_check(int n)
{
	int x = (int)(sqrt(n));

	// Checking Pronic Number by
	// multiplying consecutive numbers
	if (x*(x + 1) == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int checkCountOfPronicNumbers(int nA, int nB)
{
	int nTotalCount = 0;
	for (int i = nA; i <= nB; i++)
	{
		bool bRet = pronic_check((i / 2) - 1);
		if (bRet)
		{
			nTotalCount++;
		}
	}
	return nTotalCount - 1;
}

// Function to check if x
// is a Pronic Number or not
bool checkPronic(int x)
{

	for (int i = 0; i <= (int)(sqrt(x)); i++) {

		// Check for Pronic Number by
		// multiplying consecutive
		// numbers X * (X + 1)
		if (x == i * (i + 1)) {
			return true;
		}
	}
	return false;
}

// Function to count pronic
// numbers in the range [A, B]
void countPronic(int A, int B)
{
	// Initialise count
	int count = 0;

	// Iterate from A to B
	for (int i = A; i <= B; i++) {

		// If i is pronic
		if (checkPronic(i)) {

			// Increment count
			count++;
		}
	}

	// Print count
	cout << count;
}

void ReverseString(char* strLeft, char* strRight)
{
	for (char c; --strRight - strLeft > 0; ++strLeft)
	{
		c = *strLeft;
		*strLeft = *strRight;
		*strRight = c;
	}
}



char* ReverseWordsInAString(char* szInput, int nRight)
{
	char* szEnd = szInput + strlen(szInput);
	char* szRetString = szInput;
	char* szTemp;

	while (isspace(*szInput))
	{
		++szInput;
	}

	while ((isspace(*szEnd) || !*szEnd) && szEnd - szInput > 0)
	{
		--szEnd;
	}

	ReverseString(szInput, ++szEnd);

	while (szEnd - szInput > 0)
	{
		while (isspace(*szInput))
			++szInput;

		szTemp = szInput;

		while (!isspace(*szTemp) && *szTemp)
			++szTemp;
		ReverseString(szInput, szTemp);

		szInput = szTemp;
	}

	return szRetString;

}

void stringProblem()
{
	string strInput = " 715K 2009-09-23 system.zip~";
	// Vector of string to save tokens
	vector <string> tokens;

	// stringstream class check1
	stringstream check1(strInput);

	string intermediate;

	// Tokenizing w.r.t. space ' '
	while (getline(check1, intermediate, ' '))
	{
		tokens.push_back(intermediate);
	}
		
}

string reverseWords(string s) {
	stringstream ss(s);
	string word;
	vector<string> vWords;
	while (ss >> word)
		vWords.push_back(word);
	reverse(vWords.begin(), vWords.end());

	string ans;
	for (auto eachWord : vWords)
	{
		// ans is intially empty and so an extra space appended infront of 
		// the string. This should be removed.
		ans += " " + eachWord;
	}
	// removing extra space in the front.
	ans.erase(0, 1);

	return ans;

}

class Solution {

public:
	string intToRoman(int num) 
	{
		string sb;
		vector<int> numericValues = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		vector<string> romanSymbols = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

		for (int i = 0; i < numericValues.size() && num > 0; i++)
		{
			while (numericValues[i] <= num)
			{
				num -= numericValues[i];
				sb += romanSymbols[i];
			}
		}

		return sb;
	}

	int romanToInt(string s) 
	{
		unordered_map<char, int> romanNums = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			auto itr = romanNums.find(s[i]);
			if (s[i] == 'I' && s[i + 1] == 'V') {
				// To generate the difference of -1 we reduce -2 from 1.
				// Now this result difference is summed with the existing answer.
				// iter->second already have the extra val if its I it'll have 1 if its X it'll have 10 and if its C it'll have 100
				// itr.second will have 1 here so 1 - 2 = -1 
				ans += itr->second - 2;
			}
			else if (s[i] == 'I' && s[i + 1] == 'X') {
				// To generate the difference of -1 we reduce -2 from 1.
				// Now this result difference is summed with the existing answer.
				// itr.second will have 1 here so 1 - 2 = -1 
				ans += itr->second - 2;
			}
			else if (s[i] == 'X' && s[i + 1] == 'L') {
				// To generate the difference of -10 we reduce -20 from 10.
				// Now this result difference is summed with the existing answer.
				// itr.second will have 10 here so 10 - 20 = -10 
				ans += itr->second - 20;
			}
			else if (s[i] == 'X' && s[i + 1] == 'C') {
				// To generate the difference of -10 we reduce -20 from 10.
				// Now this result difference is summed with the existing answer.
				// itr.second will have 10 here so 10 - 20 = -10 
				ans += itr->second - 20;
			}
			else if (s[i] == 'C' && s[i + 1] == 'D') {
				// To generate the difference of -100 we reduce -200 from 100.
				// Now this result difference is summed with the existing answer.
				// itr.second will have 100 here so 100 - 200 = -100 
				ans += itr->second - 200;
			}
			else if (s[i] == 'C' && s[i + 1] == 'M') {
				// itr.second will have 100 here so 100 - 200 = -100 
				ans += itr->second - 200;
			}
			else {
				auto itr2 = romanNums.find(s[i]);
				ans += itr2->second;
			}
		}
		return ans;
	}
};

// Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.
// ex: A -> 1, B -> 2, C -> 3, ..., Z -> 26, AA -> 27, AB -> 28
int titleToNumber(string columnTitle) 
{
	int result = 0;
	int n = columnTitle.length();
	for (int i = 0; i < n; i++) {
		result = result * 26;
		// In Java, subtracting characters is subtracting ASCII values of characters
		result += (columnTitle.at(i) - 'A' + 1);
	}
	return result;

}

int reverseANumber(int nInput)
{
	int nTemp = 0;
	while (nInput)
	{
		nTemp = nTemp * 10 + nInput % 10;
		nInput = nInput / 10;
	}
	return nTemp;
}

void printMatrixInSpiralOrder(vector<vector<int>> nMatrix)
{
	int nRow = nMatrix.size();
	int nCol = nMatrix[0].size();
	if (nRow == 0 || nCol == 0)
	{
		return;
	}
	int nTop = 0;
	int nDown = nRow - 1;
	int nLeft = 0;
	int nRight = nCol - 1;
	int nDirection = 0;

	while (nTop <= nDown && nLeft <= nRight)
	{
		// Direction is a cool addition for this problem
		if (nDirection == 0)
		{
			for (int j = nLeft; j <= nRight; j++)
			{
				cout << nMatrix[nTop][j] << " ";
			}
			nTop++;
		}
		else if (nDirection == 1)
		{
			for (int i = nTop; i <= nDown; i++)
			{
				cout << nMatrix[i][nRight] << " ";
			}
			nRight--;
		}
		else if (nDirection == 2)
		{
			for (int k = nRight; k >= nLeft; --k)
			{
				cout << nMatrix[nDown][k] << " ";
			}
			nDown--;
		}
		else if (nDirection == 3)
		{
			for (int d = nDown; d >= nTop; --d)
			{
				cout << nMatrix[d][nLeft] << " ";
			}
			nLeft++;
		}
		nDirection = (nDirection + 1) % 4;
	}
}



/*
https://leetcode.com/problems/sort-colors/
75. Sort Colors
Problem statement from leetcode:
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Solution approach:

We have seen 2 ptr approach to sort 0's and 1's.
A normal sort approach would take nLogn time. We can do better than that.
Here we can use 3 ptr approach.
first ptr in low (lowPtr), 2nd ptr in high (highPtr), 3rd ptr in middle(midPtr)

To start with we keep both low and mid ptrs in same place.

We loop through the list until the midPtr becomes higher than highPtr. (this mean O(N))
all comparisons happens interms of array values pointed by midPtr.

Whenever the loop runs we check either one of the below conditions to be valid. 
now everytime we encounter array index of midPtr pointing to 1 we can increment midPtr
now everytime we encounter array index of midPtr pointing to 0 we can swap it with lowPtr and increment lowPtr and MidPtr.
now everytime we encounter array index of midPtr pointing to 2 we can swap it with highPtr and decrement the highPtr.
*/

void sort0s1sAnd2s(vector<int> & inputArr)
{
	int nLowPtr = 0;
	int nHighPtr = inputArr.size() - 1;
	int nMidPtr = 0;

	while (nMidPtr <= nHighPtr)
	{
		if (inputArr[nMidPtr] == 0)
		{
			swap(inputArr[nLowPtr], inputArr[nMidPtr]);
			nMidPtr++;
			nLowPtr++;
		}
		else if (inputArr[nMidPtr] == 1)
		{
			nMidPtr++;
		}
		else if (inputArr[nMidPtr] == 2)
		{
			swap(inputArr[nHighPtr], inputArr[nMidPtr]);
			nHighPtr--;
		}
	}
}


// Given a binary array nums, return the maximum number of consecutive 1's in the array.
// Approach: 
// maintian count and maxcount, Loop through the size of the array, for every 1s increment the count.
// if current elem is not 1 then check if the currCount is greater than maxCount and update the bigger one in maxCount. 
// (Remember that if the consecutive 1's is in the end of array the maxCount is not updated, as we're waiting to find a 0)
// So, when returning we need to check if the currCountt is higher than max count and then return the maxCount.

int findMAxContinous1s(vector<int> inputArr)
{
	int nCurrCount = 0;
	int nMaxCount = 0;

	for (int i = 0; i < inputArr.size(); i++)
	{
		if (inputArr[i] == 1)
		{
			// For every consecutive 1 increment the count.
			nCurrCount++;
		}
		else
		{
			nMaxCount = max(nCurrCount, nMaxCount);
			// Reset the current count, as out objective is to find the continous 1s.
			nCurrCount = 0;
		}
	}
	
	// We should check the maxCount and currCount 
	return max(nCurrCount, nMaxCount);
}

// Leet code: 1869. Longer Contiguous Segments of Ones than Zeros
/*
Given a binary string s, return true if the longest contiguous segment of 1's is strictly longer than the longest contiguous segment of 0's in s, 
or return false otherwise.

For example, in s = "110100010" the longest continuous segment of 1s has length 2, and the longest continuous segment of 0s has length 3.
Note that if there are no 0's, then the longest continuous segment of 0's is considered to have a length 0. The same applies if there is no 1's.
*/
// Approach: This problem is very similar to above problem except that we need to maintian currCounter and maxCounter for both 0's and 1's
// Once after finshing the count throughout the arr before return check which one is higher and then return accordingly.


bool findHighestContinous1sOr0s(vector<int> inputArr)
{
	int nMaxZerCount = 0;
	int nMaxOneCount = 0;
	int nCurrZeroCount = 0;
	int nCurrOneCount = 0;

	for (int i = 0; i < inputArr.size(); i++)
	{
		if (inputArr[i] == 1)
		{
			++nCurrOneCount;
			nCurrZeroCount = 0;
			nMaxOneCount = max(nCurrOneCount, nMaxOneCount);
		}
		else if (inputArr[i] == 0)
		{
			++nCurrZeroCount;
			nCurrOneCount = 0;
			nMaxZerCount = max(nCurrZeroCount, nMaxZerCount);
		}
	}
	return nMaxOneCount > nMaxZerCount ? true : false;
}


int findSquareRoot(int nX)
{
	if (nX < 2)
		return nX;
	int nLeft = 2; int nRight = nX / 2;
	int nTemp;
	int nPivot;
	while (nLeft <= nRight)
	{
		nPivot = nLeft + (nRight - nLeft) / 2;
		nTemp = (long)nPivot * nPivot;
		if (nTemp > nX)
			nRight = nPivot - 1;
		else if (nTemp < nX)
			nLeft = nPivot + 1;
		else
			return nPivot;
	}
	return nRight;
}


void groupElementsBasedOnOccurence(vector<int>& inputArr)
{
	unordered_map<int, int> mapOfValToFreq;
	for (auto elem : inputArr)
	{
		mapOfValToFreq[elem]++;
	}
	int nPrev = 0;
	for (auto elem : mapOfValToFreq)
	{
		int nInnerLoop = mapOfValToFreq[elem.first];
		for (int j = nPrev; j < nPrev + nInnerLoop; j++)
		{
			inputArr[j] = elem.first;
		}
		nPrev += elem.second;
	}

}

/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
*/
//Floyd's algorithm TC: O(n), AS: O(1)
		/*Here we consider that there is a presence of cycle just like in case of circular linked list.
		And the starting point of the cycle is the duplicated number as once the list will return to it.*/
		//eg: 
		// arr[] :  1,  4,  3,  2,  3
		// idx  :   0   1   2   3   4
		/*
		Starting list traversal from nums[0] -> nums[nums[0]] -> nums[nums[0]] -> .......
			  1 -> 4 -> 3 ->2
						^   |
						| __|
		 */
int findDuplicate(vector<int> & inputVector)
{
	if (inputVector.size() == 2)
		return inputVector[0];
	int nSlow = inputVector[0];
	int nFast = inputVector[inputVector[0]];

	while (nSlow != nFast)
	{
		nSlow = inputVector[nSlow];
		nFast = inputVector[inputVector[nFast]];
	}
}


int findLowestMissingNumber(vector<int>& inputArr)
{
	unordered_map<int, bool> mapOfNumbers;
	int nHighestVal = 0;
	for (auto elem : inputArr)
	{
		mapOfNumbers[elem] = true;
		if (elem > nHighestVal)
			nHighestVal = elem;
	}

	for (int i = 1; i <= nHighestVal; i++)
	{
		if (mapOfNumbers.find(i) == mapOfNumbers.end())
		{
			return i;
		}
		if (i == nHighestVal)
		{
			return nHighestVal + 1;
		}
	}
}

/*
* Add Binary
* https://leetcode.com/problems/add-binary/
Given two binary strings a and b, return their sum as a binary string.
*/
/*
string addBinary(string a, string b)
{
	string  result;
	int nIdxA = a.size();
	int nIdxB = b.size();
	int nSum = 0;
	while (nIdxA > 0 || nIdxB > 0)
	{
		nSum = nSum > 1 ? 1 : 0;
		if (nIdxA > 0)
			nSum += a[--nIdxA] - '0';
		if (nIdxB > 0)
			nSum += b[--nIdxB] - '0';
		result += to_string(nSum % 2);
	}
	if (nSum > 0 ? 1 : 0)
		result += to_string(nSum > 1 ? 1 : 0);
	reverse(result.begin(), result.end());
	return  result;
}
*/
string addBinary(string a, string b) {

	int i = a.size() - 1, j = b.size() - 1, carry = 0;
	string sum = "";
	while (i >= 0 || j >= 0 || carry == 1) {
		carry += i >= 0 ? a[i--] - '0' : 0;
		carry += j >= 0 ? b[j--] - '0' : 0;
		sum = char(carry % 2 + '0') + sum;
		carry /= 2;
	}
	return sum;
}
// Problem statement
/*
1460. Make Two Arrays Equal by Reversing Sub-arrays

You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty sub-array of arr and reverse it. 
You are allowed to make any number of steps.

Return true if you can make arr equal to target or false otherwise.

Example 1: 
Input: target = [1,2,3,4], arr = [2,4,1,3]
Output: true
Explanation: You can follow the next steps to convert arr to target:
1- Reverse sub-array [2,4,1], arr becomes [1,4,2,3]
2- Reverse sub-array [4,2], arr becomes [1,2,4,3]
3- Reverse sub-array [4,3], arr becomes [1,2,3,4]
There are multiple ways to convert arr to target, this is not the only way to do so.
*/

bool canBeEqual(vector<int>& target, vector<int>& arr) {

	map<int, int> mpArrVals;
	set<int> stTracker;

	for (auto eachElem : target)
	{
		mpArrVals[eachElem]++;
		stTracker.insert(eachElem);
	}

	for (auto eachElem : arr)
	{
		mpArrVals[eachElem]++;
	}
	for (auto eachElem : mpArrVals)
	{
		if (eachElem.second % 2 != 0)
			return false;
	}
	if (mpArrVals.size() == stTracker.size())
		return true;

	return false;
}

bool checkMonotonicArray(vector<int>& nInputArray)
{
	bool bMonotonicIncreasing = true;
	bool bMonotonicDecreasing = true;

	// The monotonic array will increase or decrease in one direction
	// it will never increase and decrease like a sine wave.
	// By checking both increase and decrease of each elements in the same loop 
	// As we are checking i with i+ 1 the loop shoould end within nSize - 1;
	for (int i = 0; i < nInputArray.size() - 1; i++)
	{
		if (nInputArray[i] > nInputArray[i + 1]) bMonotonicIncreasing = false;
		if (nInputArray[i] < nInputArray[i + 1]) bMonotonicDecreasing = false;
	}
	// in same loop if both happens then it is not monotonic array
	return bMonotonicIncreasing || bMonotonicDecreasing;
}

/*
* 1762. Buildings With an Ocean View
* https://leetcode.com/problems/buildings-with-an-ocean-view/
Problem statement: There are n buildings in a line. You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. A building has an ocean view if the building can see the ocean without obstructions. Formally, a building has an ocean view if 
all the buildings to its right have a smaller height.
Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.

Example 1:

Input: heights = [4,2,3,1]
Output: [0,2,3]
Explanation: Building 1 (0-indexed) does not have an ocean view because building 2 is taller.
Example 2:

Input: heights = [4,3,2,1]
Output: [0,1,2,3]
Explanation: All the buildings have an ocean view.
Example 3:

Input: heights = [1,3,2,4]
Output: [3]
Explanation: Only building 3 has an ocean view.
*/

// Thre are two approaches to solve this problem
// This is basically a monotonic array.
// In first approach we can make use of stack 
// In second approach we can make use of MaxSoFar val/

// Approach 1

vector<int> canSeeTheBeach(vector<int> buildingHeights)
{
	vector<int> answerBuildingHeights;
	stack<int> maxBuildingHeight;
	int nSize = buildingHeights.size();
	for (int nCurrIndex = nSize - 1; nCurrIndex >= 0; --nCurrIndex)
	{
		while (!maxBuildingHeight.empty() && buildingHeights[maxBuildingHeight.top()] < buildingHeights[nCurrIndex])
			maxBuildingHeight.pop();
		if (maxBuildingHeight.size() == 0)
			answerBuildingHeights.push_back(nCurrIndex);
		maxBuildingHeight.push(nCurrIndex);
	}
	sort(answerBuildingHeights.begin(), answerBuildingHeights.end());
	return answerBuildingHeights;
}

// Approach 2
vector<int> findBuildings(vector<int>& heights) 
{
	int nMaxHeightSoFar = -1;
	vector<int> answerBuildingHeights;
	int nSize = heights.size();

	for (int nCurr = nSize - 1; nCurr >= 0; --nCurr)
	{
		// If there is no building higher (or equal) than the current one to its right,
		// push it in the answer array.
		if (nMaxHeightSoFar < heights[nCurr])
		{
			answerBuildingHeights.push_back(nCurr);
		}
		nMaxHeightSoFar = heights[nCurr];
	}
	reverse(answerBuildingHeights.begin(), answerBuildingHeights.end());
	return answerBuildingHeights;
}

// The below program takes care of arranging/ srting an array with 0's and 1's
void seggregate0sAnd1s(vector<int> nInputArr, int nLeft, int nRight)
{
	while (nLeft < nRight)
	{
		while (nLeft < nRight && nInputArr[nLeft] == 0)
			nLeft++;
		while (nLeft < nRight && nInputArr[nRight] == 1)
			nRight--;
		if (nLeft < nRight)
		{
			nInputArr[nLeft] = 0;
			nInputArr[nRight] = 1;
			nLeft++;
			nRight--;
		}
	}
}

/*
There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. You are given an array heights of distinct integers where heights[i] represents 
the height of the ith person.

A person can see another person to their right in the queue if everybody in between is shorter than both of them. More formally, the ith person can see the jth person if i < j and 
min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.


Example: 1
Input: heights = [10,6,8,5,11,9]
Output: [3,1,2,1,1,0]
Explanation:
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them.

Example: 2
Input: heights = [5,1,2,3,10]
Output: [4,1,1,1,0]
*/

// Steps to solve both the monotonic array problems
// Maitain a stack to hold maxHeight
// Loop through the overall height check if until stack is not empty and when curr height is more than the previous val pop stack.
// check if stack is empty then push the current index inside the result.
// push the 

vector<int> canSeePersonsCount(vector<int>& personHeights)
{
	stack<pair<int, int>> stPersonHeightToIndex;
	vector<int> resultCanSeePersonsCount(personHeights.size());

	for (int i = 0; i < personHeights.size(); i++)
	{
		int nCurrHeight = personHeights[i];
		// After this loop it is ensuring only the tallest is remainging in the stack.
		// If we see from top of stack it should be ascending.
		while (!stPersonHeightToIndex.empty() && stPersonHeightToIndex.top().first < nCurrHeight)
		{
			int nPrev = stPersonHeightToIndex.top().second;
			stPersonHeightToIndex.pop();							// until the curr height remains higher than the top of stack remove the elems from stack// Seeing from top should be ascending.
			resultCanSeePersonsCount[nPrev]++;						// PRevious shorter person can see next taller person;
		}
		if (!stPersonHeightToIndex.empty())
		{
			// if the current height is lees than previous vals in stack then increment the prevs count;
			resultCanSeePersonsCount[stPersonHeightToIndex.top().second]++;
		}
		stPersonHeightToIndex.push({ nCurrHeight , i });
	}
	return resultCanSeePersonsCount;
}


// Random Pick with Weight
/*
You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it.
The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).

Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]

Explanation
Solution solution = new Solution([1]);
solution.pickIndex(); // return 0. The only option is to return 0 since there is only one element in w.


Input
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output
[null,1,1,1,1,0]

Explanation
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // return 1. It is returning the second element (index = 1) that has a probability of 3/4.
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 0. It is returning the first element (index = 0) that has a probability of 1/4.

Since this is a randomization problem, multiple answers are allowed.
All of the following outputs can be considered correct:
[null,1,1,1,1,0]
[null,1,1,1,1,1]
[null,1,1,1,0,0]
[null,1,1,1,0,1]
[null,1,0,1,0,0]
......
and so on.
*/

class SolutionRandWeight
{
	vector<int> vectorOfBuckets;
public:
	SolutionRandWeight(vector<int> & randomWeights)
	{
		for (auto elem : randomWeights)
		{
			vectorOfBuckets.push_back(elem + (vectorOfBuckets.empty() ? 0 : vectorOfBuckets.back()));
		}
	}

	int pickIndex()
	{
		int nRand_Weight = rand() % vectorOfBuckets.back();
		return upper_bound(vectorOfBuckets.begin(), vectorOfBuckets.end(), nRand_Weight) - vectorOfBuckets.begin();
	}
};




/*
189. Rotate Array
https://leetcode.com/problems/rotate-array/
Given an array, rotate the array to the right by k steps, where k is non-negative.
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/
// Rotate an array by k times

void rotateArrays(vector<int>& inputArr, int nNumOfRotation)
{
	int nSize = inputArr.size();
	nNumOfRotation %= nSize;

	reverse(inputArr.begin(), inputArr.end());
	reverse(inputArr.begin(), inputArr.begin() + nSize - nNumOfRotation);
	reverse(inputArr.begin() + nSize - nNumOfRotation, inputArr.end());
}

void rotateArraysLeftDir(vector<int>& inputArr, int nNumOfRotation)
{
	int nSize = inputArr.size();
	nNumOfRotation %= nSize;

	reverse(inputArr.begin(), inputArr.end());
	reverse(inputArr.begin() + nSize - nNumOfRotation, inputArr.end());
	reverse(inputArr.begin(), inputArr.begin() + nSize - nNumOfRotation);
}

/*
* Rotate Array --> Medium
* https://leetcode.com/problems/rotate-array/
Given an array, rotate the array to the right by k steps, where k is non-negative.
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]


Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/
// For Ex: {1, 2, 3, 4, 5, 6, 7} , k = 3
// Step 1: {4, 3, 2, 1, 5, 6, 7}
// Step 2: {4, 3, 2, 1, 7, 6, 5}
// Step 3: {5, 6, 7, 1, 2, 3, 4} --> Done

void rotate(vector<int>& nums, int k) {
	int nSize = nums.size();
	int nK = k;
	nK %= nSize;

	reverse(nums.begin(), nums.begin() + nSize - nK);
	reverse(nums.begin() + nSize - nK, nums.end());
	reverse(nums.begin(), nums.end());
}
// find Common Elements in 2 unsorted Arr
vector<int> findCommonElements(vector<int> nArr1, vector<int> nArr2)
{
	set<int> uniqueElems;
	for (auto elem : nArr1)
	{
		uniqueElems.insert(elem);
	}
	set<int> trackerSet;
	for (auto elem : nArr2)
	{
		if (uniqueElems.find(elem) != uniqueElems.end())
		{
			trackerSet.insert(elem);
		}
	}
	vector<int> nResultArr;
	for (auto elem : trackerSet)
	{
		nResultArr.push_back(elem);
	}

	return nResultArr;
}

/*
Given two sparse vectors, compute their dot product.

Implement class SparseVector:

SparseVector(nums) Initializes the object with the vector nums
dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between 
two SparseVector.

Follow up: What if only one of the vectors is sparse?
*/

class SparseVector
{
	unordered_map<int, int> indexToValMap;
public:
	SparseVector(vector<int>& nInputArr)
	{
		if (nInputArr.empty())
		{
			return;
		}
		for (int i = 0; i < nInputArr.size(); i++)
		{
			if (nInputArr[i] != 0)
			{
				indexToValMap[i] = nInputArr[i];
			}
		}
	}

	int dotProduct(SparseVector& vec)
	{
		if (vec.indexToValMap.empty())
			return 0;
		int nResultSum = 0;
		for (auto it : indexToValMap)
		{
			if (vec.indexToValMap.find(it.first) != vec.indexToValMap.end())
			{
				nResultSum += vec.indexToValMap[it.first] * indexToValMap[it.first];
			}
			return nResultSum;
		}
	}
};


void refLectColums(vector<vector<int>>& inputMatrix)
{
	int nSize = inputMatrix.size();
	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize / 2; j++)
		{
			int nTemp = inputMatrix[i][j];
			inputMatrix[i][j] = inputMatrix[i][nSize - 1 - j];
			inputMatrix[i][nSize - 1 - j] = nTemp;
		}
	}
}


void matrixTransPose(vector<vector<int>>& inputMatrix)
{
	int nSize = inputMatrix.size();
	for(int i = 0; i< nSize; i++)
	{
		for (int j = i + 1; j < nSize; j++)
		{
			// make the row val as colum val and colum val as row val;
			int nTemp = inputMatrix[j][i];
			inputMatrix[j][i] = inputMatrix[i][j];
			inputMatrix[j][i] = nTemp;
		}
	}
}
/*
input:
1 2 3
4 5 6
7 8 9

After transpose
1 4 7
2 5 8
3 6 9

After Reflect

7 4 1
8 5 2
9 6 3
*/

void rotateArray(vector<vector<int>>& inputMatrix)
{
	// To achieve rotations it is a 2 step process.
	// After doing this below function the final result is just 1 step away.
	matrixTransPose(inputMatrix);
	// We just need to swap the head and tail colums of every row.
	refLectColums(inputMatrix);
}
/*
How to store 2 array elements in 1 index.

input [] = {1, 2, 3, 4, 5}

max ELem = 5
max index = 4
min index = 0;

formula
for even indexes i % 2 == 0

arr[0] = 1;

arr[i] = arr[i] + (arr[maxIndex] % (maxElem + 1)) * (maxElem + 1);
arr[0] = arr[0] + (arr[4] % (5 + 1)) * (5 + 1)
0 = 0 + (5 % 6) * 6;
arr[0] = 31;

Now after this decrement maxIndex;


for Odd indexes i%2 != 0

arr[0] = 31
arr[1] = 2;
maxElem = 5 ;
arr[i] = arr[i] + (arr[minIndex] % (maxElem + 1)) * (maxElem + 1);
arr[1] = arr[1] + (arr[0] % (5 + 1))* (5 + 1);

2 = 2 + (31 % 6) * 6;
2 = 2 + (1 * 6);
arr[1] = 8;
now after this process increment minIndex;




*/
// this logic will work only if the array is sorted.
void reArrangeArray(vector<int>& inputArr)
{
	int nSize = inputArr.size();
	int nMaxIndex = nSize;
	int nMinIndex = 0;
	int nMaxElem = inputArr[nMaxIndex - 1];
	int nActualMaxElem = inputArr[nMaxIndex - 1];
	sort(inputArr.begin(), inputArr.end());

	for (int i = 0; i < nSize; i++)
	{
		if (i % 2 == 0)
		{
			inputArr[i] = inputArr[i] + (inputArr[nMaxIndex - 1] % (nMaxElem + 1)) * (nMaxElem + 1);
			nMaxIndex--;
		}
		if (i % 2 != 0)
		{
			inputArr[i] = inputArr[i] + (inputArr[nMinIndex] % (nMaxElem + 1)) * (nMaxElem + 1);
			nMinIndex++;
		}

	}

	cout << " Original input arr : ";
	for (auto elem : inputArr)
	{
		cout << elem % (nActualMaxElem + 1) << " ";
	}
	cout << endl;

	cout << " Changed array : ";
	for (auto elem : inputArr)
	{
		cout << elem / (nActualMaxElem + 1) << " ";
	}
	cout << endl;
}

// rearrange array elements in such a way that arr[i] becomes arr[arr[i]] with O(1) extra space

void reArrangeArrayElemsAsIndex(vector<int>& inputArr)
{
	int nSize = inputArr.size();

	// Step 1: Increase all the array elements by (inputArr[inputArr[i]] % nSize) * nSize;
	for (int i = 0; i < inputArr.size(); i++)
	{
		inputArr[i] = inputArr[i] + ((inputArr[inputArr[i]] % nSize) * nSize);
	}

	// Step 2: Divide all the array elements by nSize;
	for (int i = 0; i < nSize; i++)
	{
		inputArr[i] = inputArr[i] / nSize;
	}
}

// Adding 2 strings
string addString(string& strNum1, string& strNum2)
{
	int nNum1Ptr = strNum1.size() - 1;
	int nNum2Ptr = strNum2.size() - 1;
	int nCarry = 0;
	string strResultSum;
	while (nNum1Ptr > -1 || nNum2Ptr > -1)
	{
		int nTempNum1Digit = (nNum1Ptr) > -1 ? strNum1[nNum1Ptr] - '0' : 0;
		int nTempNum2Digit = (nNum2Ptr) > -1 ? strNum2[nNum2Ptr] - '0' : 0;
		int nCurrSum = nTempNum1Digit + nTempNum2Digit + nCarry;
		char cCurrSumDigit = (nCurrSum % 10) + '0';
		nCarry = nCurrSum / 10;
		strResultSum += cCurrSumDigit;
		--nNum1Ptr;
		--nNum2Ptr;
	}
	if (nCarry == 1)
	{
		strResultSum += (1 + '0');
	}
	reverse(strResultSum.begin(), strResultSum.end());

	return strResultSum;
}


/*
* https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.
*/

// Before writing logic for the program.. Just write the rotated array as a example then start 

int findMinInRotatedArr(vector<int>& inputVec, int nLow, int nHigh)
{
	if (nHigh < nLow)
		return inputVec[0];
	if (nLow == nHigh)
		return inputVec[nLow];

	int nMid = nLow + (nHigh - nLow) / 2;

	if (nMid < nHigh && inputVec[nMid + 1] < inputVec[nMid])
	{
		return inputVec[nMid + 1];
	}
	else if (nLow < nMid && inputVec[nMid - 1] > inputVec[nMid])
	{
		return inputVec[nMid];
	} 
	else if (inputVec[nMid] < inputVec[nHigh])						// If this condition succeeds then its monotonic so check in prev half
	{
		return findMinInRotatedArr(inputVec, nLow, nMid - 1);		// Check in first half.
	}
	else
		return findMinInRotatedArr(inputVec, nMid + 1, nHigh);
}

int findMinInARotatedArr(vector<int>& nums) {
	return findMinInRotatedArr(nums, 0, nums.size() - 1);
}

/*
* Find Pivot Index -->Easy
* https://leetcode.com/problems/find-pivot-index/
* https://www.youtube.com/watch?v=HhCzL4ciCD4
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
*/


int findPivotIndex(vector<int>& nums)
{
	int nLeftSum = 0;
	int nRightSum = 0;
	for (int elem : nums)
	{
		nRightSum += elem;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		nRightSum -= nums[i];
		if (nLeftSum == nRightSum)
		{
			return i;
		}
		nLeftSum += nums[i];
	}
	return -1;
}


/*
* Search in Rotated Sorted Array
* https://leetcode.com/problems/search-in-rotated-sorted-array/
* https://www.youtube.com/watch?v=yPdfjEB8TvQ
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting 
array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at 
pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/


// To solve this problem We'll be using binary search technique.
// The binary search cannot be done on the full array. Binary search needs to happen in 2 different sub array.
// these sub arrays are divided by a pivot point.
// The Pivot point can be found by following check. If the array is rotated there will be pivot point where i (i > i + 1) or (i - 1 > i). 
// if there is no pivot point then the array is already sorted. In this case we can use plain binary search.
// When Pivot is found then below 2 type of binary search is required.
// if(nArr[0] <= nTarget) return binarySearch(nArr, 0, nPivot - 1, nTarget);
// else return biarySearch(nArr, nPivot + 1, nSize - 1, nTarget);
// else return nPivot;
// below logic will find the pivot
// if(nMid < nHigh && nArr[nMid] > nArr[nMid + 1]) return nMid;
// if(nLow < nMid && nArr[nMid - 1] > nArr[nMid]) return nMid;

// The below function is a plain binary search of keyToFind
int binarySearch(vector<int> nRotatedArr, int nLow, int nHigh, int nKeyToFind)
{
	if (nHigh < nLow)
		return -1;

	int nMid = nLow + (nHigh - nLow) / 2;
	if (nKeyToFind == nRotatedArr[nMid])
		return nMid;
	if (nKeyToFind > nRotatedArr[nMid])
		return binarySearch(nRotatedArr, nMid + 1, nHigh, nKeyToFind);

	return binarySearch(nRotatedArr, nLow, nMid - 1, nKeyToFind);
}

int findPivotPoint(vector<int> nRotatedArr, int nLow, int nHigh)
{
	if (nHigh < nLow)
		return -1;
	if (nHigh == nLow)
		return nLow;
	int nMid = nLow + (nHigh - nLow) / 2;
	if (nRotatedArr[nLow] < nRotatedArr[nHigh])
		return -1;
	if (nMid < nHigh && nRotatedArr[nMid] > nRotatedArr[nMid + 1])
		return nMid;
	if (nLow < nMid && nRotatedArr[nMid - 1] > nRotatedArr[nMid])
		return nMid;
	// This means all the big elements are the front half and chances of finding pivot dipping point in the front half is more.
	if (nRotatedArr[nLow] >= nRotatedArr[nMid])
		return findPivotPoint(nRotatedArr, nLow, nMid - 1);

	return findPivotPoint(nRotatedArr, nMid + 1, nHigh);
}

int searchANumberInRotatedArray(vector<int>& nums, int target) {
	int nPivotVal = findPivotPoint(nums, 0, nums.size() - 1);
	if (nPivotVal == -1)
		return binarySearch(nums, 0, nums.size(), target);
	if (target == nums[nPivotVal])
		return nPivotVal;
	// Now we need to decide which half the binary search needs to be applied.
	// We already found the pivot point now 
	if (nums[0] <= target)
		return binarySearch(nums, 0, nPivotVal - 1, target);

	return binarySearch(nums, nPivotVal + 1, nums.size() - 1, target);

}



/*
*  K Closest Points to Origin
* https://leetcode.com/problems/k-closest-points-to-origin/
* https://www.youtube.com/watch?v=rI2EBUEMfTk
* https://www.youtube.com/watch?v=XcblB8JVrX8
* 
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
*/

// This below struct will be useful to return lowest value between the points sent to it.
// This can directly be used in the sort function as a comparator operator.

struct ComparePoints
{
	bool operator()(const vector<int>& p1, const vector<int>& p2)
	{
		return (p1[0] * p1[0] + p1[1] * p1[1]) < (p2[0] * p2[0] + p2[1] * p2[1]);
	}
};

// Approach 1 using soring of vectors. This will take n + n Log n time.
vector<vector<int>> kClosestPointToOrigin(vector<vector<int>>& points, int nK)
{
	sort(points.begin(), points.end(), ComparePoints());
	vector<vector<int>> result;
	for (int i = 0; i < nK; i++)
	{
		result.push_back(points[i]);
	}
	return result;
}

// approach 2 uses Heapify n Log K is the time complexity here.
vector<vector<int>> kClosestPointToOriginUsingPQ(vector<vector<int>>& points, int nK)
{
	priority_queue<vector<int>, vector<vector<int>>, ComparePoints> pq;
	// After this loop the heap or PQ will hold K smallest elements
	for (vector<int>& pt : points)
	{
		if (pq.size() < nK)
		{
			// We'll store the fist K points
			pq.push(pt);
		}
		else
		{
			// Checking every incoming points and sending only the min value points
			// We compare which the maximum: the root of this priority queue or the incoming point.
			// we'll discard the maximum and push the minimum of the two in the comparison.
			const vector<int>& top = pq.top();
			// Cmpute the dist of top from pq.
			int d1 = top[0] * top[0] + top[1] * top[1];
			// Compute the dist of incoming point
			int d2 = pt[0] * pt[0] + pt[1] * pt[1];
			// discard the max of the two and push the min val.
			if (d1 > d2)
			{
				pq.pop();
				pq.push(pt);
			}
		}
	}
	vector<vector<int>> result;
	// Now take the elemetns from pq and push inside the returning result vector.
	while (!pq.empty())
	{
		result.push_back(pq.top());
		pq.pop();
	}
	return result;
}


// Group anagrams 
/*
* 49. Group Anagrams
https://leetcode.com/problems/group-anagrams/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) {

	vector<vector<string>> res;
	unordered_map<string, vector<string>> mp;

	for (auto s : strs)
	{
		string curr = s;
		sort(curr.begin(), curr.end());
		mp[curr].push_back(s);
	}

	for (auto i : mp)
		res.push_back(i.second);

	return res;

}
int groupAnagramsNew(vector<string>& strs) {

	vector<vector<string>> res;
	unordered_map<string, vector<string>> mp;
	unordered_map<string, int> mpCountOfanagram;
	int nLargestCountOfAnagram = INT_MIN;

	for (auto s : strs)
	{
		string curr = s;
		sort(curr.begin(), curr.end());
		mp[curr].push_back(s);
		mpCountOfanagram[curr] += 1;
		nLargestCountOfAnagram = max(nLargestCountOfAnagram, mpCountOfanagram[curr]);
	}

	for (auto i : mp)
		res.push_back(i.second);

	return 0;

}

//void computeLPSArray(char* pat, int M, int* lps);
// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(string pat, int M, vector<int>& lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
// Prints occurrences of txt[] in pat[]
void KMPSearch(string pat, string txt)
{
	int M = pat.size();
	int N = txt.size();

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	vector<int> lps(M);

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}


int FindIfExtendedPalindrome(string strInput)
{
	string strTemp = strInput;
	reverse(strTemp.begin(), strTemp.end());
	if (strInput == strTemp)
		return 1;
	else
	{
		for (int i = 0; i < strInput.size(); i++)
		{
			for (int j = 0; i < strInput.size(); j++)
			{
				//KMPSearch(strInput, strInput.begin() + i);
			}
		}
	}
}

/*
* 953. Verifying an Alien Dictionary
https://leetcode.com/problems/verifying-an-alien-dictionary/
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order.The order of the alphabet is some permutation of lowercase letters.
Given a sequence of words written in the alien language, and the order of the alphabet, return true ifand only if the given words are sorted lexicographically in this alien language.

EXample 1:
Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Example 2:
Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Example 3:
Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.)
According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

*/
bool checkLexicalOrderSorting(const string& str1, const string& str2, unordered_map<char, int>  letterRank)
{
	int nSize = min(str1.size(), str2.size());

	for (int i = 0; i < nSize; i++)
	{
		int nCurrCharRankS1 = letterRank[str1[i]];
		int nCurrCharRankS2 = letterRank[str2[i]];

		if (nCurrCharRankS1 == nCurrCharRankS1)
			continue;
		else if (nCurrCharRankS1 > nCurrCharRankS2)
			return false;
		else if (nCurrCharRankS1 < nCurrCharRankS2)
			return true;
	}

	if (str1.size() > str2.size())
		return false;
	return true;
}
bool isAlienLangwordsSorted(vector<string>& wordsList, string order)
{
	unordered_map<char, int> letterRank;
	int nRank = 0;
	for (const auto& letter : order)
	{
		letterRank[letter] = ++nRank;
	}
	for (int i = 0; i < wordsList.size() - 1; i++)
	{
		if (!checkLexicalOrderSorting(wordsList[i], wordsList[i + 1], letterRank))
			return false;
	}
	string strSample = " Very Good!";
	// strSample.
	//strSample.append()
	reverse(strSample.begin(), strSample.end());
	return true;
}

/*
* One Edit Distance
* https://leetcode.com/problems/one-edit-distance/
* Look at the solution section for better expanation.
Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

A string s is said to be one distance apart from a string t if you can:

Insert exactly one character into s to get t.
Delete exactly one character from s to get t.
Replace exactly one character of s with a different character to get t.

ex:
Input: s = "ab", t = "acb"
Output: true
*/

bool isOneEditDistance(string s, string t) {
	int nSizeOfS = s.size();
	int nSizeOfT = t.size();

	// ensure that s is less than t.
	if (nSizeOfS > nSizeOfT)
		return isOneEditDistance(t, s);

	// length of difference of characters cant be more than 2.
	if (abs(nSizeOfS - nSizeOfT) > 1)
		return false;

	// If the difference in length is 1 and all chars match until nth char of s then last char will differ.
	// Which is 1 edit dist away.
	// If all chars match until ith char and then there are 2 cases.
	for (int i = 0; i < nSizeOfS; i++)
	{
		// If all chars until ith char matches
		if (s[i] != t[i])
		{
			// Check if length of the string is same.
			if (nSizeOfS == nSizeOfT)
			{
				// if length matches then the remaining substring of s and t should match as well.
				// Which mean only difference is ith non matching char. For Ex: abXde != abdde (In this case only a substitute of a char would have happened).
				return (s.substr(i + 1) == t.substr(i + 1));
			}
			else
			{
				// control came here means already there is 1 mistmatch in char at ith location.
				// Now the reminder of the chars should match.
				// for string s substring should match from i while for t it should match from i + 1 to n + th character.
				// For EX: abcdef != abcXdef here t string is longer.
				return (s.substr(i) == t.substr(i + 1));
			}
		}
	}
	// If s + 1 size is same as t size then its 1 edit dist away.
	return (nSizeOfS + 1 == nSizeOfT);

}


/*
* 242. Valid Anagram
* https://leetcode.com/problems/valid-anagram/
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Input: s = "anagram", t = "nagaram"
Output: true

Input: s = "rat", t = "car"
Output: false
*/
// input 1:- strInput   - Contains string1
// input 2: strAnagram  -- Contains anagram of string 1.
bool isAnagram(string strInput, string strAnagram)
{
	vector<int> strCharMap(26);
	if (strInput.empty() && strAnagram.empty())
		return true;
	if (strInput.empty() || strAnagram.empty())
		return false;
	if (strInput.size() != strAnagram.size())
		return false;
	for (int i = 0; i < strAnagram.size(); i++)
	{
		strCharMap[strAnagram[i] - 'a']++;
		strCharMap[strInput[i] - 'a']--;
	}
	for (int elem : strCharMap)
	{
		if (elem != 0)
		{
			return false;
		}
	}
	return true;

}

// Multiply strings
vector<char> multiplyStrings(string strNum1, string strNum2)
{
	if (strNum1 == "0" || strNum2 == "0")
		return { '0' };
	reverse(strNum1.begin(), strNum1.end());
	reverse(strNum2.begin(), strNum2.end());

	int nTotalNumDigit = strNum1.size() + strNum2.size();
	vector<char> strRetAnswer(nTotalNumDigit, '0');

	for (int nPlaceValNum2 = 0; nPlaceValNum2 < strNum2.size(); nPlaceValNum2++)
	{
		int nCurrPlaceVal2Digit = strNum2[nPlaceValNum2] - '0';

		for (int nPlaceValNum1 = 0; nPlaceValNum1 < strNum1.size(); nPlaceValNum1++)
		{
			int nCurrPlaceVal1Digit = strNum1[nPlaceValNum1] - '0';

			int nNumOfZeroes = nPlaceValNum1 + nPlaceValNum2;
			// What was added as carry in the previous computation is picked here intuitively.
			// HEre we are extracting carry from previous computation and sum it with current multiplication result.
			int nCarry = strRetAnswer[nNumOfZeroes] - '0';
			int nMultiplication = nCurrPlaceVal1Digit * nCurrPlaceVal2Digit + nCarry;
			strRetAnswer[nNumOfZeroes] = (nMultiplication % 10) + '0';
			// HEre the += is for appending.
			strRetAnswer[nNumOfZeroes + 1] += (nMultiplication / 10) + '0';
		}
	}
	if (strRetAnswer.back() == '0')
	{
		strRetAnswer.pop_back();
	}
	reverse(strRetAnswer.begin(), strRetAnswer.end());

	return strRetAnswer;
}
// Multiply strings
string multiplyStringsNew(string strNum1, string strNum2)
{
	if (strNum1 == "0" || strNum2 == "0")
	{
		return false;
	}
	vector<int> nResultNum(strNum1.size() + strNum2.size(), 0);

	for (int i = 0; i < strNum1.size(); i++)
	{
		for (int j = 0; j < strNum2.size(); j++)
		{
			nResultNum[i + j + 1] = (strNum1[i] - '0') * (strNum2[j] - '0');
			nResultNum[i + j] += nResultNum[i + j + 1] / 10;
			nResultNum[i + j + 1] = nResultNum[i + j + 1] % 10;
		}
	}
	int i = 0;
	while (i < nResultNum.size() && nResultNum[i] == 0)
		i++;
	string strResult;
	while (i < nResultNum.size())
		strResult += (char)(nResultNum[i++] + '0');

	return strResult;
}


// find anagrams 

/*
* https://leetcode.com/problems/find-all-anagrams-in-a-string/
* https://www.youtube.com/watch?v=fYgU6Bi2fRg&t=467s
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/

// The critical logic in this algorithm is to keep 2 pointer and starting it from same location
// 
vector<int> findAnagramPlacements(string strSentence, string strPattern)
{
	vector<int> nIdxOfAnagrams;
	int nSizeSentence = strSentence.size();
	int nSizePatt = strPattern.size();

	vector<int> patterHash(26, 0);
	vector<int> hashOfChars(26, 0);

	if (nSizeSentence < nSizePatt)
		return nIdxOfAnagrams;
	int nLeft = 0;
	int nRight = 0;
	// Here in this loop while filling the pattern in the pattern hash
	// nHashOfChars will try to fill whatever char it is able to find in the sentence.
	while (nRight < nSizePatt)
	{
		patterHash[strPattern[nRight] - 'a'] += 1;
		hashOfChars[strSentence[nRight] - 'a'] += 1;
		nRight++;
	}
	// Array is 0 based index.
	nRight -= 1;
	// In this loop the nHashOfChars is compared with patternHash 
	// If it is found then the location of anagram is pushed inside return list.
	// If not then the window is moved towards right direction to find anagram.
	// Right window starts from the length of pattern size. Left window starts from the 0th index.
	while (nRight < nSizeSentence)
	{
		// As and when pattern is found 
		if (patterHash == hashOfChars)
			nIdxOfAnagrams.push_back(nLeft);
		nRight++;
		if (nRight != nSizeSentence)
		{
			// Moving window in right direction to explore and check anagram
			hashOfChars[strSentence[nRight] - 'a'] += 1;
		}
		// Removing old chars to accomodate new chars in the window.
		hashOfChars[strSentence[nLeft] - 'a'] -= 1;
		// We are maintaining the first window in the left pointer.
		// When we expand the right window the left window should be contracted.
		nLeft++;
	}
	return nIdxOfAnagrams;
}


/*
Given a string str and an integer K, the task is to check whether the given string is K-periodic.
A string is k-periodic if the string is a repetition of the sub-string str[0 … k-1] i.e. the string “ababab” is 2-periodic.
Print Yes if the given string is k-periodic, else print No.

Input: str = “geeksgeeks”, k = 5
Output: Yes
Given string can be generated by repeating the prefix of length k i.e. “geeks”

Input: str = “geeksforgeeks”, k = 3
Output: No
*/
bool isPrefix(string strInput, int nLenOfTotalStr, int nLenOfFistWind, int nK)
{
	if (nLenOfFistWind + nK > nLenOfTotalStr)
		return false;
	for (int j = 0; j < nK; j++)
	{
		// here j is starting from first character of first wind.
		// nLenOfFistWind is starting from first character of second wind
		if (strInput[nLenOfFistWind] != strInput[j])
			return false;
		nLenOfFistWind++;
	}
	return true;
}

bool isPeriodic(string strInput, int nLenOfString, int nK)
{
	// Check in every window if the characters are matching.
	// We are initializing the loop with size of window and for every loop
	// we are ofsetting the window size until size is less than length of string.
	for (int i = nK; i < nLenOfString; i += nK)
	{
		if (!isPrefix(strInput, nLenOfString, i, nK))
			return false;
	}
	return true;
}


/*
Given a string s, return true if a permutation of the string could form a palindrome.
https://leetcode.com/problems/palindrome-permutation/
in any planidromic string of even length all characters will have even number of occurences.
In any palindromic string of odd length, the middle chracter will occur only once and all the remaining characters have occureces of even number.
https://www.youtube.com/watch?v=edluuHln06g
*/

bool canBePermutedPalindrome(string inputString) {
	vector<int> palindromicCharMap(128);

	for (int i =0; i<inputString.size(); i++)
	{
		palindromicCharMap[inputString[i]]++;
	}
	int nMidCharCount = 0;
	for (int i = 0; i < palindromicCharMap.size() && nMidCharCount <= 1; i++)
	{
		if (palindromicCharMap[i] % 2 != 0)
		{
			nMidCharCount++;
		}
	}
	return (nMidCharCount <= 1);
}

/*
Leetcode: Valid Word Square
Given an array of strings words, return true if it forms a valid word square.

A sequence of strings forms a valid word square if the kth row and column read the same string, where 0 <= k < max(numRows, numColumns).

Input: words = ["abcd","bnrt","crmy","dtye"]
Output: true
Explanation:
The 1st row and 1st column both read "abcd".
The 2nd row and 2nd column both read "bnrt".
The 3rd row and 3rd column both read "crmy".
The 4th row and 4th column both read "dtye".
Therefore, it is a valid word square.

EX: 2
Input: words = ["abcd","bnrt","crm","dt"]
Output: true
Explanation:
The 1st row and 1st column both read "abcd".
The 2nd row and 2nd column both read "bnrt".
The 3rd row and 3rd column both read "crm".
The 4th row and 4th column both read "dt".
Therefore, it is a valid word square.

Ex: 3
Input: words = ["ball","area","read","lady"]
Output: false
Explanation:
The 3rd row reads "read" while the 3rd column reads "lead".
Therefore, it is NOT a valid word square.
*/

bool validWordSquare(vector<string>& words) {
	int nRows = words.size();
	for (int nRowCell = 0; nRowCell < nRows; nRowCell++)
	{
		for (int nColCell = 0; nColCell < words[nRowCell].size(); nColCell++)
		{
			if (nColCell >= nRows || nRowCell >= words[nColCell].size() || words[nColCell][nRowCell] != words[nRowCell][nColCell])
				return false;
		}
	}
	return true;
}
/*
* 680. Valid Palindrome II
https://leetcode.com/problems/valid-palindrome-ii/

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:
Input: s = "aba"
Output: true

Example 2:
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:
Input: s = "abc"
Output: false
*/
// Algorithm to check if the given string can be a palindrome if we can remove atmost 1 character of the characters.
// To solve this problem we need to iterate the string in both direction and check if every character is matching or not
// For the first non matching character, try and remove the characters (either do i+1 which moves to right dir. in beginning or j-1 which moves to left direction from the end.)
// Valid Palindrome II --> Leetcode
// https://www.youtube.com/watch?v=NCJH42La_cU
bool isPalindrome(string strInput, int nLeft, int nRight)
{
	if (nRight < nLeft)
		return false;
	while (nLeft < nRight)
	{
		if (strInput[nLeft++] != strInput[nRight--])
		{
			return false;
		}
	}
	return true;
}
// To Solve this problem, use 2 pointer approach.
// Approach string from both the ends in a loop.
// As the string is 1 edit dist away from palindrome,
// Check for unmatching char in the string.
// The moment we find unmatching char, we try to not include that char and 
// Check if reminder of the string is palindrome or not.
bool isValidPalindrome(string strInput)
{
	if (strInput.empty())
		return true;
	int nLow = 0;
	int nHigh = strInput.size() - 1;

	while (nLow < nHigh)
	{
		if (strInput[nLow] != strInput[nHigh])
		{
			// Confirming if palindrome is just 1 edit distance away.
			return isPalindrome(strInput, nLow + 1, nHigh) || isPalindrome(strInput, nLow, nHigh - 1);
		}
		nLow++;
		nHigh--;
	}
	return true;
}


/*
* https://leetcode.com/problems/custom-sort-string/
You are given two strings order and s. All the words of order are unique and were sorted in some custom order previously.

Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, 
then x should occur before y in the permuted string.

Return any permutation of s that satisfies this property.
*/
// In this problem, Order is the string in which the sorting order of position of characters are defined.
// In reference to that we need to jumble the string to make the order similar as the inputOrder string.
// Step 1: use a char map to record the frequence of characters in the string to be sorted.
// Step 2: Now based on the order use the recorded Frequecy to check the overlapping characters and their index reference in order string push the char into answer and reduce count in freq.
// Step 3: Now all the remaining characters should be pushed into answer reducing the freq. (remember that raining characters can have more freq).
string customSortString(string order, string s) {
	vector<int> charMapFreq;
	for (char c : s)
	{
		charMapFreq[c - 'a'] += 1;
	}
	string strAnswer;
	for (char cVal : order)
	{
		// Sane char could have more freq, hence loop is required.
		// Based on the frequency of the characters in the order string, construct the answer string.
		while (charMapFreq[cVal - 'a'] > 0)
		{
			strAnswer += cVal;
			charMapFreq[cVal - 'a'] -= 1;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		int nFreq = charMapFreq[i];
		while (nFreq > 0)
		{
			strAnswer += ((char)(i + 'a'));
			nFreq--;
		}
	}

	return strAnswer;
}

/*
A bracket is any of the following characters: (, ), {, }, [, or ].
We consider two brackets to be matching if the first bracket is an open-bracket, e.g., (, {, or [, and the second bracket is a close-bracket of the same type. That means ( and ), [ and ], and { and } are the only pairs of matching brackets.
Furthermore, a sequence of brackets is said to be balanced if the following conditions are met:
The sequence is empty, or
The sequence is composed of two or more non-empty sequences, all of which are balanced, or
The first and last brackets of the sequence are matching, and the portion of the sequence without the first and last elements is balanced.
You are given a string of brackets. Your task is to determine whether each sequence of brackets is balanced. If a string is balanced, return true, otherwise, return false


In leet code it is below problem
Valid Parentheses
https://leetcode.com/problems/valid-parentheses/
*/

bool isParanthesesBalanced(string strInput)
{
	map<char, char> mapOfParanthesesBalancer;
	mapOfParanthesesBalancer['}'] = '{';
	mapOfParanthesesBalancer[')'] = '(';
	mapOfParanthesesBalancer[']'] = '[';

	stack<char> stkParanthesesBalancer;

	for (int i = 0; i < strInput.size(); i++)
	{
		char cCurrVal = strInput[i];
		if (mapOfParanthesesBalancer.find(cCurrVal) != mapOfParanthesesBalancer.end())
		{
			// We are trying to match equivalent open parantheses for the current closed parantheses.
			char cTopVal = stkParanthesesBalancer.empty() ? '#' : stkParanthesesBalancer.top();
			// If the corresponding open parantheses not found for the closed parantheses then there is imbalance.
			if (mapOfParanthesesBalancer[cCurrVal] != cTopVal)
			{
				return false;
			}
			stkParanthesesBalancer.pop();
		}
		else
		{
			// Here all the first half of parantheses are stored.
			stkParanthesesBalancer.push(cCurrVal);
		}
	}
	// Its balanced only when its empty.
	return stkParanthesesBalancer.empty();
}

/*
* 1249. Minimum Remove to Make Valid Parentheses
* https://www.youtube.com/watch?v=EE_9U798nvQ&list=RDCMUC9fDC_eBh9e_bogw87DbGKQ&start_radio=1
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
*/

bool isBalancedBrackets(string strInput)
{
	int nBracketBalance = 0;
	for (char eachBrack : strInput)
	{
		if (eachBrack == '(')
			nBracketBalance++;
		else if (eachBrack == ')')
			nBracketBalance--;
		// Handling more or less brackets.
		if (nBracketBalance < 0)	// This logic will handle the missing bracket or too much bracket scenario.
			return false;
	}
	// Only if nCount is 0 then the parantheses is balanced.
	return nBracketBalance == 0;
}

string minRemoveToMakeValid(string s) {
	vector<string> collectionOfBalancedParanth;
	map<string, bool> mapOfVisitedParanthStr;
	queue<string> qListOfValidBracketPairs;
	qListOfValidBracketPairs.push(s);
	int nBalancedParathFound = 0;
	while (!qListOfValidBracketPairs.empty())
	{
		string strCurrParanthesesPairs = qListOfValidBracketPairs.front();
		qListOfValidBracketPairs.pop();
		if (mapOfVisitedParanthStr[strCurrParanthesesPairs])
			continue;
		mapOfVisitedParanthStr[strCurrParanthesesPairs] = true;
		if (isBalancedBrackets(strCurrParanthesesPairs))
		{
			nBalancedParathFound = 1;
			collectionOfBalancedParanth.push_back(strCurrParanthesesPairs);
		}
		if (nBalancedParathFound)
			continue;	// The reamaining logic is for parantheses correction which is not needed for balanced parantheses.
		// This loop is to modify the string and generate different combinations of parantheses
		// This different combinations of modified parantheses order can then be inspected after pushing inside queue.
		for (int i = 0; i < strCurrParanthesesPairs.size(); i++)
		{
			// We need to modify only the brackets in the string. igonore other characters
			string strModifiedParathStr = strCurrParanthesesPairs.substr(0, i) + strCurrParanthesesPairs.substr(i + 1, strCurrParanthesesPairs.size());
			// This modified collection can then be verified for balance and if found balance add in the balanced collection.
			qListOfValidBracketPairs.push(strModifiedParathStr);
		}
	}
	return collectionOfBalancedParanth[0];
}

/*
1249. Minimum Remove to Make Valid Parentheses
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
*/

string minRemoveToMakeValidParantheses(string s)
{
	int nOpenBrFoundInStr = 0;
	int nBalanceTracker = 0;
	string sb;
	// This loop will predominantly focus on removing extra ')'
	for (int i = 0; i < s.size(); i++)
	{
		char nCurrChar = s[i];
		if (nCurrChar == '(')
		{
			nOpenBrFoundInStr++;
			nBalanceTracker++;
		}
		else if (nCurrChar == ')')
		{
			// nBalanceTracker will be when all open brackets are matched or when there was no open bracket 
			// When there was a closed br without a amtching open br.
			if (nBalanceTracker == 0)
				continue;
			nBalanceTracker--;
		}
		// When there is extra right bracket its not even included here (the last ')' will not be added in final string).
		// when there is extra '(' then it is added and included in this string however nCountOfOpenBrsToKeep = nOpenBrFoundInStr - nBalanceTracker; will help
		// us determine how many '(' to keep.
		sb += nCurrChar;
	}
	string strBalancedBrsResult;
	int nCountOfOpenBrsToKeep = nOpenBrFoundInStr - nBalanceTracker;

	// this loop is to remove extra '('
	for (int i = 0; i < sb.size(); i++)
	{
		char cCurrChar = sb[i];
		if (cCurrChar == '(')
		{
			nCountOfOpenBrsToKeep--;
			// nCountOfOpenBrsToKeep = nOpenBrFoundInStr - nBalanceTracker; using this equation we are able to eliminated or not added to strResult the extra '(' in the last is excluded.
			if (nCountOfOpenBrsToKeep < 0)
				continue;
		}

		strBalancedBrsResult += cCurrChar;
	}
	return strBalancedBrsResult;
}

/*
* 32. Longest Valid Parentheses
* https://leetcode.com/problems/longest-valid-parentheses/
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
*/
// to solve this problem we can count the open and closed br
// We need to coulnt num of extra open brs and num of extra closed brs.


int longestValidParentheses(string strInput) {

	int nOpenBrCount = 0;
	int nClosedBrCount = 0;
	int nMaxValidPars = 0;
	for (int i = 0; i < strInput.size(); i++)
	{
		char cCurrChar = strInput[i];
		if (cCurrChar == '(')
		{
			nOpenBrCount++;
		}
		else
		{
			nClosedBrCount++;
		}
		if (nOpenBrCount == nClosedBrCount)
		{
			// Remember the nOpenBrCount and nClosedBrCount has the length so far.
			int nLenOfValidPar = nOpenBrCount + nClosedBrCount;
			nMaxValidPars = max(nMaxValidPars, nLenOfValidPar);
		}
		else if (nClosedBrCount > nOpenBrCount)
		{
			nOpenBrCount = nClosedBrCount = 0;
		}
	}
	nOpenBrCount = nClosedBrCount = 0;
	for(int i = strInput.size() - 1; i >= 0; i--)
	{
		char cCurrChar = strInput[i];
		if (cCurrChar == '(')
		{
			nOpenBrCount++;
		}
		else
		{
			nClosedBrCount++;
		}
		if (nOpenBrCount == nClosedBrCount)
		{
			// Remember the nOpenBrCount and nClosedBrCount has the length so far.
			int nLenOfValidPar = nOpenBrCount + nClosedBrCount;
			nMaxValidPars = max(nMaxValidPars, nLenOfValidPar);
		}
		else if (nOpenBrCount > nClosedBrCount)
		{
			nOpenBrCount = nClosedBrCount = 0;
		}
	}
	return nMaxValidPars;

}


// the below algorithm tries to find the maximum length of valid bracket pairs.
// We need to use 2 loops. First loop will move from left to right and check if count of open bracket == closed bracket.
// if so then record the len of valid pairs. and get the nMaxValidPairs by using the max operation on these 2 vars.
// We need 2 similar loops only difference between then would be that first loop should check for extra closed bracket size more than open br and reset the br counts to 0.
// the second loop will check for extra open br. size more than closed br. and reset the br count top 0.
// in botht the loops we need to record the open and closed br counts.
// then check if both are equal then record the len of valid brs.
// 
int findMaxLenOfValidBrackets(string strInput)
{
	int nOpenBrCount = 0;
	int nClosedBrCount = 0;
	int nMaxValidPairsOfBr = 0;
	for (int i = 0; i < strInput.size(); i++)
	{
		if (strInput[i] == '(')
		{
			nOpenBrCount++;
		}
		else 
		{
			nClosedBrCount++;
		}
		if (nOpenBrCount == nClosedBrCount)
		{
			int nLenOfValidBrPairs = nOpenBrCount + nClosedBrCount;
			nMaxValidPairsOfBr = max(nLenOfValidBrPairs, nMaxValidPairsOfBr);
		}
		else if (nClosedBrCount > nOpenBrCount )	// when iterating from left to right check for more close br count.
		{
			nOpenBrCount = nClosedBrCount = 0;
		}
	}
	nOpenBrCount = nClosedBrCount = 0;
	for (int i = strInput.size() - 1; i >= 0; i--)
	{
		if (strInput[i] == '(')
		{
			nOpenBrCount++;
		}
		else
		{
			nClosedBrCount++;
		}
		if (nOpenBrCount == nClosedBrCount)
		{
			int nLenOfValidBrPairs = nOpenBrCount + nClosedBrCount;
			nMaxValidPairsOfBr = max(nLenOfValidBrPairs, nMaxValidPairsOfBr);
		}
		else if (nOpenBrCount > nClosedBrCount)			// When iterating from right to left check for more number for open br count.
		{
			nOpenBrCount = nClosedBrCount = 0;
		}
	}
	return nMaxValidPairsOfBr;
}


// RegEx Samples
vector<string> splitStringOnForwardSlash(string path) {
	vector<string> elements;
	string rgx_str = "/+";

	regex rgx(rgx_str);

	sregex_token_iterator iter(path.begin(), path.end(), rgx, -1);
	sregex_token_iterator end;

	while (iter != end) {
		elements.push_back(*iter);
		++iter;
	}

	return elements;
}

string simplifyPath(string path) {
	//complete this code return the simplified path
	string res;
	vector<string> tokens = splitStringOnForwardSlash(path);
	vector<string> stk;

	for (auto token : tokens) {
		if (!stk.empty() && token == "..")
			stk.pop_back();
		if (!(token == "." || token == ".." || token == ""))
			stk.push_back(token);
	}

	for (auto word : stk)
		res += "/" + word;

	return res.length() ? res : "/";
}

/*
* https://leetcode.com/problems/word-search/
* Word Search
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
*/

// This problem can be solved by back tracking or DFS.
// We need to first match the starting character of the word and from there we need to touch the neighbouring cell and check if all the characters in the word is matched.
// To avoid visiting the same cell agian mark the cell with '#' character, but before marking dont forget to get the curr char so that it can be set again after dfs.
// as usual boundary conditions needs to be checked.
// One extra condition here is that check of curr offset is the length of word.

bool DFSDeepSearchWords(vector<vector<char>>& board, int rCell, int cCell, int nWordLenCount, string word)
{
	int nRows = board.size();
	int nCols = board[0].size();
	if (rCell < 0 || rCell >-nRows || cCell < 0 || cCell >= nCols || board[rCell][cCell] != word[nWordLenCount])
		return false;
	char cCurrCellVal = board[rCell][cCell];
	board[rCell][cCell] = '#';
	bool bReturnVal = DFSDeepSearchWords(board, rCell + 1, cCell, nWordLenCount + 1, word) || DFSDeepSearchWords(board, rCell - 1, cCell, nWordLenCount + 1, word) || DFSDeepSearchWords(board, rCell, cCell + 1, nWordLenCount + 1, word) || DFSDeepSearchWords(board, rCell, cCell - 1, nWordLenCount + 1, word);
	board[rCell][cCell] = cCurrCellVal;
	return bReturnVal;
}

bool checkIFWordExists(vector<vector<char>>& board, string word)
{
	int nRows = board.size();
	int nCols = board[0].size();
	int nWordLenCount = 0;
	for (int rCell = 0; rCell < nRows; rCell++)
	{
		for (int cCell = 0; cCell < nCols; cCell++)
		{
			if (board[rCell][cCell] == word[0] && DFSDeepSearchWords(board, rCell, cCell, nWordLenCount, word))
			{
				return true;
			}
		}
	}
	return false;
}




/*
* https://leetcode.com/problems/toeplitz-matrix/
Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
*/
/*
{	{1,2,3,4},
	{5,1,2,3},
	{9,5,1,2}
}
*/
bool isToeplitzMatrix(vector<vector<int>>& inputMatrix) {
	for (int r = 0; r < inputMatrix.size(); r++)
	{
		for (int c = 0; c < inputMatrix[0].size(); c++)
		{
			if (r > 0 && c > 0 && inputMatrix[r - 1][c - 1] != inputMatrix[r][c])
				return false;
		}
	}
	return true;
}

/*
* // https://www.youtube.com/watch?v=ZQMJ1mrmhKo
* https://leetcode.com/problems/island-perimeter/
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, 
and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. 
The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
*/

int islandPerimeter(vector<vector<int>>& grid) {
	int nRows = grid.size();
	int nCols = grid[0].size();
	int nPerimeter = 0;
	for (int r = 0; r < nRows; r++)
	{
		for (int c = 0; c < nCols; c++)
		{
			if (grid[r][c] == 1)
			{
				nPerimeter += 4;
				if (r > 0 && grid[r - 1][c] == 1)
					nPerimeter -= 2;
				if (c > 0 && grid[r][c - 1] == 1)
					nPerimeter -= 2;
			}
		}
	}
	return nPerimeter;
}

/*
https://leetcode.com/problems/max-area-of-island/
695. Max Area of Island

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
*/

// This problem ca be solved by using DFS technique.
// We need to iterate through the rows and cols of the matrix and deep search the islands only
// when we find currCell == 1 in the loop. 
// Make sure to check the max size returned from the deep search function and compare witht he current
// island area. this will ensure in finding the largest islabd area.

int deepSearchTheIslandArea(vector<vector<int>>& gridInput, int nRCell, int nCCell)
{
	int nRows = gridInput.size();
	int nCols = gridInput[0].size();

	if (nRCell < 0 || nRCell > nRows || nCCell < 0 || nCCell > nCols || gridInput[nRCell][nCCell] != 1)
		return 0;

	gridInput[nRCell][nCCell] = 2;

	return (1 + deepSearchTheIslandArea(gridInput, nRCell + 1, nCCell) + deepSearchTheIslandArea(gridInput, nRCell - 1, nCCell) + deepSearchTheIslandArea(gridInput, nRCell, nCCell + 1) + deepSearchTheIslandArea(gridInput, nRCell, nCCell - 1));
}

int findMaxAreaOfIsland(vector<vector<int>>& gridInput)
{
	int nRows = gridInput.size();
	int nCols = gridInput[0].size();
	int nMaxAreaOfIsland = 0;
	for (int nR = 0; nR < nRows; nR++)
	{
		for (int nC = 0; nC < nCols; nC++)
		{
			if (gridInput[nR][nC] == 1)
			{
				nMaxAreaOfIsland = max(nMaxAreaOfIsland, deepSearchTheIslandArea(gridInput, nR, nC));
			}
		}
	}
	return nMaxAreaOfIsland;
}

/*
* 694. Number of Distinct Islands
https://leetcode.com/problems/number-of-distinct-islands/

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Return the number of distinct islands.

Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
Output: 1

Input: grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
Output: 3
*/

// This problem is quite very similar to number of island problem and uses DFS.
// The only difference here, which makes this problem bit difficult and different is that, 
// We need to keep track of relative positions of each land amongs each land grouping, that way we can compare if the island is similar or not.
// For this purpose we need to build a string that tracks each land positions, we can then store this into a set.


// We need to use string value to track which direction currently the search is happening.
// X = start
// O = Out of bounds
// U = up
// D = down
// L = left
// R = right

string dfsFindUniqueLands(vector<vector<int>>& gridMatrix, int nRCell, int nCCell, int nRows, int nCols, string strDirection)
{
	if (nRCell < 0 || nRCell >= nRows || nCCell < 0 || nCCell >= nCols || gridMatrix[nRCell][nCCell] == 0)
		return "O";
	gridMatrix[nRCell][nCCell] = 0;

	string strLeft = dfsFindUniqueLands(gridMatrix, nRCell, nCCell - 1, nRows, nCols, "L");
	string strRight = dfsFindUniqueLands(gridMatrix, nRCell, nCCell + 1, nRows, nCols, "R");
	string strUp = dfsFindUniqueLands(gridMatrix, nRCell - 1, nCCell, nRows, nCols, "U");
	string strDown = dfsFindUniqueLands(gridMatrix, nRCell + 1, nCCell, nRows, nCols, "D");

	return strDirection + strLeft + strRight + strUp + strDown;

}
int findNumberOfDistinctIslands(vector<vector<int>>& gridMatrix)
{
	int nRows = gridMatrix.size();
	int nCols = gridMatrix[0].size();

	set<string> stUniqueLandGroupings;
	for (int nR = 0; nR < nRows; nR++)
	{
		for (int nC = 0; nC < nCols; nC++)
		{
			if (gridMatrix[nR][nC] == 1)
			{
				string trackerForUniqueLandMasses = dfsFindUniqueLands(gridMatrix, nR, nC, nRows, nCols, "X");
				stUniqueLandGroupings.insert(trackerForUniqueLandMasses);
			}
		}
	}
	return stUniqueLandGroupings.size();
}


string removeDuplicates(string & strInput)
{
	int i = 0;
	while (i < strInput.size())
	{
		if (strInput[i] == strInput[i + 1])
		{
			strInput.erase(i, 2);
			i = 0;
			continue;
		}
		i++;
	}
	return strInput;
}

/*
* 227. Basic Calculator II
* https://leetcode.com/problems/basic-calculator-ii/
Given a string s which represents an expression, evaluate this expression and return its value.

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().	
*/

int calculate(string strEquation)
{
	int nLen = strEquation.size();
	if (nLen == 0)
		return 0;
	stack<int> stckEquation;
	int nCurrNum = 0;
	char currOperation = '+';
	for (int i = 0; i < nLen; i++)
	{
		char cCurrChar = strEquation[i];
		// If current number is digit then just strore it in the nCurrNum.
		if (isdigit(cCurrChar))
		{
			nCurrNum = (nCurrNum * 10) + (cCurrChar - '0');
		}
		// If the current digit is not a number or a white space..
		if (!isdigit(cCurrChar) && !iswspace(cCurrChar) || i == nLen - 1)
		{
			// if the opertator is + then simply push inside stack.
			// If the operator is - then push as -ve number.
			// If the operator is '*' or '/' then we need to handle differently.
			// Remember to delay the process of updating currNum and currOperation.
			if (currOperation == '-')
			{
				stckEquation.push(-nCurrNum);
			}
			else if (currOperation == '+')
			{
				stckEquation.push(nCurrNum);
			}
			else if (currOperation == '*')
			{
				int nNumInStckTop = stckEquation.top();
				stckEquation.pop();
				stckEquation.push(nNumInStckTop * nCurrNum);
			}
			else if (currOperation == '/')
			{
				int nNumInStckTop = stckEquation.top();
				stckEquation.pop();
				stckEquation.push(nNumInStckTop / nCurrNum);
			}
			// if the current char is not a number then it has to be an operator.
			currOperation = cCurrChar;
			nCurrNum = 0;
		}
	}
	int nResult = 0;
	while (stckEquation.size() != 0)
	{
		nResult += stckEquation.top();
		stckEquation.pop();
	}
	return nResult;
}


/*
* 286. Walls and Gates
* https://leetcode.com/problems/walls-and-gates/
You are given an m x n grid rooms initialized with these three possible values.

-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Sample Input

INF  -1   0   INF
INF  INF INF  -1
INF  -1  INF  -1
 0   -1  INF  INF
*/
// This problem can be solved by DFS
// Step 1: find and mark the gates. Iterate through every cell and check if current cell is gate.
// Step 2: If so then mark a default distance. Do this inside new function DFS.
// Step 3: This DFS function takes care of chekcing the boundaries of the matrix and also checks if the current cell is wall or gate.
// Step 4: After validation all the corner cases now mark the current cell if the current distance is higher than marked dist.
// Step 5: Now explore the neighbouring cells of the cell after incrementing the current distance. 

// Idea: To mark the distance to the gate. We need to first go the gate cells and from there start filling the neighbouring cells distances

void DFSearchDistFromGate(vector<vector<int>>& matrixRooms, int nRows, int nCols, int nRowCell, int nColCell, int nCurrDist)
{
	if (nRowCell < 0 || nRowCell > nRows || nColCell < 0 || nColCell > nCols || matrixRooms[nRowCell][nColCell] == 0 || matrixRooms[nRowCell][nColCell] == -1)
	{
		return;
	}
	if (matrixRooms[nRowCell][nColCell] > nCurrDist)
	{
		matrixRooms[nRowCell][nColCell] = nCurrDist;
		DFSearchDistFromGate(matrixRooms, nRows, nCols, nRowCell + 1, nColCell, nCurrDist + 1);
		DFSearchDistFromGate(matrixRooms, nRows, nCols, nRowCell, nColCell + 1, nCurrDist + 1);
		DFSearchDistFromGate(matrixRooms, nRows, nCols, nRowCell - 1, nColCell, nCurrDist + 1);
		DFSearchDistFromGate(matrixRooms, nRows, nCols, nRowCell, nColCell - 1, nCurrDist + 1);
	}
}

void wallsAndGate(vector<vector<int>>& matrixRooms)
{
	int nRows = matrixRooms.size();
	int nCols = matrixRooms[0].size();

	for (int nRowCell = 0; nRowCell < nRows; nRowCell++)
	{
		for (int nColCell = 0; nColCell < nCols; nColCell++)
		{
			if (matrixRooms[nRowCell][nColCell] == 0)
			{
				DFSearchDistFromGate(matrixRooms, nRows, nCols, nRowCell, nColCell, 1);
			}
		}
	}
}


/*
Diagonal traverse
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
*/
// When solving this problem first start thinking on the longest diagonal.
// When priting longest diagonal we'll decrease the row and increment the column.
// when the last column is reached we can not go to any other cell.
// The only possibility is to move to the down cell.




/*
* 1865. Finding Pairs With a Certain Sum
https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
https://www.youtube.com/watch?v=6uvsmkvxGw0
https://www.youtube.com/watch?v=aRh53-jCZZI&t=3s
One of the tough proiblems
You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

Add a positive integer to an element of a given index in the array nums2.
Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
Implement the FindSumPairs class:

FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.
*/

class FindSumPairs {
	vector<int> one, two;
	unordered_map<int, int> mp;
public:
	FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
		one = nums1;
		two = nums2;
		for (auto& it : two)
		{
			mp[it]++;
		}
	}

	void add(int index, int val) {
		mp[two[index]]--;
		two[index] += val;
		mp[two[index]]++;
	}

	int count(int tot) {
		int count = 0;
		for (int& j : one) {
			count += mp[tot - j];
		}
		return count;
	}
};
// Here is the fuction only for the above problem statement
int numberOfWays(vector<int>& arr, int k)
{
	// Write your code here
	unordered_map<int, int> m;
	int n = arr.size();
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (m.find(k - arr[i]) != m.end()) {
			count += m[k - arr[i]];
		}
		m[arr[i]]++;
	}
	return count;
}


/*
* https://leetcode.com/problems/remove-duplicates-from-sorted-array/
26.Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. 
More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. 
It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
	assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.
*/
// As per the problem statement we should not allocate extra memory
// We should not modify the given array.
// We need to reuse the same array given to us.
// The final array should not have duplicates.
int removeDuplicatesFromGivenArr(vector<int> nInputArr)
{
	int nIdx = 0;
	if (nInputArr.empty())
		return 0;
	for (int j = 1; j < nInputArr.size(); j++)
	{
		if (nInputArr[nIdx] != nInputArr[j])
		{
			// Onl;y when next element is not matching we are moving forward.
			nIdx++;
		}

		nInputArr[nIdx] = nInputArr[j];
	}
	nInputArr.erase(nInputArr.begin() + nIdx + 1, nInputArr.end());

	return nIdx + 1;
}

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

// to solve this problem first maintain a maxProfit var and initialize as 0
// and minPrice var and intitalize as INT_MAX.
// Not for every price val in the arr check if curr val is less than min price if so update minPrice.
// else compute price[i] - minPrice > maxProfit.


int maxProfit(vector<int>& prices) 
{
	int nMaxProfit = 0;
	int nMinPrice = INT_MAX;

	for (int i = 0; i < prices.size(); i++)
	{
		if (prices[i] < nMinPrice)
		{
			// When less price is found that needs to be registered.
			nMinPrice = prices[i];
		}
		else if(nMaxProfit < prices[i] - nMinPrice)
		{
			// In all other scenarios this computation should happen
			nMaxProfit = prices[i] - nMinPrice;
		}
	}
	return nMaxProfit;
}


/*
* Product of Array Except Self
https://leetcode.com/problems/product-of-array-except-self/solution/
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/
vector<int> productExceptSelf(vector<int>& nums) 
{
	int nSize = nums.size();
	// Final answer array to be returned
	vector<int> nAnswer(nSize);
	// answer[i] contains the product of all the elements to the left
	// Note: for the element at index '0', there are no elements to the left,
	// so the answer[0] would be 1
	nAnswer[0] = 1;
	int nRet = 1;
	for (int i = 1; i < nSize; i++)
	{
		// answer[i - 1] already contains the product of elements to the left of 'i - 1'
		// Simply multiplying it with nums[i - 1] would give the product of all 
		// elements to the left of index 'i'
		nAnswer[i] = nums[i - 1] * nAnswer[i - 1];
	}
	// R contains the product of all the elements to the right
	// Note: for the element at index 'length - 1', there are no elements to the right,
	// so the R would be 1
	for (int i = nSize - 1; i >= 0; i--)
	{
		// For the index 'i', R would contain the 
		// product of all elements to the right. We update R accordingly
		nAnswer[i] = nRet * nAnswer[i];
		nRet *= nums[i];
	}
	return nAnswer;
}

/*
* Container With Most Water
* https://leetcode.com/problems/container-with-most-water/
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/
// this problem is very very similar to trapped rain water between buildings problem
// We can use 2 pointer approach to move from start and end position of array
// For every array index value consider the minimum height of the vals to consider for area computation.
// Area computation is = (min height between nLeft and nRight index) * (nRight - nLeft) i.e height * width

int maxWaterStoredInContainer(vector<int>& nHeights)
{
	int nLeft = 0;
	int nRight = nHeights.size() - 1;
	int nMaxWaterStored = 0;

	while (nLeft < nRight)
	{
		int nMaxAreaSofar = 0;
		// using the lowest of the 2 heights between nLeft and nRight 
		// gives us chance to compute the correct max area.
		if (nHeights[nLeft] < nHeights[nRight])
		{
			// nRight - nLeft gives the width details
			nMaxAreaSofar = nHeights[nLeft] * (nRight - nLeft);
			nLeft++;
		}
		else
		{
			// Control comes here when right height is less than or equal to left heigh
			nMaxAreaSofar = nHeights[nRight] * (nRight - nLeft);
			nRight--;
		}
		if (nMaxWaterStored < nMaxAreaSofar)
			nMaxWaterStored = nMaxAreaSofar;
	}
	return nMaxWaterStored;
}

/*
* Set Matrix Zeroes
https://leetcode.com/problems/set-matrix-zeroes/
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
*/

void setZeroes(vector<vector<int>>& matrix) {
	int nRows = matrix.size();
	int nCols = matrix[0].size();

	vector<bool> vRowMaps(nRows);
	vector<bool> vColMaps(nCols);
	for (int r = 0; r < nRows; r++)
	{
		for (int c = 0; c < nCols; c++)
		{
			if (matrix[r][c] == 0)
			{
				vRowMaps[r] = true;
				vColMaps[c] = true;
			}
		}
	}

	for (int r = 0; r < nRows; r++)
	{
		for (int c = 0; c < nCols; c++)
		{
			if (vRowMaps[r] == true || vColMaps[c] == true)
			{
				matrix[r][c] = 0;
			}
		}
	}

}


/*
Meta Facebook question


Largest Triple Products
You're given a list of n integers arr[0..(n-1)]. You must compute a list output[0..(n-1)] such that, for each index i (between 0 and n-1, inclusive), 
output[i] is equal to the product of the three largest elements out of arr[0..i] (or equal to -1 if i < 2, as arr[0..i] then includes fewer than three elements).
Note that the three largest elements used to form any product may have the same values as one another, but they must be at different indices in arr.
Signature
int[] findMaxProduct(int[] arr)
Input
n is in the range [1, 100,000].
Each value arr[i] is in the range [1, 1,000].
Output
Return a list of n integers output[0..(n-1)], as described above.
Example 1
n = 5
arr = [1, 2, 3, 4, 5]
output = [-1, -1, 6, 24, 60]
The 3rd element of output is 3*2*1 = 6, the 4th is 4*3*2 = 24, and the 5th is 5*4*3 = 60.
Example 2
n = 5
arr = [2, 1, 2, 1, 2]
output = [-1, -1, 4, 4, 8]
The 3rd element of output is 2*2*1 = 4, the 4th is 2*2*1 = 4, and the 5th is 2*2*2 = 8.
*/

struct MinComparePoints
{
	bool operator()(const int p1, const int& p2)
	{
		return (p1 > p2) ? true : false;
	}
};

vector<int> findMaxProduct(vector<int> arr)
{
	priority_queue<int, vector<int>, MinComparePoints> pqMinHeap, pqMinHeapNew;
	vector<int> outputArr;
	outputArr.push_back(-1);
	outputArr.push_back(-1);
	vector<int> tempCalc;

	for (int nElem : arr)
	{
		pqMinHeap.push(nElem);
		if (pqMinHeap.size() == 3)
		{
			pqMinHeapNew = pqMinHeap;
			while (!pqMinHeapNew.empty())
			{
				tempCalc.push_back(pqMinHeapNew.top());
				pqMinHeapNew.pop();
			}
			outputArr.push_back(tempCalc[0] * tempCalc[1] * tempCalc[2]);
			tempCalc.clear();
			pqMinHeap.pop();
		}
		
	}
	return outputArr;
}


bool balancedSplitExists(vector<int> nArr)
{
	sort(nArr.begin(), nArr.end());
	vector<int> nTempArr = nArr;
	int nSize = nArr.size();
	for (int i = 1; i < nSize; i++)
	{
		nTempArr[i] += nTempArr[i - 1];
	}
	for (int i = nSize - 1; i >= 1; i--)
	{
		if ((nTempArr[i - 1] * 2 == nTempArr[i]) && nArr[i -1] != nArr[i])
			return true;
	}
	return false;
}

string findEncryptedWords(string strInput, int nLow, int nHigh)
{
	if (strInput.empty() || strInput == "")
		return strInput;
	//nLow = 0;
	// int nHigh = strInput.size() - 1;
	int nMid = 0;
	if (strInput.size() % 2 == 1)
	{
		nMid = (strInput.size() - 1) / 2;
	}
	else
	{
		nMid = (strInput.size()/2 - 1);
	}

	return strInput[nMid] + findEncryptedWords(strInput.substr(0, nMid), 0, strInput.size()) + findEncryptedWords(strInput.substr(nMid + 1, strInput.size()), nMid + 1, strInput.size());

}



// Facebook meta interview question
/*
Suppose we have a list of N numbers, and repeat the following operation until we're left with only a single number: Choose any two numbers and replace them with their sum. Moreover, we associate a penalty with each operation equal to the value of the new number, and call the penalty for the entire list as the sum of the penalties of each operation.
For example, given the list [1, 2, 3, 4, 5], we could choose 2 and 3 for the first operation, which would transform the list into [1, 5, 4, 5] and incur a penalty of 5. The goal in this problem is to find the highest possible penalty for a given input.
Signature:
int getTotalTime(int[] arr)
Input:
An array arr containing N integers, denoting the numbers in the list.
Output format:
An int representing the highest possible total penalty.
Constraints:
1 ≤ N ≤ 10^6
1 ≤ Ai ≤ 10^7, where *Ai denotes the ith initial element of an array.
The sum of values of N over all test cases will not exceed 5 * 10^6.
Example
arr = [4, 2, 1, 3]
output = 26
First, add 4 + 3 for a penalty of 7. Now the array is [7, 2, 1]
Add 7 + 2 for a penalty of 9. Now the array is [9, 1]
Add 9 + 1 for a penalty of 10. The penalties sum to 26.
arr = [4, 2, 1, 3] ===> [4, 3, 2, 1]
[7, 2, 1] ==> [9, 1] ==> 10 ===> 10 + 9 + 7 ==> 26
*/

int getTotalTime(vector<int> nArr)
{
	sort(nArr.begin(), nArr.end(), greater<int>());
	int nSumResult = 0;
	for (int i = 1; i < nArr.size(); i++)
	{
		nArr[i] += nArr[i - 1];
		nSumResult += nArr[i];
	}
	return nSumResult;
}

/*
* Facebook
* Meta problem
Given a list of N triangles with integer side lengths, determine how many different triangles there are. Two triangles are considered to be the same if they can both be 
placed on the plane such that their vertices occupy exactly the same three points.
Signature
int countDistinctTriangles(ArrayList<Sides> arr)
or
int countDistinctTrianges(int[][] arr)
Input
In some languages, arr is an Nx3 array where arr[i] is a length-3 array that contains the side lengths of the ith triangle. In other languages, arr is a list of structs/objects that each represent a single triangle with side lengths a, b, and c.
It's guaranteed that all triplets of side lengths represent real triangles.
All side lengths are in the range [1, 1,000,000,000]
1 <= N <= 1,000,000
Output
Return the number of distinct triangles in the list.
Example 1
arr = [[2, 2, 3], [3, 2, 2], [2, 5, 6]]
output = 2
The first two triangles are the same, so there are only 2 distinct triangles.
Example 2
arr = [[8, 4, 6], [100, 101, 102], [84, 93, 173]]
output = 3
All of these triangles are distinct.
Example 3
arr = [[5, 8, 9], [5, 9, 8], [9, 5, 8], [9, 8, 5], [8, 9, 5], [8, 5, 9]]
output = 1
All of these triangles are the same.
*/

/*
struct triangl
{
public:
	int a;
	int b;
	int c;
};

struct triangleComparator
{
	bool operator()(const triangl& t1, const triangl& t2)
	{
		return (t1.a < t2.a&& t1.b < t2.b&& t1.c < t2.c);
	}
};

int countDistinctTriangles()
{
	vector<struct triangl> triList = { {7, 6, 5}, {5, 7, 6}, {8, 2, 9}, {2, 3, 4}, {2, 4, 3} };
	// map<struct triangle, int> setToHoldDistinct;
	// tuple<struct triangl::a, struct triangl::b, struct triangl::c >> tup;
	// set<pair<struct triangl::a, struct triangl::b, struct triangl::c>> setToHoldDistinct;
	//std::sort(triList.begin(), triList.end(), triangleComparator());
	for (auto tri : triList)
	{
		// setToHoldDistinct[tri]++;
		setToHoldDistinct.insert(tri);
	}
	return setToHoldDistinct.size();
}*/


/*
Magical Candy Bags
You have N bags of candy.The ith bag contains arr[i] pieces of candy, and each of the bags is magical!
It takes you 1 minute to eat all of the pieces of candy in a bag(irrespective of how many pieces of candy are inside), and as soon as you finish, the bag mysteriously refills.If there were x pieces of candy in the bag at the beginning of the minute, then after you've finished you'll find that floor(x / 2) pieces are now inside.
You have k minutes to eat as much candy as possible.How many pieces of candy can you eat ?
Signature
int maxCandies(int[] arr, int K)
Input
1 ≤ N ≤ 10, 000
1 ≤ k ≤ 10, 000
1 ≤ arr[i] ≤ 1, 000, 000, 000
Output
A single integer, the maximum number of candies you can eat in k minutes.
Example 1
N = 5
k = 3
arr = [2, 1, 7, 4, 2]
output = 14
In the first minute you can eat 7 pieces of candy.That bag will refill with floor(7 / 2) = 3 pieces.
In the second minute you can eat 4 pieces of candy from another bag.That bag will refill with floor(4 / 2) = 2 pieces.
In the third minute you can eat the 3 pieces of candy that have appeared in the first bag that you ate.
In total you can eat 7 + 4 + 3 = 14 pieces of candy.
*/
/*
struct MaxComparator
{
	bool operator()(const int& v1, const int& v2)
	{
		return v1 < v2 ? true : false;
	}
};

int maxCandies(vector <int> arr, int k) {
	priority_queue<int, vector<int>, MaxComparator> maxHeap;
	for (int nElem : arr)
	{
		maxHeap.push(nElem);
	}
	int nResult = 0;
	int nTopElem = 0;
	while (k--)
	{
		nTopElem = maxHeap.top();
		nResult += nTopElem;
		maxHeap.pop();
		maxHeap.push(nTopElem / 2);
	}
	return nResult;
}
*/
/*
* 347. Top K Frequent Elements
* https://leetcode.com/problems/top-k-frequent-elements/
* Design a system that stores top k topics in face book. asked in McAfee
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]

*/
/*
class SolutionTopKFreq
{
	// Struct to store values and its frequencies
	struct NodeOne
	{

		int nVal;
		int nFreq;
		NodeOne(int n, int f)
		{
			nVal = n;
			nFreq = f;
		}

	};
	struct MaxCompareOper
	{
		bool operator()(const NodeOne& a, NodeOne& b)
		{
			return a.nFreq < b.nFreq;
		}
	};
public:
	vector<int> topKFrequent(vector<int>& inputNums, int nK)
	{
		unordered_map<int, int> mapToValFreq;
		// Step 1: Store freq of all elems in map.
		for (int nElem : inputNums)
		{
			mapToValFreq[nElem] += 1;
		}

		// Step 2: Now build a heap
		// This is a custom heap to sort it based on frequency
		priority_queue<NodeOne, vector<NodeOne>, MaxComparator> heapOfNums;			// Compare defines max heap based on frequency
		for (auto iter : mapToValFreq)
		{
			heapOfNums.push(NodeOne(iter.first, iter.second));
		}
		// Stores top K elements
		vector<int> retAnswer;
		// Step 3: pop top K elements and store in vector.
		while (nK--)
		{
			NodeOne nodeTemp = heapOfNums.top();
			heapOfNums.pop();
			retAnswer.push_back(nodeTemp.nVal);
		}
		return retAnswer;
	}

};
*/

void minHeapify(vector<int> nInputArr, int N, int i)
{
	int nLeft = 2 * i;
	int nRight = 2 * i + 1;
	int nSmallest = i;
	if (nLeft < N && nInputArr[nLeft] < nInputArr[i])
		nSmallest = nLeft;
	else
		nSmallest = nRight;
	if (nSmallest != i)
	{
		swap(nInputArr[i], nInputArr[nSmallest]);
		minHeapify(nInputArr, N, nSmallest);
	}
}

void buildHeap(vector<int> inputArr, int N)
{
	for (int i = N / 2 - 1; i >= 0; --i)
	{
		minHeapify(inputArr, N, i);
	}
	for (int i = N - 1; i >= 0; i--)
	{
		swap(inputArr[0], inputArr[i]);
		minHeapify(inputArr, i, 0);
	}
}

/*
1010. Pairs of Songs With Total Durations Divisible by 60
https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
Tag: asked in KinAxis
You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. 
Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

Example 1:

Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
Example 2:

Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
*/
// This problem is solved by keeping track of all the remaining times of the previous songs and 
// we need to find sub sequence with total time dvisible by 60. To do this we are checking in a loop if current time can be combined with any of the previous occurence of time
// to make it multiple of 60. For this we use previous occurence of timing tracker.
int numPairsDivisibleBy60(vector<int>& time) 
{
	vector<int> remainingTimingTracker(60, 0);
	int nCount = 0;
	for (int eachSongTime : time)
	{
		if (eachSongTime % 60 == 0)
		{
			// We are making this counter 0 because we are looking for pair of songs. not a single song.
			nCount += remainingTimingTracker[0];
		}
		else
		{
			// To locate the prvious un paired song timing
			// This is like I have 20 do u have 40?
			nCount += remainingTimingTracker[60 - eachSongTime % 60];
		}
		// This is like registering for later pairing
		remainingTimingTracker[eachSongTime % 60]++;
	}
	return nCount;
}

// Moving Average
// Finding Sliding Window Average.
vector<int> findRunningAverage(vector<int>& nInputArr, int nWindLen)
{
	// queue<int> nRunningWind(nWindLen);
	vector<int> nRunningWind(nWindLen, 0);
	int nSize = nInputArr.size();
	int nLeft = 0; int nRight = nWindLen;
	int nCurrWindSum = 0;
	int nCurWindAvg = 0;
	vector<int> nRetArr;
	for (int i = 0; i < nSize; i++)
	{
		while (i == 0 && nLeft < nRight)
		{
			nCurrWindSum += nInputArr[nLeft];
			nLeft++;
		}
		if (i == 0)
		{
			nCurWindAvg = nCurrWindSum / nWindLen;
		}
		else
		{
			if (i - 1 + nWindLen < nSize)
			{
				nCurrWindSum = nCurrWindSum - nInputArr[i - 1] + nInputArr[i - 1 + nWindLen];
				nCurWindAvg = nCurrWindSum / nWindLen;
			}
			else
				break;
		}
		nRetArr.push_back(nCurWindAvg);
	}
	return nRetArr;
}

// This was asked in VMWare.

vector<int> findFirstoccuringNegative(vector<int>& nInputArr, int nWindSize)
{
	queue<int> qArr;
	vector<int> nFirstOccuringNegInEachWind;
	if (nInputArr.empty())
		return {};
	if (nInputArr.size() < nWindSize)
		return {};
	int nWindCounter = 0;
	bool bFlagForEachWind = false;
	for (int i = 0; i < nInputArr.size(); i++)
	{
		qArr.push(nInputArr[i]);
		if (qArr.back() < 0 && nInputArr.size() - nWindSize - 1 > i)
		{
			nFirstOccuringNegInEachWind.push_back(nInputArr[i]);
		}
		else if (qArr.back() < 0 && bFlagForEachWind == false)
		{
			nFirstOccuringNegInEachWind.push_back(nInputArr[i]);
		}
		if(i > nWindSize  -1)
		{
			qArr.pop();
		}
		if (nInputArr.size() - nWindSize <= i && nInputArr[i] < 0)
		{
			bFlagForEachWind = false;
		}
		nWindCounter++;
	}
	return nFirstOccuringNegInEachWind;
}
/*
* 65. Valid Number
* https://leetcode.com/problems/valid-number/
https://www.youtube.com/watch?v=ixKZ30_AuFM
A valid number can be split up into these components (in order):

A decimal number or an integer.
(Optional) An 'e' or 'E', followed by an integer.
A decimal number can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One of the following formats:
One or more digits, followed by a dot '.'.
One or more digits, followed by a dot '.', followed by one or more digits.
A dot '.', followed by one or more digits.
An integer can be split up into these components (in order):

(Optional) A sign character (either '+' or '-').
One or more digits.
For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

Given a string s, return true if s is a valid number.



Example 1:

Input: s = "0"
Output: true
Example 2:

Input: s = "e"
Output: false
Example 3:

Input: s = "."
Output: false

*/
// To solve this problem we need to consider all the edge cases.
// The integer function totall checks about integerness. Integer cna have 0th index val - or + 
// Integer should have numbers 0 to 9. if anything else found return false. Integer segement should not be emtpy.

// Then second validation or verification is for decimal.
// a Decimal number can start with '-' or '+'. 
// a decimal number cant have more than 1 '.'
// before and after the dot it should have numbers only

// Now the third and main validation is for 'e' or 'E'.
// A valid number should have only 1 e all the following numbers of e should be integers.
// the preceding digits before e can be integer or decimal.

bool isInteger(string s)
{
	if (s.empty())
		return false;
	if (s[0] = '-' || s[0] == '+')
		s = s.substr(1);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			continue;
		return false;
	}
	return !s.empty();
}

bool isDecimal(string s)
{
	if (s.empty())
	{
		return false;
	}
	if (s[0] == '-' || s[0] == '+')
	{
		s = s.substr(1);
	}

	int nDotcount = count(s.begin(), s.end(), '.');
	int nIdx = 0;
	if (nDotcount == 1)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '.')
			{
				nIdx = i;
				break;
			}
		}
		for (int i = 0; i < nIdx; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				continue;
			return false;
		}
		for (int i = nIdx + 1; i < s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				continue;
			return false;
		}
		return s.size() > 1;
	}
	return false;

}

bool isValidNumber(string s)
{
	int nSize = s.size();
	int nECount = 0;
	for (int i = 0; i < nSize; i++)
	{
		if (s[i] == 'e' || s[i] == 'E')
			++nECount;
	}
	if (nECount > 1)
		return false;
	if (nECount)
	{
		int nIdx = 0;
		for (int i = 0; i < nSize; i++)
		{
			if (s[i] == 'e' || s[i] =='E')
			{
				nIdx = i;
				break;
			}
		}
		if (!isInteger(s.substr(nIdx + 1)))
			return false;

		s = s.substr(0, nIdx);
	}

	// The remiaining letters after '.' should be integer or decimal
	return isInteger(s) || isDecimal(s);
}

/*
* 23. Merge k Sorted Lists
* https://leetcode.com/problems/merge-k-sorted-lists/
* Asked in KinAxis
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
*/

vector<int> mergeKLists(vector<vector<int>>& listOfLists) 
{
	priority_queue<int, vector<int>, greater<int>> pqMaxHeap;
	vector<int> retArr;
	for (auto list : listOfLists)
	{
		for(auto elem : list)
		{ 
			pqMaxHeap.push(elem);
		}
	}
	while (!pqMaxHeap.empty())
	{
		int nCurrElem = pqMaxHeap.top();
		pqMaxHeap.pop();
		retArr.push_back(nCurrElem);
	}
	return retArr;
}


/*
282. Expression Add Operators
https://leetcode.com/problems/expression-add-operators/
https://www.youtube.com/watch?v=PY8fO9KfuIA
Hard Problem
Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the 
digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.



Example 1:

Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
Example 2:

Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
Example 3:

Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.

*/

// When we look carefully in the problem statement there is a clue there about the approach to be followed.
// It says "return all possibilities" this means we need to try backtracking as one of the solution approach.
// Important thing to remember when solving this problem is '*' operator should be handled differently than other operators ('-' or  '+')
/*
class SolutionForAddOperators
{
	vector<string> retAns;
public:
	// currIdx - this is curr Index, strPath - This we need to prepare every time we process.
	// resSofar - 
	void DFSOperation(int currIdx, string strPath, long resSofar, long prevNum, string strInput, int nTarget)
	{
		if(currIdx == strInput.size())
		{
			if (resSofar == nTarget)
				retAns.push_back(strPath);			// here strPath contains the overall Equation expression that computes to nTarget.
			return;
		}
		for (int i = currIdx; i < strInput.size(); i++)
		{
			if (i > currIdx && strInput[currIdx] == '0')
				break;								// Skip the leading zeroes
			long lCurrNum = 
		}
	}
	vector<string> addOperators(string strNum, int target) 
	{
		DFSOperation(0, "", 0, 0, strNum, target);
		return retAns;
	}
};*/



/*
On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:

The north direction is the positive direction of the y-axis.
The south direction is the negative direction of the y-axis.
The east direction is the positive direction of the x-axis.
The west direction is the negative direction of the x-axis.
The robot can receive one of three instructions:

"G": go straight 1 unit.
"L": turn 90 degrees to the left (i.e., anti-clockwise direction).
"R": turn 90 degrees to the right (i.e., clockwise direction).
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.
*/



void sampleTest()
{
	int a = 1;
	int& b = a;
	int* p = &a;
	a = 2;
	b = 3;

	cout << *p << endl;
}

struct sampleNew
{
	int m_i;
	~sampleNew()
	{
		cout << m_i << " " << endl;
	}
};


struct sampleTestNew
{
	int mass{ 2 };
	mutable double vitamin{ 4.25 };
	void printVit() const
	{
		cout << vitamin << endl;
	}
};

void sampleTrialTest()
{
	auto l1 = []() {cout << "apple"; };
	auto l2 = []() {cout << "apple"; };

	cout << ::is_same_v<decltype(l1), decltype(l2)>;
}

int findNumOfPairs(vector<int> a, vector<int> b) {
	if (a.empty() || b.empty())
	{
		return -1;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int nCurrCount = 0;
	int nMaxCount = INT_MIN;
	int naSize = a.size() - 1;
	int nbSize = b.size() - 1;
	for (int i = naSize; i >= 0; i--)
	{
		for (int j = nbSize; j >= 0; j--)
		{
			if (a[i] > b[j])
			{
				nCurrCount += 1;
			}
			else {
				continue;
			}

		}
		nMaxCount = max(nMaxCount, nCurrCount);
		nCurrCount = 0;
	}
	return nMaxCount;
}

int main()
{
	vector<int> inputA = { 1, 2, 3, 4, 5 };
	vector<int> inputB = { 6, 6, 1 , 1, 1 };
	int nMaxUnqCount = findNumOfPairs(inputA, inputB);

	inputA = { 1, 2, 3 };
	inputB = { 1 , 1, 1 };
	nMaxUnqCount = findNumOfPairs(inputA, inputB);
	sampleTrialTest();
	const sampleTestNew newTest;
	newTest.vitamin = 42;
	newTest.printVit();
	auto a = new sampleNew[3]{ {0}, {1}, {2} };
	delete[] a;
	// Find if Increasing Triplet
	vector<int> ascArray = { 3, 1, 0, 2, 1, -1, 3, 7, 2 };
	bool isIncreasngTriplet = increasingTriplet(ascArray);

	ascArray = { 3, 1, 0, 2, 1, 3, 7, 2 };
	isIncreasngTriplet = increasingTriplet(ascArray);

	 ascArray = { 3, 1, 0, 2, 3, 1, 3, 7, 2 };
	 isIncreasngTriplet = increasingTriplet(ascArray);

	 ascArray = { 3, 0, 0, 0, 0, 0, 0, 0, 2 };
	 isIncreasngTriplet = increasingTriplet(ascArray);

	sampleTest();
	string strPalindrom = "levrel";
	bool bIsValidPalindromeOf1EDist = isValidPalindrome(strPalindrom);
	strPalindrom = "leevel";
	bIsValidPalindromeOf1EDist = isValidPalindrome(strPalindrom);

	// Given an array with equal number of odds and even numbers
	// Below function arranges odd number in odd indexes
	// and even number in even indexes
	vector<int> nGeneralArray = { 1, 2, 3, 4, 5, 6, 7, 8 };
	arrangeOddAndEvenValInOddAndEvenIndexes(nGeneralArray);

	vector<int> nGeneralNewArray = { 1, 2, 3, 4, 5, 6, 7, 8 };
	ArrangeOddAndEvenValsInRepectiveIdx(nGeneralNewArray);

	int nRetVal = longestValidParentheses(")()())");

	int nLenOfValiBrPairs = findMaxLenOfValidBrackets(")()())");
	nLenOfValiBrPairs = findMaxLenOfValidBrackets("(()");

	// Below Program checks if the given integer is palindrome or not
	// To check the palindromic integer we may check only half of the integer
	// The remaing half should be same as reversed val. 
	bool bIsIntegerPalindrome = IsPalindromicInteger(35453);
	bIsIntegerPalindrome = IsPalindromicInteger(1000);
	double dRet = average('c', 'd');
	std::string myString = "sendmail2venki@gmail.com";
	stringToIntHash(myString);
	myString = "mailsend2venki@gmail.com";
	stringToIntHash(myString);
	myString = "send2mailvenki@gmail.com";
	stringToIntHash(myString);
	myString = "sendvenki2mail@gmail.com";
	stringToIntHash(myString);
	myString = "venkisendmail2@gmail.com";
	stringToIntHash(myString);
	myString = "venki2sendmail@gmail.com";
	stringToIntHash(myString);



	// Find missing element in an continous numbered array (un sorted)
	// Array contains value from 0 to N
	// This problem can be solved by applying gaussian function.
	vector<int> arrayNumVector = { 3, 7, 0, 2, 5, 9, 1, 4, 6 };
	int nReturnVal = FindMissingNumberInContinousUnsortedArray(arrayNumVector);

	// Find the two sum array indexes
	vector<int> nArray = { 2, 7, 11, 15 };
	int nTarget = 9 + 4 + 9;
	vector<int> nRetVector = findTwoSum(nArray, nTarget);

	// The below algorithm is useful in finding the largest continous subarray with equal number of 0's and 1's.
	// This problem can be solved by using hash map. The approach for this problem is bit similar to 2 sum in array.
	vector<int> nArrayOf0sAnd1s = { 0, 0, 1, 0, 0, 0, 1, 1 };
	int nMaxCountofContinous0sAnd1s = findMaxSubArrayLengthOf0sAnd1s(nArrayOf0sAnd1s);


	vector<int> nInputArrOfColors = { 2,0,2,1,1,0 };
	sortColors(nInputArrOfColors);

	nInputArrOfColors = { 0,1,2,0,2,0,1,1,0,2,2,1,1,2,2,1,0,1,0,1 };
	sortColors(nInputArrOfColors);

	/*
	// The below function increments the array  LSB digit by 1.
	vector<int> sampleArray = { 9, 9, 9, 9 };
	sampleArray = incrementDigitInArray(sampleArray);

	sampleArray = { 8, 9, 9, 9 };
	sampleArray = incrementDigitInArray(sampleArray);

	sampleArray = { 1, 2, 3, 9 };
	sampleArray = incrementDigitInArray(sampleArray);

	sampleArray = { 1, 2, 3, 4 };
	sampleArray = incrementDigitInArray(sampleArray);

	*/
	vector<int> sampleVector = { 1, 2, 3, 4 };
	int nReturnValue = firstMissingPositive(sampleVector);

	f(6);
	f(12);
	f(30);
	f(56);
	f(49);

	int n = 56;
	pronic_check(n) == true ? cout << "YES" : cout << "NO" << endl;
	pronic_check(6) == true ? cout << "YES" : cout << "NO" << endl;
	pronic_check(12) == true ? cout << "YES" : cout << "NO" << endl;
	pronic_check(24) == true ? cout << "YES" : cout << "NO" << endl;
	pronic_check(56) == true ? cout << "YES" : cout << "NO" << endl;
	pronic_check(49) == true ? cout << "YES" : cout << "NO" << endl;
	int nPronicCount = checkCountOfPronicNumbers(6, 30);


	countPronic(6, 56);
	stringProblem();


	// The below function will find the maximum sum between continous array elements.
	vector<int> inputVector = { -2,1,-3,4,-1,2,1,-5,4 };
	cout << " Maximum sum by continous elements in the givent input is: " << maxContinousSubArraySum(inputVector);

	// The below function finds the kth largest element in the array.
	vector<int> inputVectorArray = { 3,2,3,1,2,4,5,5,6 };
	int kthLargest = findKthLargest(inputVectorArray, 5);
	findKthLargestII(inputVectorArray, 5);
	inputVectorArray = { 3,2,1,5,6,4 };
	kthLargest = findKthLargest(inputVectorArray, 2);
	findKthLargestII(inputVectorArray, 2);

	vector<string> inputFoKthLargest = { "4", "2", "7", "1", "5", "3", "6" };
	string strRet = findKthLargestIII(inputFoKthLargest, 5);

	// Find the triplets which are summing to 0. This logic works only for finding zero sum.
	vector<int> inputArrayWithNegativeNums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>>  triplets = FindTripletsSummingToZero(inputArrayWithNegativeNums, 0);

	// Below function is useful to move the zero elements in the array to the end of array.
	vector<int> nInputArr = { 4, 6, 1, 0, 33, 16, 7, 2, 63, 0, 1, 22, 65, 0, 26, 54, 0, 18 };
	moveZeroesToEnd(nInputArr);

	// Find Sub array summ K
	inputVectorArray = { 3,2,1,5,6,4 };
	int nRetCountVal = FindSubArrSum(inputVectorArray, 9);

	inputVectorArray = { 3,4,7,2,-3,1 };
	nRetCountVal = FindSubArrSum(inputVectorArray, 7);

	inputVectorArray = { 3,2,1,5,6,4 };
	nRetCountVal = FindSubArraySum(inputVectorArray, 9);

	inputVectorArray = { 3,4,7,2,-3,1 };
	nRetCountVal = FindSubArraySum(inputVectorArray, 7);


	//// Find if Increasing Triplet
	//vector<int> ascArray = { 3, 1, 0, 2, 1, 3, 7, 2 };
	//bool isIncreasngTriplet = increasingTriplet(ascArray);


	// To invoke Roman to integer conversion function
	Solution resultObj;
	int nVal = resultObj.romanToInt("MDVCCLXXVI");

	nVal = resultObj.romanToInt("IXIV");
	nVal = resultObj.romanToInt("CMCDXCXL");
	nVal = resultObj.romanToInt("XL");
	nVal = resultObj.romanToInt("XC");
	nVal = resultObj.romanToInt("CD");


	string srRomanResult = resultObj.intToRoman(1994);
	srRomanResult = resultObj.intToRoman(994);
	srRomanResult = resultObj.intToRoman(1664);
	srRomanResult = resultObj.intToRoman(94699);

	// Below snipper of code is useful for reversing a string
	char sz[] = "Hello World!";
	char szNew[] = "Hello World!";
	cout << sz << endl;
	ReverseString(sz, sz + _countof(sz) - 1);
	cout << sz << endl;

	cout << szNew << endl;
	char* szRetReversedWords = ReverseWordsInAString(szNew, strlen("Hello World!"));
	cout << szRetReversedWords << endl;

	int nRetColNum = titleToNumber("ZX");
	nRetColNum = titleToNumber("AB");
	nRetColNum = titleToNumber("HW");
	nRetColNum = titleToNumber("QK");
	nRetColNum = titleToNumber("A");
	nRetColNum = titleToNumber("Y");
	nRetColNum = titleToNumber("YY");

	int nRet = reverseANumber(1572);

	double dReturn;
	dReturn = myPow(2, 6);
	double dReturnNew = findPower(2, 6);


	vector<vector<int>> nMatrix = { {1,2,3,4}, {2,4,9,5}, {9,8,7,6} };
	printMatrixInSpiralOrder(nMatrix);
	vector<vector<int>> intervals = { {0, 30}, {5, 10}, {15, 20} };
	if (canAttendMeetings(intervals))
	{
		cout << " Yes all MEeeting can be attended" << endl;
	}
	else
	{
		cout << " Nope! Not all Meetings can be attended" << endl;
	}
	intervals = { {0, 30}, {31, 49}, {15, 20} };
	if (canAttendMeetings(intervals))
	{
		cout << " Yes all MEeeting can be attended" << endl;
	}
	else
	{
		cout << " Nope! Not all Meetings can be attended" << endl;
	}
	intervals = { {0, 30}, {31, 49}, {51, 60} };
	if (canAttendMeetings(intervals))
	{
		cout << " Yes all MEeeting can be attended" << endl;
	}
	else
	{
		cout << " Nope! Not all Meetings can be attended" << endl;
	}
	vector<int> inputArrWith0s1sAnd2s = { 2,0,2,1,1,0 };
	sort0s1sAnd2s(inputArrWith0s1sAnd2s);

	vector<int> arrWithContinous1s = { 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1 };
	int nMAxContinous1s = findMAxContinous1s(arrWithContinous1s);

	vector<int> arrWithContinous0sAnd1s = { 1, 1, 0, 1, 0, 0, 0, 1, 0 };
	bool bContinousZeroOrOneResult = findHighestContinous1sOr0s(arrWithContinous0sAnd1s);
	vector<int> sampleInput = { 1, 2, 3, 1, 2, 1 };
	groupElementsBasedOnOccurence(sampleInput);
	sampleInput = { 5, 2, 5, 3, 5, 4, 4, 3, 1, 2, 2 };
	groupElementsBasedOnOccurence(sampleInput);

	sampleInput = { 5, 3, 27, 1, 85, 4, 2, 6, 9, 8, 7 };
	int nSmallestMissingNum = findLowestMissingNumber(sampleInput);

	sampleInput = { 5, 3, 1, 4, 2, 6, 9, 8, 7 };
	nSmallestMissingNum = findLowestMissingNumber(sampleInput);

	sampleInput = { 1, 2, 0 };
	nSmallestMissingNum = findLowestMissingNumber(sampleInput);

	string strReturn = addBinary("1111", "1101");

	strReturn = addBinary("0011", "0001");

	// This below algorithm merges overlapping intervals found in a subarray into one.
	vector<vector<int>> nIntervalArr = { {1, 3}, {2, 6}, {5, 14}, {8, 10}, {15, 18} };
	vector<vector<int>> mergedArray = mergeIntervals(nIntervalArr);


	vector<vector<int>> meetingIntervals = { {0,30 },{5, 10 },{15, 20 } };
	// This function will determine number of meeting rooms required for conducting the meeting in above time.
	int nNumberOfMeetningRooms = minMeetingRooms(meetingIntervals);


	vector<int> buildingHeights = { 4,2,3,1 };
	vector<int> beachViewBuildings = canSeeTheBeach(buildingHeights);

	buildingHeights = { 4,2,1, 5,1 };
	beachViewBuildings = findBuildings(buildingHeights);

	buildingHeights = { 4,2,4,3,1 };
	beachViewBuildings = findBuildings(buildingHeights);
	vector<int> inputFor3SumClosest = { -1,2,1,-4 };
	int nSumCloserToTarget = threeSumClosest(inputFor3SumClosest, 2);

	vector<int> slidingWinMax = { 1,3,-1,-3,5,3,6,7 };
	vector<int> collectionOfMaxInEachWindow = findSlidingWindMax(slidingWinMax, 3);

	vector<int> nArrEq0sAnd1s = { 0, 1, 1, 0, 1 };
	int nRetResult = findMaxLengthofEqual0sAnd1s(nArrEq0sAnd1s);

	vector<int> rotateArr = { 1, 2, 3, 4, 5, 6, 7 };
	rotateArrays(rotateArr, 3);
	rotateArr = { 1, 2, 3, 4, 5, 6, 7 };
	rotateArraysLeftDir(rotateArr, 3);


	rotateArr = { 1, 2, 3, 4, 5, };
	int nPivotPoint = findPivotIndex(rotateArr);
	rotateArraysLeftDir(rotateArr, 4);
	nPivotPoint = findPivotIndex(rotateArr);
	rotateArr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	rotate(rotateArr, 2);
	int nRetIdx = searchANumberInRotatedArray(rotateArr, 2);
	rotate(rotateArr, 4);
	nRetIdx = searchANumberInRotatedArray(rotateArr, 2);
	nRetIdx = searchANumberInRotatedArray(rotateArr, 6);

	
	rotateArr = { 41, 73, 89, 7, 10, 1, 59, 58, 84, 77, 77, 97, 58, 1, 86, 58, 26, 10, 86, 51 };
	rotateArraysLeftDir(rotateArr, 10);
	
	int nMinFromRotatedArr = findMinInARotatedArr(rotateArr);

	vector<int> arrWithProds = { 10,5,2,6 };
	int nKCount = findSubArrayProductLessThanK(arrWithProds, 100);

	//

	arrWithProds = { 1, 2, 3, 5 };
	nKCount = findSubArrayProductLessThanK(arrWithProds, 11);

	vector<int> nElemArr1 = { 2, 6, 2, 3, 4, 1, 8, 0, 2, 5, 8, 1, 56, 97 };
	vector<int> nElemArr2 = { 5,2, 3,6,3, 4,76,3, 1, 21,3,46,8,9, 856,23,5, 4, 7, 798,9 };
	vector<int> interElems = findCommonElements(nElemArr1, nElemArr2);

	vector<int> personHeights = { 10, 6, 8, 5, 11, 9 };
	vector<int> resultPersonHeightCanSee = canSeePersonsCount(personHeights);

	vector<string> wordList = { "hello","leetcode" };
	string order = "hlabcdefgijkmnopqrstuvwxyz";
	bool bIsLexicallySorted = isAlienLangwordsSorted(wordList, order);

	wordList = { "word","world","row" };
	order = "worldabcefghijkmnpqstuvxyz";
	bIsLexicallySorted = isAlienLangwordsSorted(wordList, order);

	wordList = { "apple", "app" };
	order = "abcdefghijklmnopqrstuvwxyz";
	bIsLexicallySorted = isAlienLangwordsSorted(wordList, order);

	int nRetSQRoot = findSquareRoot(findSquareRoot(625));

	vector<vector<int>> inputMatrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	matrixTransPose(inputMatrix);

	vector<int> nInputArrArrange = { 1, 2, 3, 4, 5 };
	reArrangeArray(nInputArrArrange);


	nInputArrArrange = { 5, 1, 2, 3, 4 };
	reArrangeArray(nInputArrArrange);

	vector<char> strRetMultiplyVal = multiplyStrings("25", "25");
	string strRetResultNum = multiplyStringsNew("12", "30");
	strRetResultNum = multiplyStringsNew("123", "456");

	vector<int> anangramPositions = findAnagramPlacements("abcdebacb", "cab");

	anangramPositions = findAnagramPlacements("edeabcdebad", "cab");
	string strSubStrRepeat = "geeksgeeks";
	bool isPeriodicSubStr = isPeriodic(strSubStrRepeat, strSubStrRepeat.size(), 5);
	strSubStrRepeat = "ababab";
	isPeriodicSubStr = isPeriodic(strSubStrRepeat, strSubStrRepeat.size(), 3);
	vector<vector<int>> linIntervals = { {1, 3}, {6, 9} };
	vector<int> newInterval = { 2, 5 };
	vector<vector<int>> mergedInterval = insertInterval(linIntervals, newInterval);

	linIntervals = { {1, 2}, {3, 4}, { 5, 8}, {9, 12}, {16, 21}, {26, 29} };
	newInterval = { 11, 26 };
	mergedInterval = insertInterval(linIntervals, newInterval);

	vector<vector<int>> inputPoints = { {1, 3}, {-2, 2} };
	vector<vector<int>> closestPoints = kClosestPointToOrigin(inputPoints, 1);

	inputPoints = { {3, 3}, {5, -1}, {-2, 4} };
	closestPoints = kClosestPointToOrigin(inputPoints, 2);


	inputPoints = { {3, 3}, {5, -1}, {-2, 4} };
	closestPoints = kClosestPointToOriginUsingPQ(inputPoints, 2);

	vector<int> inputArrWithNegVals = { 2,-1,2 };
	shortestSubarrayWithSumGreaterOrEqToK(inputArrWithNegVals, 3);

	inputArrWithNegVals = { 2, 7, 3, -8, 4, 10 };
	shortestSubarrayWithSumGreaterOrEqToK(inputArrWithNegVals, 12);
	vector<string> strAnagramList = { "abc", "bca", "cba", "abz", "zba", "baz", "baz" };
	groupAnagrams(strAnagramList);
	int nLargestCount = groupAnagramsNew(strAnagramList);

	string strPalindromicAnagram = "radar";
	bool bIsPalindromePossible = canBePermutedPalindrome(strPalindromicAnagram);

	strPalindromicAnagram = "laal";
	bIsPalindromePossible = canBePermutedPalindrome(strPalindromicAnagram);

	strPalindromicAnagram = "adadhghgiwiwn";
	bIsPalindromePossible = canBePermutedPalindrome(strPalindromicAnagram);

	strPalindromicAnagram = "szbgbgzs";
	bIsPalindromePossible = canBePermutedPalindrome(strPalindromicAnagram);

	strPalindromicAnagram = "sfzbgbwgzs";
	bIsPalindromePossible = canBePermutedPalindrome(strPalindromicAnagram);

	vector<int> inputPrdArr = { -3, 2, -4, 6, 0, -8, 5 };
	int nMaxProdVal = maxProductSubArr(inputPrdArr);
	string strInputValue = "abbaca";
	string strReturnVal = removeDuplicates(strInputValue);

	int nFormulaResult = calculate("5 * 8 - 3");


	vector<vector<int>> islandPerimMatrix = { {0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{1, 1, 0, 0} };
	int nPerimeterOfGivenIsland = islandPerimeter(islandPerimMatrix);

	vector<int> nSampleInputArr = { 1, 2, 3, 4, 5, 6 };
	productExceptSelf(nSampleInputArr);

	vector<int> heightOfWaterContainerWalls = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int nMaxWaterStoredInContainer =  maxWaterStoredInContainer(heightOfWaterContainerWalls);
	vector<int> prodArr = { 1, 2, 3, 4, 5 };
	vector<int> retProdArr = findMaxProduct(prodArr);

	vector<int> spliArrInputs = { 1, 5, 7, 1 };
	bool bRetSplitArr = balancedSplitExists(spliArrInputs);
	spliArrInputs = { 12, 7, 6, 7, 6 };
	bRetSplitArr = balancedSplitExists(spliArrInputs);
	spliArrInputs = { 1 , 2, 2, 1, 3, 3, 3, 14, 3, 4 };
	bRetSplitArr = balancedSplitExists(spliArrInputs);
	string strEncryptedWords = findEncryptedWords("facebook", 0, string("facebook").size());
	vector<int> nGeneralArr = { 4, 1, 2, 3 };
	int nSumResult = getTotalTime(nGeneralArr);

	// int retDistinctTriangles = countDistinctTriangles();

	vector<int> subArrSampleForSumK = { 1,2,3 };
	findCounOfSubArraysToMakeK(subArrSampleForSumK, 3);
	subArrSampleForSumK = { 1,2,3, 6, 3, 8, 7, 9, 6};
	findCounOfSubArraysToMakeK(subArrSampleForSumK, 15);

	vector<int> subArrSumWithMultiplsOfK = { 23,2,4,6,7 };
	checkIfSubarraySumIsMultiplesOfK(subArrSumWithMultiplsOfK, 6);

	subArrSumWithMultiplsOfK = { 23,2,6,4,7 };
	checkIfSubarraySumIsMultiplesOfK(subArrSumWithMultiplsOfK, 6);
	
	subArrSumWithMultiplsOfK = { 23,2,6,4,7 };
	checkIfSubarraySumIsMultiplesOfK(subArrSumWithMultiplsOfK, 13); 


	vector<int> windThatContainsSubArrSum = { 1,-1,5,-2,3 };
	int nMaxWindSizeOfSubArrSum = maxWindSizeOfSubArrSumOfK(windThatContainsSubArrSum, 3);

	windThatContainsSubArrSum = { -2,-1,2,1 };
	nMaxWindSizeOfSubArrSum = maxWindSizeOfSubArrSumOfK(windThatContainsSubArrSum, 1);

	vector<int> nArray1 = { 1 , 2, 2, 1, 3, 3, 3, 14, 3, 4 };
	vector<int> nArray2 = { 5, 3, 7, 2, 8, 2, 1, 7, 3, 4 };
	nArray1 = intersectionOf2ArraysII(nArray1, nArray2);

	nArray1 = { 1 , 2, 2, 1, 3, 3, 3, 14, 3, 4, 7};
	nArray2 = { 5, 3, 7, 2, 8, 2, 1, 7, 3, 4 };
	nArray1 = intersectionOf2ArraysII(nArray1, nArray2);

	// Below problem is asked in meta- Facebook.
	vector <int> arr_1{ 2, 1, 7, 4, 2 };
	//int nCandyResult = maxCandies(arr_1, 3);

	int k_2 = 3;
	vector <int> arr_2{ 19, 78, 76, 72, 48, 8, 24, 74, 29 };
	//nCandyResult = maxCandies(arr_2, 3);

	vector<int> nInputArrVecforSubDivByK = { 4,5,0,-2,-3,1 };
	int nCountOfSubArrDivsByK = subarraysDivByK(nInputArrVecforSubDivByK, 5);
	vector<int> inputArrToMergeBig(6);
	inputArrToMergeBig = { 1, 2, 3 };
	vector<int> secArrToMergeSmall = { 2, 5, 6 };
	// mergeSortedArraysInto1st(inputArrToMergeBig, inputArrToMergeBig.size(),  secArrToMergeSmall, secArrToMergeSmall.size());

	vector<int> arrOfVals4KDiffPairs = { 3,1,4,1,5 };
	findUniqPairsWithKDiff(arrOfVals4KDiffPairs, 2);

	arrOfVals4KDiffPairs = { 1,2,3,4,5 };
	findUniqPairsWithKDiff(arrOfVals4KDiffPairs, 1);

	arrOfVals4KDiffPairs = { 1,3,1,5,4 };
	findUniqPairsWithKDiff(arrOfVals4KDiffPairs, 0);

	arrOfVals4KDiffPairs = { 3,1,4,1,5 };
	findUniqPairsWithKDiff(arrOfVals4KDiffPairs, 4);

	vector<int> arr1ToFindSumPairs = { 1, 1, 2, 2, 2, 3 };
	vector<int> arr2ToFindSumPairs = { 1, 4, 5, 2, 5, 4 };
	FindSumPairs toFindSumPairs(arr1ToFindSumPairs, arr2ToFindSumPairs);
	toFindSumPairs.count(7);
	toFindSumPairs.add(3, 2);


	vector<int> songTimings = { 30,20,150,100,40 };
	numPairsDivisibleBy60(songTimings);

	vector<int> runningWind = { 1, 2, 3, 4, 5, 6, 7 };
	findRunningAverage(runningWind, 3);

	string strInputParanthesesStr = "lee(t(c)o)de)";
	minRemoveToMakeValidParantheses(strInputParanthesesStr);

	strInputParanthesesStr = "a)b(c)d";
	minRemoveToMakeValidParantheses(strInputParanthesesStr);

	strInputParanthesesStr = "))((";
	minRemoveToMakeValidParantheses(strInputParanthesesStr);


	vector<vector<int>> nMatrixSample = { {1, 4, 7, 8}, {3, 5, 6, 7}, {2, 8, 9, 9} };
	vector<int> mregedKLists = mergeKLists(nMatrixSample);

	vector<int> arrToFindMaxSubArr = { 5, -2, 3, -6, 3, 4, 76, 31, 1, 21 };

	int nMaxSubArrSum = maxSubArray(arrToFindMaxSubArr);

	nMaxSubArrSum = maxSubArrayNew(arrToFindMaxSubArr);

	vector<int> nRedundantValArr = { 1, 2, 3, 3, 5, 5, 6, 6, 6, 6, 8, 9, 9, 9 };
	vector<int> nStartAndEndIdx = searchRangeOfIdxOfGivenVal(nRedundantValArr, 6);
	
	return 0;
}

