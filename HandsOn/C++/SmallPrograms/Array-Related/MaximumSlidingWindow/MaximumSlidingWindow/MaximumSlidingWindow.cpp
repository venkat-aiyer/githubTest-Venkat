// MaximumSlidingWindow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <deque>
#include <vector>
#include <map>
#include <queue>
#include <concurrent_priority_queue.h>
using namespace std;

// This problem is very important in array category.
// Given an array of number we need to find the maximum value in a sliding window in the array.
// Where the window of array elements will change by sliding the window by 1 element towards right.

// This problem can be solved by multiple approaches.
// Naive approach with 2 loops.
// using dequeue
// Using priority queues
// Using dynamic programming

// The below solution uses heap data structure to solve the issue.
// Heap algorithm for finding max value in the sliding window
// 1. Build Max heap from 1st K elements ( First window)
// 2. Declare and use an answer array to store maxof each window.
// 2. a. (Pop  out of range elements)
// 2. b. (Push new elements).

vector<int> maxValsInEverySlidingWindowUsingHeap(vector<int> & arrayNumbers, int k)
{
	// Pair <int, int> contains (arrayNumbers[i], i);
	priority_queue<pair<int, int>> maxHeap;				// Max heap to find max values in each sliding window.
	vector<int> answerVector;							// Stores maximum values in each sliding window.
	// We need to pop the maximum top value from heap when new max is found by sliding the window outside current window
	for (int i = 0; i < arrayNumbers.size(); ++i)
	{
		// Remove the top value from heap if the window is slided outside the current window size.
		// to accomodate new max val in new window.
		while ((!maxHeap.empty()) && maxHeap.top().second <= (i - k))	// Pop the root or max element if it is out of current sliding window
		{
			maxHeap.pop();
		}
		maxHeap.push(make_pair(arrayNumbers[i], i));	// Push current element along with its index inside the heap.		
		if (i >= k - 1)									// Store max in the window if we have a valid window(Based on size K)
		{
			answerVector.push_back(maxHeap.top().first);
		}
	}
	return answerVector;
}

// The below approach used queue datastructure as it is 2 ended and behaves like doubly linked list.
vector<int> maxValsInEverySlidingWindowUsingQueue(vector<int> & arrayNumbers, int k)
{
	deque<pair<int, int>> dq;
	vector<int> answerVector;

	for (int i = 0; i < arrayNumbers.size(); ++i)
	{
		if (!dq.empty() && dq.front().second <= (i - k))			// Remove front element if it goes out of window size
			dq.pop_front();
		while (!dq.empty() && dq.back().first < arrayNumbers[i])	// Maintain elements in descending order.
			dq.pop_back();
		dq.push_back(make_pair(arrayNumbers[i], i));				// Push the current node.
		if (i >= (k - 1))
		{
			answerVector.push_back(dq.front().first);				// Include maximum of current window.
		}
	}
	return answerVector;
}
int main()
{
	vector<int> nums = { 3, 1, -1, 4, -3, 5, 3, 6, 7 };
	int k = 3;
	vector<int> retVector = maxValsInEverySlidingWindowUsingHeap(nums, k);
    return 0;
}

