// TopKFrequentWords.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// The below algorithm provides solution to find Top K Frequent words. The input to the algorithm is words list and K.
// We need to return the Top K frequent words list with the same lexicographic order.


vector<string> findTopKFrequentWords(vector<string> wordList, int nK)
{
    unordered_map<string, int> wordsCountMap;
    for (string eachWord : wordList)
        wordsCountMap[eachWord]++;
    // Remember to include queue
    priority_queue<pair<int, string>> pqFrequentWords;
    for (auto it : wordsCountMap)
    {
        // We provide -ve sign to use min-heap. minus sign used to build min heap.
        pqFrequentWords.push({ -it.second, it.first });
        if (pqFrequentWords.size() > nK)
            pqFrequentWords.pop();
    }
    vector<string> resWordsInFreqOrder;
    while (--nK)
    {
        resWordsInFreqOrder.push_back(pqFrequentWords.top().second);
        pqFrequentWords.pop();
    }
    reverse(resWordsInFreqOrder.begin(), resWordsInFreqOrder.end());

    return resWordsInFreqOrder;
    
}

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
