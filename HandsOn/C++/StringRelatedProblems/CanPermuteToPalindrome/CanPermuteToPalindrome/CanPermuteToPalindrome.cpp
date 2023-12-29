// CanPermuteToPalindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

/*
Given a string s, return true if a permutation of the string could form a palindrome.
https://leetcode.com/problems/palindrome-permutation/
in any planidromic string of even length all characters will have even number of occurences.
In any palindromic string of odd length, the middle chracter will occur only once and all the remaining characters have occureces of even number.
https://www.youtube.com/watch?v=edluuHln06g
*/
bool canPermuteToPlindrom(string strInput)
{
    vector<int> charMap(26);
    for (int i = 0; i < strInput.size(); i++)
    {
        charMap[strInput[i] - 'a']++;
    }
    int nMidCharCount = 0;
    for (int i = 0; i < strInput.size() && nMidCharCount <= 1; i++)
    {
        if (charMap[strInput[i] - 'a'] % 2 != 0)
        {
            nMidCharCount++;
        }
    }
    return (nMidCharCount <= 1);
}

int main()
{
    std::cout << "Hello World!\n";
    string strPalindromicAnagram = "radar";
    bool bIsPalindromePossible = canPermuteToPlindrom(strPalindromicAnagram);

    strPalindromicAnagram = "laal";
    bIsPalindromePossible = canPermuteToPlindrom(strPalindromicAnagram);

    strPalindromicAnagram = "adadhghgiwiwn";
    bIsPalindromePossible = canPermuteToPlindrom(strPalindromicAnagram);

    strPalindromicAnagram = "szbgbgzs";
    bIsPalindromePossible = canPermuteToPlindrom(strPalindromicAnagram);

    strPalindromicAnagram = "sfzbgbwgzs";
    bIsPalindromePossible = canPermuteToPlindrom(strPalindromicAnagram);
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
